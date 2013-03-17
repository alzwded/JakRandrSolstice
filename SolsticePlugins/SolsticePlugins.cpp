// SolsticePlugins.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SolsticePlugins.h"
#include <SolsticeRuntime.h>


// This is an example of an exported variable
SOLSTICEPLUGINS_API int nSolsticePlugins=0;

SOLSTICEPLUGINS_API void test_ai(void* ai, void** mem, int icmd)
{
	ai_command_t cmd = static_cast<ai_command_t>(icmd);
	switch(cmd) {
	case act_INIT:
		break;
	case act_LOOP:
		break;
	case act_FINI:
		break;
	}
}
