#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "ai.h"

class DllInst // no export
{
private:
	DllInst(HMODULE id) {}
	DllInst(const DllInst& other);
	~DllInst();
public:
	DllInst Load(const std::string& dll);
	aif_t Function(const std::string& fid);
private:
	HMODULE m_id;
}

class SOLSTICERUNTIME_API PluginManager
{
public:
	aif_t get(const std::string& dll, const std::string& fid);
	void clear();

private:
	std::map<dll, DllInst> m_plugins;
};