// BaseStruct.h :  基本幾何結構資料
#include "stdafx.h"

class MyPoint 
{
public:
	CPoint point;	//定義點X，Y座標
	COLORREF color;  //定義顏色
	int Tpye;       //定義點樣式
	MyPoint()
	{
		color = RGB(0, 0, 255);
		point=(0,0);
		Tpye=0;    //0:點 1:圓點
	} 
};

class MyLine 
{
public:
	CPoint StartPnt, EndPnt,Prepoint;	//定義形狀的終點與起點
   	COLORREF color;   //定義顏色
	MyLine()
	{
		color = RGB(255, 0, 0);
		StartPnt=(0,0);
	}
 
};