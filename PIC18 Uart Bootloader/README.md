# 🔄 PIC18 UART Bootloader

This project involved the development of a **custom UART bootloader** for the **PIC18F microcontroller**, enabling **in-field firmware programming** using another MCU — specifically an **ESP32** — instead of a PC.  
It was developed for a **client in the USA** who needed a simplified, MCU-controlled version of Microchip’s standard UART bootloader.

---

## 🎯 Project Objectives

- Design a **lightweight and standalone UART bootloader** for the PIC18F microcontroller.  
- Enable **firmware updates directly from an embedded controller (ESP32)** without requiring direct connection to a PC.  
- Maintain **reliability and simplicity** of the bootloading process using UART communication.  
- Provide a **testing and demonstration tool** using a Visual Studio–based GUI.  

---

## 🧩 My Contributions

- Developed a **custom UART bootloader firmware** for the PIC18F series using **MPLAB X IDE**.  
- Created a **compact communication protocol** between the ESP32 and PIC18F for firmware transfer and verification.  
- Implemented **flash memory write routines** and automatic application launch after programming.  
- Designed a **C# PC GUI tool in Visual Studio** for testing and demonstrating the bootloader operation.  
- Validated the complete system through **Proteus simulation**.  

---

## 🧰 Technologies and Tools Used

| Tool / Component | Purpose |
|------------------|----------|
| **Microcontroller** | PIC18F Series |
| **Host Controller** | ESP32 (for bootloading via UART) |
| **Communication Protocol** | UART |
| **IDE** | MPLAB X with XC8 Compiler |
| **PC Application** | Visual Studio (C#) for GUI-based testing |
| **Simulation Tool** | Proteus Design Suite |

---

