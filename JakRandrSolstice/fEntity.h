#pragma once

// entity factory

#include "exceptions.h"
#include "gsp.h"
#include "tEntity.h"

class fEntity
{
public:
	static gsp spawn(tEntity type)
	{
		switch(type) {
		case te_UNDEFINED:
			THROW(UndefinedTypeException, "");
			break;
		default:
			THROW(UnknownTypeException, "");
			break;
		}
	}
};