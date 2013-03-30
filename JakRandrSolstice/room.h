#pragma once

#include <dllDefines.h>

#include <list>
#include "vec.h"
#include "gsp.h"

class SOLSTICERUNTIME_API room;

class SOLSTICERUNTIME_API room_portal {
public:
	room_portal() {}
	room_portal(const vec3& p1, const vec3& p2);

	friend class room;
};

EXPIMP_TEMPLATE template struct SOLSTICERUNTIME_API std::pair<room_portal, room*>;
EXPIMP_TEMPLATE template class SOLSTICERUNTIME_API std::list<std::pair<room_portal, room*>>;
EXPIMP_TEMPLATE template class SOLSTICERUNTIME_API std::list<gsp>;

class SOLSTICERUNTIME_API room {
public:
	room() {}

	void loop();

	void computeVisible(); // compute other visible rooms
private:
	std::list<std::pair<room_portal, room*>> m_rooms;
	std::list<gsp> m_entities;
};