// BaseStruct.h :  �򥻴X�󵲺c���
#include "stdafx.h"

class MyPoint 
{
public:
	CPoint point;	//�w�q�IX�AY�y��
	COLORREF color;  //�w�q�C��
	int Tpye;       //�w�q�I�˦�
	MyPoint()
	{
		color = RGB(0, 0, 255);
		point=(0,0);
		Tpye=0;    //0:�I 1:���I
	} 
};

class MyLine 
{
public:
	CPoint StartPnt, EndPnt,Prepoint;	//�w�q�Ϊ������I�P�_�I
   	COLORREF color;   //�w�q�C��
	MyLine()
	{
		color = RGB(255, 0, 0);
		StartPnt=(0,0);
	}
 
};