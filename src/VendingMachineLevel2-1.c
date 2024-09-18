/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:49:34
 * @LastEditTime : 2024-09-18 12:49:36
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel2-1.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"AddItem.h"
#include"ItemInfo.h"
#include"BuyItem.h"
#include"Pay.h"
#include"StateMachine.h"
int main()
{
    VendingMachineState state = SELL;
    while(state!=END)
    {
        state=nextState(state);
    }
    return 1;
}