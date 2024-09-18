/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 22:58:44
 * @LastEditTime : 2024-09-18 16:53:50
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-3.c
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
    VendingMachineState state = ADD;
    while(state!=END)
    {
        state=nextState(state);
    }
    return 1;
}