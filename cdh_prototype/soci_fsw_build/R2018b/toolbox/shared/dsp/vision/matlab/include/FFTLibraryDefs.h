/*
 * FFTLibraryDefs.h
 *  Copyright 2010 The MathWorks, Inc.
 *  Defines enumerated types related to third-party FFT libraries. 
 *  These enumerated types are used in the S-function and HostLib_FFT.
 */

#ifndef FFTLIBRARYDEFS_H_
#define FFTLIBRARYDEFS_H_

enum FFTAlgType {
    FFTC2C = 1, FFTR2C, FFTC2R
};

enum FFTFloatType {
    FFTDouble = 1,
    FFTSingle
};

#endif /* FFTLIBRARYDEFS_H_ */
