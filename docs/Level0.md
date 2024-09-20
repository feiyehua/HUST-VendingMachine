# Level0 学习记录
一般来说，我们可以用如下命令将一个.c文件编译为可执行文件：

`gcc hello.c -o hello`

将一个.c文件编译成一个可执行文件具体分为4步：
## 第一步 预处理
命令：`gcc -E hello.c -o hello.i`

预处理中，编译器处理预处理命令（一般#开头。）

`#include`:将include的头文件内容复制进入输出的文件中

`//，/* */`:删除注释

`#define`:展开宏

如，原代码为：

test.h：

```
/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-09-20 12:26:47
 * @LastEditTime : 2024-09-20 12:26:48
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : test.h
 * @     © 2024 FeiYehua
 */

int hello()
{
    int a=0;
}
```

test.c：
```
/*
 * @Author       : FeiYehua
 * @Date         : 2024-08-29 17:06:19
 * @LastEditTime : 2024-09-20 12:26:42
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : test.c
 *      © 2024 FeiYehua
 */
#include"test.h"
//using namespace std;
#define test TEST
int main()
{
    #if 0
    char a[100]; 
    #endif 
    //printf("进行购买操作\n请输入需要购买");
    int test=0;
    //scanf("%*c %*d %d",&num);
    //printf("%d",num);
    //test
    return 0;
}
```

处理后：
```
# 1 "test.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 424 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "test.c" 2
# 10 "test.c"
# 1 "./test.h" 1
# 11 "./test.h"
int hello()
{
    int a=0;
}
# 11 "test.c" 2


int main()
{




    int TEST=0;



    return 0;
}

```

## 第二步 编译
命令：`gcc -S test.i -o test.s`

编译时，编译器将上一步展开的代码转换为汇编代码。
如
test.i
```
# 1 "test.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 424 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "test.c" 2
# 13 "test.c"
int main()
{
    int a=0,b=1;
    int c=a+b;
    return 0;
}
```

test.s
```
	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 0
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	mov	w0, #0                          ; =0x0
	str	wzr, [sp, #12]
	str	wzr, [sp, #8]
	mov	w8, #1                          ; =0x1
	str	w8, [sp, #4]
	ldr	w8, [sp, #8]
	ldr	w9, [sp, #4]
	add	w8, w8, w9
	str	w8, [sp]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols

```
汇编代码的阅读在此不作详述。

## 第三步 汇编

汇编将汇编代码转换为机器码，命令为：

`gcc -c test.s -o test.o`

## 第四步 链接

链接器将多个编译出来的.o文件链接，最终生成可执行的二进制文件。

如，当涉及到多个.c文件的编译时，就需要链接器才能将c文件之间的函数链接起来，最终生成完整的可执行文件。

命令为：

`gcc test.o -o test`