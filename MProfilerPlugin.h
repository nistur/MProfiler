#ifndef __MARATIS_PROFILER_PLUGIN_H__
#define __MARATIS_PROFILER_PLUGIN_H__

#ifdef WIN32
#   include <windows.h>
#   define DLLEXPORT __declspec(dllexport)
#else
#   define DLLEXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif
DLLEXPORT void StartPlugin(void);
DLLEXPORT void EndPlugin(void);

#ifdef __cplusplus
}
#endif

#endif /*__MARATIS_PROFILER_PLUGIN_H__*/
