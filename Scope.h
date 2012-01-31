#pragma once
#ifndef __SCOPE_H__
#define __SCOPE_H__

#include "Shiny.h"

namespace ShinyProfiler
{
    class Scope
    {
    public:
	Scope(const char* name);
	~Scope();

	void Begin();
	void End();
    private:
	ShinyZone* m_Zone;
	ShinyNodeCache m_Cache;
	char*      m_Name;
    };
};

#endif /*__SCOPE_H__*/
