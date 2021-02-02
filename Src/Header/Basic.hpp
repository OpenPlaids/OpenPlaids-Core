#pragma once

#include "../Header/Include.hpp"

#define WINDOW_W 900*0.5
#define WINDOW_H 1000*0.5

////通过坐标和百分数定义绘图区域和设置区域
//
//int CanvasDrawL;
//int CanvasDrawU;
//int CanvasDrawR;
//int CanvasDrawD;
//int CanvasDrawNum;
//
//
//int SystemDrawL;
//int SystemDrawU;
//int SystemDrawR;
//int SystemDrawD;
//
////本程序不再采用之前采用的全局刷新的策略，而改用局部刷新，挑战更多烧脑的地方
//
//HRGN CanvasDrawHRGN;
//HRGN SystemDrawHRGN;
//
////把复制份数作为全局变量
//
//int DrawDuplicate;
//#define DUPLICATE_SINGLE 1001
//#define DUPLICATE_SQUARE 1002
//#define DUPLICATE_MULTIPLY 1003
//
//int CanvasOriginalDrawL;
//int CanvasOriginalDrawU;
//int CanvasOriginalDrawR;
//int CanvasOriginalDrawD;
//int CanvasOriginalDrawNum;

//通过坐标和百分数定义绘图区域和设置区域

extern int CanvasDrawL = (int)WINDOW_W * 0.000;
extern int CanvasDrawU = (int)WINDOW_H * 0.000;
extern int CanvasDrawR = (int)WINDOW_W * 1.000;
extern int CanvasDrawD = (int)WINDOW_H * 0.900;
extern int CanvasDrawNum = CanvasDrawR;


extern int SystemDrawL = (int)WINDOW_W * 0.000;
extern int SystemDrawU = (int)WINDOW_H * 0.901;
extern int SystemDrawR = (int)WINDOW_W * 1.000;
extern int SystemDrawD = (int)WINDOW_H * 1.000;

//本程序不再采用之前采用的全局刷新的策略，而改用局部刷新，挑战更多烧脑的地方

HRGN CanvasDrawHRGN = CreateRectRgn(CanvasDrawL, CanvasDrawU, CanvasDrawR, CanvasDrawD);
HRGN SystemDrawHRGN = CreateRectRgn(SystemDrawL, SystemDrawU, SystemDrawR, SystemDrawD);

//把复制份数作为全局变量

extern int DrawDuplicate = 0;
#define DUPLICATE_SINGLE 1001
#define DUPLICATE_SQUARE 1002
#define DUPLICATE_MULTIPLY 1003

extern int CanvasOriginalDrawL = 0;
extern int CanvasOriginalDrawU = 0;
extern int CanvasOriginalDrawR = 0;
extern int CanvasOriginalDrawD = 0;
extern int CanvasOriginalDrawNum = 0;