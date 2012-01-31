#include "Tools.h"


namespace ShinyProfiler
{
    u32 APHash(const char* str, u32 len)
    {
	u32 hash = 0xAAAAAAAA;
	u32 i    = 0;
	
	for(i = 0; i < len; str++, i++)
	{
	    hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ (*str) * (hash >> 3)) :
		(~((hash << 11) + ((*str) ^ (hash >> 5))));
	}
	
	return hash;
    }
};
