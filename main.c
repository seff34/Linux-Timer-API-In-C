#include "timer.h"

//Global Timer Signal Variables
#define TIMER_SIGNAL_1 SIGRTMIN + 1
#define TIMER_SIGNAL_2 SIGRTMIN + 2
#define TIMER_SIGNAL_3 SIGRTMIN + 3

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


int main(int argc,char **argv)
{
    (void)argc;
    (void)argv;

    //Dynamic Memory Allocate
    timerValues_t *timer1 = (timerValues_t *)malloc(sizeof(timerValues_t));
    timerValues_t *timer2 = (timerValues_t *)malloc(sizeof(timerValues_t));
    timerValues_t *timer3 = (timerValues_t *)malloc(sizeof(timerValues_t));
    //Init Signal
    timerInit(timer1,TIMER_SIGNAL_1,timerCallback_1);
    timerInit(timer2,TIMER_SIGNAL_2,timerCallback_2);
    timerInit(timer3,TIMER_SIGNAL_3,timerCallback_3);

    //Timer Start
    timerStart(timer1, 0   , 1000 );  //-> 1second Periodic Timer
    timerStart(timer2, 1000, 1000 );  //-> 1second Periodic Timer
    timerStart(timer3, 3000, 0 );     //-> 3second One Shot Timer

    //Timer Stop
    timerStop(timer1);
    timerStop(timer2);
    timerStop(timer3);

    while(1);

    //Dynamic Memory Deallocate
    timerDeinit(timer1);
    timerDeinit(timer2);
    timerDeinit(timer3);

    return EXIT_SUCCESS;
}