#include <iostream>

#include "dtocpp_led.h"

DTOCPP_NAMESPACE_BEGIN

void LedDefaultOutCallback( void       * userData,
                            TLedChannelType,
                            const char * data,
                            int          len )
{
    std::cout.write( data, len );
}

DTOCPP_NAMESPACE_END
