# 🔌 Multiple Input and Output Driver

This project was developed for a client who required a **microcontroller-based control and feedback system** capable of handling multiple input and output channels efficiently.  
The design uses a **PIC18F microcontroller** with **I²C-based expansion modules** to extend its digital I/O and PWM capabilities for scalable industrial or embedded applications.

---

## 🎯 Project Objectives

- Design a **modular and scalable control system** supporting multiple digital and PWM channels.  
- Implement **I²C-based communication** to interface with external I/O and PWM driver modules.  
- Enable **real-time feedback monitoring** and **precise actuator control**.  
- Validate system functionality through complete **Proteus simulation** before hardware deployment.

---

## 🧩 My Contributions

- Developed firmware in **C** to control **MCP23017** (I/O expander) and **PCA9685** (PWM driver) over the I²C bus.  
- Implemented **multi-channel input/output routines** for seamless communication and data exchange.  
- Designed and simulated the complete system in **Proteus** to verify timing, communication, and control logic.  
- Integrated **feedback monitoring** and **PWM-based output control** for closed-loop applications.  
- Optimized I²C communication for reliable, synchronized operation between all connected devices.

---

## 🧰 Technologies and Tools Used

| Tool / Component | Purpose |
|------------------|----------|
| **Microcontroller** | PIC18F Series |
| **I/O Expander** | MCP23017 – 16-bit GPIO via I²C |
| **PWM Driver** | PCA9685 – 16-channel PWM via I²C |
| **Communication Protocol** | I²C (400 kHz Fast Mode) |
| **Firmware Environment** | MPLAB X IDE with XC8 Compiler |
| **Simulation Tool** | Proteus Design Suite |

---
