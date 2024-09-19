/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:44:46
 * @LastEditTime : 2024-09-19 23:29:05
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : StateMachine.c
 *      © 2024 FeiYehua
 */
//这是状态机的核心实现代码。
#include<stdio.h>
#include"StateMachine.h"
#include"BuyItem.h"
#include"Pay.h"
#include"AddItem.h"
#include"CheckIfEmpty.h"
VendingMachineState nextState(VendingMachineState currentState,int cfg)//状态机的状态转移函数
{
    switch(currentState)
    {
        case ADD:
        {
            if(addItem(cfg)!=0)
            {
                printf("输入内容错误！\n");
                return ADD;
            }
            return BUY;//加入完成后，跳转到让用户购买的状态
        }
        case BUY:
        {
            int totalPrice=0;
            if(buyItem(&totalPrice,cfg)!=0)
            {
                return BUY;
            }
            if(payItem(totalPrice,cfg)!=0)
            {
                return BUY;
            }
            if(checkIfEmpty()==0)
            {
                printf("货物已售空，欢迎下次再来！\n");
                return END;//如果售空，则结束程序
            }
            return BUY;//没有售空时，继续允许用户购买
        }
        case END:
            return END;//END状态时，状态机直接退出，此语句不会执行
    }
}