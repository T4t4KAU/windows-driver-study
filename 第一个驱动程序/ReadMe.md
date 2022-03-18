默认情况下每个驱动程序都有一个叫作DriverEntry的入口点，可将DriverEntry当作驱动程序的"main"函数。这个函数会被系统线程在IRQL PASSIVE_LEVEL（0）上调用。有时候驱动程序须要卸载。
在那时，DriverEntry里做过的所有事必须被恢复原状。无法恢复的部分会产生泄露，在下一次重启之前，内核无法清除这些泄露。驱动程序可以拥有一个Unload例程，它会在驱动程序从内存中卸载时
自动得到调用。必须使用驱动程序对象的DriverUnload成员来设置指向这个例程的指针。Unload例程接受驱动程序对象(与传给DriverEntry的是同一个)并返回void。由于sample驱动程序在
DriverEntry里并未分配任何资源所以Unload例程里就没有什么要做的。

#regedit.png -- 在注册表中添加键值
#cmd.png -- 命令行启动服务
#debug_view.png -- 打印结果
#view.png -- 查看进程
