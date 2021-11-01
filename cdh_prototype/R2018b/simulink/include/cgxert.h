/*
 * PUBLISHED header for C cgxert, the runtime library for CGXE C file
 *
 * Copyright 2014-2017 The MathWorks, Inc.
 *
 */

#ifndef cgxert_h
#define cgxert_h

#if defined(_MSC_VER)
# pragma once
#endif
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3))
# pragma once
#endif

/*
 * Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#endif

#ifndef LIBCGXERT_API
#define LIBCGXERT_API
#endif

#if defined(BUILDING_LIBMWCGXERT) || defined(DLL_IMPORT_SYM)
/* internal use */
# include "simstruct/simstruc.h"
#else
/* external use */
# include "simstruc.h"
#endif

#include <setjmp.h>
#include <stdarg.h>

typedef void *CgxertCTX;

typedef struct covrtInstance covrtInstance;

typedef enum
{
    CGXERT_DIAG_BLOCK_PATH = 0,
    CGXERT_DIAG_STRING,
    CGXERT_DIAG_STRING_FROM_DOUBLE,
    CGXERT_DIAG_NUMERIC,
    CGXERT_DIAG_NUMERIC_FROM_DOUBLE
} cgxertDiagnosticsInputType;


/*
 *  MATLAB INTERNAL USE ONLY :: macro wrappers
 */
EXTERN_C LIBCGXERT_API const void*         cgxertGetInputPortSignal(CgxertCTX ctx, int32_T/*Sint32*/index);
EXTERN_C LIBCGXERT_API const void* const * cgxertGetInputPortSignalPtrs(CgxertCTX ctx, int32_T ip);
EXTERN_C LIBCGXERT_API void*  cgxertGetOutputPortSignal(CgxertCTX ctx, int32_T index);
EXTERN_C LIBCGXERT_API void*  cgxertGetDWork(CgxertCTX ctx, int32_T index);
EXTERN_C LIBCGXERT_API void*  cgxertGetRunTimeParamInfoData(CgxertCTX ctx, int32_T index);
EXTERN_C LIBCGXERT_API void   cgxertSetSimStateCompliance(CgxertCTX ctx, int32_T simStateCompliance);
EXTERN_C LIBCGXERT_API void   cgxertSetStopRequested(CgxertCTX ctx, bool stop);
EXTERN_C LIBCGXERT_API void   cgxertSetErrStat(CgxertCTX ctx, char* errMsg);
EXTERN_C LIBCGXERT_API void   cgxertSetSolverNeedsReset(CgxertCTX ctx);
EXTERN_C LIBCGXERT_API double cgxertGetT(CgxertCTX ctx);

/*
 * MATLAB INTERNAL USE ONLY :: Get varsize I/O port dimensions array address
 */
EXTERN_C LIBCGXERT_API int* cgxertGetCurrentInputPortDimensions(CgxertCTX ctx, int32_T portNumber);
EXTERN_C LIBCGXERT_API int* cgxertGetCurrentOutputPortDimensions(CgxertCTX ctx, int32_T portNumber);
EXTERN_C LIBCGXERT_API void cgxertSetCurrentOutputPortDimensions(CgxertCTX ctx, int32_T pIdx, int32_T dIdx, int32_T val);

/*
 * MATLAB INTERNAL USE ONLY :: Sim through codegen subsystem utilities
 */
EXTERN_C LIBCGXERT_API void    cgxertCheckCurrentInputPortDimensions(CgxertCTX ctx, const char* sysObjName, const char* methodName);
EXTERN_C LIBCGXERT_API void    cgxertCallAccelRunBlock(CgxertCTX ctx, int32_T sysIdx, int32_T blkIdx, int32_T method);
EXTERN_C LIBCGXERT_API int32_T cgxertGetSubsysIdx(CgxertCTX ctx);
EXTERN_C LIBCGXERT_API void*   cgxertPrepareEmlrtTLS(CgxertCTX ctx, void *aEmlrtCtx, int32_T sysIdx, int32_T blkIdx);

/*
 * MATLAB INTERNAL USE ONLY :: Runtime info access utilities
 */
EXTERN_C LIBCGXERT_API void*          cgxertGetRuntimeInstance(CgxertCTX ctx);
EXTERN_C LIBCGXERT_API void           cgxertSetRuntimeInstance(CgxertCTX ctx, void* instance);
EXTERN_C LIBCGXERT_API void*          cgxertGetEMLRTCtx(CgxertCTX ctx);
EXTERN_C LIBCGXERT_API SimStruct*     cgxertGetSimStruct(CgxertCTX ctx);
EXTERN_C LIBCGXERT_API covrtInstance* cgxertGetCovrtInstance(CgxertCTX ctx, int key);
EXTERN_C LIBCGXERT_API uint32_T       cgxertGetCovId(CgxertCTX ctx, int key);
EXTERN_C LIBCGXERT_API void           cgxertSetNumTicksToNextHitForControllableRate(CgxertCTX ctx, double numTicksToNextHit);
EXTERN_C LIBCGXERT_API bool           cgxertGetErrorStatus(CgxertCTX ctx);

/*
 * MATLAB INTERNAL USE ONLY :: macro wrappers for Data Store Memory functions
 */
EXTERN_C LIBCGXERT_API void ReadFromDataStoreElement_wrapper(CgxertCTX ctx, int dsmIndex, char* dsmName, int elementIndex);
EXTERN_C LIBCGXERT_API void WriteToDataStoreElement_wrapper(CgxertCTX ctx, int dsmIndex, char* dsmName, int elementIndex);
EXTERN_C LIBCGXERT_API void AccessDataStore_wrapper(CgxertCTX ctx, int dsmIndex, char* dsmName, int isReadOnly);
EXTERN_C LIBCGXERT_API void UpdateDataStoreLog_wrapper(CgxertCTX ctx, void* dsmId);
EXTERN_C LIBCGXERT_API bool cgxertGetDSMBlockDiagnosticsEnabled_wrapper(CgxertCTX ctx, int dsmIdx, const char* dsmName);
EXTERN_C LIBCGXERT_API void GetDataStoreNameAddrIdx_wrapper(CgxertCTX ctx, const char *name, void **dsmAddress, int *dsmIndex);
EXTERN_C LIBCGXERT_API void MemRegionCreateDescriptor_wrapper(CgxertCTX ctx, int numSubMemRegions, SFcnMemRegionInfo** memRegionDescriptor);
EXTERN_C LIBCGXERT_API void MemRegionSetFlatSubElement_wrapper(CgxertCTX ctx, SFcnMemRegionInfo* memRegionDescriptor, int subRegionIdx, int busElementIdx, int numFlatIdx, int *flatIdxs);
EXTERN_C LIBCGXERT_API void AccessDataStoreRegion_wrapper(CgxertCTX ctx, int dsmIdx, void *dataAddr,  SFcnMemRegionInfo* dsmRegionDescriptor, bool isReadOnly);
EXTERN_C LIBCGXERT_API void MemRegionDestroyDescriptor_wrapper(CgxertCTX ctx, SFcnMemRegionInfo** memRegionDescriptor);

/*
 * MATLAB INTERNAL USE ONLY :: Check for Ctrl+C interrupt from the command prompt
 */
EXTERN_C LIBCGXERT_API unsigned int cgxertListenForCtrlC(CgxertCTX ctx);

/*
 * MATLAB INTERNAL USE ONLY :: Call Simulink Function server
 */
EXTERN_C LIBCGXERT_API void cgxertCallSLFcn(SimStruct *S,
                                            const char* fcnName,
                                            const char* fullPath,
                                            int blkId,
                                            int numInputs,
                                            void* inArgs,
                                            void* inSizes,
                                            int numOutputs,
                                            void* outArgs,
                                            int* outSizes);

/*
 * MATLAB INTERNAL USE ONLY :: Handle runtime diagnostic report request
 */
EXTERN_C LIBCGXERT_API void cgxertReportError(CgxertCTX ctx, int sysIdx, int blkIdx,
                                              const char* const aMsgID,
                                              const int aArgCount, ...);

EXTERN_C LIBCGXERT_API void cgxertReportWarning(CgxertCTX ctx, int sysIdx, int blkIdx,
                                                const char* const aMsgID,
                                                const int aArgCount, ...);

/*
 * MATLAB INTERNAL USE ONLY :: gcb utilities
 */
EXTERN_C LIBCGXERT_API void cgxertSetGcb(CgxertCTX ctx, int sysIdx, int blkIdx);
EXTERN_C LIBCGXERT_API void cgxertRestoreGcb(CgxertCTX ctx, int sysIdx, int blkIdx);

/*
 * MATLAB INTERNAL USE ONLY :: Multi-threading helpers
 */
EXTERN_C LIBCGXERT_API void  cgxertSemCreate(CgxertCTX ctx, void **semPtr);
EXTERN_C LIBCGXERT_API void  cgxertSemPost(CgxertCTX ctx, void *semPtr);
EXTERN_C LIBCGXERT_API void  cgxertSemWait(CgxertCTX ctx, void *semPtr);
EXTERN_C LIBCGXERT_API void  cgxertSemDestroy(CgxertCTX ctx, void *semPtr);

EXTERN_C LIBCGXERT_API void  cgxertEnterParallelRegion(CgxertCTX ctx);
EXTERN_C LIBCGXERT_API void  cgxertExitParallelRegion(CgxertCTX ctx);
EXTERN_C LIBCGXERT_API void* cgxertAllocTLS(SimStruct *S, int32_T threadId);
EXTERN_C LIBCGXERT_API void  cgxertSetTLSJmpBufEnv(CgxertCTX ctx, jmp_buf *aJBEnv);

/*
 * MATLAB INTERNAL USE ONLY :: Profiling instrumentation functions.
 */
EXTERN_C LIBCGXERT_API void* cgxertCreateSectionProfiles(size_t sectionCount);
EXTERN_C LIBCGXERT_API void  cgxertStartProfiling(void* opaqueSectionProfiles, size_t sectionNumber);
EXTERN_C LIBCGXERT_API void  cgxertStopProfiling(void* opaqueSectionProfiles, size_t sectionNumber);
EXTERN_C LIBCGXERT_API void  cgxertExportSectionProfiles(void* opaqueSectionProfiles, CgxertCTX ctx);
EXTERN_C LIBCGXERT_API void  cgxertExportToEngineSectionProfiles(void* opaqueSectionProfiles, uint32_T *sectionBlkIds, CgxertCTX ctx);
EXTERN_C LIBCGXERT_API void  cgxertDestroySectionProfiles(void* opaqueSectionProfiles);

#endif /* cgxert_h */
