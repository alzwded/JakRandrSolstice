#pragma once

#include <string>

class UUIDgenerator {
public:
	UUIDgenerator(const char* prefix = "u")
		: m_prefix(prefix)
	{}

	void setPrefix(const char* prefix)
	{
		m_prefix = prefix;
	}

	std::string next();

private:
	int nextNumber();
private:
	std::string m_prefix;
};