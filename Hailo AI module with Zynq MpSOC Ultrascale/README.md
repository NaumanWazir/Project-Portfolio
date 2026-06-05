# Hailo AI Module Integration with Zynq MPSoC Ultrascale

## Overview

As a Research Manager at NTU, I worked on integrating the **Hailo-8L AI accelerator module** with the **ZSOM-F01 platform based on Zynq MPSoC Ultrascale**.

The project involved both hardware-level debugging and software stack integration, ensuring successful detection and operation of the Hailo module within a PetaLinux environment. The work also included applying ZEDAC-based protection to safeguard model files and inference outputs.

## My Role

* Debugged hardware-level issue preventing **Hailo-8L detection on ZSOM-F01**
* Identified root cause as **missing PCIe clock termination resistor**
* Integrated **Hailo SDK into PetaLinux environment**
* Built and customized **PetaLinux image for hardware support**
* Developed and applied patches to enable stable system integration
* Created Python-based demonstration application for end-to-end validation

## Features

* Integration of **Hailo-8L AI accelerator with Zynq MPSoC Ultrascale platform**
* Full **PetaLinux SDK integration and customization**
* Hardware debug of **PCIe clock signal integrity issue**
* Kernel and system-level patching for hardware enablement
* Python-based inference demo application
* ZEDAC-based protection for:

  * Model files
  * Selected output image streams
* Multi-camera inference demonstration (3 image sources)

## Demonstration

* User runs inference using Hailo AI model on multiple camera inputs
* System executes model inference on Zynq + Hailo-8L pipeline
* ZEDAC protects both:

  * Model integrity during execution
  * Selected output frames from corruption

## Outcome

* Successfully enabled **Hailo-8L detection and operation on ZSOM-F01 platform**
* Resolved critical **hardware-software integration issue at PCIe interface level**
* Delivered a working **end-to-end AI inference demo system on embedded Linux**
* Demonstrated applicability of **ZEDAC protection in heterogeneous AI accelerator pipelines**
