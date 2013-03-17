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
}