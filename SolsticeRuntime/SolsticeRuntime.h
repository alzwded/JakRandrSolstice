#pragma once

#include <dllDefines.h>

#include <ai.h>
#include <exceptions.h>
#include <gsp.h>
#include <iEntity.h>
#include <bEntity.h>
#include <fEntity.h>
#include <entityDB.h>
#include <roomDB.h>
#include <room.h>
#include <SolsticeApplication.h>
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
