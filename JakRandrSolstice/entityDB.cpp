#include "entityDB.h"

gsp entityDB::spawn(const std::string& name) const
{
	auto i = m_db.find(name);
	if(i != m_db.end()) {
		return i->second.ref<iEntity>.deepCopy();
	} else {
		THROW_MSG(NameNotFoundException, name.c_str());
	}
}