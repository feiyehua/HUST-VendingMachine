/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:51:08
 * @LastEditTime : 2024-09-18 22:41:47
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel2-2.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"AddItem.h"
#include"GlobalVariables.h"
#include"BuyItem.h"
#include"Pay.h"
#include"StateMachine.h"
#ifdef _WIN32
#include<windows.h>
#endif
int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    VendingMachineState state = ADD;
    while(state!=END)
    {
        state=nextState(state,3);//状态设置为3，添加回退功能
    }
    return 0;
}