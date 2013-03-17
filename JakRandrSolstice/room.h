#pragma once

#include <dllDefines.h>

#include <list>
#include "vec.h"
#include "gsp.h"

class SOLSTICERUNTIME_API room;

class SOLSTICERUNTIME_API room_portal {
protected:
	room_portal(const vec3& p1, const vec3& p2);

	friend class room;
};

class SOLSTICERUNTIME_API room {
public:
	room() {}

	void loop();

	void computeVisible(); // compute other visible rooms
private:
	std::list<std::pair<room_portal, room*>> m_rooms;
	std::list<gsp> m_entities;
};