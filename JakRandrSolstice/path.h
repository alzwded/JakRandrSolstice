#pragma once

#include <string>
#include <list>

class SOLSTICERUNTIME_API path sealed 
{
public:
	path(const std::list<std::string>&, bool root = false);
	path(const std::string&, bool root = false);
	path(const path&);
	path(bool root = true);

	std::string& head();
	std::string& last();
	std::string& str();

	void push_back(const std::string&);
	void push_back(const path&);
	void pop();

	bool operator<(const path&);
	bool empty();
private:
	bool m_root;
	std::list<std::string> m_nodes;

	bool cache_invalid;
	std::string cache_tail;
	std::string cache_head;
	std::string cache_fullPath;
};