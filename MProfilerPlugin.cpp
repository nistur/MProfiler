#include "MProfilerPlugin.h"

#include "Profiler.h"
#include "MProfiler_npk.h"

ShinyProfiler::Profiler* s_profiler = 0;

MINGED_PLUGIN_START_IMPLEMENT(MProfiler)
{
    s_profiler = new ShinyProfiler::Profiler;

    s_profiler->init();

    MEngine* engine = MEngine::getInstance();
    engine->setProfilerContext(s_profiler);
}

MINGED_PLUGIN_END_IMPLEMENT(MProfiler)
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
