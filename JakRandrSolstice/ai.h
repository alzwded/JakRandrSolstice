#pragma once

#include <dllDefines.h>

#include "gsp.h"
#include "iEntity.h"

/*
	ai logic is stored in plugin-like dlls

	each logic loop thing is a function with signature aif_t

	in more detail:
		void (*aif_t)(void* pAi, void** pMemBlock, int iCommand);
		pAi is this
		pMemBlock is a pointer to a void* which will contain the memory used
			internally by an instance of an ai loop
		iCommand is an ai_command_t enum value
			act_INIT		call initialization code (i.e. alloc pMemBlock)
			act_LOOP		regular ai loop thingy
			act_FINI		call uninitialization code (i.e. clear pMemBlock 
							since that was allocated in another dll)

	so it will be called something like
		m_func(this, &m_mem, act_LOOP);
*/

typedef enum {
	act_UNKNOWN = 0,
	act_INIT = 1,
	act_LOOP = 2,
	act_FINI = 3,
	act_LAST
} ai_command_t;

typedef void (*aif_t)(void*, void**, int);

class SOLSTICERUNTIME_API ai {
public:
	ai(const gsp&);
	virtual void loop() =0;

	iEntity& ctx();

private:
	gsp m_ctx;
	void* m_mem;
	aif_t m_func; // loaded with PluginManager
};