#include "stdafx.h"
#include <uuidgenerator.h>
#include <sstream>

std::string UUIDgenerator::next()
{
	std::stringstream s;
	s << "#" << m_prefix << nextNumber();
	return s.str();
}

int UUIDgenerator::nextNumber()
{
	static unsigned long g_id = 0;
	return ++g_id;
}