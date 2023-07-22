#pragma once

#include <sstream>

#include "dtocpp.h"

DTOCPP_NAMESPACE_BEGIN

using TLedChannelType   = unsigned;
using TLedWriteCallback = void (*)( void * userData, TLedChannelType, const char *, int len );

void LedDefaultOutCallback( void * userData, TLedChannelType, const char *, int len );

struct LedStream;

struct LedStream {
    std::ostream & mStream;

    ~LedStream();

    static LedStream factory( std::ostream  & o,
                              void          * ledInfo,
                              TLedChannelType channel ){
        return LedStream( o, ledInfo, channel );
    }

private:
    LedStream( std::ostream  & o,
               void          * ledInfo,
               TLedChannelType channel )
        : mStream( o ),
        mLedInfo( ledInfo ),
        mChannel( channel ){}

    void          * mLedInfo = nullptr;
    TLedChannelType mChannel;
};

DTOCPP_NAMESPACE_END
