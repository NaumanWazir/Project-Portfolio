# 🚜 Wireless Remote-Control Trailer Dolly (EEZImover)

## 🎯 Project Objective  
The **EEZImover** is a **wireless remote-control trailer dolly** developed for a **Canadian client** to enable effortless and precise trailer maneuvering.  
The objective was to design a **robust ESP32-based control system** capable of smooth wireless driving, motor control, and safe operation under varying load and terrain conditions.  
*(Source code not disclosed due to NDA agreement.)*  

---

## 💡 My Contributions  
- Designed and implemented the **firmware architecture** for the ESP32 acting as both **Bluetooth central** and **motion control unit**.  
- Integrated **wireless gamepad communication** for intuitive throttle and steering control.  
- Developed **serial communication protocols** between ESP32 and **Sabertooth 2x60 dual motor driver**.  
- Implemented **PWM-based speed ramping** for soft acceleration and braking.  
- Added **failsafe and safety interlocks** to stop motion automatically if the wireless link is lost.  
- Validated the complete control logic through simulation and real-hardware testing.  

---

## 🧰 Technologies & Tools Used  
- **Microcontroller:** ESP32  
- **Motor Driver:** Sabertooth 2x60 Dual Motor Controller  
- **Communication:** Bluetooth (gamepad) and UART (motor control)  
- **IDE:** Arduino IDE  
- **Programming Language:** C / C++ (Arduino Framework)  

---

🔒 *Confidential commercial project – developed under NDA. Source code cannot be shared.*  
🔗 [Official Product Website](https://eezimover.com/)
