/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 22:58:44
 * @LastEditTime : 2024-09-17 23:12:49
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-3.c
 *      © 2024 FeiYehua
 */
#include<stdio.h>
#include<AddItem.h>
#include<ItemInfo.h>
typedef enum {
    ERROR,
    SELL,
    EMPTY
} VendingMachineState;
VendingMachineState nextState(VendingMachineState currentState)
{
    switch(currentState)
    {
        case ERROR:
            return ERROR;
        case SELL:
            return SELL;
        case EMPTY:
        {
            printf("物品已经售空，请摆放货物");
            addItem(1);
        }
    }
}
int main()
{

    
    addItem(1);


}