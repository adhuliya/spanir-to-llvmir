SPAN IR to LLVM IR
=======================

This is a project to convert the SPAN IR to LLVM IR using the LLVM API.


This project requires the following steps,
1. Manually migrate SPAN IR's Python implementation to C++.
2. Use LLVM API to convert each IR statement to the corresponding LLVM IR stmt.

We will most certainly incrementally develop each part.
