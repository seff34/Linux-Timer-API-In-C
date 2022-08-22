<h1 class="code-line" data-line-start=0 data-line-end=1 ><a id="LinuxTimerAPI_0"></a>Linux-Timer-API</h1>
<p class="has-line-data" data-line-start="1" data-line-end="2">#Linux Timer Library with POSIX</p>
<p class="has-line-data" data-line-start="5" data-line-end="6">#----------EXAMPLE----------</p>
<p class="has-line-data" data-line-start="9" data-line-end="60">INIT<br>
{<br>
//Global Timer Signal Variables<br>
#define TIMER_SIGNAL_1 SIGRTMIN + 1<br>
#define TIMER_SIGNAL_2 SIGRTMIN + 2<br>
#define TIMER_SIGNAL_3 SIGRTMIN + 3<br>
//Dynamic Memory Allocate<br>
timerValues_t *timer1 = (timerValues_t *)malloc(sizeof(timerValues_t));<br>
timerValues_t *timer2 = (timerValues_t *)malloc(sizeof(timerValues_t));<br>
timerValues_t *timer3 = (timerValues_t *)malloc(sizeof(timerValues_t));<br>
//Init Signal<br>
timerInit(timer1,TIMER_SIGNAL_1,timerCallback_1);<br>
timerInit(timer2,TIMER_SIGNAL_2,timerCallback_2);<br>
timerInit(timer3,TIMER_SIGNAL_3,timerCallback_3);<br>
}<br>
START - STOP<br>
{<br>
//Timer Start<br>
timerStart(timer1, 0   , 1000 );  -&gt; 1second Periodic Timer<br>
timerStart(timer2, 1000, 1000 );  -&gt; 1second Periodic Timer<br>
timerStart(timer3, 3000, 0 );     -&gt; 3second One Shot Timer<br>
//Timer Stop<br>
timerStop(timer1);<br>
timerStop(timer2);<br>
timerStop(timer3);<br>
}<br>
CALLBACKS<br>
{<br>
void timerCallback_1(int signal)<br>
{<br>
//(void)signal;<br>
printf(“Timer Interrupt %d ------------\n”,signal);<br>
}<br>
void timerCallback_2(int signal)<br>
{<br>
//(void)signal;<br>
printf(“Timer Interrupt %d ------------\n”,signal);<br>
}<br>
void timerCallback_3(int signal)<br>
{<br>
//(void)signal;<br>
printf(“Timer Interrupt %d ------------\n”,signal);<br>
}<br>
}<br>
DEINIT<br>
{<br>
//Dynamic Memory Deallocate<br>
timerDeinit(timer1);<br>
timerDeinit(timer2);<br>
timerDeinit(timer3);<br>
}</p>
