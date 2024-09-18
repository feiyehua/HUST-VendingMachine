cmake_minimum_required(VERSION 3.5.0)
project(HUST-VendingMachine VERSION 0.1.0 LANGUAGES C)
include_directories(include)
add_executable(Level1-1 src/VendingMachineLevel1-1.c src/AddItem.c)
add_executable(Level1-2 src/VendingMachineLevel1-2.c src/Pay.c)
add_executable(Level1-2File src/VendingMachineLevel1-2File.c src/Pay.c)
add_executable(Level1-3 src/VendingMachineLevel1-3.c src/AddItem.c src/Pay.c src/BuyItem.c src/StateMachine.c)
add_executable(Level2-1 src/VendingMachineLevel2-1.c src/AddItem.c src/Pay.c src/BuyItem.c src/StateMachine.c)

