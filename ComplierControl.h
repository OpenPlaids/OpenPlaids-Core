#pragma once

//本文件作用为起到一个通用的将多个平台提供的头信息转化为一个本程序内部用较为易懂的语言写成的接口
//开发者无需记忆各种繁杂的头文件预处理指令，只需要负责

//
//BASIC
//默认不手工开启
//部分内容可在后文中自动定义
//

#ifdef _DEBUG
#define DEBUG
#endif

#ifdef _RELEASE
#define RELEASE
#endif

//#define DEBUG
//#define DEBUG_ARGUMENT
//#define RELEASE
//#define PUBLISH
//#define OpenMP_AVAILABLE //开OMP
//#define SDL_AVALIABLE  //开C++11的sdl检查，目前仅支持MSVC

//
//MODE
//默认手工开启
//

#define MODE_MILD     //稳一点，先过
//#define MODE_VIOLENT//激进主义，将采用更多可能的人工智能
//#define MODE_ARGUMENT//传参

//
//SYSTEM
//默认不手工开启
//采用检测头文件中定义的方式来自动化定义系统控制
//

#ifdef _WIN32
#ifndef SYSTEM_WINDOWS
#define SYSTEM_WINDOWS
#endif // !SYSTEM_WINDOWS
#endif // _WIN32_WINNT

#ifdef linux
    #define SYSTEM_LINUX
#endif // linux

#ifdef __sun
    #define SYSTEM_SOLARIS
#endif // __sun

//#define SYSTEM_WINDOWS
//#define SYSTEM_LINUX
//#define SYSTEM_UNIX
//#define SYSTEM_MACOS
//#define SYSTEM_IPADOS
//#define SYSTEM_SOLARIS
//#define SYSTEM_OTHERS
//#define SYSTEM_MCU //单片机

//
//COMPLIER
//默认不手工开启
//通过各种标记进行检测
//

#ifdef _MSC_VER
#define SYSTEM_WINDOWS
#if _MSC_VER>=1800 //MSVC++ 12.0 (Visual Studio 2013 version 12.0) and after
#ifndef SDL_AVALIABLE
#define SDL_AVALIABLE
#endif
#else if _MSC_VER<=1200 //MSVC++ 6.0 (Visual Studio 6.0 version 6.0) and before
#define VC6_0
#endif
#endif
#else
#endif // _MSC_VER

//#define 

//
//LANGUAGE
//默认手工开启
//在考虑如何根据系统环境以及头文件来检测语言，可能比较困难，初步人工指定
//

#define zh_CN
#define LANGUAGE_zh_CN
//#define en_US
//#define LANGUAGE_en_US
//#define ja_JP
//#define LANGUAGE_ja_JP
//#define LANGUAGE_OTHERS

//
//REFERENCE
//

//https://docs.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt?view=vs-2019
//https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B