#include "FSM.h"
#include "SENSOR_MANAGER.h"
#include <stdio.h>
#include "FLAGS.h"
#include "SYSTEM_STATE.h"

int telemetry_enabled = 0;

void process_event(SystemState *state, SystemEvent event, EventQueue *q)
{
    if(event == EVENT_STATUS)
    {
        if(*state == STATE_IDLE)
        {
            printf("SYSTEM STATE = IDLE\n");
        }

        else if(*state == STATE_ACTIVE)
        {
            printf("SYSTEM STATE = ACTIVE\n");
        }

        else if(*state == STATE_SAFE_MODE)
        {
            printf("SYSTEM STATE = SAFE MODE\n");
        }

        else if(*state == STATE_ERROR)
        {
            printf("SYSTEM STATE = ERROR\n");
        }

        return;
    }

    switch(*state)
    {
        case STATE_IDLE:

            if(event == EVENT_START)
            {
                *state = STATE_ACTIVE;

                printf("SPACECRAFT ACTIVATED\n");
            }

            else
            {
                printf("SYSTEM IDLE - START REQUIRED\n");
            }

            break;


        case STATE_ACTIVE:

            if(event == EVENT_STOP)
            {
                *state = STATE_IDLE;

                telemetry_enabled = 0;

                printf("SPACECRAFT STOPPED\n");
            }

            else if(event == EVENT_TIMEOUT)
            {
                system_flags |= SENSOR_TIMEOUT;

                *state = STATE_SAFE_MODE;

                printf("TIMEOUT DETECTED -> SAFE MODE\n");
            }

            else if(event == EVENT_READ_TEMP)
            {
                float temp = read_temperature(q);

                printf("TEMP = %.1f C\n", temp);
            }

            else if(event == EVENT_READ_DIST)
            {
                float dist = read_distance(q);

                printf("DIST = %.1f cm\n", dist);
            }

            else if(event == EVENT_READ_ALL)
            {
                float temp = read_temperature(q);
                float dist = read_distance(q);

                printf("TEMP = %.1f C\n", temp);
                printf("DIST = %.1f cm\n", dist);
            }

            else if(event == EVENT_START_TELEMETRY)
            {
                telemetry_enabled = 1;

                printf("AUTONOMOUS TELEMETRY ENABLED\n");
            }

            else if(event == EVENT_STOP_TELEMETRY)
            {
                telemetry_enabled = 0;

                printf("AUTONOMOUS TELEMETRY DISABLED\n");
            }

            else if(event == EVENT_SENSOR_FAIL)
            {
                *state = STATE_SAFE_MODE;

                printf("SENSOR FAILURE DETECTED\n");
            }

            else
            {
                printf("UNKNOWN EVENT IN ACTIVE MODE\n");
            }

            break;


        case STATE_SAFE_MODE:

            if(event == EVENT_RESET)
            {
                *state = STATE_IDLE;

                telemetry_enabled = 0;

                printf("SYSTEM RESET\n");
            }

            else
            {
                printf("SAFE MODE ACTIVE - RESET REQUIRED\n");
            }

            break;


        case STATE_ERROR:

            if(event == EVENT_RESET)
            {
                *state = STATE_IDLE;

                telemetry_enabled = 0;

                printf("ERROR RESET COMPLETE\n");
            }

            else
            {
                printf("SYSTEM ERROR STATE\n");
            }

            break;


        default:

            printf("INVALID SYSTEM STATE\n");

            break;
    }
}
