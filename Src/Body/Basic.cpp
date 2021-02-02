#include "../Header/Basic.hpp"

////通过坐标和百分数定义绘图区域和设置区域
//
//CanvasDrawL = (int)WINDOW_W * 0.000;
//CanvasDrawU = (int)WINDOW_H * 0.000;
//CanvasDrawR = (int)WINDOW_W * 1.000;
//CanvasDrawD = (int)WINDOW_H * 0.900;
//CanvasDrawNum = CanvasDrawR;
//
//
//SystemDrawL = (int)WINDOW_W * 0.000;
//SystemDrawU = (int)WINDOW_H * 0.901;
//SystemDrawR = (int)WINDOW_W * 1.000;
//SystemDrawD = (int)WINDOW_H * 1.000;
//
////本程序不再采用之前采用的全局刷新的策略，而改用局部刷新，挑战更多烧脑的地方
//
//CanvasDrawHRGN = CreateRectRgn(CanvasDrawL, CanvasDrawU, CanvasDrawR, CanvasDrawD);
//SystemDrawHRGN = CreateRectRgn(SystemDrawL, SystemDrawU, SystemDrawR, SystemDrawD);
//
////把复制份数作为全局变量
//
//DrawDuplicate = 0;
//#define DUPLICATE_SINGLE 1001
//#define DUPLICATE_SQUARE 1002
//#define DUPLICATE_MULTIPLY 1003
//
//CanvasOriginalDrawL = 0;
//CanvasOriginalDrawU = 0;
//CanvasOriginalDrawR = 0;
//CanvasOriginalDrawD = 0;
//CanvasOriginalDrawNum = 0;