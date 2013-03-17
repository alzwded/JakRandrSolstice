#pragma once

#include <dllDefines.h>
#include <room.h>
#include <roomDB.h>
#include <entityDB.h>
#include <PluginManager.h>
#include <path.h>

typedef void (*callbackdisplayrederfunc)(const room&);

class SOLSTICERUNTIME_API SolsticeApplication
{
public:
	static SolsticeApplication& Instance();

	static void SetRenderFunction(callbackdisplayrederfunc);

	static void Init(int argc, char* argv[]);
	static void MainLoop();

	// called from plugins to spawn a new entity at given path
	static void Allocate(const path p, const std::string type, const float x, const float y, const float z);
	// called from plugins to despawn an entity at given path
	static void Deallocate(const path p);
private:
	callbackdisplayrederfunc m_callback;
	roomDB m_roomDB;
	entityDB m_entityDB;
	PluginManager m_mgr;
};