/*
 * dsp_fft_common_sim - DSP Blockset definitions
 *       common to both FFT and IFFT blocks.
 *
 *  Copyright 1995-2011 The MathWorks, Inc.
 */

#ifndef dsp_fft_common_sim_h
#define dsp_fft_common_sim_h

#include "sim_common/dsp_sim.hpp"

/*
 * FFT common argument cache, used during simulation only
 */
typedef struct {
    int_T       nRows;        // # of rows = fft length 
    int_T       nChans;       // # of channels/cols     

    int_T       invScale; // Flag: scale IFFT by N  
    void       *outPtr;   // Output data pointer    
    const void *inPtr;    // Input data pointer     
    void       *dataPtr;  // Pointer to data on which FFT has to be performed
                          //  For in-place, same as outPtr, else same as inPtr
                              
    const void *twidPtr;      // Twiddle table Pointer  
    const void *zero;         // Pointer to unknown datatype zero 
    int_T bytes_per_element;  // Number of bytes per element for unknown datatype 
    void       *wkspace;      // Pointer to DWork for Deinterleaver 
    
    int_T       twidTableSize;
    int_T       twiddleStep;        // Strides to take within twiddle table 
    int_T       twiddleStepAlongR;  // Strides to take within twiddle table 
                                    // along row 
    void       *copyDWork; // DWork used in 2D FFT for copying rows as columns 
    void       *copyDWork1;// DWork used in 2D FFT for copying rows as columns 
    void       *copyCS;    // DWork used for CS IFFT mode. 
    void       *cs2dDwork;// DWork for 2D CS IFFT.
    
    boolean_T   is2D;//need for run-time error checking for nCols in 2D
    boolean_T   isVarDim;
    boolean_T   needToSetCurOutDimRunTime;
    boolean_T   isInputCplx;      // Used for wrap functionality
    int_T       nInRows;          // Used for wrap functionality 
    int_T       wrapTimes;        // Used for wrap functionality 
    
    void       *padWrapInPtr;     // Input pointer for pad/wrap function
    void       *padWrapOutPtr;    // Output pointer for pad/wrap function 

    int_T       nDctDims;     // 1 for 1D, 2 for 2D - potentially arbitrary
    int_T      *vectorLength; // Number of elements in each vector 
    int_T      *prodLowDims;  // Product of dims LT selected dimension 
    int_T      *prodHighDims; // Product of dims GT selected dimension 
                              // Above three added for DCT N-D support. Use 
                              // when FFT block is updated for N-D. 
    
    void       *idxDWork;     // DWork used in DCT for applying stride for N-D
    void       *dctFcnPtrBuf; // buffer for storing DCT function pointers

    boolean_T   useLibraryFn; // True if a library function should be used

    int_T       hostLibDWorkIdx; // DWork index for the host library pointer
    void       *dWorkPtr;      // pointer to the host library dwork
    int_T       fftwdwIdx;     // Index of a dwork that FFTW uses for
                               // conjugate-symmetric IFFTs
    void       *fftwdwPtr;     // pointer to the above dwork
} MWDSP_FFTArgsCache;

// Functions to create RTP Sine table for FFT routines
extern void CreateFullFloatSineTableRTP(SimStruct *S, 
                                        int_T      N,
                                        int_T      rtp_index, 
                                        DTypeId    rtp_dtype, 
                                        const char *rtpName);
extern void CreateSineTableRTP(SimStruct *S, 
                               boolean_T  SPEED, 
                               int_T      NFFT,
                               int_T      rtp_index, 
                               DTypeId    rtp_dtype,
                               const char *rtpName);

#endif /* dsp_fft_common_sim_h */

/* [EOF] dsp_fft_common_sim.h */

