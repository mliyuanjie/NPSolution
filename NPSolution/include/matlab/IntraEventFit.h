//
// MATLAB Compiler: 8.1 (R2020b)
// Date: Fri Apr 16 20:00:31 2021
// Arguments:
// "-B""macro_default""-W""cpplib:IntraEventFit,all,version=1.0""-T""link:lib""-
// d""U:\MATLabScript2020\clib\IntraEventFit\for_testing""-v""U:\MATLabScript202
// 0\IntraEventFit.m"
//

#ifndef IntraEventFit_h
#define IntraEventFit_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_IntraEventFit_C_API 
#define LIB_IntraEventFit_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_IntraEventFit_C_API 
bool MW_CALL_CONV IntraEventFitInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_IntraEventFit_C_API 
bool MW_CALL_CONV IntraEventFitInitialize(void);

extern LIB_IntraEventFit_C_API 
void MW_CALL_CONV IntraEventFitTerminate(void);

extern LIB_IntraEventFit_C_API 
void MW_CALL_CONV IntraEventFitPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_IntraEventFit_C_API 
bool MW_CALL_CONV mlxIntraEventFit(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_IntraEventFit
#define PUBLIC_IntraEventFit_CPP_API __declspec(dllexport)
#else
#define PUBLIC_IntraEventFit_CPP_API __declspec(dllimport)
#endif

#define LIB_IntraEventFit_CPP_API PUBLIC_IntraEventFit_CPP_API

#else

#if !defined(LIB_IntraEventFit_CPP_API)
#if defined(LIB_IntraEventFit_C_API)
#define LIB_IntraEventFit_CPP_API LIB_IntraEventFit_C_API
#else
#define LIB_IntraEventFit_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_IntraEventFit_CPP_API void MW_CALL_CONV IntraEventFit(int nargout, mwArray& datax, mwArray& datay, mwArray& Coef, const mwArray& data, const mwArray& args);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
