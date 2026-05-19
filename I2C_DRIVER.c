#include "I2C_DRIVER.h"
#include <stdlib.h>
#include <time.h>


float i2c_read_temperature()
{
    int r = rand() % 100;

    // 10% failure rate
    if(r < 10)
    {
        return -1;
    }

    // base temp = 26.5 with noise (-2.0 to +2.0)
    float noise = ((rand() % 41) - 20) / 10.0;
    return 26.5 + noise;
}


float i2c_read_distance()
{
    int r = rand() % 100;

    // 10% failure rate
    if(r < 10)
    {
        return -1;
    }

    // base distance = 142 with noise (-5 to +5)
    float noise = (rand() % 11) - 5;
    return 142.0 + noise;
}
