# ZEDAC Runtime Memory Protection Library

## Overview

As a Research Manager at NTU, I developed a **runtime memory protection library** to extend the capabilities of the ZEDAC EDAC system.

While the existing ZEDAC library could protect files on storage media, it did not address **runtime memory (DDR)** vulnerabilities. This project focuses on protecting critical in-memory data such as **configuration parameters, AI model weights, and constants** during execution.

## My Role

* Designed and implemented a **real-time EDAC library in C** for runtime memory protection
* Extended ZEDAC capability from storage protection to **DDR memory protection**
* Defined architecture for **layered parity generation and recovery**
* Integrated external **TMR-based FRAM storage** for secure parity storage
* Implemented **background memory scrubbing mechanism**

## Features

* Protection of **static and semi-static data in runtime memory (DDR)**
* Configurable protection for **user-defined memory regions (8KB to 32KB blocks)**
* **Layered parity generation** for enhanced error detection and correction
* Support for **multi-bit error correction**
* **Hardware-independent implementation**
* **Radiation-resilient parity storage** using external TMR-protected FRAM
* **Background scrubbing** for continuous error detection and correction

## System Architecture

* Software EDAC Engine
* Layered Parity Generator
* External TMR FRAM Storage
* Background Scrubbing Scheduler

## Operation Flow

* User defines critical memory regions (e.g., model weights) via API
* EDAC engine computes layered parity
* Final parity layer stored in external TMR FRAM
* Background process periodically scans memory
* Errors are detected and corrected automatically

## Performance

* Supported memory protection granularity: **8KB to 32KB per region**
* Scalable to large datasets. Example: **2GB protection (decoding) completed in ~45 seconds (Raspberry Pi platform)**
* Error correction capability: **up to 300 bit errors in 2KB data**
* Memory overhead: **~35% for parity storage**
* CPU overhead: **low impact due to background execution model**

## Outcome

* Enabled **runtime memory protection** beyond storage-level EDAC
* Demonstrated reliable protection of **critical AI and configuration data in DDR**
* Achieved **high error correction capability under simulated fault conditions**
* Provided a scalable solution for **radiation-prone and safety-critical environments**
* Established foundation for **continuous memory scrubbing-based protection systems**
