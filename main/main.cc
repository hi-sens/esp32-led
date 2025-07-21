#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "lwip/err.h"
#include "lwip/sys.h"

// Status LED
#define LED_RED GPIO_NUM_1


void led_config()
{
    gpio_reset_pin(LED_RED);
    gpio_set_direction(LED_RED, GPIO_MODE_OUTPUT);
}

void led_task(void *pvParameter)
{
  while (1) {
    // We are connecting - blink fast
    gpio_set_level(LED_RED, 0);
    vTaskDelay(200 / portTICK_PERIOD_MS);
    gpio_set_level(LED_RED, 1);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}


// Main application
extern "C" void app_main() {
  printf("Starting LED application...\n");
  led_config();
  xTaskCreate(led_task, "led_task", 2048, NULL, 10, NULL);
}
