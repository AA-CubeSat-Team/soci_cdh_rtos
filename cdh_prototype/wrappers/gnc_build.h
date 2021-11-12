// declares function for GNC_BUILD.c

#ifndef GNCBUILD_H
#define GNCBUILD_H

extern char gnc_build_flag;

void gnc_build_init(void);
void timer_init(void);
void rt_OneStep(void);

#endif                                 /* GNCBUILD_H */
