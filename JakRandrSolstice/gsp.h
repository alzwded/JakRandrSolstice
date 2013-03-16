#pragma once

#include "exceptions.h"
#include "iEntity.h"

class gsp
{
public:
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
		if(--*m_rc == 0) {
			delete m_rc;
			delete m_p;
		}
	}

	iEntity* get() { return m_p; }

	template<class Y>
	Y* cast() { return dynamic_cast<Y*>(m_p); }

	template<class Y>
	Y& ref() { return *dynamic_cast<Y*>(m_p); }
private:
	iEntity* m_p;
	int* m_rc;
};