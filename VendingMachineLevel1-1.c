/*
 * @Author       : FeiYehua
 * @Date         : 2024-09-16 23:16:13
 * @LastEditTime : 2024-09-17 00:06:11
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : VendingMachine.c
 *      © 2021 FeiYehua
 */
#include<stdio.h>
struct itemInfo{
    char name;//货物的名称
    //int place; //货物的位置
    int price;
    int quan;//货物的价格和数量
}vendingMachineItem[30];//使用一个结构体存储售货机的物品数量,数组下标为位置
int main()
{
    for(int i=1;i<=29;i++)
    {
        vendingMachineItem[i].quan=0;
    }
    int n=0;//n表示物品的种类种数
    printf("请输入物品总数\n");
    scanf("%d",&n);
    printf("请依次输入货物的名称、位置、单价、数量，每行输入一种商品的信息\n");
    for(int i=1;i<=n;i++)
    {
        char name=0;
        int place,quan,price;
        getchar();
        scanf("%c%d%d%d",&name,&place,&price,&quan);
        vendingMachineItem[place].name=name;
        vendingMachineItem[place].price=price;
        vendingMachineItem[place].quan=quan;
    }
    for(int i=1;i<=29;i++)
    {
        if(vendingMachineItem[i].quan==0)//如果货架上无货，则不输出
        {
            continue;
        }
        else{//输出货架上的货物信息
            printf("%d: ",i);
            for(int j=1;j<=vendingMachineItem[i].quan;j++)
            {
                printf("%c",vendingMachineItem[i].name);
            }
            printf(" %d\n",vendingMachineItem[i].price);
        }
    }
    return 0;
}
/*
A 3 5 7
B 2 4 6
C 1 2 4
F 5 6 7
T 11 9 10
*/