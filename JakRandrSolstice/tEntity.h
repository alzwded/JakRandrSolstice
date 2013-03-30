#pragma once

typedef enum {
	te_UNDEFINED = 0,
	te_SKELNODE,
	te_FLESHNODE,
	te_TRIA,
	te_QUAD,
	te_SKIN,
	te_SKELETON,
	te_BODY,
	te_COMPOUND,
	te_BLOB,
	te_PLAYER,
	te_END_OF_ENUM
} tEntity;