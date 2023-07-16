#pragma once

#include <sstream>

#include "dtocpp.h"

DTOCPP_NAMESPACE_BEGIN

using TLedChannelType   = unsigned;
using TLedWriteCallback = void (*)( void * userData, TLedChannelType, const char *, int len );

DTOCPP_NAMESPACE_END
