# Data-Communication-Lab


📘 Overview

This repository contains various C and MATLAB implementations of core topics in Data Communication and Networking.
It includes practical simulations and algorithms for encoding schemes, error detection, bit/character stuffing, and IPv4 conversions. These implementations are designed for learning, experimentation, and demonstration of fundamental data communication principles.

💡 Features
🔢 Encoding Techniques (MATLAB)

NRZ-L Encoding – Non-Return to Zero Level encoding simulation

NRZ-I Encoding – Non-Return to Zero Inverted encoding simulation

Manchester Encoding – Synchronization-based binary encoding

Differential Manchester Encoding – Edge-based transition signaling

AMI Encoding – Alternate Mark Inversion encoding

Pseudoternary Encoding – Ternary line coding scheme

🧮 Error Detection (C)

CRC Generation & Verification – Polynomial-based error detection

Parity Check – Single-bit error detection technique

Polynomial CRC – Custom CRC computation using generator polynomials

🧱 Data Stuffing (C)

Character Stuffing & Destuffing – Frame boundary preservation for byte-oriented protocols

Bit Stuffing & Destuffing – Data transparency in bit-oriented protocols

🌐 IPv4 Conversions (C)

Binary to Decimal Conversion – Converts IPv4 binary address to decimal format

Decimal to Binary Conversion – Converts IPv4 decimal address to binary format

🧰 Tools and Languages

MATLAB (.m) – For signal visualization and encoding scheme analysis

C Programming (.c) – For algorithmic and bitwise operations in data transmission

📁 File Structure
📂 DataComm-Algorithms
├── AMI_Encoding_In_Matlab.m
├── Manchester_in_matlab.m
├── Differential_manchester_in_Matlab.m
├── NRZ_L_in_matlam.m
├── NRZ_I_in_matlab.m
├── Pseudoternary.c
├── CRC_Generation_and_Error_Detection_In_C.c
├── CRC_Verification_at_Receiver_Side.c
├── Polynomial_CRC_in_C.c
├── Parity_Check_in_c.c
├── Character_stuffing_destuffing.c
├── Bit_Stuffing_Destuffing.c
├── IPV4_Binary_To_Decimal_in_C.c
├── IPV4_Decimal_To_Binary_in_C.c
└── Lab_Manual_1

🚀 How to Run
🧩 For MATLAB Files

Open MATLAB.

Load the .m file (e.g., Manchester_in_matlab.m).

Run the script to visualize the signal encoding.

⚙️ For C Files

Use any C compiler (e.g., Code::Blocks, GCC).

Compile using:

gcc filename.c -o output
./output


Input test data when prompted to observe results.

📚 Learning Objectives

Understand digital line coding techniques.

Explore error detection mechanisms (CRC, Parity).

Analyze bit/character stuffing in communication frames.

Implement IPv4 data conversion logic.

👩‍💻 Contributors

Developed by: Nadia Akter Eshita
Department: Computer Science and Engineering (CSE)
Institution: Green University of Bangladesh
