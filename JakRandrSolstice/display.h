#pragma once

#include <SolsticeRuntime.h>

void glutRender(const room&);

void glutCallback()
{
	SolsticeApplication::MainLoop();
}