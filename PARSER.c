#include "PARSER.h"
#include <string.h>

SystemEvent parse_command(char *input)
{
    if(strcmp(input, "START") == 0)
    {
        return EVENT_START;
    }

    else if(strcmp(input, "STOP") == 0)
    {
        return EVENT_STOP;
    }

    else if(strcmp(input, "READ_TEMP") == 0)
    {
        return EVENT_READ_TEMP;
    }

    else if(strcmp(input, "READ_DIST") == 0)
    {
        return EVENT_READ_DIST;
    }

    else if(strcmp(input, "READ_ALL") == 0)
    {
        return EVENT_READ_ALL;
    }

    else if(strcmp(input, "STATUS") == 0)
    {
        return EVENT_STATUS;
    }

    else if(strcmp(input, "RESET") == 0)
    {
        return EVENT_RESET;
    }

    else if(strcmp(input, "START_TELEMETRY") == 0)
    {
        return EVENT_START_TELEMETRY;
    }

    else if(strcmp(input, "STOP_TELEMETRY") == 0)
    {
        return EVENT_STOP_TELEMETRY;
    }

    return EVENT_NONE;
}
