# Dynamic Tuned Gyroscope (DTG) Rebalance Loop Redesign (2011–2012)  

This project addressed a long-standing challenge faced by our Inertial Navigation System (INS) development team.  

## Background  

Dynamic Tuned Gyroscopes (DTGs) are essential sensors in an **Inertial Navigation System**. They provide a cost-effective alternative **Ring Laser Gyroscopes**, while still delivering the required performance for many aerospace and defense applications.  

A DTG sensor consists of two main parts:  
1. **The sensing element**  
2. **The rebalance loop with power supply circuitry**  

Our team procured DTG sensors from an international supplier. While the sensors themselves were reliable, the **rebalance loop circuitry provided by the manufacturer consistently failed to meet performance standards**.  

The supplier could only provide design changes at a significant cost, which was not feasible. Prior to my involvement, my seniors attempted to design a indgenious rebalance loop, but these efforts stalled due to limited insight into the sensor’s internal parameters. The project had been abandoned for about four years before I joined in 2011.  

## My Contribution  

When I took over, the prevailing belief was that the task was not achievable. I restarted the project from scratch with the following approach:  

- **Reverse Engineering the Manufacturer’s Card**  
  - The manufacturer’s card was essentially a black box, but by probing its connectors, I identified three distinct functional sections:  
    1. **Three-phase power supply**  
    2. **Reference sine wave generator**  
    3. **Demodulation and feedback circuitry**  
  - Further testing revealed that the **primary issue lay within the demodulation and feedback section**.  

- **Understanding the Feedback Path**  
  - The DTG outputs a signal in the form of **AM modulation** at a predefined reference frequency.  
  - The rebalance loop must:  
    1. **Demodulate the signal** – Multiply the modulated output with the reference signal, then filter using a low-pass filter to extract the signal of interest.  
    2. **Filter and shape the response** – Pass through a series of high-pass/low-pass filters and a **notch filter** tuned to the DTG’s natural frequency.  
    3. **Control loop** – Apply **PID control** to stabilize and linearize the sensor response.  
    4. **Output stage** – Drive the gyroscope via a MOSFET-based output driver.  

- **Simulation and Validation**  
  - I **modeled the entire circuit in OrCAD** and conducted detailed **PSpice simulations** to validate stability, frequency response, and noise performance.  
  - By tuning the notch filter and PID loop parameters, I was able to meet the system’s dynamic range and bandwidth requirements.  

## Outcome  

The redesigned rebalance loop successfully replaced the underperforming manufacturer’s circuitry. This solution eliminated the dependency on costly external redesigns and demonstrated that **local engineering efforts could overcome proprietary design barriers**.  

This project not only solved a critical technical challenge for our INS program but also set the foundation for **future in-house development of gyroscope support electronics**.  
  
 