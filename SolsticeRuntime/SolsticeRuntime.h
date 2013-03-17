// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SOLSTICERUNTIME_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SOLSTICERUNTIME_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SOLSTICERUNTIME_EXPORTS
#define SOLSTICERUNTIME_API __declspec(dllexport)
#else
#define SOLSTICERUNTIME_API __declspec(dllimport)
#endif

#include <ai.h>
#include <exceptions.h>
#include <gsp.h>
#include <iEntity.h>
#include <bEntity.h>
#include <fEntity.h>
#include <entityDB.h>
#include <roomDB.h>
#include <room.h>
#include <PluginManager.h>
#include <path.h>
#include <reader.h>
//#include <uuidgenerator.h> // this needn't be exported
//#include <vec.h> // template class

// This class is exported from the SolsticeRuntime.dll
class SOLSTICERUNTIME_API CSolsticeRuntime {
public:
	CSolsticeRuntime(void);
	// TODO: add your methods here.
};

extern SOLSTICERUNTIME_API int nSolsticeRuntime;

SOLSTICERUNTIME_API int fnSolsticeRuntime(void);
