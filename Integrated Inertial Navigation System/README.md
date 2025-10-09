# Integrated Navigation System (INS) Development (2018)  

This project focused on developing an **Integrated Inertial Navigation System (INS + GPS)**, a key step in advancing the navigation capabilities of future space programs.  

## Background  

By 2018, the integration of **GPS with INS** was already common in major space agencies. However, our team faced significant constraints:  

- **High-Dynamic GPS Receivers** – Required for launch vehicles, but procurement was not possible due to **cost** and **ITAR restrictions**.  
- **Local Receiver Development** – Until 2018, our agency’s in-house GPS receiver team was not mature enough to produce a fully qualified solution.  

Recognizing that GPS receivers would eventually become available, our group began work on an **integrated INS prototype** that could:  
- Provide a standalone **inertial solution** when GPS is unavailable.  
- Seamlessly switch to a combined **INS + GPS integrated solution** when GPS is available.  

## My Contribution  

I was responsible for two critical areas of development:  

- **PCB Design for System Integration**  
  - Designed the hardware interface PCB essential for integrating GPS with the INS core system.  
  - Ensured clean signal routing and minimal latency between inertial sensors, GPS interface, and processor.  

- **Firmware Implementation**  
  - Translated **navigation algorithms developed in MATLAB** into **embedded C** for the **PIC32 microcontroller**.  
  - Implemented real-time data fusion logic to integrate inertial sensor data with GPS updates.  
  - Optimized code for deterministic execution and robustness in edge cases (e.g., GPS dropouts).  

## Outcome  

- Successfully delivered a **working Integrated INS prototype**, capable of operating in both standalone and integrated modes.  
- Established the foundation for future projects once indigenous high-dynamic GPS receivers became available.  
- Strengthened agency expertise in **sensor fusion and embedded real-time navigation software**.  

## Technologies & Tools  

- **PIC32 microcontroller** (Embedded C)  
- **MATLAB-to-C algorithm translation**  
- **Navigation algorithm integration**  
- **Custom PCB design for INS + GPS interface**  
