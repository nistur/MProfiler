#include "ShinyProfiler.h"

void MShinyProfiler::pushScope(const char* name)
{
    ShinyZone* zone = new ShinyZone;
    zone->next = NULL;
    zone->_state = SHINY_ZONE_STATE_HIDDEN;
    zone->name = name;
    zone->data = { { 0, 0 }, { 0, 0 }, { 0, 0 } };

    m_zones.push_back(zone);

    _PROFILE_ZONE_BEGIN(*zone);
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
