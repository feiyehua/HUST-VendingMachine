/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-17 12:44:51
 * @LastEditTime : 2024-09-17 12:44:53
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
    while(total<price)
    {
        int n=0;
        scanf("%d",&n);
        if(n!=1&&n!=2&&n!=5)
        {
            printf("投入金额错误");
        }
        total+=n;
    }
    printf("完成投币，开始找零\n%d",total-price);
    return 0;
}