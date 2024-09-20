# Level1 学习笔记
## 管理和编译含有多个.c文件的工程
在Level1中，考虑到后续Level中还会用到摆放货物等功能，所以将相关函数放到了一个单独的.c文件中，方便后续的调用。
一般来说，项目的组织结构为：

```
project\
    include\
        a.h
        b.h
    src\
        a.c
        b.c
    readme.md
```

此时，我们将gcc的编译指令改为：`gcc -I./include a.c -o a`，即可正常编译。
不过在重新编译时，收到提示：

```Undefined symbols for architecture arm64:
  "_addItem", referenced from:
      _main in VendingMachineLevel1-1-78b716.o

ld: symbol(s) not found for architecture arm64

clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

查阅相关资料，了解到编译器并不会自动将主执行文件中引用的头文件中声明、并在另一个C文件中定义的函数链接到可执行文件中，因此出现了链接错误的提示。

因此，将编译命令修改为`gcc -I./include a.c b.c -o a`，其中b.c包含了b.h中声明的函数的定义。

## 使用CMake配置自动化编译
由于项目有一定规模，涉及到多个C文件的编译，所以采用了CMake配置自动化编译。
CMake的核心文件是CMakeList.txt。
我的CMakeList.txt：
```
cmake_minimum_required(VERSION 3.5.0)
project(HUST-VendingMachine VERSION 0.1.0 LANGUAGES C) //这是项目的名称
include_directories(include) //include目录，相当于 -I./include
add_executable(VendingMachineLevel1-1 src/GlobalVariables.c src/VendingMachineLevel1-1.c src/AddItem.c)//编译指令，第一个参数是生成可执行文件的名称，后面的参数是所用到的c文件。
```
使用VSCode的CMake插件创建CMakeList.txt并配置好后，在build目录中`make`即可编译出可执行文件。

## 状态机
我所理解的状态机是经过优化，使代码可读性、可维护性更强的大模拟。

在我的程序中，给售货机的工作设置成为了状态机。该状态机有
    BUY,
    ADD,
    END
三个状态。初始状态为ADD，需要用户摆放货物。如果摆放出错，会继续要求用户摆放；摆放成功，则进入BUY状态，要求用户购买。END为程序退出点。

~~本来希望用状态机实现更加复杂的状态转换的，比如在收货状态时进行补货。不过按照题目要求砍掉了这个功能~~

