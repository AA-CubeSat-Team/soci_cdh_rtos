/*
 *  dspsrt_rt.h
 *
 *  Copyright 1995-2016 The MathWorks, Inc.
 */

#ifndef dspsrt_rt_h
#define dspsrt_rt_h

#include "dsp_rt.h"
#ifdef MW_DSP_RT
#include "src/libmw_src_util.h"
#else
#include "libmw_src_util.h"
#endif

/* do not inline recursive quick sort functions */
#define DSPQSRTNOINLINE_EXPORT DSPQSRT_EXPORT

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Function naming glossary
 * ---------------------------
 *
 * MWDSP = MathWorks DSP Blockset
 *
 * Data types - (describe inputs to functions, not outputs)
 * R   = real single-precision
 * D   = real double-precision
 * S08 = int8_T
 * U08 = uint8_T
 * S16 = int16_T
 * U16 = uint16_T
 * S32 = int32_T
 * U32 = uint32_T
 */

/* Function naming convention
 * --------------------------
 *
 *    1) MWDSP_ is a prefix used with all Mathworks DSP runtime library
 *       functions.
 *    2) The second field (Sort) indicates that this function is implementing the
 *       Sort algorithm.
 *    3) The third field [Qk | Ins] indicates quick sort or insertion sort algorithm.
 *    4) The fourth field [Val | Idx] indicates sort by value or by index.
 *    5) The last field enumerates the data type from the above list.
 *       The data types of the input and output are the same.
 *
 *    Examples:
 *       MWDSP_Sort_Qk_Val_D is the Sort run time function for
 *       quick sort by value algorithm for double precision inputs.
 */

/* Quick Sort by index */
#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_Sort_Qk_Idx_D(
    const real_T *dataArray,
    uint32_T *idxArray,
    int_T iQS, int_T jQS);
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_Sort_Qk_Idx_R(
    const real32_T *dataArray,
    uint32_T *idxArray,
    int_T iQS, int_T jQS);
#endif /* !INTEGER_CODE */

LIBMW_SRC_API void MWDSP_Sort_Qk_Idx_S32(
    const int32_T *dataArray,
    uint32_T *idxArray,
    int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Idx_U32(
    const uint32_T *dataArray,
    uint32_T *idxArray,
    int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Idx_S16(
    const int16_T *dataArray,
    uint32_T *idxArray,
    int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Idx_U16(
    const uint16_T *dataArray,
    uint32_T *idxArray,
    int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Idx_S08(
    const int8_T *dataArray,
    uint32_T *idxArray,
    int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Idx_U08(
    const uint8_T *dataArray,
    uint32_T *idxArray,
    int_T iQS, int_T jQS);

/* Quick Sort by value */
#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_Sort_Qk_Val_D(real_T *dataArray,
                                                int_T iQS, int_T jQS);
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_Sort_Qk_Val_R(real32_T *dataArray,
                                                int_T iQS, int_T jQS);
#endif /* !INTEGER_CODE */

LIBMW_SRC_API void MWDSP_Sort_Qk_Val_S32(int32_T *dataArray,
                                                  int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Val_U32(uint32_T *dataArray,
                                                  int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Val_S16(int16_T *dataArray,
                                                  int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Val_U16(uint16_T *dataArray,
                                                  int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Val_S08(int8_T *dataArray,
                                                  int_T iQS, int_T jQS);

LIBMW_SRC_API void MWDSP_Sort_Qk_Val_U08(uint8_T *dataArray,
                                                  int_T iQS, int_T jQS);

/* Helper macros used in quick sort by index functions */
#define qsortIdxSwap(iQS,jQS) {uint32_T t    = *(idxArray+iQS); \
                           *(idxArray+iQS) = *(idxArray+jQS); \
                           *(idxArray+jQS) = t;}

#define qsortIdxOrder(iQS,jQS) {if( *(dataArray+*(idxArray+iQS)) > \
                            *(dataArray+*(idxArray+jQS)) ) qsortIdxSwap(iQS,jQS)}

#define qsortIdxOrder3(iQS,jQS,kQS) {qsortIdxOrder(iQS,jQS); qsortIdxOrder(iQS,kQS); qsortIdxOrder(jQS,kQS);}


/* Insertion Sort by value */
#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_Sort_Ins_Val_D(real_T *dataArray, int_T n );
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_Sort_Ins_Val_R(real32_T *dataArray, int_T n );
#endif /* !INTEGER_CODE */

LIBMW_SRC_API void MWDSP_Sort_Ins_Val_S32(int32_T *dataArray, int_T n );

LIBMW_SRC_API void MWDSP_Sort_Ins_Val_U32(uint32_T *dataArray, int_T n );

LIBMW_SRC_API void MWDSP_Sort_Ins_Val_S16(int16_T *dataArray, int_T n );

LIBMW_SRC_API void MWDSP_Sort_Ins_Val_U16(uint16_T *dataArray, int_T n );

LIBMW_SRC_API void MWDSP_Sort_Ins_Val_S08(int8_T *dataArray, int_T n );

LIBMW_SRC_API void MWDSP_Sort_Ins_Val_U08(uint8_T *dataArray, int_T n );


/* Insertion Sort by index */
#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_Sort_Ins_Idx_D(const real_T *dataArray, uint32_T *idxArray, int_T n);
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_Sort_Ins_Idx_R(const real32_T *dataArray, uint32_T *idxArray, int_T n);
#endif /* !INTEGER_CODE */

LIBMW_SRC_API void MWDSP_Sort_Ins_Idx_S32(const int32_T *dataArray, uint32_T *idxArray, int_T n);

LIBMW_SRC_API void MWDSP_Sort_Ins_Idx_U32(const uint32_T *dataArray, uint32_T *idxArray, int_T n);

LIBMW_SRC_API void MWDSP_Sort_Ins_Idx_S16(const int16_T *dataArray, uint32_T *idxArray, int_T n);

LIBMW_SRC_API void MWDSP_Sort_Ins_Idx_U16(const uint16_T *dataArray, uint32_T *idxArray, int_T n);

LIBMW_SRC_API void MWDSP_Sort_Ins_Idx_S08(const int8_T *dataArray, uint32_T *idxArray, int_T n);

LIBMW_SRC_API void MWDSP_Sort_Ins_Idx_U08(const uint8_T *dataArray, uint32_T *idxArray, int_T n);


/* XXX The functions are still used by dspblks/v3/dspsrt.c */
#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_SrtQkRecD(
    const real_T *qid_array,
    int_T *qid_index,
    int_T iQS, int_T jQS);
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
#if defined(CREAL_T)
LIBMW_SRC_API void MWDSP_SrtQkRecZ(
    const creal_T *qid_array,
    int_T   *qid_index,
    real_T  *sort,
    int_T iQS, int_T jQS);
#endif /* CREAL_T */
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API void MWDSP_SrtQkRecR(
    const real32_T *qid_array,
    int_T *qid_index,
    int_T iQS, int_T jQS);
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
#if defined(CREAL_T)
LIBMW_SRC_API void MWDSP_SrtQkRecC(
    const creal32_T *qid_array,
    int_T *qid_index,
    real32_T *sort,
    int_T iQS, int_T jQS);
#endif /* CREAL_T */
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API int_T MWDSP_SrtQidPartitionD(
    const real_T *qid_array,
    int_T *qid_index,
    int_T iQS,
    int_T jQS,
    int_T pivot );
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API boolean_T MWDSP_SrtQidFindPivotD(
    const real_T *qid_array,
    int_T *qid_index,
    int_T iQS,
    int_T jQS,
    int_T *pivot );
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API int_T MWDSP_SrtQidPartitionR(
     const real32_T *qid_array,
     int_T *qid_index,
     int_T iQS,
     int_T jQS,
     int_T pivot );
#endif /* !INTEGER_CODE */

#if !defined(INTEGER_CODE) || !INTEGER_CODE
LIBMW_SRC_API boolean_T MWDSP_SrtQidFindPivotR(
     const real32_T *qid_array,
     int_T *qid_index,
     int_T iQS,
     int_T jQS,
     int_T *pivot );
#endif /* !INTEGER_CODE */

#define qid_Swap(iQS,jQS) {int_T t        = *(qid_index+iQS); \
                       *(qid_index+iQS) = *(qid_index+jQS); \
                       *(qid_index+jQS) = t;}

#define qid_Order(iQS,jQS) {if( *(qid_array+*(qid_index+iQS)) > \
                            *(qid_array+*(qid_index+jQS)) ) qid_Swap(iQS,jQS)}

#define qid_Order3(iQS,jQS,kQS) {qid_Order(iQS,jQS); qid_Order(iQS,kQS); qid_Order(jQS,kQS);}

#ifdef __cplusplus
}
#endif


#endif /* dspsrt_rt_h */
