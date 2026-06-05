# Large Language Model (LLM) Protection using ZEDAC

## Overview

This project demonstrates the application of the **ZEDAC-based protection framework** for safeguarding **Large Language Models (LLMs)** against memory corruption.

It extends the concepts used in the AI model protection and voter module work, applying them to a deployed LLM running on **NVIDIA Jetson Orin Nano**.

The system uses **TinyLlama** executed through **llama.cpp (C/C++ backend)** and provides a ChatGPT-like interface via a **Flask-based web application**.

## My Role

* Integrated **TinyLlama model (llama.cpp backend)** on NVIDIA Jetson Orin Nano
* Extended ZEDAC-based protection concepts to LLM inference pipelines
* Developed Flask-based **interactive chat interface**
* Demonstrated impact of memory corruption on LLM behavior
* Integrated fault injection to simulate model degradation

## Features

* Deployment of **TinyLlama LLM on embedded GPU platform (Jetson Orin Nano)**
* ChatGPT-like user interface using **Flask web framework**
* Integration with **C/C++ based llama.cpp inference engine**
* Fault injection mechanism to simulate memory corruption
* ZEDAC-based protection applied to model memory regions
* Real-time comparison between:

  * Clean model execution
  * Corrupted model execution

## Observed Behavior

* Without corruption, the model produces stable responses and typically completes inference without reaching maximum token limits
* With injected memory corruption:

  * Output quality degrades significantly
  * Model generates incoherent or “gibberish” responses
  * Token usage increases abnormally due to unstable generation behavior

## Outcome

* Demonstrated the sensitivity of **LLM inference to memory-level corruption**
* Validated applicability of **ZEDAC-based protection techniques for generative AI models**
* Provided a working framework to observe and analyze corruption effects in real time
* Established a baseline for future research in **fault-tolerant LLM deployment on edge devices**
