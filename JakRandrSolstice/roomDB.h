#pragma once

// essentially just a giant list of rooms

#include <list>
#include "room.h"

class roomDB {
public:
	roomDB() {}
	void add(const room& r) { m_db.push_back(r); }
	std::list<room>::iterator begin() { return m_db.begin(); }
	std::list<room>::iterator end() { return m_db.end(); }
	typedef std::list<room>::iterator iterator;
private:
	std::list<room> m_db;
};