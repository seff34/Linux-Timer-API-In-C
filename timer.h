#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

#define TIMER_SIGNAL_1 SIGRTMIN + 1
#define TIMER_SIGNAL_2 SIGRTMIN + 2
#define TIMER_SIGNAL_3 SIGRTMIN + 3
#define TIMER_SIGNAL_4 SIGRTMIN + 4
#define TIMER_SIGNAL_5 SIGRTMIN + 5
#define TIMER_SIGNAL_6 SIGRTMIN + 6
#define TIMER_SIGNAL_7 SIGRTMIN + 7

/* EXAMPLE
INIT
{
    //Global Timer Signal Variables
    #define TIMER_SIGNAL_1 SIGRTMIN + 1
    #define TIMER_SIGNAL_2 SIGRTMIN + 2
    #define TIMER_SIGNAL_3 SIGRTMIN + 3

    //Dynamic Memory Allocate
    timerValues_t *timer1 = (timerValues_t *)malloc(sizeof(timerValues_t));
    timerValues_t *timer2 = (timerValues_t *)malloc(sizeof(timerValues_t));
    timerValues_t *timer3 = (timerValues_t *)malloc(sizeof(timerValues_t));
    //Init Signal
    timerInit(timer1,TIMER_SIGNAL_1,timerCallback_1);
    timerInit(timer2,TIMER_SIGNAL_2,timerCallback_2);
    timerInit(timer3,TIMER_SIGNAL_3,timerCallback_3);
}
START - STOP 
{
    //Timer Start
    timerStart(timer1, 0   , 1000 );  -> 1second Periodic Timer
    timerStart(timer2, 1000, 1000 );  -> 1second Periodic Timer
    timerStart(timer3, 3000, 0 );     -> 3second One Shot Timer
    //Timer Stop
    timerStop(timer1);
    timerStop(timer2);
    timerStop(timer3);
}
CALLBACKS
{
    void timerCallback_1(int signal)
    {
        //(void)signal;
        printf("Timer Interrupt %d ------------\n",signal);
    }
    void timerCallback_2(int signal)
    {
        //(void)signal;
        printf("Timer Interrupt %d ------------\n",signal);
    }
    void timerCallback_3(int signal)
    {
        //(void)signal;
        printf("Timer Interrupt %d ------------\n",signal);
    }
}
DEINIT
{
    //Dynamic Memory Deallocate
    timerDeinit(timer1);
    timerDeinit(timer2);
    timerDeinit(timer3);
}
*/

/**
 * @brief Timer Values Structere
 * @param timer         [timer_t]  Timer Configs;
 * @param oneShotMsec   [uint16_t] One Shot Timer Value
 * @param periodicMsec  [uint16_t] Periodic Timer Value
 * @param timerSignal   [uint16_t] Timer Signal Name
 */
typedef struct{
    timer_t timer;
    uint16_t oneShotMsec;
    uint16_t periodicMsec;
    uint16_t timerSignal;
}timerValues_t;

/**
 * @brief  Initalize Timer [ Look Example ]
 * @param  [in] values   [timerValues_t*] Timer Values Variables 
 * @param  [in] SIGNAL   [uint16_t]       Timer Signal    
 * @param  [in] CALLBACK [void*]          Timer Interrupt Callback Function
 * @return [int8_t]      Function Execute Result
 * @retval [0]           Success
 * @retval [-1]          Fail
 */
int8_t timerInit(timerValues_t *values,uint16_t SIGNAL,void *CALLBACK);

/**
 * @brief  Deinitalize Timer
 * @param  [in] values   [timerValues_t*] Timer Values Variables 
 * @return [int8_t]      Function Execute Result
 * @retval [0]           Always Success
 */
int8_t timerDeinit(timerValues_t *values);

/**
 * @brief  Timer Start 
 * @param  [in] values    [timerValues_t*] Timer Values Variables 
 * @param  [in] ONESHOTMS [uint16_t]       Timer One Shot Value
 * @param  [in] PERIODICMS[uint16_t]       Timer Periodic Value
 * @return [int8_t]       Function Execute Result
 * @retval [0]            Success
 * @retval [-1]           Fail
 */
int8_t timerStart(timerValues_t *values,uint16_t ONESHOTMS,uint16_t PERIODICMS);

/**
 * @brief  Timer Stop
 * @param  [in] values   [timerValues_t*] Timer Values Variables 
 * @return [int8_t]      Function Execute Result
 * @retval [0]           Success
 * @retval [-1]          Fail
 */
int8_t timerStop(timerValues_t *values);