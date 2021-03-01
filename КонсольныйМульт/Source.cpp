#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<process.h>
#include<thread>

using namespace std;

HANDLE console;
COORD coord;
HWND hWnd;

const int ConsoleWidth = 120;
const int ConsoleHeigh = 35;
int speed = 1000;



int ManX;
int ManY;

int NoteX;
int NoteY;

int NadpisX = 30;
int NadpisY = 7;

char ActionSmb = '0';
char BackgroundSmb = ' ';


bool map[ConsoleHeigh][ConsoleWidth];

//		
//		
//		{     //   Здесь лево (строки)
//			  /*	Здесь верх	*/
//			  /* (столбики)	*/
//			/*		||      */						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			/*		||      */						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			/*		||      */						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//		
//		};
//		

bool NewMap[ConsoleHeigh][ConsoleWidth];


bool Pole1[9][80] =
{
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

//	bool Vipusk[7][80] = 
//	{
//		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//		0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,
//		0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,0,
//		0,1,0,0,0,0,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,
//		0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,
//		0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,
//		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//	};

bool Vipusk[7][80] = 
{// c днём рожденья!
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,1,1,0,0,0,0,1,1,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,
	    0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,
	    0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,
	    0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,
	    0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

bool HelloWorld[7][80] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

bool HelloWorldKurs[7][80] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

bool Pole[7][80]=
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};


bool ManUra1[10][10]
{
	0,0,1,1,0,0,0,0,0,0,
	0,1,0,1,0,0,0,0,0,0,
	1,1,0,1,1,0,0,0,0,1,
	1,1,1,0,1,0,0,0,1,0,
	0,1,1,1,0,0,0,1,0,0,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool ManUra2[10][10]
{
	0,0,1,1,0,0,0,0,0,0,
	1,1,0,1,1,0,0,0,0,0,
	1,1,0,1,1,0,0,0,0,1,
	1,1,1,0,1,0,0,0,1,0,
	0,1,1,1,0,0,0,1,0,0,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool ManKickHand1[10][10] =
{
	0,0,0,1,1,0,0,0,0,0,
	0,0,1,0,1,0,0,0,0,0,
	0,0,1,0,1,1,0,0,0,1,
	0,0,1,1,0,1,0,0,1,0,
	0,0,1,1,1,0,0,1,0,0,
	1,0,1,1,1,1,1,1,1,1,
	1,0,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0
};
bool ManKickHand2[10][10] =
{
	0,0,0,1,1,0,0,0,0,0,
	0,0,1,0,1,0,0,0,0,0,
	0,0,1,0,1,0,0,0,0,1,
	0,0,1,1,0,0,0,0,1,0,
	0,0,1,1,1,1,1,1,0,0,
	1,0,1,1,1,1,1,1,1,1,
	1,0,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0
};

bool ManOnKlava[10][10] =
{
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,0,0,0,1,
	0,0,0,1,0,0,1,0,1,0,
	0,0,1,1,1,1,0,1,0,0,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,0,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool ManOnTheTable[10][10]
{
	0,0,1,1,0,0,0,0,0,0,
	0,1,0,1,0,0,0,0,0,0,
	0,1,0,1,0,0,0,0,0,0,
	0,1,1,0,0,0,0,0,0,0,
	0,1,1,1,1,0,0,0,0,0,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool ManOnTheNote[10][10]
{
	0,0,1,1,0,0,0,0,0,0,
	0,1,0,1,0,0,0,0,0,0,
	0,1,0,1,0,0,0,0,0,1,
	0,1,1,0,0,0,0,0,1,0,
	0,1,1,1,1,0,0,1,0,0,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool ManOnTheNoteCircle[10][10]
{
	0,0,0,1,0,0,0,0,0,0,
	0,0,1,0,1,0,0,0,0,0,
	0,0,1,0,1,0,0,0,0,1,
	0,0,0,1,1,0,0,0,1,0,
	0,0,1,1,1,1,0,1,0,0,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool ManOnTheNoteKvadro[10][10]
{
	0,0,1,1,1,0,0,0,0,0,
	0,0,1,0,1,0,0,0,0,0,
	0,0,1,0,1,0,0,0,0,1,
	0,0,0,1,1,0,0,0,1,0,
	0,0,1,1,1,1,0,1,0,0,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool ManOnTheTableCodding[10][10]
{
	0,0,0,0,1,1,0,0,0,0,
	0,0,0,1,0,1,0,0,0,0,
	0,0,0,1,0,1,0,0,0,1,
	0,0,0,1,1,0,0,0,1,0,
	0,0,1,1,1,1,0,1,0,0,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,1,0,1,0,0,1,0,
	1,1,1,1,0,1,0,0,1,0,
	1,0,1,1,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool Table[8][10]
{
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	1,0,0,0,1,1,1,1,1,1,
	1,0,0,0,0,1,0,0,1,0,
	1,1,1,0,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};

bool TableWithNote[8][10]
{
	0,0,0,0,0,0,0,0,0,1,
	0,0,0,0,0,0,0,0,1,0,
	0,0,0,0,0,0,0,1,0,0,
	1,0,0,0,1,1,1,1,1,1,
	1,0,0,0,0,1,0,0,1,0,
	1,1,1,0,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,1,0
};



//bool StandMan[12][8]
//{
//	0,0,0,1,1,0,0,0,
//	0,0,1,0,0,1,0,0,
//	0,0,1,0,0,1,0,0,
//	0,0,0,1,1,0,0,0,
//	0,0,1,1,1,1,0,0,
//	0,1,0,1,1,0,1,0,
//	1,0,0,1,1,0,0,1,
//	0,0,0,1,1,0,0,0,
//	0,0,1,0,0,1,0,0,
//	0,0,1,0,0,1,0,0,
//	0,0,1,0,0,1,0,0,
//	0,0,1,0,0,1,0,0
//};

int StandMan[12][8]
{
	0,0,2,1,1,2,0,0,
	0,2,1,2,2,1,2,0,
	0,2,1,2,2,1,2,0,
	0,2,2,1,1,2,2,0,
	0,2,1,1,1,1,2,0,
	2,1,2,1,1,2,1,2,
	1,2,2,1,1,2,2,1,
	2,2,2,1,1,2,2,2,
	0,2,1,2,2,1,2,0,
	0,2,1,2,2,1,2,0,
	0,2,1,2,2,1,2,0,
	0,2,1,2,2,1,2,0
};

bool StandManWithUpHands1[12][8]
{
	0,0,0,1,1,0,0,0,
	0,0,1,0,0,1,0,0,
	0,1,1,0,0,1,1,0,
	0,1,0,1,1,0,1,0,
	0,0,1,1,1,1,0,0,
	0,0,0,1,1,0,0,0,
	0,0,0,1,1,0,0,0,
	0,0,0,1,1,0,0,0,
	0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0
};

bool StandManWithUpHands2[12][8]
{
	0,0,0,1,1,0,0,0,
	0,0,1,0,0,1,0,0,
	1,0,1,0,0,1,0,1,
	0,1,0,1,1,0,1,0,
	0,0,1,1,1,1,0,0,
	0,0,0,1,1,0,0,0,
	0,0,0,1,1,0,0,0,
	0,0,0,1,1,0,0,0,
	0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0
};

bool WalkMan1[12][6]
{
	0,0,0,0,0,0,
	0,0,0,1,1,0,
	0,0,1,0,0,1,
	0,0,1,0,0,1,
	0,0,1,1,1,0,
	0,0,1,1,0,0,
	0,1,1,1,1,0,
	1,0,1,1,0,1,
	0,0,1,0,1,0,
	0,0,1,0,0,1,
	0,1,0,0,0,1,
	1,0,0,0,0,1
};

bool WalkMan2[12][6]
{
	0,0,0,0,0,0,
	0,0,0,1,1,0,
	0,0,1,0,0,1,
	0,0,1,0,0,1,
	0,0,1,1,1,0,
	0,0,1,1,0,0,
	0,0,1,1,0,0,
	0,0,1,1,0,0,
	0,0,0,1,0,0,
	0,0,0,1,1,0,
	0,0,1,1,0,0,
	0,0,0,1,0,0
};


void DrawSmb(int i, int j)
{
	if (map[i][j] == 1)cout << ActionSmb;
	else cout << BackgroundSmb;
}

void ClearFragment(int x0, int y0, int x1, int y1)
{
	for (int i = y0; i < y1; i++)
		for (int j = x0; j < x1; j++)
			map[i][j] = 0;
}

void ClearMap()
{
	ClearFragment(0, 0, ConsoleWidth, ConsoleHeigh);
}

void MakeMap1EqualMap2(bool map1[ConsoleHeigh][ConsoleWidth], bool map2[ConsoleHeigh][ConsoleWidth])
{
	for (int i = 0; i < ConsoleHeigh; i++)
		for (int j = 0; j < ConsoleWidth; j++)
		{
			map1[i][j] = map2[i][j];
		}
}

void DrawMap()
{
	for (int i = 0; i < ConsoleHeigh; i++)
		for (int j = 0; j < ConsoleWidth; j++)
		{
			coord.X = j;
			coord.Y = i;
			SetConsoleCursorPosition(console, coord);
			DrawSmb(i, j);
		}
}


void DrawFragment(int x1, int y1, int x2, int y2)
{
	for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
		{
			coord.X = j;
			coord.Y = i;
			SetConsoleCursorPosition(console, coord);
			
			DrawSmb(i, j);

		}
}

///////////////////////////////////////////////////////////

void DrawNadpis(int x, int y, bool nadpis[7][80])
{
	for (int i = 0; i < 78; i++)
		for (int j = 0; j < 7; j++)
			map[y + j][x + i] = nadpis[j][i];
}

void DrawPole(int x, int y)
{
	for (int i = 0; i < 80; i++)
		for (int j = 0; j < 9; j++)
			map[y + j][x + i] = Pole1[j][i];
}

void DrawStandMan(int xl, int y)
{
	ManX = xl - 3;
	ManY = y;
	for (int i = y; i <y + 12; i++)
		for (int j = xl - 3; j < xl + 5; j++)
		{
			if (StandMan[i - y][j - xl + 3] == 1)
			{
				map[i][j] = 1;
			}
		}
}

void DrawManWithUpHands(bool number)
{
	for (int i = 0; i <12; i++)
		for (int j = 0; j < 8; j++)
		{
			if (number == 1)
			map[ManY + i][ManX + j] = StandManWithUpHands1[i][j];
			else map[ManY + i][ManX + j] = StandManWithUpHands2[i][j];
		}
}

void DrawWalkMan1(int x, int y)
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			map[y + i][x + j] = WalkMan1[i][j];
}

void DrawWalkMan2(int x, int y)
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			map[y + i][x + j] = WalkMan2[i][j];
}

void DrawWalkMan(int x0, int y0, int steps)
{
	int xn = x0;
	for (int k = 0; k < 2*steps+1; k++)
	{

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
			{			
				k % 2 == 0 ? map[y0 + i][xn + j] = WalkMan1[i][j] : map[y0 + i][xn + j] = WalkMan2[i][j];
			}
		ClearFragment(xn-2, y0, xn, y0 + 12);
		DrawFragment(xn-2, y0, xn + 6 - 1, y0 + 12 - 1);
		
		Sleep(speed/4);
		xn = xn + 2;
	}
	ManX = xn;
	ManY = y0;
}

void DrawWalkMan1Left(int x, int y)
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			map[y + i][x + j] = WalkMan1[i][5-j];
}

void DrawWalkMan2Left(int x, int y)
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			map[y + i][x + j] = WalkMan2[i][5 - j];
}

void DrawWalkManLeft(int steps)
{
	for (int k = 0; k < steps; k++)
	{
		ClearFragment(ManX, ManY, ManX + 8, ManY + 12);
		if (k % 2 == 0)
			DrawWalkMan1Left(ManX, ManY);
		else
			DrawWalkMan2Left(ManX, ManY);

		DrawFragment(ManX, ManY, ManX + 8, ManY + 12);
		Sleep(speed / 4);
		ManX = ManX - 2;
	}

}

void DrawWalkManOnOnePlace(int x0, int y0, int steps)
{
	int xn = x0;
	for (int k = 0; k < 2 * steps + 1; k++)
	{

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
			{
				k % 2 == 0 ? map[y0 + i][xn + j] = WalkMan1[i][j] : map[y0 + i][xn + j] = WalkMan2[i][j];
			}
		ClearFragment(xn - 2, y0, xn, y0 + 12);
		DrawFragment(xn - 2, y0, xn + 6 - 1, y0 + 12 - 1);

		Sleep(speed / 4);
	}
	ManX = xn;
	ManY = y0;
}

void DrawTable(int x, int y)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 10; j++)
		{
			if((i+y<ConsoleHeigh)&&(j + x<ConsoleWidth))
			map[i + y][j + x] = Table[i][j];
		}
}

void DrawTableWithNote(int x, int y)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 10; j++)
		{
			if ((i + y<ConsoleHeigh) && (j + x<ConsoleWidth))
				map[i + y][j + x] = TableWithNote[i][j];
		}
}

void DrawManMovingFromTable()
{
	int xt = ManX;
	int yt = ManY + 4;
	ManX = ManX + 1;

	for (int k = 0; k < 5; k++)
	{
		ClearFragment(ManX-1, ManY, xt + 10, yt + 8);
		DrawTableWithNote(xt, yt);

		if (k % 2 == 0)
			for (int i = 0; i < 12; i++)
				for (int j = 0; j < 6; j++)
					if (WalkMan2[i][5 - j] == 1)map[ManY + i][ManX + j] = 1;
					else;
		else
			for (int i = 0; i < 12; i++)
				for (int j = 0; j < 6; j++)
					if (WalkMan1[i][5 - j] == 1)map[ManY + i][ManX + j] = 1;


		DrawFragment(ManX-1, ManY, xt + 10, yt + 8);
		Sleep(speed/4);
		ManX = ManX - 2;
	}
}

void DrawManOnTheTable(int x, int y,bool ManAndStol[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
				map[i + y][j + x] = ManAndStol[i][j];
		}
}

void DrawManOnTheNote(int x, int y)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			map[i + y][j + x] = ManOnTheNote[i][j];
		}
}

void DrawManOnTheTable(int x, int y)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			map[y + i][x + j] = ManOnTheTable[i][j];
}

void DrawManMovingToTable(int x, int y)
{
	// х,у - координаты левого верхнего угла человека

	for (int k = 0;k<3; k++)
	{
	
		ClearFragment(x, y, x + 16, y + 12);
		DrawTable(x + 7, y + 4);
		ManX = ManX + 2;	
		
		if(k%2==0)
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
			{
			
				if (WalkMan2[i][j] == 1)
					map[ManY + i][ManX + j] = 1;
			}
		else
			for (int i = 0; i < 12; i++)
				for (int j = 0; j < 6; j++)
				{

					if (WalkMan1[i][j] == 1)
						map[ManY + i][ManX + j] = 1;
				}

		DrawFragment(x, y, x + 16, y + 12);
		Sleep(speed / 4);
	}

/*

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
		{
			map[y + i][x + j] = WalkMan1[i][j];
		}
	DrawTable(x + 7, y + 4);
	DrawFragment(x, y, x + 16, y + 12);

	Sleep(speed/4);
	ClearFragment(x, y, x + 16, y + 12);
	DrawTable(x + 7, y + 4);
	ManX = ManX + 2;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
		{
			if (WalkMan2[i][j] == 1)
				map[ManY + i][ManX + j] = 1;
		}
	DrawFragment(x, y, x + 16, y + 12);

	Sleep(speed/4);
	ClearFragment(x, y, x + 16, y + 12);
	DrawTable(x + 7, y + 4);
	ManX = ManX + 2;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
		{
			if (WalkMan1[i][j] == 1)
				map[ManY + i][ManX + j] = 1;
		}
	DrawFragment(x, y, x + 16, y + 12);

	Sleep(speed/4);
	ClearFragment(x, y, x + 16, y + 12);
	DrawTable(x + 7, y + 4);
	ManX = ManX + 2;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
		{
			if (WalkMan2[i][j] == 1)
				map[ManY + i][ManX + j] = 1;
		}
	DrawFragment(x, y, x + 16, y + 12);
	*/

	ClearFragment(x, y, x + 16, y + 12);
	DrawManOnTheTable(x + 7, y+2);
	DrawFragment(x, y, x + 16, y + 12);
	Sleep(speed);
}

void DrawManAndTable(int x, int y,int stopman)
{
	int xt(ConsoleWidth), yt(ManY + 4);


	DrawWalkMan(x, y, stopman);
	ClearFragment(ManX - 2, ManY, ManX, ManY + 12);

	DrawWalkMan2(ManX, ManY);
	DrawFragment(ManX - 4, ManY, ManX + 5, ManY + 12);
	Sleep(speed / 4);
	ClearFragment(ManX, ManY, ManX + 5, ManY + 12);



	for (int k=0; xt>ManX+4; )
	{
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
			{
				k % 2 == 0 ? map[ManY + i][ManX + j] = WalkMan1[i][j] : map[ManY + i][ManX + j] = WalkMan2[i][j];
			}
		ClearFragment(xt+10, yt, xt + 12, yt + 10);
		DrawTable(xt, yt);
		DrawFragment(ManX - 2, ManY, xt + 12, yt + 9);;

		xt = xt - 2;
		k++;
		Sleep(speed / 4);
	}
	DrawManMovingToTable(ManX, ManY);
}

void DrawCodding(int x, int y,int k)
{
	bool b = 0;
	for (int i = 0; i < 2*k + 1; i++)
	{
		coord.X = x - 0;
		coord.Y = y - 1;
		SetConsoleCursorPosition(console, coord);
		i % 2 == 0 ? cout << ActionSmb : cout<<BackgroundSmb;

		coord.X = x - 0;
		coord.Y = y - 2;
		SetConsoleCursorPosition(console, coord);
		i % 2 == 1 ? cout << ActionSmb : cout << BackgroundSmb;

		Sleep(speed/10);
	}
}

void OneTimeCodding()
{
	DrawManOnTheTable(ManX, ManY, ManOnTheTableCodding);
	DrawFragment(ManX, ManY, ManX+10, ManY +10);
	Sleep(speed / 4);

	DrawCodding(NoteX, NoteY, 10);
	Sleep(speed / 2);

	//DrawManOnTheNote(ManX, ManY);
	//DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
	//Sleep(speed / 2);

	DrawManOnTheTable(ManX, ManY, ManOnTheNoteCircle);
	DrawFragment(ManX, ManY, ManX + 10, ManY + 10);

}

void Ura()
{
	DrawManOnTheTable(ManX, ManY, ManUra1);
	DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
	Sleep(speed / 5);

	DrawManOnTheTable(ManX, ManY, ManUra2);
	DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
	Sleep(speed / 5);

	DrawManOnTheTable(ManX, ManY, ManUra1);
	DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
	Sleep(speed);

}

void Kick()
{
	DrawManOnTheTable(ManX, ManY, ManKickHand1);
	DrawFragment(ManX, ManY, ManX + 10, ManY + 10);


	Sleep(speed);
	ClearFragment(ManX, ManY, ManX + 10, ManY + 10);
	DrawManOnTheTable(ManX, ManY, ManKickHand2);
	DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
	Sleep(speed);
}

void Jump()
{
	ClearFragment(ManX, ManY, ManX + 7, ManY + 11);
	DrawFragment(ManX, ManY, ManX + 7, ManY + 10);
	ManY++;
	DrawManWithUpHands(1);
	DrawFragment(ManX, ManY, ManX + 7, ManY + 10);
	ManY--;

	Sleep(speed/8);

	for (int k = 0; k < 4; k++)
	{
		ClearFragment(ManX, ManY, ManX + 7, ManY + 15);
		DrawManWithUpHands(1);
		DrawFragment(ManX, ManY, ManX + 7, ManY + 12);
		Sleep(speed/8);
		ManY = ManY - 1;
	}

	ClearFragment(ManX, ManY, ManX + 7, ManY + 15);
	DrawManWithUpHands(0);
	DrawFragment(ManX, ManY, ManX + 7, ManY + 12);
	Sleep(speed/5);
	ManY = ManY + 1;

	for (int k = 0; k < 4; k++)
	{
		ClearFragment(ManX, ManY-2, ManX + 7, ManY + 10);
		DrawManWithUpHands(1);
		DrawFragment(ManX, ManY-2, ManX + 7, ManY + 12);
		Sleep(speed/8);
		ManY = ManY + 1;
	}
	
	ClearFragment(ManX, ManY-2, ManX + 7, ManY + 11);
	DrawFragment(ManX, ManY-2, ManX + 7, ManY + 10);
	DrawManWithUpHands(1);
	DrawFragment(ManX, ManY, ManX + 7, ManY + 10);
	ManY--;
	Sleep(speed/8);

}


// Начинать движение с того пикселя, который расположен первым по ходу движения! (в лево - с наим х, вниз - с наиб у и т.д.)

void    MoveUp(int y, int x, int distanse)
{
	NewMap[x - distanse][y] = map[x][y];
	NewMap[x][y] = !NewMap[x][y];
}
	  			   		  
void  MoveDown(int y, int x, int distanse)
{
	NewMap[x + distanse][y] = map[x][y];
	NewMap[x][y] = !NewMap[x][y];
}
	  			   		  
void  MoveLeft(int y, int x, int distanse)
{
	NewMap[x][y - distanse] = map[x][y];
	NewMap[x][y] = !NewMap[x][y];
}
				   		  
void MoveRight(int y, int x, int distanse)
{
	NewMap[x][y + distanse] = map[x][y];
	NewMap[x][y] = !NewMap[x][y];
}

void MoveManDown(int xl, int xr, int y, int distance)
{
	MoveDown(xl - 1, y + 10, distance);
	MoveDown(xr + 1, y + 10, distance);	MoveDown(xl - 1, y + 9, distance);
	MoveDown(xr + 1, y + 9, distance);

	MoveDown(xl - 1, y + 8, distance);
	MoveDown(xr + 1, y + 8, distance);

	MoveDown(xl - 1, y + 7, distance);
	MoveDown(xr + 1, y + 7, distance);

	MoveDown(xl, y + 6, distance);
	MoveDown(xr, y + 6, distance);

	MoveDown(xl, y + 5, distance);
	MoveDown(xr, y + 5, distance);

	MoveDown(xl, y + 4, distance);
	MoveDown(xr, y + 4, distance);
	MoveDown(xl - 1, y + 4, distance);
	MoveDown(xr + 1, y + 4, distance);

	MoveDown(xl - 2, y + 3, distance);
	MoveDown(xl, y + 3, distance);
	MoveDown(xr, y + 3, distance);
	MoveDown(xr + 2, y + 3, distance);

	MoveDown(xl - 1, y + 2, distance);
	MoveDown(xr + 1, y + 2, distance);

	MoveDown(xl - 1, y + 1, distance);
	MoveDown(xr + 1, y + 1, distance);

	MoveDown(xl, y, distance);
	MoveDown(xr, y, distance);
}

void MoveManUp(int xl, int xr, int y, int distance)
{


	MoveUp(xl, y, distance);
	MoveUp(xr, y, distance);

	MoveUp(xl - 1, y + 1, distance);
	MoveUp(xr + 1, y + 1, distance);

	MoveUp(xl - 1, y + 2, distance);
	MoveUp(xr + 1, y + 2, distance);

	MoveUp(xl - 2, y + 3, distance);
	MoveUp(xl, y + 3, distance);
	MoveUp(xr, y + 3, distance);
	MoveUp(xr + 2, y + 3, distance);

	MoveUp(xl, y + 4, distance);
	MoveUp(xr, y + 4, distance);
	MoveUp(xl - 1, y + 4, distance);
	MoveUp(xr + 1, y + 4, distance);

	MoveUp(xl, y + 5, distance);
	MoveUp(xr, y + 5, distance);

	MoveUp(xl, y + 6, distance);
	MoveUp(xr, y + 6, distance);

	MoveUp(xl - 1, y + 7, distance);
	MoveUp(xr + 1, y + 7, distance);

	MoveUp(xl - 1, y + 8, distance);
	MoveUp(xr + 1, y + 8, distance);

	MoveUp(xl - 1, y + 9, distance);
	MoveUp(xr + 1, y + 9, distance);

	MoveUp(xl - 1, y + 10, distance);
	MoveUp(xr + 1, y + 10, distance);
}

void JumpMan(int t)
{
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManDown(11, 12, 7, 1);
	MakeMap1EqualMap2(map, NewMap);
	MoveUp(10, 18, 1);
	MoveUp(13, 18, 1);

	Sleep(t);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManUp(11, 12, 8, 1);
	MakeMap1EqualMap2(map, NewMap);
	MoveUp(10, 18, 1);
	MoveUp(13, 18, 1);


	Sleep(t);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManUp(11, 12, 7, 1);

	Sleep(t);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();


	MoveManUp(11, 12, 6, 1);

	Sleep(t / 2);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();


	MoveManUp(11, 12, 5, 1);

	Sleep(t / 4);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManUp(11, 12, 4, 1);

	Sleep(t / 8);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();


	MoveManDown(11, 12, 3, 1);
	Sleep(t / 16);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManDown(11, 12, 4, 1);
	Sleep(t / 8);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManDown(11, 12, 5, 1);
	Sleep(t / 4);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManDown(11, 12, 6, 1);
	Sleep(t / 2);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManDown(11, 12, 7, 1);
	MoveDown(10, 18, 1);
	MoveDown(13, 18, 1);

	Sleep(t);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();

	MoveManUp(11, 12, 8, 1);
	MakeMap1EqualMap2(map, NewMap);
	MoveUp(10, 18, 1);
	MoveUp(13, 18, 1);

	Sleep(t);
	MakeMap1EqualMap2(map, NewMap);
	DrawMap();
}


bool volna[ConsoleHeigh][ConsoleWidth];

void Volna_WithMan(int x0, int y0)
{
	int xn = x0;
	int yn = y0;
			
	int ManX0 = ManX;
	int ManY0 = ManY;
	
	for (int i = y0; i < ConsoleHeigh; i++)
		for (int j = x0; j < ConsoleWidth; j++)
			volna[i][j] = 1;


	for (int k = 0; k <ConsoleHeigh+5; k++)
	{
		k % 2 == 0 ? volna[x0][y0] = 1 : k = k;

		MakeMap1EqualMap2(NewMap, volna);
		for (int i = ManY0; i < ManY0 + 12; i++)
			for (int j = ManX0; j <ManX0 + 8; j++)
				{
				
				if (StandMan[i-ManY0][j-ManX0] == 1)
				{
					NewMap[i][j] = 1;
				}
				else if (StandMan[i - ManY0][j - ManX0] == 2)NewMap[i][j] = 0;
			
			}

		MakeMap1EqualMap2(map, NewMap);
		DrawFragment(x0, y0, xn, yn);

	

		for (int i = yn; i >= y0; i--)
			for (int j = xn; j >= x0; j--)
			{
				
					if (volna[i][j] == 1)
				{
					volna[i][j] = 0;
					
					if (i > j) volna[i+1][j] = 1;
					else if (i < j)volna[i][j + 1] = 1;
					else
					{
						volna[i + 1][j] = 1;
						volna[i][j + 1] = 1;
						volna[i + 1][j + 1] = 1;
					}

				}
	
			}


		Sleep(speed/5);
		xn++;
		if (yn == ConsoleHeigh - 2) xn--;
		else yn++;
		
		
	}
}

bool Matrix[ConsoleWidth][ConsoleHeigh];

void SetRandMatrix()
{
	//srand(time(NULL));
	for (int i = 0; i < ConsoleWidth;i++)
		for (int j = 0; j < ConsoleHeigh; j++)
		{
			if (rand() % 2 == 0)Matrix[i][j] = 0;
			else Matrix[i][j] = 1;
		}
}


int MyRand = 8;

int k;

void DefMatrix()
{
	int YlastSmb(0);
	
	for (int j = 0; j < ConsoleWidth; j++)
	{
		YlastSmb = -1;
		for (int i = ConsoleHeigh-1; (i >= 0) && (YlastSmb == -1); i--)
			if (Matrix[j][i] == 1)YlastSmb = i;

	//	YlastSmb == -1 ? YlastSmb++ : YlastSmb = YlastSmb;
	//	wsprintf(str, L"LastY = %d", YlastSmb);
	//	SetConsoleTitle(str);

		for (int i = YlastSmb; i >= 0; i--)
		{
			Matrix[j][i + 1] = Matrix[j][i];
		}	
		srand(time_t(NULL));


		if(k%2==0)
		if (MyRand%4==0)
		if (j % 7 == 0)
		{
			if (MyRand % 6 == 0)
			Matrix[j][0] = 1;
			else Matrix[j][0] = 0;
		}				

		for (int i = YlastSmb; i >= 0; i--)
		{
			map[i][j] = Matrix[j][i];
		}

		DrawFragment(j, 0, j, YlastSmb);

		// безопасность человечка
		//if (j > ManX&&j<ManX + 15 && YlastSmb>ManY - 2)
		//{
		//	for (int a = YlastSmb+1; a >= 0; a--)Matrix[j][a] = 0;
		//	for (int i = YlastSmb; i >= 0; i--)
		//	{
		//		map[i][j] = Matrix[j][i];
		//	}
		//	BackgroundSmb = ' ';
		//	DrawFragment(j, 0, j, YlastSmb);
		//	BackgroundSmb = '0';
		//}

		if (YlastSmb > ConsoleHeigh)
		{
			for (int a = YlastSmb + 1; a >= 0; a--)Matrix[j][a] = 0;
			for (int i = YlastSmb; i >= 0; i--)
			{
				map[i][j] = Matrix[j][i];
			}
			BackgroundSmb = ' ';
			DrawFragment(j, 0, j, YlastSmb);
			BackgroundSmb = '0';
		}

		MyRand =19*sin(MyRand)+k;
	}
		

}


void main()
{

	int n;

	console = GetStdHandle(STD_OUTPUT_HANDLE);	
	WCHAR str[200];
	GetConsoleTitle(str, 200);
	SetConsoleTitle(L"Console");
	hWnd = FindWindow(NULL, L"Console");
	SetConsoleTitle(str);

	system("cls");
	Sleep(1500);

	for (int k = 0; k < 1;k++)
	{
		cout << "0";
		Sleep(speed);
		system("cls");
		Sleep(speed);
	}

	cout << "0";
	Sleep(speed);


	ManX = 10;
	ManY = 20;
	
						Volna_WithMan(0,0);
					
						MakeMap1EqualMap2(map, NewMap);
					
						MoveUp(16,25, 2);
						MoveUp(17, 26, 4);
					
						MakeMap1EqualMap2(map, NewMap);
						DrawFragment(10,20, 17, 31);
					
					
						Sleep(speed);
					
						ClearMap();		
						DrawStandMan(ManX+3, ManY);
						DrawMap();
					
						Sleep(speed);
					
						ClearFragment(10, 20, 25, 30);
						DrawFragment(10, 20, 25, 30);
			
					DrawWalkMan(10, 20, 10);
				
					ClearFragment(ManX-2, ManY, ManX + 5, ManY + 12);
					DrawWalkMan2(ManX, ManY);
					ManX = ManX + 2;
					DrawFragment(ManX-4, ManY, ManX + 5, ManY + 12);
					Sleep(speed/4);
					ClearFragment(ManX, ManY, ManX + 5, ManY + 12);
					
					DrawManAndTable(ManX, ManY, 4);
			
		NoteX = ManX + 7;
		NoteY = ManY + 7;

	ManX = ManX + 1;
	ManY = ManY + 2;
				
				DrawManOnTheTable(ManX, ManY, ManOnTheTableCodding);
				DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
				Sleep(speed/4);
			
				DrawManOnTheNote(ManX, ManY);
				DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
				Sleep(speed);
	
	
		OneTimeCodding();
		DrawPole(NadpisX - 1, NadpisY - 1);
		DrawFragment(NadpisX - 1, NadpisY - 1, NadpisX + 80, NadpisY + 8);
		Sleep(speed);

		OneTimeCodding();
		ActionSmb = '1';
		BackgroundSmb = '0';
		DrawMap();
		Sleep(speed);
	
		OneTimeCodding();
		ActionSmb = '0';
		BackgroundSmb = ' ';
		DrawMap();
		Sleep(speed);
		

		OneTimeCodding();		
		DrawPole(NadpisX - 1, NadpisY - 1);
		DrawNadpis(NadpisX, NadpisY, HelloWorld);
		DrawFragment(NadpisX - 1, NadpisY - 1, NadpisX + 80, NadpisY + 8);
		Sleep(speed);

		Ura();


		OneTimeCodding();
		DrawPole(NadpisX - 1, NadpisY - 1);
		DrawNadpis(NadpisX, NadpisY, HelloWorldKurs);
		DrawFragment(NadpisX - 1, NadpisY - 1, NadpisX + 80, NadpisY + 8);
		Sleep(speed);


		DrawManOnTheTable(ManX, ManY, ManOnKlava);
		DrawFragment(ManX, ManY, ManX + 10, ManY + 10);


	ActionSmb = '1';
	BackgroundSmb = '0';
	
	

	//Matrix
	for (k = 0; k < 200; k++)
	{
				DefMatrix();
		
				//оглянуться
				if (k == 10)
				{
					ClearFragment(ManX, ManY, ManX + 10, ManY + 10);
					ActionSmb = '0';
					BackgroundSmb = ' ';
					DrawManOnTheTable(ManX, ManY, ManOnTheNoteCircle);
					DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
					ActionSmb = '1';
					BackgroundSmb = '0';
				}
			
				if (k == 13)
				{
					ClearFragment(ManX, ManY, ManX + 10, ManY + 10);
					ActionSmb = '0';
					BackgroundSmb = ' ';
					DrawManOnTheTable(ManX, ManY, ManOnTheNoteKvadro);
					DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
					ActionSmb = '1';
					BackgroundSmb = '0';
				}
			
				if (k == 15)
				{
					ClearFragment(ManX, ManY, ManX + 10, ManY + 10);
					ActionSmb = '0';
					BackgroundSmb = ' ';
					DrawManOnTheTable(ManX, ManY, ManOnTheNoteCircle);
					DrawFragment(ManX, ManY, ManX + 10, ManY + 10);
					ActionSmb = '1';
					BackgroundSmb = '0';
				}
			
			
				//покодить
			
				if (k > 20 && k < 30)
				{
					ActionSmb = '0';
					BackgroundSmb = ' ';
					
					ClearFragment(ManX, ManY, ManX + 10, ManY + 10);
					DrawManOnTheTable(ManX, ManY, ManOnTheTableCodding);
					DrawFragment(ManX, ManY, ManX + 10, ManY + 10);

					coord.X = NoteX - 0;
					coord.Y = NoteY - 1;
					SetConsoleCursorPosition(console, coord);
					cout << ActionSmb;
			
					coord.X = NoteX - 0;
					coord.Y = NoteY - 2;
					SetConsoleCursorPosition(console, coord);
					cout << BackgroundSmb;
				
			
					Sleep(speed / 10);
			
					coord.X = NoteX - 0;
					coord.Y = NoteY - 1;
					SetConsoleCursorPosition(console, coord);
					cout << BackgroundSmb;
			
					coord.X = NoteX - 0;
					coord.Y = NoteY - 2;
					SetConsoleCursorPosition(console, coord);
					cout << ActionSmb;
					ActionSmb = '1';
					BackgroundSmb = '0';
				}
			
				if (k > 40)
				{
					
					ClearFragment(ManX, ManY, ManX + 10, ManY + 10);
					ActionSmb = '0';
					BackgroundSmb = ' ';

					Kick();

					ActionSmb = '1';
					BackgroundSmb = '0';
					break;
				}
			
				if ((k > 20 && k < 30)|(k > 60 && k < 80))	Sleep(speed / 10);
				else
				Sleep(speed/5);
		
			
	}

	DrawMap();
	Sleep(speed);

	OneTimeCodding();
	ClearMap();
	DrawManOnTheTable(ManX, ManY, ManOnTheNoteCircle);
	DrawMap();
	Sleep(speed);

	OneTimeCodding();
	ActionSmb = '0';
	BackgroundSmb = ' ';
	DrawPole(NadpisX - 1, NadpisY - 1);
	DrawNadpis(NadpisX, NadpisY, HelloWorld);
	DrawMap();
	Sleep(speed);


	


	OneTimeCodding();
	DrawPole(NadpisX - 1, NadpisY - 1);
	DrawNadpis(NadpisX, NadpisY, Vipusk);
	DrawFragment(NadpisX - 1, NadpisY - 1, NadpisX + 80, NadpisY + 8);
	Sleep(speed);
	Ura();


	ManX = ManX;
	ManY = ManY - 2;
	
	ClearFragment(ManX, ManY, ManX + 10, ManY + 10);
	DrawFragment(ManX, ManY, ManX + 10, ManY + 10);

	DrawManMovingFromTable();
	DrawWalkManLeft(8);
	
	ClearFragment(ManX, ManY, ManX + 8, ManY + 12);


	DrawStandMan(ManX+3,ManY);	
	DrawFragment(ManX, ManY, ManX + 8, ManY + 12);
	Sleep(speed/4);


	for (int k = 0; k < 2;k++)
	Jump();


	for (int k = 0; k < 4; k++)
	{
		ClearFragment(ManX, ManY, ManX + 7, ManY + 15);
		DrawManWithUpHands(1);
		DrawFragment(ManX, ManY, ManX + 7, ManY + 12);
		Sleep(speed / 4);
		ManY = ManY - 1;
	}

	ClearFragment(ManX, ManY, ManX + 7, ManY + 15);
	DrawManWithUpHands(0);
	DrawFragment(ManX, ManY, ManX + 7, ManY + 12);
	Sleep(speed / 3);
	ManY = ManY + 1;

	DrawMap();
	Sleep(speed);

	//ClearMapFragment(ManX, ManY, ManX + 7, ManY + 12);
	//DrawStandMan(ManX+3, ManY+1);



	










//		испыталка				for (int i = 0; i < 12; i++)
//							for (int j = 0; j < 6; j++)
//								NewMap[i][j] = 0;
//					
//					
//						MakeMap1EqualMap2(map, NewMap);
//						DrawFragment(0,0,12,6);
//					
//					
//						MoveDown(2, 2, 1);
//						MoveDown(4, 4, 1);
//											MakeMap1EqualMap2(map, NewMap);
//						MoveDown(2, 2, 1);
//						MoveDown(4, 4, 1);
//					
//						MakeMap1EqualMap2(map, NewMap);
//						DrawFragment(0, 0, 12, 6);

	//for (int i = 0; i < 12; i++)
	//	for (j = 0; j < 6; j++)
	//	{
	//		coord.X = j;
	//		coord.Y = i;
	//		SetConsoleCursorPosition(console, coord);
	//		cout << WalkMan2[i][j];
	//
	//	}

	cin >> n;
}