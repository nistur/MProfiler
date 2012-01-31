#ifndef __TOOLS_H__
#define __TOOLS_H__

#include "Types.h"

namespace ShinyProfiler
{
    u32 APHash(const char* str, u32 len);
};

#include <cstring>
#define Hash(string) APHash(string, strlen(string));

#endif /*__TOOLS_H__*/
