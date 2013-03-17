#pragma once

#include <dllDefines.h>

// entity factory

#include "exceptions.h"
#include "gsp.h"
#include "tEntity.h"

class SOLSTICERUNTIME_API fEntity
{
public:
	static gsp spawn(tEntity type);
};