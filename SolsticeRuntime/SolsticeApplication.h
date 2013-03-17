#pragma once

#include <dllDefines.h>
#include <room.h>
#include <roomDB.h>
#include <entityDB.h>
#include <PluginManager.h>

typedef void (*callbackdisplayrederfunc)(const room&);

class SOLSTICERUNTIME_API SolsticeApplication
{
public:
	static SolsticeApplication& Instance();

	static void SetRenderFunction(callbackdisplayrederfunc);

	static void Init(int argc, char* argv[]);
	static void MainLoop();
private:
	callbackdisplayrederfunc m_callback;
	roomDB m_roomDB;
	entityDB m_entityDB;
	PluginManager m_mgr;
};