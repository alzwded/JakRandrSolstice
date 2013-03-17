
#include "stdafx.h"
#include <PluginManager.h>

DllInst::~DllInst()
{
	if(m_id) {
		FreeLibrary(m_id);
	}
}

DllInst::DllInst(const DllInst& other)
{
	m_id = other.m_id;
	const_cast<DllInst&>(other).m_id = NULL;
}

DllInst DllInst::Load(const std::wstring &dll)
{
	HMODULE id = LoadLibrary(dll.c_str());

	if(!id) {
		LPVOID lpMsgBuf;
		DWORD dw = GetLastError();

		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dw,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR) &lpMsgBuf,
			0, NULL );

		THROW_MSG(FileNotFoundException, (wchar_t*)lpMsgBuf);
	}

	DllInst ret(id);

	return ret;
}

aif_t DllInst::Function(const std::string& fid)
{
	if(!m_id) {
		THROW(NullPtrException);
	}

	aif_t ret = (aif_t) GetProcAddress(m_id, fid.c_str());

	if(!ret) {
		LPVOID lpMsgBuf;
		DWORD dw = GetLastError();

		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dw,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR) &lpMsgBuf,
			0, NULL );

		THROW_MSG(FileNotFoundException, (wchar_t*)lpMsgBuf);
	}

	return ret;
}

aif_t PluginManager::get(const std::wstring &dll, const std::string &fid)
{
	std::map<std::wstring, DllInst>::iterator i = m_plugins.find(dll);
	if(i != m_plugins.end()) {
		return i->second.Function(fid);
	} else {
		DllInst lib = DllInst::Load(dll);
		aif_t ret = lib.Function(fid);
		m_plugins[dll] = lib;
		return ret;
	}
}

void PluginManager::clear()
{
	m_plugins.clear();
}