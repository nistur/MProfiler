#include "Profiler.h"

#include "Tools.h"

#include "Shiny.h"

#include <stdio.h>

namespace ShinyProfiler
{
    void Profiler::pushScope(const char* name)
    {	
	u32 hash = Hash(name);

	if(m_Scopes.find(hash) == m_Scopes.end())
	{
	    m_Scopes[hash] = new Scope(name);
	}
	
	if(Scope* scope = m_Scopes[hash])
	{
	    m_Callstack.push(scope);
	    scope->Begin();
	}
    }
    
    void Profiler::popScope()
    {
	Scope* scope = m_Callstack.top();
	scope->End();

	m_Callstack.pop();
    }
    
    void Profiler::init()
    {
    }
    
    void Profiler::update()
    {
	PROFILE_UPDATE();
	PROFILE_OUTPUT(0);
    }
    
    void Profiler::cleanup()
    {
    }
};
