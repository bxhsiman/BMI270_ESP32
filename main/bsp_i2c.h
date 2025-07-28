#pragma once
#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

void bsp_i2c_init(void);

void bsp_i2c_primary_bus_get_handle(i2c_master_bus_handle_t *handle);
void bsp_i2c_primary_bus_get_semaphore(SemaphoreHandle_t *semaphore);
