/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-18 12:44:46
 * @LastEditTime : 2024-09-19 11:00:17
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : StateMachine.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include"StateMachine.h"
#include"BuyItem.h"
#include"Pay.h"
#include"AddItem.h"
VendingMachineState nextState(VendingMachineState currentState,int cfg)
{
    switch(currentState)
    {
        case ERROR:
        {
            return END;
        }
        case SELL:
        {
            /*printf("请选择要进行的操作\n");
            printf("1.摆放\n");
            printf("2.购买\n");
            printf("0.退出\n");
            int ope=0;
            scanf("%d",&ope);
            switch(ope)
            {
                case 0:
                    return END;
                case 1:
                    return ADD;
                case 2:
                    return BUY;
                default:
                    return ERROR;
            }*/
           return BUY;
        }
        case ADD:
        {
            if(addItem(cfg)!=0)
            {
                printf("输入内容错误！\n");
                return ADD;
            }
            return SELL;
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
            return SELL;
        }
        case END:
            return END;
    }
}