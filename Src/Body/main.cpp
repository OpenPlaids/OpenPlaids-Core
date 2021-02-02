#define Easyx

#ifdef Easyx

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<easyx.h>
#include<graphics.h>
#include<time.h>
#include<math.h>

#include "../Header/Color.h"

int RandColorRGB(int * R, int * G, int * B);

#define WINDOW_W 900*0.5
#define WINDOW_H 1000*0.5

//通过坐标和百分数定义绘图区域和设置区域

int CanvasDrawL = (int)WINDOW_W * 0.000;
int CanvasDrawU = (int)WINDOW_H * 0.000;
int CanvasDrawR = (int)WINDOW_W * 1.000;
int CanvasDrawD = (int)WINDOW_H * 0.900;
int CanvasDrawNum = CanvasDrawR;


int SystemDrawL = (int)WINDOW_W * 0.000;
int SystemDrawU = (int)WINDOW_H * 0.901;
int SystemDrawR = (int)WINDOW_W * 1.000;
int SystemDrawD = (int)WINDOW_H * 1.000;

//本程序不再采用之前采用的全局刷新的策略，而改用局部刷新，挑战更多烧脑的地方

HRGN CanvasDrawHRGN = CreateRectRgn(CanvasDrawL, CanvasDrawU, CanvasDrawR, CanvasDrawD);
HRGN SystemDrawHRGN = CreateRectRgn(SystemDrawL, SystemDrawU, SystemDrawR, SystemDrawD);

//把复制份数作为全局变量

int DrawDuplicate = 0;
#define DUPLICATE_SINGLE 1001
#define DUPLICATE_SQUARE 1002
#define DUPLICATE_MULTIPLY 1003

int CanvasOriginalDrawL = 0;
int CanvasOriginalDrawU = 0;
int CanvasOriginalDrawR = 0;
int CanvasOriginalDrawD = 0;
int CanvasOriginalDrawNum = 0;

int InitDraw(int mode)
//mode干什么用还没定,先留着
{
	cleardevice();
	setfillcolor(RED);
	solidrectangle(CanvasDrawL, CanvasDrawU, CanvasDrawR, CanvasDrawD);
	setfillcolor(LIGHTGRAY);
	solidrectangle(SystemDrawL, SystemDrawU, SystemDrawR, SystemDrawD);
	int CanvasDraw(int mode);
	int SystemDraw(int mode);
	CanvasDraw(1);
	return 0;
}

int CanvasDraw(int mode)
{

	int DrawDuplicate = DUPLICATE_MULTIPLY;



	//int RandColorRGB(int R, int G, int B);
	int ParaVertTwiceDraw(int Begin, int End, COLORREF Color);
	//确定原本位置和大小
	if (DrawDuplicate == DUPLICATE_SINGLE)
	{
		CanvasOriginalDrawL = CanvasDrawL;
		CanvasOriginalDrawU = CanvasDrawU;
		CanvasOriginalDrawR = CanvasDrawR;
		CanvasOriginalDrawD = CanvasDrawD;
		CanvasOriginalDrawNum = CanvasOriginalDrawR;
	}
	else if(DrawDuplicate == DUPLICATE_SQUARE)
	{
		CanvasOriginalDrawL = CanvasDrawL;
		CanvasOriginalDrawU = CanvasDrawU;
		CanvasOriginalDrawR = (int)CanvasDrawR / 2;
		CanvasOriginalDrawD = (int)CanvasDrawD / 2;
		CanvasOriginalDrawNum = CanvasOriginalDrawR;
	}
	else if (DrawDuplicate == DUPLICATE_MULTIPLY)
	{
		CanvasOriginalDrawL = CanvasDrawL;
		CanvasOriginalDrawU = CanvasDrawU;
		CanvasOriginalDrawR = (int)CanvasDrawR / 3;
		CanvasOriginalDrawD = (int)CanvasDrawD / 3;
		CanvasOriginalDrawNum = CanvasOriginalDrawR;
	}
#ifdef DEBUG
	else
	{
		CanvasOriginalDrawL = CanvasDrawL;
		CanvasOriginalDrawU = CanvasDrawU;
		CanvasOriginalDrawR = (int)CanvasDrawR / DrawDuplicate;
		CanvasOriginalDrawD = (int)CanvasDrawD / DrawDuplicate;
		CanvasOriginalDrawNum = CanvasOriginalDrawR;
	}
#else
	else
	{
		printf("请检查您的配置文件，DrawDuplicate限制为1/2/3\n");
		exit(-1);
	}
#endif // DEBUG

#ifdef _DEBUG
	printf("CanvasOriginalDrawL=%d\nCanvasOriginalDrawU=%d\nCanvasOriginalDrawR=%d\nCanvasOriginalDrawD=%d\n", CanvasOriginalDrawL, CanvasOriginalDrawU, CanvasOriginalDrawR, CanvasOriginalDrawD);
#endif // _DEBUG

	//第一代算法：直接涂一个十字



	

#ifndef RAND
	//首先随机取色

	int BG_R = 0;
	int BG_G = 0;
	int BG_B = 0;
	int FG_R = 0;
	int FG_G = 0;
	int FG_B = 0;
	printf("=====开始随机生成色彩，请耐心等待几秒=====\n");
	RandColorRGB(&BG_R, &BG_G, &BG_B);
	Sleep(500);
	RandColorRGB(&FG_R, &FG_G, &FG_B);
#ifdef _DEBUG
	printf("BG   BG_R=%d,BG_G=%d,BG_B=%d\n", BG_R, BG_G, BG_B);
	printf("FG   FG_R=%d,FG_G=%d,FG_B=%d\n", FG_R, FG_G, FG_B);
#endif // _DEBUG
	COLORREF Background = RGB(BG_R, BG_G, BG_B);//背景色
	COLORREF Foreground = RGB(FG_R, FG_G, FG_B);//前景色
	printf("=====色彩随机生成完成，将继续构建样式=====\n");
#else
	COLORREF Background = RGB(20, 200, 20);//背景色
	COLORREF Foreground = RGB(100, 100, 220);//前景色
#endif // RAND

	setfillcolor(Background);
	solidrectangle(CanvasOriginalDrawL, CanvasOriginalDrawU, CanvasOriginalDrawR, CanvasOriginalDrawD);
	setfillcolor(Foreground);
	ParaVertTwiceDraw((int)CanvasOriginalDrawNum*0.200, (int)CanvasOriginalDrawNum*0.300, Foreground);

#ifdef _DEBUG
	printf("CanvasOriginalDrawNum=%d\n", CanvasOriginalDrawNum);
#endif // _DEBUG

	IMAGE OriginDuplicate = NULL;
	//saveimage(_T("778899.bmp"), OriginDuplicate);
	getimage(&OriginDuplicate, 0, 0, CanvasOriginalDrawNum, CanvasOriginalDrawNum);
	int index = 0;
	if (DrawDuplicate == DUPLICATE_SQUARE)
	{
		putimage(0, CanvasOriginalDrawNum, &OriginDuplicate, SRCCOPY);
		putimage(CanvasOriginalDrawNum, 0, &OriginDuplicate, SRCCOPY);
		putimage(CanvasOriginalDrawNum, CanvasOriginalDrawNum, &OriginDuplicate, SRCCOPY);
	}
	if (DrawDuplicate == DUPLICATE_MULTIPLY)
	{
		int index = 0;
		int jndex = 0;
		for (index = 0; index <= 2; ++index)
		{
			for (jndex = 0; jndex <= 2; ++jndex)
			{
				if (index != 0 || jndex != 0)
				{
					putimage(CanvasOriginalDrawNum*index, CanvasOriginalDrawNum*jndex, &OriginDuplicate, SRCCOPY);
				}
			}
		}
	}
	return 0;
}

//关于Canvas等变量名称的分析文档将随后发布

int SystemDraw(int mode)
{
	//一代算法计划添加的有：刷新、退出、设置、算法版本信息显示
	//一代算法计划改进的有：增加手动选择增长能力的界面
	//希望添加自动保存
	//以上为1.1.0希望看到的
	return 0;
}

int ParaVertTwiceDraw(int Begin, int End, COLORREF Color)
{
	setfillcolor(Color);

#ifdef _DEBUG
	printf("Begin=%d\nEnd=%d\n", Begin, End);
#endif // _DEBUG

	//Draw Vertical
	solidrectangle(Begin, 0, End, CanvasOriginalDrawNum);
	//Draw Parallel
	solidrectangle(0, Begin, CanvasOriginalDrawNum, End);
	return 0;
}



#endif // Easyx


int main(void)
{
	printf("Welcome to use OpenPlaids！\n");
	//
	//LOGO print
	//
#ifdef Easyx
	printf("You are using OCS for Easyx\n");
	//那就不用读取ini配置文件了，直接读取config.txt
	FILE *config;
	if (fopen("config.txt", "r") != NULL)
	{
		config = fopen("config.txt", "r");
	}
	//读取config
	int WindowSizeW = 0;
	int WindowSizeH = 0;
	int AlgorithmVersion = 0;
	if (WindowSizeW != 0 && WindowSizeH != 0)
	{
		initgraph(WindowSizeW, WindowSizeH, SHOWCONSOLE);
	}
	else
	{
		initgraph(WINDOW_W, WINDOW_H, SHOWCONSOLE);
	}
	//Call DisplayDraw Func
	InitDraw(0);
#endif // Easyx

	system("PAUSE");
	return 0;
}