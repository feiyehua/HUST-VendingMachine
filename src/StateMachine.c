/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:44:46
 * @LastEditTime : 2024-09-19 17:52:06
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
VendingMachineState nextState(VendingMachineState currentState,int cfg)
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
            return BUY;
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
            return BUY;
        }
        case END:
            return END;
    }
}