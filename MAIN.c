#include "FSM.h"
#include "QUEUE.h"
#include "PARSER.h"
#include "SENSOR_MANAGER.h"

#include <stdio.h>
#include <string.h>
#include <windows.h>

extern int telemetry_enabled;

int main()
{
    SystemState state = STATE_IDLE;

    EventQueue q;

    init_queue(&q);

    char command[50];

    printf("=== AUTONOMOUS SPACECRAFT CONTROLLER ===\n");

    printf("Commands:\n");

    printf("START\n");
    printf("STOP\n");
    printf("RESET\n");

    printf("READ_TEMP\n");
    printf("READ_DIST\n");
    printf("READ_ALL\n");

    printf("STATUS\n");

    printf("START_TELEMETRY\n");
    printf("STOP_TELEMETRY\n");

    printf("========================================\n");

    while(1)
    {
        if(telemetry_enabled)
        {
            float temp = read_temperature(&q);

            float dist = read_distance(&q);

            printf("\n[AUTO TELEMETRY]\n");

            printf("TEMP = %.1f C\n", temp);

            printf("DIST = %.1f cm\n", dist);

            Sleep(2000);
        }

        printf("\n>> ");

        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = 0;

        SystemEvent event = parse_command(command);

        enqueue(&q, event);

        SystemEvent event1 = dequeue(&q);

        process_event(&state, event1, &q);
    }

    return 0;
}
