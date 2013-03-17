#pragma once

   //disable warnings on 255 char debug symbols
    #pragma warning (disable : 4786)
   //disable warnings on extern before template instantiation
    #pragma warning (disable : 4231)

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SOLSTICERUNTIME_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SOLSTICERUNTIME_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SOLSTICERUNTIME_EXPORTS
#define SOLSTICERUNTIME_API __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define SOLSTICERUNTIME_API __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif