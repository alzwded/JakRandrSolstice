#pragma once

#include <dllDefines.h>

#include "exceptions.h"
#include "iEntity.h"

class SOLSTICERUNTIME_API gsp
{
public:
	gsp()
	{
		m_p = NULL;
		m_rc = NULL;
	}
	gsp(iEntity* p)
	{
		if(p == NULL) THROW(NullPtrException);

		m_p = p;
		m_rc = new int();
		*m_rc = 1;
	}

	gsp(const gsp& other)
	{
		m_p = other.m_p;
		m_rc = other.m_rc;
		++*m_rc;
	}

	~gsp() {
		if(!m_rc) return;

		if(--*m_rc == 0) {
			delete m_rc;
			delete m_p;
		}
	}

	bool operator==(const gsp& other)
	{
		return get() == other.get();
	}

	bool operator<(const gsp& other)
	{
		return get() < other.get();
	}

	iEntity* get() const { 
		return m_p;
	}

	template<class Y>
	Y* cast() const { return dynamic_cast<Y*>(m_p); }

	template<class Y>
	Y& ref() const {
		if(!m_p) THROW(NullPtrException);
		return *dynamic_cast<Y*>(m_p);
	}
private:
	iEntity* m_p;
	int* m_rc;
};