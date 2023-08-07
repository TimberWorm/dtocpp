#pragma once

#include <sstream>

#include "dtocpp.h"

DTOCPP_NAMESPACE_BEGIN

/**
 * \ingroup dtocpp
 * \defgroup led LED - Logging, Error and Trance API
 * @{
 */

using TLedChannelType   = unsigned;
using TLedWriteCallback = void (*)( void * userData, TLedChannelType, const char *, int len );

const TLedChannelType CLedBufferSize = 0x1fff;

/**
 * Gefault output function that is pre-initialized. Outputs all channels on std::cout.
 * Can be disabled with the function LedRemoveOutCallback.
 *
 * Gefault Ausgabe Funktion die vorinitialisiert ist. Gibt alle Channel auf std::cout aus.
 * Kann mit der Funktion LedRemoveOutCallback Deaktiviert werden.
 */
void LedDefaultOutCallback( void * userData, TLedChannelType, const char *, int len );
void LedRemoveOutCallback( TLedWriteCallback );

struct LedStream {
    std::ostream & mStream;

    ~LedStream();
    static LedStream lockStream( TLedChannelType );

private:
    LedStream( std::ostream  & o,
               void          * ledInfo,
               TLedChannelType cha )
        : mStream( o ),
        mLedInfo( ledInfo ),
        mChannel( cha ){}

    void          * mLedInfo = nullptr;
    TLedChannelType mChannel;
};

#define LED( cha, ... ) \
    do { \
        if( DTOCPP_NAMESPACE LedTestChannle( cha ) ) { \
            auto ledStream = DTOCPP_NAMESPACE LedStream::lockStream(); \
            ledStream.mStream << __VA_ARGS__; \
        } \
    } while( 0 )

/**
 * }@
 */

DTOCPP_NAMESPACE_END
