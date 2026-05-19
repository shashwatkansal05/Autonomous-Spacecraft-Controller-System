# 🚀 Autonomous Spacecraft Controller System

An event-driven embedded firmware project designed to model how autonomous spacecraft onboard software manages communication, telemetry, sensor handling, and fault recovery using modular firmware architecture.

---

# 📌 Project Overview

This project demonstrates a spacecraft control system capable of:

- Receiving ground-control style commands
- Managing spacecraft operational states
- Reading simulated onboard sensors
- Generating autonomous telemetry
- Detecting faults and entering SAFE_MODE
- Handling events through a queue-driven firmware architecture

The primary goal of this project was to practice real embedded systems concepts beyond basic linear C programs.

---

# 🧠 Embedded Systems Concepts Implemented

- Finite State Machine (FSM)
- Event-driven firmware architecture
- Queue-based event handling
- UART-style command parser
- Simulated I2C sensor communication
- Sensor manager abstraction layer
- Autonomous telemetry system
- SAFE_MODE fault recovery
- Timeout and sensor failure handling
- Modular embedded firmware organization

---

# 🏗️ Firmware Architecture

```
Ground Command Interface
            ↓
         Parser Layer
            ↓
        Event Queue
            ↓
     FSM Controller
            ↓
 Sensor Manager Layer
            ↓
 Simulated I2C Drivers
            ↓
      Telemetry Output
```

---


# 📡 Supported Commands

| Command | Function |
|---|---|
| `START` | Activate spacecraft |
| `STOP` | Stop spacecraft |
| `RESET` | Reset system |
| `READ_TEMP` | Read temperature sensor |
| `READ_DIST` | Read distance sensor |
| `READ_ALL` | Read all sensors |
| `STATUS` | Display spacecraft state |
| `START_TELEMETRY` | Enable autonomous telemetry |
| `STOP_TELEMETRY` | Disable telemetry |

---

# 🛰️ Features

✅ FSM-based spacecraft control  
✅ Event queue driven architecture  
✅ Autonomous telemetry generation  
✅ onboard sensor communication  
✅ SAFE_MODE and fault handling  
✅ UART-style command interface  
✅ Modular firmware-style software design  
✅ Embedded-style layered architecture  

---



# 💻 Example Execution

```
>> START
SPACECRAFT ACTIVATED

>> READ_TEMP
TEMP = 24.5 C

>> START_TELEMETRY
AUTONOMOUS TELEMETRY ENABLED

[AUTO TELEMETRY]
TEMP = 24.8 C
DIST = 120.0 cm

>> STATUS
SYSTEM STATE = ACTIVE
```



