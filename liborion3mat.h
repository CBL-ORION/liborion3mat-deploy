/*
 * MATLAB Compiler: 4.18.1 (R2013a)
 * Date: Sun Jul 12 17:26:37 2015
 * Arguments: "-B" "macro_default" "-W" "lib:liborion3mat" "-T" "link:lib" "-d"
 * "orion/.build/liborion3mat" "-N"
 * "-p" "curvefit" "-p" "images" "-p" "stats" "-w"
 * "enable:specified_file_mismatch" "-w" "enable:repeated_file" "-w"
 * "enable:switch_ignored" "-w" "enable:missing_lib_sentinel" "-w"
 * "enable:demo_license" "-v" "main/ORION3.m" "-a" "." 
 */

#ifndef __liborion3mat_h
#define __liborion3mat_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_liborion3mat
#define PUBLIC_liborion3mat_C_API __global
#else
#define PUBLIC_liborion3mat_C_API /* No import statement needed. */
#endif

#define LIB_liborion3mat_C_API PUBLIC_liborion3mat_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_liborion3mat
#define PUBLIC_liborion3mat_C_API __declspec(dllexport)
#else
#define PUBLIC_liborion3mat_C_API __declspec(dllimport)
#endif

#define LIB_liborion3mat_C_API PUBLIC_liborion3mat_C_API


#else

#define LIB_liborion3mat_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_liborion3mat_C_API 
#define LIB_liborion3mat_C_API /* No special import/export declaration */
#endif

extern LIB_liborion3mat_C_API 
bool MW_CALL_CONV liborion3matInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_liborion3mat_C_API 
bool MW_CALL_CONV liborion3matInitialize(void);

extern LIB_liborion3mat_C_API 
void MW_CALL_CONV liborion3matTerminate(void);



extern LIB_liborion3mat_C_API 
void MW_CALL_CONV liborion3matPrintStackTrace(void);

extern LIB_liborion3mat_C_API 
bool MW_CALL_CONV mlxORION3(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);



extern LIB_liborion3mat_C_API bool MW_CALL_CONV mlfORION3(mxArray* full_path_input_file);

#ifdef __cplusplus
}
#endif
#endif
