#include "stdafx.h"
#include <fEntity.h>


gsp fEntity::spawn(tEntity type)
{
	switch(type) {
	case te_UNDEFINED:
		THROW(UndefinedTypeException);
		break;
	case te_PLAYER:
	case te_COMPOUND:
	case te_BLOB:
	case te_SKIN:
	case te_SKELETON_NODE:
	case te_TRIA:
	case te_QUAD:
	case te_FLESH_NODE:
	case te_BODY:
		THROW(NotImplementedException);
		break;
	default:
		THROW(UnknownTypeException);
		break;
	}

	return gsp();
}