
#include "stdafx.h"
#include <entityDB.h>

gsp entityDB::spawn(const std::string& name) const
{
	std::map<std::string, gsp>::const_iterator i = m_db.find(name);
	if(i != m_db.end()) {
		return i->second.ref<iEntity>().deepCopy();
	} else {
		THROW_MSGA(NameNotFoundException, name.c_str());
	}
}