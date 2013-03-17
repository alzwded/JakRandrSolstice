#pragma once

#include <dllDefines.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "ai.h"
#include <map>
#include <string>

class SOLSTICERUNTIME_API DllInst;
EXPIMP_TEMPLATE template class SOLSTICERUNTIME_API std::map<std::wstring, DllInst>;

class SOLSTICERUNTIME_API DllInst 
{
public:
	DllInst() { m_id = NULL; }
	DllInst(HMODULE id) {}
	DllInst(const DllInst& other);
	~DllInst();

	static DllInst Load(const std::wstring& dll);
	aif_t Function(const std::string& fid);
private:
	HMODULE m_id;
};

class SOLSTICERUNTIME_API PluginManager
{
public:
	aif_t get(const std::wstring& dll, const std::string& fid);
	void clear();

private:
	std::map<std::wstring, DllInst> m_plugins;
};