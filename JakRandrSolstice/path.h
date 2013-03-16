#pragma once

#include <string>
#include <list>

class path sealed 
{
public:
	path(const std::list<std::string>&);
	path(const std::string&);
	path();

	void addNode(const std::string&);
	path head();
	path tail();

	std::string toString();

	bool empty();

private:
	std::string m_tail;
	path m_head;
};