
#include "stdafx.h"
#include <entityDB.h>

gsp entityDB::spawn(const std::wstring& name) const
{
	std::map<std::wstring, gsp>::const_iterator i = m_db.find(name);
	if(i != m_db.end()) {
		return i->second.ref<iEntity>().deepCopy();
	} else {
		THROW_MSG(NameNotFoundException, name.c_str());
	}
}