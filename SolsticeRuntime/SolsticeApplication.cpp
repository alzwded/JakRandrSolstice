#include "stdafx.h"
#include <SolsticeApplication.h>
#include <fstream>
#include <Reader.h>
using namespace std;

SolsticeApplication& SolsticeApplication::Instance()
{
	static SolsticeApplication aApplication;
	return aApplication;
}

void SolsticeApplication::SetRenderFunction(callbackdisplayrederfunc f)
{
	if(f == NULL) THROW(NullPtrException);
	Instance().m_callback = f;
}

void SolsticeApplication::Init(int argc, char* argv[])
{
	Instance().m_roomDB.clear();
	Instance().m_entityDB.clear();
	Reader r(Instance().m_roomDB, Instance().m_entityDB);
	for(int i = 1; i <= argc; ++i) {
		if(strncmp(argv[i], "-r", 3) == 0) {
			fstream f(argv[++i], ios::in);
			std::wstringstream s;
			s << argv[i];
			if(f.bad()) THROW_MSG(FileNotFoundException, s.str().c_str());
			r.readRooms(f);
			f.close();
		} else if(strncmp(argv[i], "-e", 3) == 0) {
			fstream f(argv[++i], ios::in);
			std::wstringstream s;
			s << argv[i];
			if(f.bad()) THROW_MSG(FileNotFoundException, s.str().c_str());
			r.readEntities(f);
			f.close();
		} else if(strncmp(argv[i], "-a", 3) == 0) {
			// unneccesary
		}
	}
	r.done();
}

void SolsticeApplication::MainLoop()
{
	/*
	receiveInput();

	activeRoom = movePlayerAndUpdateCamera();
	
	activeRoom.loop();
	for(activeRoom::iterator i = globalRoomList.begin(); i != globalRoomList.end(); ++i) {
		i->loop();
	}

	ProcessAllocations();

	activeRoom.computeVisible();

	render(activeRoom);
	for(activeRoom::iterator i = activeRoom.begin(); i != activeRoom.end(); ++i) {
		render(*i);
	}
	*/
}

void SolsticeApplication::Allocate(const char *path, const char *type, const float x, const float y, const float z)
{
	// blbla m_entityDB.spawn(
}

void SolsticeApplication::Deallocate(const char *path)
{
	// find in room and baleet
}