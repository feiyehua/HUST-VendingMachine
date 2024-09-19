/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:49:34
 * @LastEditTime : 2024-09-18 22:14:54
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
int main()
{
    VendingMachineState state = ADD;
    while(state!=END)
    {
        state=nextState(state,2);//状态设置为2，处理单次多个购买、摆放
    }
    return 1;
}