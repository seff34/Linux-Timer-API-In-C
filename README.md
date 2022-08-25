
# Embedded Linux Timer API

Library is a High-Level POSIX TIMER API.


## API Functions

#### Define Timer Signal

```c
#define TIMER_SIGNAL_1 SIGRTMIN + 1
```

#### Allocate Memory
```c
timerValues_t *timer1 = (timerValues_t *)malloc(sizeof(timerValues_t));
```
#### Timer Initalize
```c
timerInit(timer1,TIMER_SIGNAL_1,timerCallback_1);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Name` | `timer_t` | Timer Name |
| `Signal` | `uint16_t` | Timer Signal|
| `Callback  ` | `void *` | Timer Callback Functions |

#### Timer Start

```c
timerStart(timer1, 0 , 1000 );   -> 1second Periodic Timer
timerStart(timer1, 1000, 1000 ); -> 1second Periodic Timer
timerStart(timer1, 3000, 0 );    -> 3second One Shot Timer
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Name` | `timer_t` | Timer Name |
| `Time_Ms` | `uint16_t` | One Shot Timer Value (ms)|
| `Time_Ms  ` | `uint16_t ` | Periodic Timer Value (ms) |

#### Timer Stop
```c
timerStop(timer1);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Name` | `timer_t` |  Timer Name |

#### Timer Deinit
```c
timerDeinit(timer1);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Name` | `timer_t` | Timer Name |

#### Timer Callback Function
```c
void timerCallback_1(int signal)
{
    //(void)signal;
    printf("Timer Interrupt %d ------------\n",signal);
}
```
## Download Code

Clone Project

```bash
  git clone https://github.com/seff34/Linux-Timer-API
```


  
## References:

https://man7.org/linux/

https://demirten.gitbooks.io/linux-sistem-programlama/content/timers/posix.html



  
