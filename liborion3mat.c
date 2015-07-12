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

#include <stdio.h>
#define EXPORTING_liborion3mat 1
#include "liborion3mat.h"

static HMCRINSTANCE _mcr_inst = NULL;


#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_liborion3mat_C_API
#define LIB_liborion3mat_C_API /* No special import/export declaration */
#endif

LIB_liborion3mat_C_API 
bool MW_CALL_CONV liborion3matInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream((void *)(liborion3matInitializeWithHandlers));
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_liborion3mat_C_API 
bool MW_CALL_CONV liborion3matInitialize(void)
{
  return liborion3matInitializeWithHandlers(mclDefaultErrorHandler, 
                                            mclDefaultPrintHandler);
}

LIB_liborion3mat_C_API 
void MW_CALL_CONV liborion3matTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_liborion3mat_C_API 
void MW_CALL_CONV liborion3matPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_liborion3mat_C_API 
bool MW_CALL_CONV mlxORION3(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "ORION3", nlhs, plhs, nrhs, prhs);
}

LIB_liborion3mat_C_API 
bool MW_CALL_CONV mlfORION3(mxArray* full_path_input_file)
{
  return mclMlfFeval(_mcr_inst, "ORION3", 0, 0, 1, full_path_input_file);
}

