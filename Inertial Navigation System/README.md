# Inertial Navigation System (INS) Development and Testing  

When I joined the **Inertial Navigation group in 2011**, the team was working with a legacy INS prototype originally designed for a **low-orbit satellite launch vehicle**. Although stable, the system had several limitations that needed to be addressed for future programs.  

## Legacy System Limitations  

1. **Gyroscope availability** – The system used **Dynamic Tuned Gyroscopes (DTGs)**, which were no longer in production.  
2. **Limited ADC resolution** – The signal conditioning stage relied on a **12-bit ADC**, restricting overall navigation accuracy.  
3. **Obsolete processor** – The system was based on an **ADSP (Analog Devices DSP)**, which was no longer available due to geopolitical restrictions.  

## My Contribution  

I began with **assembly and testing** tasks to fully understand the legacy INS before transitioning into new system development. My key contributions included:  

- **Gyroscope Rebalance Loop Circuitry**  
  - Designed a **new DTG rebalance loop** to replace the unavailable original solution.  
  - This work directly addressed the first major limitation of the legacy system.  

- **High-Resolution ADC Integration**  
  - The team had procured a **24-bit ADC**, but it had never been tested due to lack of software support.  
  - I independently wrote the **low-level driver**, validated its performance, and integrated it into the INS PCB.  
  - This significantly improved navigation accuracy by enhancing sensor data fidelity.  

- **Processor Migration (ADSP → PIC32)**  
  - Transitioned the prototype from **ADSP** to **PIC32** microcontrollers.  
  - Implemented embedded code to run **navigation algorithms developed in MATLAB**.  
  - Ensured real-time execution and compatibility with system hardware.  

## Outcome  

- Delivered a **modernized INS prototype** that resolved critical hardware and software limitations.  
- Improved **sensor accuracy and system reliability** through new ADC integration and control circuitry design.  
- Established a platform that became the foundation for subsequent programs, including:  
  - **Integrated Navigation System (INS + GPS)**  
  - **Fault-Tolerant Integrated Navigation System**  

## Technologies & Tools  

- **DTG Rebalance Loop Design**  
- **24-bit ADC driver development** (embedded C)  
- **PIC32 microcontroller firmware**  
- **MATLAB → Embedded C translation**  
- **System testing and validation**  
