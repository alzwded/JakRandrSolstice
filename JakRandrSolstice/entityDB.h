#pragma once

// holds templates for all entity types defined at root level in .entities files
// this is used to spawn particular entities in rooms

#include <map>
#include <sstream>
#include "iEntity.h"
#include "fEntity.h"
#include "tEntity.h"
#include "gsp.h"

class entityDB {
public:
	entityDB() {}
	
	gsp spawn(const std::string& name) const;

	void add(const gsp& e) { m_db.insert(std::make_pair(e.ref<iEntity>.name(), e)); }
	void clear() { m_db.clear(); }
private:
	std::map<std::string, gsp> m_db;
};