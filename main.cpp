
//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//#ifdef __WINDOWS_
//	printf("win32");
//#endif
//}

//#include"ComplierControl.h"
//
//#ifdef DiskRedeemer_OpenMP
////#include"DiskRedeemer_INIwriter.h"
//#include"DiskRedeemer_OpenMP.h"
//
//int main(int argc, char *argv[])
//{
//	main_Redeemer(argc, argv);
//	return 0;
//}
//#endif // DiskRedeemer_OpenMP//主程序
//
//#ifdef DiskRedeemer_INIwriter
//#include"DiskRedeemer_INIwriter.h"
////#include"DiskRedeemer_OpenMP.h"
//
//int main(void)
//{
//	main_INIwriter();
//	return 0;
//}
//#endif // DiskRedeemer_INIwriter

#define Easyx

#ifdef Easyx

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<easyx.h>
#include<graphics.h>

#define WINDOW_W 900*0.5
#define WINDOW_H 1000*0.5

int MainDrawL = (int)WINDOW_W * 0.000;
int MainDrawU = (int)WINDOW_H * 0.000;
int MainDrawR = (int)WINDOW_W * 1.000;
int MainDrawD = (int)WINDOW_H * 0.900;

int SystemDrawL = (int)WINDOW_W * 0.000;
int SystemDrawU = (int)WINDOW_H * 0.901;
int SystemDrawR = (int)WINDOW_W * 1.000;
int SystemDrawD = (int)WINDOW_H * 1.000;

int InitDraw(int mode)
//mode干什么用还没定,先留着
{
	cleardevice();
	setfillcolor(RED);
	solidrectangle(MainDrawL, MainDrawU, MainDrawR, MainDrawD);
	setfillcolor(LIGHTGRAY);
	solidrectangle(SystemDrawL, SystemDrawU, SystemDrawR, SystemDrawD);
	return 0;
}



#endif // Easyx


int main(void)
{
	printf("Welcome to use OpenCheckSkirt！\n");
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