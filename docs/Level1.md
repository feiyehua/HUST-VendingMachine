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

## 状态机
