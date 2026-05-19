#include "SENSOR_MANAGER.h"
#include "I2C_DRIVER.h"
#include "QUEUE.h"
#include "EVENTS.h"
#include "FLAGS.h"
#include "SYSTEM_STATE.h"

float read_temperature(EventQueue *q)
{
    float val = i2c_read_temperature();

    if(val == -1)
    {
        system_flags |= SENSOR_TIMEOUT;

        enqueue(q, EVENT_SENSOR_FAIL);
        return -1;
    }

    return val;
}


float read_distance(EventQueue *q)
{
    float val = i2c_read_distance();

    if(val == -1)
    {
        system_flags |= SENSOR_TIMEOUT;

        enqueue(q, EVENT_SENSOR_FAIL);
        return -1;
    }

    return val;
}
