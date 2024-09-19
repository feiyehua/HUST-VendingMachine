/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 22:58:44
 * @LastEditTime : 2024-09-19 14:48:21
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-3.c
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
        state=nextState(state,1);//将状态机配置为1，只处理一次摆放、单个商品购买
    }
    return 1;
}