# ⚙️ Motor PID Control

This project implements a **PID (Proportional–Integral–Derivative)** control system for a **two-wheel drive robot** using the **PIC24FJ256GA702** microcontroller and an **L298N motor driver**.  
It features **dual DC motors with encoders**, enabling precise closed-loop control for forward, reverse, and turning maneuvers.

---

## 🎯 Project Objectives

Design a **stable and accurate closed-loop motor control system** capable of maintaining desired speed and direction for a two-wheel drive robot.  
The system should use encoder feedback for precise motion control and support external control via a **UART interface**.

---

## 🧩 My Contributions

- Developed **PID control firmware** for dual DC motors with real-time encoder feedback.  
- Implemented **directional movement** control for forward, backward, left, and right maneuvers.  
- Created a **UART-based interface** for command input and live monitoring.  
- Tuned **PWM outputs** for smooth acceleration and precise speed regulation.  
- Verified full system operation through **Proteus simulation** before hardware deployment.

---

## 🧰 Technologies and Tools Used

| Tool / Technology | Purpose |
|------------------|---------|
| **Microcontroller** | PIC24FJ256GA702 |
| **Motor Driver** | L298N Dual H-Bridge |
| **Motors** | Two DC motors with quadrature encoders |
| **Control Algorithm** | PID (Proportional–Integral–Derivative) |
| **Development Environment** | MPLAB X IDE |
| **Simulation Tool** | Proteus |

---
