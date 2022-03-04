#ifndef RTW_LINUX_H
#define RTW_LINUX_H

/*
 * Copyright 2011 The MathWorks, Inc.
 *
 * File: rtw_linux.h
 *
 * Abstract:
 *  Function prototypes and defines pthread mutex/semaphores
 */
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#ifndef __USE_UNIX98
#define __USE_UNIX98
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void rtw_pthread_mutex_init( void** mutexDW );        

#ifdef __cplusplus
}
#endif

#define rtw_pthread_mutex_lock( mutexDW ) \
    pthread_mutex_lock((pthread_mutex_t *)(mutexDW));

#define rtw_pthread_mutex_unlock( mutexDW ) \
    pthread_mutex_unlock((pthread_mutex_t *)(mutexDW));

#define rtw_pthread_mutex_destroy( mutexDW )      \
    pthread_mutex_destroy((pthread_mutex_t *)(mutexDW)); \
    free(mutexDW);

#define rtw_pthread_sem_create( semaphoreDW, initVal ) \
    *semaphoreDW = malloc(sizeof(sem_t));               \
    sem_init(*(semaphoreDW), 0, (initVal));

#define rtw_pthread_sem_wait( semaphoreDW ) \
    sem_wait(semaphoreDW);

#define rtw_pthread_sem_post( semaphoreDW ) \
    sem_post(semaphoreDW);

#define rtw_pthread_sem_destroy( semaphoreDW ) \
    sem_destroy(semaphoreDW);                   \
    free(semaphoreDW);

#endif /* RTW_LINUX_H */

/* LocalWords:  pthread
 */
