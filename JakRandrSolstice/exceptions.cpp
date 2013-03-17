#include "stdafx.h"
#include <exceptions.h>
#include <ostream>

std::ostream& operator<<(std::ostream& o, const Exception& ex)
{
	o << ex.m_name << " in file " << ex.m_file << " in " << ex.m_func << " at line " << ex.m_line;
	if(!ex.m_text.empty()) {
		o << ": " << ex.m_text.c_str();
	}
	return o;
}