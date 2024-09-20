# Level2 学习笔记
## 使用fgets、sscanf实现整行字符串读入与解析
与scanf函数不同，使用fgets获取整行输入、再使用sscanf解析读入的字符串能更好地应多不确定的用户输入，可以很好地处理Level2中出现的END、BACK字符串。

fgets：传入的第一个参数为字符数组，第二个参数为最大的输入长度，第三个参数为输入流（一般为stdin）。

sscanf：第一个参数为字符串，第二、三个参数与scanf相似。

## 多文件项目中的全局变量

在Level2-2中，我使用了一个数组来处理撤销功能：
```
int lastLoc[4]={0,3,1,2};
int nextLoc[4]={1,2,3,1};
```

一开始，我将该变量放在头文件中，在编译时收到提示：`duplicate symbol ...`

但是在旁边声明的变量`struct itemInfo vendingMachineItem[30]`并没有收到这个提示。

查阅资料了解到不能重复定义某个变量，但是可以重复声明。所以`struct itemInfo vendingMachineItem[30]`并没有定义变量，不会出现问题；而上述数组由于已经定义，出现了问题。

规范的做法是在h文件中声明（并使用extern关键字），在c文件中定义，这样才能避免重复定义的问题。