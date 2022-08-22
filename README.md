
# Linux Timer API

Library is a High-Level POSIX TIMER API.



## API Functions

#### Define Timer Signal

```bash
#define TIMER_SIGNAL_1 SIGRTMIN + 1
```

#### Allocate Memory
```bash
timerValues_t *timer1 = (timerValues_t *)malloc(sizeof(timerValues_t));
```
#### Timer Initalize
```bash
timerInit(timer1,TIMER_SIGNAL_1,timerCallback_1);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Name` | `timer_t` | Timer Name |
| `Signal` | `uint16_t` | Timer Signal|
| `Callback  ` | `void *` | Timer Callback Functions |

#### Timer Start

```bash
timerStart(timer1, 0 , 1000 );   -> 1second Periodic Timer
timerStart(timer2, 1000, 1000 ); -> 1second Periodic Timer
timerStart(timer3, 3000, 0 );    -> 3second One Shot Timer
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Name` | `timer_t` | Timer Name |
| `Time_Ms` | `uint16_t` | One Shot Timer Value (ms)|
| `Time_Ms  ` | `uint16_t ` | Periodic Timer Value (ms) |

#### Timer Stop
```bash
timerStop(timer1);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Name` | `timer_t` |  Timer Name |

#### Timer Deinit
```bash
timerDeinit(timer1);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Name` | `timer_t` | Timer Name |

#### Timer Callback Function
```bash
void timerCallback_1(int signal)
{
    //(void)signal;
    printf("Timer Interrupt %d ------------\n",signal);
}
```
## Bilgisayarınızda Çalıştırın

Projeyi klonlayın

```bash
  git clone https://github.com/seff34/Linux-Timer-API
```


  
## References:

https://man7.org/linux/

https://demirten.gitbooks.io/linux-sistem-programlama/content/timers/posix.html



  
