#include "PluginManager.h"

DllInst::~DllInst()
{
	if(m_id) {
		FreeLibrary(m_id);
	}
}

DllInst::DllInst(const DllInst& other)
{
	m_id = other.m_id;
	other.m_id = NULL;
}

DllInst DllInst::Load(const std::string &dll)
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

		THROW_MSG(FileNotFoundException, lpMsgBuf);
	}

	DllInst ret(id);

	return ret;
}

aif_t DllInst::Function(const std::string& fid)
{
	if(!m_id) {
		THROW(NullPtrException);
	}

	ait_t ret = (aif_t) GetProcAddress(m_id, fid.c_str());

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

		THROW(FileNotFoundException, lpMsgBuf);
	}

	return ret;
}

aif_t PluginManager::get(const std::string &dll, const std::string &fid)
{
	auto i = m_plugins.find(dll);
	if(i != m_plugins.end()) {
		return i->second.Function(fid);
	} else {
		auto lib = DllInst::Load(dll);
		m_plugins[dll] = lib;
		return lib.Function(fid);
	}
}

void PluginManager::clear()
{
	m_plugins.clear();
}