#include "stdafx.h"

class MyPoint 
{
public:
CPoint point;	//�w�q�IX�AY�y��
COLORREF color,fcolor;     //�w�q�C��
int r;        //�w�q�C��
int Tpye;                   //�w�q�I�˦�
MyPoint()
{
	color = RGB(0, 0, 255);
	fcolor = RGB(255, 0, 255);
	point=(0,0);
	Tpye=0;    //0:�I 1:���I
	r = 5;
	
} 
void draw(CDC & aDC)
{
	  //   CBrush m_newbrush;		
	     CPen pen(PS_SOLID, 1,color);	//�إߵe������
	     CPen *oldPen = aDC.SelectObject(&pen);	//�]�wDC����ϥ�pen����
		// m_newbrush.CreateSolidBrush(fcolor);
		// aDC.SelectStockObject(NULL_BRUSH);	//�]�wDC���󤣨ϥεe��
		// aDC.SelectObject(&m_newbrush);
	     aDC.Ellipse(point.x - r, point.y - r, point.x + r, point.y + r);
         aDC.SetPixel(point, color); 
	//	 m_newbrush.DeleteObject();

}
};


class MyLine
{
public:
CPoint StartPnt, EndPnt,Prepoint;//�w�q�Ϊ������I�P�_�I
COLORREF color;   //�w�q�C��
MyLine()
{
color = RGB(255, 0, 0);
Prepoint=EndPnt=StartPnt=(0,0);
}
void draw(CDC & aDC)
{
         CPen pen(PS_SOLID, 1,color);	//�إߵe������
	     CPen *oldPen = aDC.SelectObject(&pen);	//�]�wDC����ϥ�pen����
	     aDC.MoveTo(StartPnt);
		 aDC.LineTo(EndPnt);
}
};