#include "bsp_i2c.h"
#include "driver/i2c_master.h"


static i2c_master_bus_handle_t s_i2c_bus_handle = NULL;
static SemaphoreHandle_t s_i2c_bus_semaphore = NULL;

void bsp_i2c_init(void)
{
    // 初始化 bus
    i2c_master_bus_config_t bus_cfg = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = I2C_NUM_0,
        .scl_io_num = 2,
        .sda_io_num = 3,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_cfg, &s_i2c_bus_handle));

    // 初始化信号量
    s_i2c_bus_semaphore = xSemaphoreCreateMutex();
}
void bsp_i2c_primary_bus_get_handle(i2c_master_bus_handle_t *handle)
{
    if (handle && s_i2c_bus_handle) {
        *handle = s_i2c_bus_handle;
    }
}

void bsp_i2c_primary_bus_get_semaphore(SemaphoreHandle_t *semaphore)
{
    if (semaphore && s_i2c_bus_semaphore) {
        *semaphore = s_i2c_bus_semaphore;
    }
}
