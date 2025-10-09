# 🩺 Movesense Custom Firmware

This project was completed under a **Non-Disclosure Agreement (NDA)** for **Piksel, Italy** ([https://piksel.com/](https://piksel.com/)).  
It involved developing and customizing firmware for the **Movesense HR+ sensor**, a wearable device based on the **Nordic nRF52832 SoC**.

---

## 🎯 Project Objectives

The primary goal was to develop **custom firmware** enabling the Movesense HR+ to track and transmit **athlete motion** and **vital signs** in real time.  
The system fuses data from the **Inertial Measurement Unit (IMU)** — acceleration and gyroscope — with **heart rate monitoring**, providing accurate and continuous physiological and motion tracking.  

Data is transmitted wirelessly via **Bluetooth Low Energy (BLE)** to a **custom iOS application** for live monitoring, visualization, and recording.  
Each Movesense unit functions as a standalone, battery-powered sensor wearable on a **chest strap** for comfort and stability during athletic activity.

---

## 🧩 My Contributions

- Developed **custom Movesense firmware** using the **Movesense SDK** and **nRF5 SDK**.   
- Designed and tested **custom BLE data packet structures** for efficient and reliable transmission.  
- Enabled **multi-sensor synchronization** supporting up to **12 Movesense HR+ devices** simultaneously.  
- Collaborated with iOS developers to ensure seamless **BLE integration and data visualization**.  
- Optimized firmware for **low-power operation** and **stable multi-device communication**.  

---

## 🧰 Technologies and Tools Used

| Tool / Technology | Purpose |
|--------------------|----------|
| **Nordic nRF52832 (ARM Cortex-M4)** | Core SoC for Movesense HR+ |
| **Movesense SDK / nRF5 SDK** | Firmware development and sensor integration |
| **Bluetooth Low Energy (BLE)** | Wireless data transmission |
| **IMU (Accelerometer + Gyroscope)** | Motion and orientation sensing |
---

