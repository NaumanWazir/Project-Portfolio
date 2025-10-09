# 🌡️ Temperature with Feedback Control System

A **closed-loop thermal management system** designed using the **PIC16F18326-IST** microcontroller.  
This project implements a **PID-based control algorithm** to regulate temperature by adjusting fan speed in real time based on sensor feedback.  
Developed for precision temperature control in laboratory or embedded product environments.

---

## 🎯 Project Objectives
- Design a **PID-controlled thermal regulation system** using a microcontroller.  
- Achieve **stable and precise temperature control** with minimal overshoot and steady-state error.  
- Integrate **digital temperature sensing** and **PWM-based fan control** for efficient heat management.  
- Provide a **PC interface** for live monitoring, parameter tuning, and system configuration via I²C communication.  

---

## 👨‍💻 My Contributions
- Developed **firmware** for closed-loop temperature control using a **PID algorithm** on the PIC16F18326-IST.  
- Implemented **I²C communication** between the MCU and a **PC host system** for configuration and data monitoring.  
- Integrated **MCP9808** temperature sensor and **TFA0412CN** DC fan for real-time feedback and actuation.  
- Enabled **dynamic configuration** from the PC to adjust target temperature, PID parameters, and fan control settings.  

---

## 🛠️ Technologies and Tools Used
- **Microcontroller:** PIC16F18326-IST  
- **Sensor:** MCP9808T-EMC (Digital Temperature Sensor)  
- **Actuator:** TFA0412CN (PWM-Controlled DC Fan)  
- **Control Algorithm:** PID (Proportional–Integral–Derivative)  
- **Communication Interface:** I²C to USB Bridge (MCU ↔ PC Host)  
- **Development Environment:** MPLAB X IDE (XC8 Compiler)  

---
