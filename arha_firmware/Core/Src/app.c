#include "app.h"
#include <stdio.h>

/* ── LED blink task ──────────────────────────────────────────────────── */
static void BlinkTask(void *arg)
{
  (void)arg;
  for (;;)
  {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
    printf("[BLINK] toggle\r\n");
    osDelay(500);
  }
}

/* ── App_Init ────────────────────────────────────────────────────────── */
void App_Init(void)
{
  printf("\r\n=== ARHA Firmware Started ===\r\n");

  /* --- GPIO setup (PB0 = LD1 green on Nucleo-H723ZG) --- */
  GPIO_InitTypeDef gpio = {0};
  gpio.Pin   = GPIO_PIN_0;
  gpio.Mode  = GPIO_MODE_OUTPUT_PP;
  gpio.Pull  = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &gpio);

  /* --- Create tasks ------------------------------------------------- */
  const osThreadAttr_t blink_attr = {
    .name       = "blinkTask",
    .stack_size = 256 * 4,
    .priority   = (osPriority_t) osPriorityNormal,
  };
  osThreadNew(BlinkTask, NULL, &blink_attr);
}
