#ifndef __APP_H
#define __APP_H

#include "main.h"
#include "cmsis_os.h"

/**
 * Called once from main() after osKernelInitialize(), before osKernelStart().
 * Create all your FreeRTOS tasks, queues, semaphores, etc. in here.
 * You never need to edit main.c — just add code to app.c.
 */
void App_Init(void);

#endif /* __APP_H */
