#pragma once

#include <dllDefines.h>
#include <room.h>

typedef void (*callbackdisplayrederfunc)(const room&);

class SOLSTICERUNTIME_API SolsticeApplication
{
public:
	static SolsticeApplication& Instance();

	static void SetRenderFunction(callbackdisplayrederfunc);

	static void Init(int argc, char* argv[]);
	static void MainLoop();
};