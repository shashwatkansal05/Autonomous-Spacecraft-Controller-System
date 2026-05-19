#ifndef FSM_H
#define FSM_H

#include "STATES.h"
#include "EVENTS.h"
#include "QUEUE.h"

void process_event(SystemState *state, SystemEvent event,EventQueue *q);

#endif
