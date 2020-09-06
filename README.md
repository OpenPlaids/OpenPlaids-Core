# DiskRedeemer

编译指南与文档
Complie Guide & Docs
中文版
zh_CN

## 前言
这玩意折腾起来非常麻烦！！！
不能同时把四个头文件都记在脑袋里的不建议使用本项目！！！
（也是为了源代码闭包做的无奈之举，避免对源代码的修改）

## 编译说明
本程序应分为两部分进行编译
第一部分先编译INIwriter
第二部分编译主程序
//我一开始是希望主程序在运行伊始可以自解压释放出INIwriter，后来发现这不可行
请您依次在ComplierControl.h中分别保留DiskRedeemer_INIwriter和DiskRedeemer_OpenMP
并注意保存每次编译的文件

## 编译参数

### 跨平台编译
#### Windows下的编译（VS2017+MSVC）
测试环境为Microsoft Windows 10 家庭中文版 10.0.18362 x Intel Core i7-8750HQ
测试的软件环境为Visual Studio 15.9.19
将OS.h中保留且仅保留
#### Linux下的编译（GUN-gcc）
测试环境为CentOS Linux 7 x  Intel(R) Xeon(R) Platinum 8163 CPU
测试的软件环境为gcc-4.8.5-39.el7.x86_64
另外，因为这个程序的主程序启用了OpenMP优化，若您的编译器不支持OpenMP，请您
因Linux下的可执行文件为elf文件，故我们推荐您用gcc main.c -o DiskRedeemer.elf
#### 其他平台下的编译
我们暂时没有方法测试，您可以启用OS.h中的define SYSTEM_OTHERS

### 跨语言编译控制
要控制在不同语言下的编译，请直接在language.h中保留且仅保留所编译语言的define不被注释

### 模式控制编译
本程序提供以下几个模式控制宏定义
#### ScenariosControl.h
要控制在不同场景下的编译，请直接在ScenariosControl.h中保留且仅保留所编译场景的define不被注释
MODE_MILD //如果需要面向用户作为辅助工具使用，请您取消这一行的注释并注释MODE_VIOLENT，默认未注释，该选项或许会轻微影响性能，但将会较为可控和安全
MODE_VIOLENT //如果需要启动破坏性的写入策略或作为惩罚性程序，请您取消这一行的注释并注释MODE_MILD，默认被注释
#### ComplierControl.h
要控制在不同参数下的编译，请直接在ComplierControl.h中保留且仅保留所编译参数的define不被注释
DEBUG //如果需要开启DEBUG模式，您可以在编译时启用这一项来生成测试版，以保证release的版本中不含有冗余的内容，默认未注释
OpenMP_AVAILABLE //如果您的编译器不支持OpenMP，您可以在编译时启用这一项来生成未启用多线程优化的版本以保证能够正常编译，默认未注释。另外请您注意，使用MSVC时OMP优化不能在64位下启动

