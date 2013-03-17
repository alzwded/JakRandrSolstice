#pragma once

#include <dllDefines.h>

#ifdef __EXCEPTIONS_INCLUDE_SEAL__
# error "exceptions.h include seal for prerequisites is already defined. How? What are you trying to do?"
#else
# define __EXCEPTIONS_INCLUDE_SEAL__
#  include "exceptions_prereq.h"
# undef __EXCEPTIONS_INCLUDE_SEAL__
#endif

EXCEPTION(OutOfRangeException)
EXCEPTION(IncompatibleTypeException)
EXCEPTION(NullPtrException)
EXCEPTION(NameNotFoundException)
EXCEPTION(FileNotFoundException)
EXCEPTION(NotImplementedException)

EXCEPTION(FactoryException)
EXTEND_EXCEPTION(FactoryException, UnknownTypeException)
EXTEND_EXCEPTION(FactoryException, UndefinedTypeException)