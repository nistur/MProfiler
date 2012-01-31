#include "MProfilerPlugin.h"

#include "Profiler.h"

#include "MEngine.h"

ShinyProfiler::Profiler* s_profiler = 0;

void StartPlugin(void)
{
    s_profiler = new ShinyProfiler::Profiler;

    s_profiler->init();

    MEngine* engine = MEngine::getInstance();
    engine->setProfilerContext(s_profiler);
}

void EndPlugin(void)
{
    s_profiler->cleanup();

    MEngine* engine = MEngine::getInstance();
    if(engine->getProfilerContext() == s_profiler)
    {
	engine->setProfilerContext(0);
    }

    delete s_profiler;
    s_profiler = 0;
}
