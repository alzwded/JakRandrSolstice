#pragma once

#include <dllDefines.h>

#include <string>
#include <list>

EXPIMP_TEMPLATE template class SOLSTICERUNTIME_API std::list<std::string>;

class SOLSTICERUNTIME_API path sealed 
{
public:
	path(const std::list<std::string>&, bool root = false);
	path(const std::wstring&, bool root = false);
	path(const path&);
	path(bool root = true);

	std::wstring& head();
	std::wstring& last();
	std::wstring& str();

	void push_back(const std::wstring&);
	void push_back(const path&);
	void pop();

	bool operator<(const path&);
	bool empty();
private:
	bool m_root;
	std::list<std::string> m_nodes;

	bool cache_invalid;
	std::wstring cache_tail;
	std::wstring cache_head;
	std::wstring cache_fullPath;
};