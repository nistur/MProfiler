#include "Scope.h"

#include <stdio.h>

namespace ShinyProfiler
{
    Scope::Scope(const char* name)
    {
	m_Zone = new ShinyZone;
	m_Zone->next = NULL;
	m_Zone->_state = SHINY_ZONE_STATE_HIDDEN;
	m_Zone->data.childTicks.avg = 0;
	m_Zone->data.childTicks.cur = 0;
	m_Zone->data.entryCount.avg = 0;
	m_Zone->data.entryCount.cur = 0;
	m_Zone->data.selfTicks.avg = 0;
	m_Zone->data.selfTicks.cur = 0;
	m_Name = new char[strlen(name)+1];
	sprintf(m_Name, name);
	m_Zone->name = m_Name;
    }

    Scope::~Scope()
    {
	delete m_Zone->name;
	delete m_Zone;
    }

    void Scope::Begin()
    {
	m_Cache = &_ShinyNode_dummy;
	ShinyManager_lookupAndBeginNode(&Shiny_instance, &m_Cache, m_Zone);
    }

    void Scope::End()
    {
	ShinyManager_endCurNode(&Shiny_instance);
    }
};
