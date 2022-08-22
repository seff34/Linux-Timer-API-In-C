/**
 * @file      timer.c
 * @author    Sefa Eren AKDOGAN
 * @brief     Linux Timer API
 * @version   1.0
 * @date      2022-07-20
 * @copyright Copyright (c) 2022
 */

#include "timer.h"

static int8_t timerConfig(timerValues_t *values);

int8_t timerInit(timerValues_t *values,uint16_t SIGNAL,void *CALLBACK)
{
    struct sigaction sa;
    struct sigevent sev;
    //timer_t tmr;
    int ret;

    values->timerSignal = SIGNAL;
    //values->timer = tmr;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = CALLBACK;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo  = values->timerSignal;

    sigemptyset(&sa.sa_mask);

    if (sigaction(values->timerSignal, &sa, NULL) == -1) {
        printf("sigaction error");
        return -1 ; 
        exit(1);
    }

    if ( (ret = timer_create(CLOCK_MONOTONIC, &sev, &values->timer/*&timer*/)) < 0) {
        printf("timer1 create failed: %s", strerror(errno));
        return -1 ;
    }
    return 0 ; 

    timerStop(values);
}
int8_t timerDeinit(timerValues_t *values)
{
    timerStop(values);
    free(values);
    return 0 ; 
}
int8_t timerStart(timerValues_t *values,uint16_t ONESHOTMS,uint16_t PERIODICMS)
{
    int8_t ret;
    timerStop(values);
    if ( values->oneShotMsec <= 10 )
        values->oneShotMsec = PERIODICMS;
    else
        values->oneShotMsec = ONESHOTMS ; 
    values->periodicMsec = PERIODICMS; 
    ret = timerConfig(values);
    return ret ;
}
int8_t timerStop(timerValues_t *values)
{
    int8_t ret;
    values->oneShotMsec = 0 ; 
    values->periodicMsec = 0; 
    ret = timerConfig(values);
    return ret ;
}

static int8_t timerConfig(timerValues_t *values)
{
    struct itimerspec new_value;
    struct itimerspec old_value;
    new_value.it_value.tv_sec     = values->oneShotMsec / 1000;
    new_value.it_value.tv_nsec    = ( values->oneShotMsec % 1000 )* 1000 * 1000;
    new_value.it_interval.tv_sec  = values->periodicMsec / 1000 ;
    new_value.it_interval.tv_nsec = ( values->periodicMsec % 1000 )* 1000 * 1000;
    if (timer_settime(values->timer/*timer*/, 0, &new_value, &old_value) < 0) {
        printf("timer settime error: %s", strerror(errno));
        return -1 ;
    }
    return 0 ; 
}
