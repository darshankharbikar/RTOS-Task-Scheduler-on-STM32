/* Time slicing and preemption */
#define configUSE_PREEMPTION                    1
#define configUSE_TIME_SLICING                  1  /* enable round-robin for equal priority tasks */

/* Needed for vTaskList and vTaskGetRunTimeStats if you want human-readable monitor */
#define configUSE_TRACE_FACILITY                1
#define INCLUDE_vTaskList                       1
#define INCLUDE_vTaskGetRunTimeStats            1
#define configGENERATE_RUN_TIME_STATS           1  /* enable runtime stats */

/* Provide platform specific runtime counter functions (implementation in a .c file or here) */
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()  ( /* configure e.g. TIM2 or DWT cycle counter */ )
#define portGET_RUN_TIME_COUNTER_VALUE()          ( DWT->CYCCNT ) /* example using DWT */

