#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H
#include "QUEUE.h"

float read_temperature(EventQueue *q);
float read_distance(EventQueue *q);

#endif
