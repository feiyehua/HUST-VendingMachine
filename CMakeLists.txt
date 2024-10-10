cmake_minimum_required(VERSION 3.5.0)
project(HUST-VendingMachine VERSION 0.1.0 LANGUAGES C)
include_directories(include)

add_executable(VendingMachineLevel1-1 src/GlobalVariables.c src/VendingMachineLevel1-1.c src/AddItem.c src/ShowItem.c)
add_executable(VendingMachineLevel1-2 src/GlobalVariables.c src/VendingMachineLevel1-2.c src/Pay.c)
add_executable(VendingMachineLevel1-2File src/GlobalVariables.c src/VendingMachineLevel1-2File.c src/Pay.c)
add_executable(VendingMachineLevel1-3 src/GlobalVariables.c src/VendingMachineLevel1-3.c src/AddItem.c src/Pay.c src/BuyItem.c src/StateMachine.c src/CheckIfEmpty.c src/ShowItem.c)
add_executable(VendingMachineLevel2-1 src/GlobalVariables.c src/VendingMachineLevel2-1.c src/AddItem.c src/Pay.c src/BuyItem.c src/StateMachine.c src/CheckIfEmpty.c src/ShowItem.c)
add_executable(VendingMachineLevel2-2 src/GlobalVariables.c src/VendingMachineLevel2-2.c src/AddItem.c src/Pay.c src/BuyItem.c src/StateMachine.c src/CheckIfEmpty.c src/ShowItem.c)

