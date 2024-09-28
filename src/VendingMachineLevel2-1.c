/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:49:34
 * @LastEditTime : 2024-09-28 22:17:22
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel2-1.c
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
        state=nextState(state,2);//状态设置为2，处理单次多个购买、摆放
    }
    return 0;
}