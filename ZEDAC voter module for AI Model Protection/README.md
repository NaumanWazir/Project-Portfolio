# ZEDAC Voter Module for AI Model Protection

## Overview

This project demonstrates the integration of a ZEDAC-based Error Detection and Correction (EDAC) system with an SPI-based hardware voter module to protect AI model integrity during inference.

The system is deployed on NVIDIA Jetson Orin Nano and focuses on safeguarding model files against memory corruption such as Single Event Upsets (SEUs). The project includes interactive demonstrations using handwritten digit recognition and YOLO-based object detection, where controlled faults are injected to visualize model degradation and recovery.

## My Role

As Research Manager at NTU, I was responsible for integrating proprietary ZEDAC EDAC software with the hardware voter module.

The EDAC software (v2) was already developed, but the team faced issues integrating the SPI-based voter module with the Jetson Orin Nano. I resolved these integration challenges and extended the system by developing two complete demonstration applications.

I also built the supporting software stack, including Python bindings for the ZEDAC C library and a web-based interface for real-time interaction.

## Features

* Integration of ZEDAC EDAC software with SPI-based voter hardware
* Deployment on NVIDIA Jetson Orin Nano
* AI model protection using parity generation and recovery
* Fault injection using random bit flips to simulate memory corruption
* Real-time visualization of inference degradation
* Model recovery using ZEDAC decoder
* Demonstration applications:

  * Handwritten digit recognition
  * YOLO-based object detection
* ZEDAC C library compiled as shared object (.so) and integrated with Python
* Interactive web interface using Flask

## Outcome

The project demonstrates a complete workflow for protecting AI models against memory corruption using EDAC and hardware redundancy.

Users can inject faults into the model, observe degradation in inference accuracy, and recover the model in real time using the ZEDAC decoding process.

This validates the feasibility of combining software-based EDAC with hardware voter mechanisms for reliable AI deployment in safety-critical environments such as space and automotive systems.

