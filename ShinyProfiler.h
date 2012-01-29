
#ifndef __MARATIS_SHINY_PROFILER_H__
#define __MARATIS_SHINY_PROFILER_H__

#include <MEngine.h>
#include <MProfiler.h>

class MShinyProfiler : public MProfilerContext
{
public:
    void pushScope(const char* name);
    void popScope();

    void init();
    void update();
    void cleanup();
};

#endif /*__MARATIS_SHINY_PROFILER_H__*/
