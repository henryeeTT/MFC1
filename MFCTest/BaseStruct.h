#include "stdafx.h"

class MyPoint 
{
public:
CPoint point;	//定義點X，Y座標
COLORREF color,fcolor;     //定義顏色
int r;        //定義顏色
int Tpye;                   //定義點樣式
MyPoint()
{
	color = RGB(0, 0, 255);
	fcolor = RGB(255, 0, 255);
	point=(0,0);
	Tpye=0;    //0:點 1:圓點
	r = 5;
	
} 
void draw(CDC & aDC)
{
	  //   CBrush m_newbrush;		
	     CPen pen(PS_SOLID, 1,color);	//建立畫筆物件
	     CPen *oldPen = aDC.SelectObject(&pen);	//設定DC物件使用pen物件
		// m_newbrush.CreateSolidBrush(fcolor);
		// aDC.SelectStockObject(NULL_BRUSH);	//設定DC物件不使用畫筆
		// aDC.SelectObject(&m_newbrush);
	     aDC.Ellipse(point.x - r, point.y - r, point.x + r, point.y + r);
         aDC.SetPixel(point, color); 
	//	 m_newbrush.DeleteObject();

}
};


class MyLine
{
public:
CPoint StartPnt, EndPnt,Prepoint;//定義形狀的終點與起點
COLORREF color;   //定義顏色
MyLine()
{
color = RGB(255, 0, 0);
Prepoint=EndPnt=StartPnt=(0,0);
}
void draw(CDC & aDC)
{
         CPen pen(PS_SOLID, 1,color);	//建立畫筆物件
	     CPen *oldPen = aDC.SelectObject(&pen);	//設定DC物件使用pen物件
	     aDC.MoveTo(StartPnt);
		 aDC.LineTo(EndPnt);
}
};