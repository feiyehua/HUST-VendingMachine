# HUST-VendingMachine
This project is written for HUST Dian Team Recruitment(Autumn 2024). 
This project is intended for Chinese reviewers, so all documents and annotations are in Chinese.

# Build 
This project uses CMake to configure build task.

Configure with CMake, run `make` in `build/`, and executables for all levels are placed in `build/` .

You can also build the project using VSCode (with CMake extension) .

# Learning Notes
Learning notes are placed in `docs/` .

# Debug
Please add `add_definitions(-D_DEBUG_)`to CMakeList.txt. The programe will print debug info.

# About file operations in Level 1-2
Please put your input file to `build/`, and rename it to `Level1-2.in` (Make sure it's plain text!) 

Then `cd build && ./VendingMachineLevel1-2File`, the output will be print in `build/Level1-2.out` .