# 📡 Wireless Bridge for Sony Remote Control Panel

This project was completed under a **Non-Disclosure Agreement (NDA)** for a **UK-based company**.  
It involved designing and developing a **Wireless Remote Control Panel (RCP) Bridge** that allows a **Sony camera** to be remotely operated without traditional wired or Ethernet connections.  
I was responsible for **both firmware and PCB design**, delivering a fully functional, production-ready prototype.

---

## 🎯 Project Objectives
- Develop a **wireless bridge** to replace the standard wired RS-422 or Ethernet connection between **Sony RCP** and **camera**.  
- Ensure **low-latency**, **high-reliability communication** comparable to a wired setup.  
- Build a **compact, cost-effective solution** without relying on Ethernet hardware.  
- Enable **debugging and diagnostics** via USB interface for testing and maintenance.  

---

## 👨‍💻 My Contributions
- Designed and implemented the complete **firmware in C** using **STM32CubeIDE** for the **STM32H7 microcontroller**.  
- Developed communication protocol handling for **RS-422 ⇄ UART conversion** and **wireless packet management**.  
- Integrated and configured the **pX2 radio module** for reliable data transmission.  
- Designed the **custom high-speed PCB** using **EasyEDA**, including RS-422 transceivers and power regulation circuits.  
- Implemented **USB debug and logging interface** for real-time system monitoring.  
- Performed **bench testing and validation** to ensure robust communication and performance under load.  

---

## 🛠️ Technologies and Tools Used
- **Microcontroller:** STM32H7 (ARM Cortex-M7)  
- **Wireless Module:** pX2 Radio Module  
- **Communication Interfaces:** RS-422 ⇄ UART, USB (CDC/Serial)  
- **Firmware Development:** STM32CubeIDE (C Programming)  
- **PCB Design:** EasyEDA  
- **Testing & Simulation:** Bench testing on custom hardware  

---
