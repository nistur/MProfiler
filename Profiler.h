
#ifndef __MARATIS_SHINY_PROFILER_H__
#define __MARATIS_SHINY_PROFILER_H__

// Maratis includes
#include <MEngine.h>
#include <MProfiler.h>

// Profile includes
#include "Types.h"
#include "Scope.h"

// System includes
#include <map>
#include <stack>

namespace ShinyProfiler
{
    class Profiler : public MProfilerContext
    {
    public:
	//----------------------------------
	// MProfilerContext virtuals
	//----------------------------------
	void pushScope(const char* name);
	void popScope();
	
	void init();
	void update();
	void cleanup();
	
    private:
	std::map<u32, Scope*> m_Scopes;
	std::stack<Scope*>    m_Callstack;
    };
};

#endif /*__MARATIS_SHINY_PROFILER_H__*/
