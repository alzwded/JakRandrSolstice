#include "stdafx.h"
#include <SolsticeApplication.h>

SolsticeApplication& SolsticeApplication::Instance()
{
	static SolsticeApplication aApplication;
	return aApplication;
}

void SolsticeApplication::Init(int argc, char* argv[])
{
}

void SolsticeApplication::MainLoop()
{
}