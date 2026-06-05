# ZEDAC Algorithm Optimization and Performance Evaluation

## Overview

As a Research Manager at NTU, I worked on optimizing and benchmarking multiple versions of the **ZEDAC Error Detection and Correction (EDAC) algorithm**.

The work focused on improving performance and reliability by evaluating and implementing different ECC schemes, including **2D Block Hamming, BCH, and hybrid combinations of 2D Hamming with LDPC-style correction techniques**.

The optimized implementations were compared against the **Neil LDPC reference implementation** to evaluate trade-offs between performance and error correction capability.

## My Role

* Implemented and optimized multiple EDAC variants in C
* Designed and executed comparative analysis against LDPC baseline
* Developed automated testing framework using:

  * C-based test suites
  * Bash scripts for batch execution
  * Python scripts for result analysis and visualization
* Applied low-level software optimization techniques to improve execution efficiency

## Features

* Implementation of multiple ECC schemes:

  * 2D Block Hamming Code
  * BCH Code
  * Hybrid 2D Hamming + LDPC-style correction
* Performance optimization techniques:

  * Loop unrolling
  * Reduction of function call overhead
  * Elimination of expensive division operations where possible
* Automated testing pipeline across multiple configurations
* Comparative benchmarking against **Neil LDPC reference model**

## Optimization Strategy

* Reduced computational overhead in encoding and decoding loops
* Minimized redundant memory access and function calls
* Replaced expensive arithmetic operations with optimized equivalents
* Structured code for better cache efficiency and execution flow

## Outcome

* Achieved **LDPC-comparable error protection performance** with improved execution speed
* Demonstrated that optimized ZEDAC variants can balance **error correction strength and computational efficiency**
* Established a reproducible benchmarking framework for future ECC algorithm evaluation
