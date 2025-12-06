# RTOS-Task-Scheduler-on-STM32
Implemented round-robin and priority-based task switching using FreeRTOS. Created a mini RTOS visualizer over UART for task status monitoring.

Title
Implemented round-robin and priority-based task switching using FreeRTOS.
Created a mini RTOS visualizer over UART for task status monitoring.


Objective	 
Designed and implemented a FreeRTOS-based scheduler supporting round-robin and priority-driven task switching, with a UART-based mini RTOS visualizer for real-time task status monitoring and debugging.


Components required
STM32F411CEU6 (Black Pill)
USB to UART converter (e.g., CP2102 or FTDI)
USB cable (for power and programming)
Jumper wires (male-to-male)
Breadboard (optional)
3.3V power source (if external supply needed)
Host PC with:
STM32CubeIDE or arm-none-eabi toolchain
Serial terminal (PuTTY / MobaXterm)
FreeRTOS source integrated in project

Connections	
STM32F411CEU6 3.3V → USB-UART converter VCC (3.3V)
STM32F411CEU6 GND → USB-UART converter GND
STM32F411CEU6 PA9 (USART1_TX) → USB-UART converter RXD
STM32F411CEU6 PA10 (USART1_RX) → USB-UART converter TXD
Micro-USB cable connects STM32 to PC for power and programming
USB-UART converter connects to PC for UART visualizer terminal

Executions	
Open STM32CubeIDE and create a new FreeRTOS-based project for STM32F411CEU6.
Configure USART1 in asynchronous mode (115200 bps, 8N1).
Integrate FreeRTOS by enabling the CMSIS-RTOS interface or adding source files manually.
Create multiple tasks with varying priorities for scheduler testing.
Implement round-robin behavior by setting equal priorities and enabling time slicing in FreeRTOSConfig.
Implement priority-based scheduling by assigning different task priorities.
Add UART print statements to transmit task names, states, and CPU time to the terminal.
Build and flash the firmware to STM32 via ST-Link.
Open PuTTY or MobaXterm terminal at 115200 bps to view live task switching and status logs.
Observe scheduler behavior and task transitions in real time on UART output.

Notes on enabling runtime stats:
For accurate run-time stats implement portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() to enable a free-running 32-bit counter. On Cortex-M4 you can enable DWT cycle counter.


Example DWT init (call once before scheduler):


CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
DWT->CYCCNT = 0;
DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

Build / configuration checklist
In STM32CubeIDE enable USART1 on PA9/PA10, generated HAL files.
Add FreeRTOS sources or use CMSIS-RTOS integration.
Ensure FreeRTOSConfig.h contains the options above.
If using DWT for run-time stats, remove code that disables DWT (some debug builds do).
Set optimization to O0/O1 for predictable timing while testing.
Terminal settings
115200 baud, 8 data bits, no parity, 1 stop bit (8N1), no flow control.
How this demonstrates scheduler behavior
With TaskA and TaskB both priority 1 and configUSE_TIME_SLICING == 1 they will time-slice round-robin.
TaskHigh at priority 2 will preempt them when ready demonstrating priority-based scheduling.
Monitor prints vTaskList showing each task state, priority, and stack high water mark. Run-time stats show CPU percentage per task if enabled.
 
Issues and their debugging	 
Checklist	 
Verify STM32F411CEU6 board powered via USB and recognized in STM32CubeIDE
Confirm FreeRTOS source added and linked correctly in the project
Enable USE_PREEMPTION and USE_TIME_SLICING in FreeRTOSConfig.h
Enable UART1 on PA9/PA10 in CubeMX or code
Set baud rate to 115200, 8N1, no flow control
Add INCLUDE_vTaskList and INCLUDE_vTaskGetRunTimeStats macros
Initialize DWT counter if using runtime stats
Create and verify 3 user tasks (TaskA, TaskB, TaskHigh) and one Monitor task
Ensure stack sizes sufficient (≥128 words each)
Build project with no errors or warnings
Flash code to STM32F411CEU6 using ST-Link
Open serial terminal (PuTTY/MobaXterm) at 115200 baud
Observe round-robin switching between equal-priority tasks
Verify higher-priority task preempts lower-priority ones
Confirm Monitor task periodically prints task list and CPU usage
Save UART output logs for report or proof

Artifacts
Firmware binary: FreeRTOS_Scheduler.hex or .bin file generated after build
UART output log: Captured terminal session showing task switching, task list, and runtime stats
Project screenshots:
STM32CubeIDE FreeRTOS task configuration
UART terminal output displaying live scheduler data
Source code files:
main.c
FreeRTOSConfig.h
freertos.c / tasks.c / timers.c
Connection diagram: STM32F411 ↔ USB-UART converter wiring
Execution video (optional): short clip showing serial monitor output updating in real time
Documentation: brief report summarizing objective, setup, observations, and results


