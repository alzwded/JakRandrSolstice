#ifndef __EXCEPTIONS_INCLUDE_SEAL__
#error "please do not include this file directly, use exceptions.h"
#else

#include <string>
#include <ostream>

#define THROW_MSG(WHAT, TEXT) do{\
	throw WHAT(TEXT, __FILE__, __FUNCSIG__, __LINE__); \
}while(0)

#define THROW(WHAT) THROW_MSG(WHAT, L"")

#define EXTEND_EXCEPTION(BASE, NAME)\
class SOLSTICERUNTIME_API NAME : public BASE { \
public: \
	NAME(\
		const wchar_t* msg,\
		const char* file,\
		const char* function,\
		const int line)\
		: BASE(msg, file, function, line)\
	{\
		setName(#NAME);\
	}\
};

#define EXCEPTION(NAME) EXTEND_EXCEPTION(Exception, NAME)

class SOLSTICERUNTIME_API Exception
{
public:
	Exception(
		const wchar_t* msg,
		const char* file,
		const char* function,
		const int line)
		: m_name("Exception")
		, m_text(msg)
		, m_file(file)
		, m_func(function)
		, m_line(line)
	{}

	friend std::ostream& operator<<(std::ostream&, const Exception&);

protected:
	void setName(const char* name)
	{
		m_name = name;
	}

private:
	std::string m_name;
	std::wstring m_text;
	std::string m_file;
	std::string m_func;
	int m_line;
};

#endif