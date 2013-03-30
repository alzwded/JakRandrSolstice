#pragma once

#include <dllDefines.h>

// holds templates for all entity types defined at root level in .entities files
// this is used to spawn particular entities in rooms

#include <map>
#include <sstream>
#include "iEntity.h"
#include "fEntity.h"
#include "tEntity.h"
#include "gsp.h"

EXPIMP_TEMPLATE template class SOLSTICERUNTIME_API std::map<std::string, gsp>;

class SOLSTICERUNTIME_API entityDB {
public:
	entityDB() {}
	
	gsp spawn(const std::string& name) const;

	void add(const gsp& e)
	{
		m_db.insert(
			std::make_pair(e.ref<iEntity>().name(), e));
	}
	void clear() { m_db.clear(); }
private:
	std::map<std::string, gsp> m_db;
};