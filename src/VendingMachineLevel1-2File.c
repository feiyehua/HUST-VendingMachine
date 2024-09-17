/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:44:51
 * @LastEditTime : 2024-09-17 23:57:51
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachineLevel1-2File.c
 *      © 2024 FeiYehua
 */

#include<stdio.h>
int price,total;
int main()
{
    freopen("Level1-2.in","r",stdin);
    freopen("Level1-2.out","w",stdout);
    printf("请输入总价\n");
    scanf("%d",&price);
    if(payItem(price,&total)!=0)
    {
        return -1;
    }
    printf("完成投币，开始找零\n%d",total-price);
    return 0;
}