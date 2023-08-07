#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <vector>
#include <iomanip>
#include <chrono>

#include "dtocpp_led.h"

DTOCPP_NAMESPACE_BEGIN

namespace {
struct LedStreamBuffer {
    static int         mNextFreeThreadID;
    char               mBuffer[CLedBufferSize];
    std::ostringstream mSStream;
    int                mThreadID = mNextFreeThreadID++;

    explicit LedStreamBuffer() {
        mSStream.rdbuf()->pubsetbuf( mBuffer, size_t( mBuffer ) - 1 );
    }
};

int LedStreamBuffer::mNextFreeThreadID = 1;

struct LedWriteCallback {
    TLedWriteCallback mCallback;
    void            * mUserData = nullptr;
};

struct LedContext {
    std::map< std::thread::id, LedStreamBuffer > mThreadStreams;

    std::mutex                      mOutCallbackMutex;
    std::mutex                      mThreadStreamsMutex;
    std::vector< LedWriteCallback > mWriteCallbacks = { { & LedDefaultOutCallback, nullptr } };
    TLedChannelType                 mChannels       = 0;

    static LedContext & get() {
        static LedContext mCtx;

        return mCtx;
    }
};
}

void LedDefaultOutCallback( void       * userData,
                            TLedChannelType,
                            const char * data,
                            int          len )
{
    std::cout.write( data, len );
}

void LedChannelOpen( TLedChannelType channel )
{
    auto & ctx = LedContext::get();

    ctx.mChannels |= static_cast< TLedChannelType > (1) << channel;
}

void LedChannelClose( TLedChannelType channel ){
    auto & ctx = LedContext::get();

    ctx.mChannels &= ~(static_cast< TLedChannelType > (1) << channel);
}

LedStream LedStream::lockStream( TLedChannelType channel )
{
    auto & ctx = LedContext::get();

    LedStreamBuffer * ledStream = nullptr;
    {
        std::lock_guard< std::mutex > lock( ctx.mThreadStreamsMutex );

        ledStream = &ctx.mThreadStreams[std::this_thread::get_id()];
    }

    auto            timeSinceEpoch = std::chrono::high_resolution_clock::now().time_since_epoch();
    const long long milliSecond    = std::chrono::duration_cast< std::chrono::milliseconds > (
        timeSinceEpoch ).count();
    const time_t second = std::chrono::duration_cast< std::chrono::seconds > (
        timeSinceEpoch ).count();
    std::tm tm = *std::gmtime( &second );

    ledStream->mSStream.seekp( 0 );
    ledStream->mSStream << std::setfill( '0' );
    ledStream->mSStream << (1900 + tm.tm_year) << '.' << std::setfill( '0' )
                        << std::setw( 2 ) << (tm.tm_mon + 1) << '.'
                        << std::setw( 2 ) << tm.tm_mday << ' ' << std::setw( 2 );

    ledStream->mSStream << tm.tm_hour << '.' << std::setw( 2 ) << tm.tm_min << '.'
                        << std::setw( 2 ) << tm.tm_sec << ':'
                        << std::setw( 3 ) << (milliSecond % 1000);

    ledStream->mSStream << std::setfill( ' ' );
    ledStream->mSStream << ':' << std::setw( 2 ) << ledStream->mThreadID << "] ";

    ledStream->mSStream << std::setfill( ' ' );
    return LedStream( ledStream->mSStream,
                      ledStream, channel );
}

DTOCPP_NAMESPACE_END
