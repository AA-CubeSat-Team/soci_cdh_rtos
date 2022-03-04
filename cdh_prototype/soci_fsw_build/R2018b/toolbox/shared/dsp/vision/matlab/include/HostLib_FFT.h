/**
 * @file HostLib_FFT.h
 * @brief Helper for the FFT block access to FFTW.
 * Copyright 2008-2017 The MathWorks, Inc.
 */

#ifndef HOSTLIB_FFT_H_
#define HOSTLIB_FFT_H_

/* Wrap everything in extern C */
#ifdef __cplusplus
extern "C" {
#endif

#include "FFTLibraryDefs.h"

extern const char *libName_FFT;

/*******************************
 * Routines which are defined in the library in question
 *******************************/
typedef void* (*pFnLibCreate_FFT)(char *err,
        const int FFTLength,
        int nFFTs,
        const void *inPtr,
        void *outPtr,
        int isIFFT,
        int is2dOp,
        int libraryControl,
        enum FFTAlgType algType,
        enum FFTFloatType floatType,
        int canOverwriteInput, 
        int isCompact, 
        int needBuffers,
        int isInplace,
        int nThread4Planner);

typedef void (*pFnLibOutputs_FFT)(void *hostLib,
        char *err,
        const void *inPtr,
        void *outPtr, 
        int nRows,
        int nCols);

/*******************************
 * Routines which we define to call the functions in the library
 *******************************/
void LibCreate_FFT(void *hostLib,
                   const int FFTLength,
                   int nFFTs,
                   const void *inPtr,
                   void *outPtr,
                   int isIFFT,
                   int is2dOp,
                   int libraryControl,
                   unsigned int algType,
                   unsigned int floatType, 
                   int canOverwriteInput, 
                   int isCompact, 
                   int needBuffers, 
                   int isInplace,
                   int nThread4Planner);
void LibOutputs_FFT(void *hostLib,
                    const void *inPtr,
                    void *outPtr,
                    int nRows,
                    int nCols);

/* Include for declarations of LibStart, LibTerminate, CreateHostLibrary, and DestroyHostLibrary. */
#include "HostLib_rtw.h"

#ifdef __cplusplus
}
#endif

#endif /* HOSTLIB_FFT_H_ */
