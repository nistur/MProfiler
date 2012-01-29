#include "ShinyProfiler.h"

#include "Shiny.h"

void MShinyProfiler::pushScope(const char* name)
{
    _PROFILE_ZONE_DEFINE(_PROFILE_ID_ZONE(Maratis), name);
    _PROFILE_ZONE_BEGIN(_PROFILE_ID_ZONE(Maratis));
}

void MShinyProfiler::popScope()
{
    PROFILE_END();
}

void MShinyProfiler::init()
{
    printf("MShinyProfiler::init()\n");
}

void MShinyProfiler::update()
{
    PROFILE_UPDATE();
    PROFILE_OUTPUT(NULL);
}

void MShinyProfiler::cleanup()
{
}
