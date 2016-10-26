/*

Copyright (c) 1999, 2000 Samuel A. Falvo II

This software is provided 'as-is', without any implied or express warranty.
In no event shall the authors be held liable for damages arising from the
use this software.

Permission is granted for anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software in a
   product, an acknowledgment in the product documentation would be
   appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

3. This notice may not be removed or altered from any source
   distribution.

*/

#ifndef GCOM_GCOM_H
#define GCOM_GCOM_H

/*
 * gcom/gcom.h
 * GCOM Release 0.1
 */

 // Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
#define GCOM_HELPER_DLL_IMPORT __declspec(dllimport)
#define GCOM_HELPER_DLL_EXPORT __declspec(dllexport)
#define GCOM_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define GCOM_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define GCOM_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define GCOM_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define GCOM_HELPER_DLL_IMPORT
#define GCOM_HELPER_DLL_EXPORT
#define GCOM_HELPER_DLL_LOCAL
#endif
#endif

 // Now we use the generic helper definitions above to define GCOM_API and GCOM_LOCAL.
 // GCOM_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
 // GCOM_LOCAL is used for non-api symbols.

#ifdef GCOM_DLL // defined if GCOM is compiled as a DLL
#ifdef GCOM_DLL_EXPORTS // defined if we are building the GCOM DLL (instead of using it)
#define GCOM_API GCOM_HELPER_DLL_EXPORT
#else
#define GCOM_API GCOM_HELPER_DLL_IMPORT
#endif // GCOM_DLL_EXPORTS
#define GCOM_LOCAL GCOM_HELPER_DLL_LOCAL
#else // GCOM_DLL is not defined: this means GCOM is a static lib.
#define GCOM_API
#define GCOM_LOCAL
#endif // GCOM_DLL

#include <gcom/types.h>
#include <gcom/unicode.h>
#include <gcom/guid.h>
#include <gcom/errors.h>
#include <gcom/interface.h>
#include <gcom/class.h>
#include <gcom/alloc.h>
#include <gcom/dll.h>
#include <gcom/registry.h>

/************************************************************************/
/* GCOM Version Information -- GCOM specific.  Microsoft COM hardcoded  */
/* version datatypes to 32-bit unsigned integers.  This is fine, but it */
/* isn't as portable as a typedef or two.				*/
/************************************************************************/

typedef uint32		GCOMVERSION;

#define GCOM_VERSION_MAJOR(v)	((uint16)(((v)>>16))&0xFFFF)
#define GCOM_VERSION_MINOR(v)	((uint16)((v)&0xFFFF))
#define MAKE_GCOMVERSION(v,r)	((uint32)((uint16)(v)<<16)|((uint16)(r)))

#define GCOM_CURRENT_VERSION	(0)
#define GCOM_CURRENT_REVISION	(3)

GCOMVERSION	CoBuildVersion( void );



/************************************************************************/
/* Miscellanious GCOM functions						*/
/************************************************************************/

HRESULT		CoInitialize( void * );
void		CoUninitialize( void );

#endif
