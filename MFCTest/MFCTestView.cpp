
// MFCTestView.cpp : CMFCTestView 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "MFCTest.h"
#endif

#include "MFCTestDoc.h"
#include "MFCTestView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTestView

IMPLEMENT_DYNCREATE(CMFCTestView, CView)

BEGIN_MESSAGE_MAP(CMFCTestView, CView)
	ON_COMMAND(ID_DRAW_POINT, &CMFCTestView::OnDrawPoint)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDM_RED, &CMFCTestView::OnRed)
	ON_COMMAND(IDM_GREEN, &CMFCTestView::OnGreen)
	ON_COMMAND(IDM_BLUE, &CMFCTestView::OnBlue)
	ON_UPDATE_COMMAND_UI(IDM_RED, &CMFCTestView::OnUpdateRed)
	ON_UPDATE_COMMAND_UI(IDM_GREEN, &CMFCTestView::OnUpdateGreen)
	ON_UPDATE_COMMAND_UI(IDM_BLUE, &CMFCTestView::OnUpdateBlue)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(IDF_Exit, &CMFCTestView::OnExit)
END_MESSAGE_MAP()

// CMFCTestView 建構/解構

CMFCTestView::CMFCTestView()
{
	// TODO: 在此加入建構程式碼
     color=RGB(255,0,0);
}

CMFCTestView::~CMFCTestView()
{
}

BOOL CMFCTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CMFCTestView 描繪

void CMFCTestView::OnDraw(CDC* pDC)
{	
	// TODO: 在此加入原生資料的描繪程式碼
		CMFCTestDoc *doc = (CMFCTestDoc *)GetDocument();
  	   int Pnum;
	   int i;
	   Pnum=doc->pArray.GetSize();  // 取得 CMFCTestDoc 中 pArray 總點數
	   for(i=0;i<Pnum;i++)
	   {
		 if(doc->pArray[i].Tpye==0)
	      pDC->SetPixel(doc->pArray[i].point,doc->pArray[i].color );
	     else
          pDC->Ellipse(doc->pArray[i].point.x - 3, doc->pArray[i].point.y - 3, doc->pArray[i].point.x + 3, doc->pArray[i].point.y + 3);
	   }
}


// CMFCTestView 診斷

#ifdef _DEBUG
void CMFCTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTestDoc* CMFCTestView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTestDoc)));
	return (CMFCTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTestView 訊息處理常式


void CMFCTestView::OnDrawPoint()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CMFCTestDoc *doc = (CMFCTestDoc *)GetDocument();//取得 CMFCTestDoc 指標物件
    doc->shapenum=0;  //畫點
  //  doc->Obj_Color=RGB(0,0,255);  //物件顏色
    doc->Obj_Color=color;  //物件顏色
	doc->P_Type=0; //系統點總類  0:點 1:圓點
}



void CMFCTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	CView::OnLButtonDown(nFlags, point);

	SetCapture();
	   
	//templine.StartPnt=point;
}


void CMFCTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	CView::OnLButtonUp(nFlags, point);
	 CClientDC aDC(this);
	 ReleaseCapture();
	// templine.EndPnt=point;
	// templine.draw(aDC);
}


void CMFCTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	    CView::OnMouseMove(nFlags, point);
	    MyPoint temppoint;   //Carray temp point
		temppoint.point=point;
		CMFCTestDoc *doc = (CMFCTestDoc *)GetDocument();
      if (this == GetCapture()&&(doc->shapenum==0))
	  {
		  CClientDC aDC(this);
		  temppoint.draw(aDC);
		  /*
	   
	   doc->Obj_Color=color;
	   if(doc->P_Type==0)
	   aDC.SetPixel(point,doc->Obj_Color );
	   else
       aDC.Ellipse(point.x - 3, point.y - 3, point.x + 3, point.y + 3);
	   ////將系統參數傳給 //Carray temp point
	   temppoint.point=point;	   
	   temppoint.color=doc->Obj_Color;
	   temppoint.Tpye=doc->P_Type;
	   doc->pArray.Add(temppoint); //記錄在 CMFCTestDoc pArray 中*/
	  }
}



void CMFCTestView::OnRed()
{
	// TODO: 在此加入您的命令處理常式程式碼
	color=RGB(255,0,0);
}


void CMFCTestView::OnGreen()
{
	// TODO: 在此加入您的命令處理常式程式碼
	color=RGB(0,255,0);
}

void CMFCTestView::OnBlue()
{
	// TODO: 在此加入您的命令處理常式程式碼
	color=RGB(0,0,255);
}

void CMFCTestView::OnUpdateRed(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	 pCmdUI->SetCheck(color == RGB(0,0,255)); 
}


void CMFCTestView::OnUpdateGreen(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	 pCmdUI->SetCheck(color == RGB(0,255,0)); 
}


void CMFCTestView::OnUpdateBlue(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	 pCmdUI->SetCheck(color == RGB(0,0,255)); 
}


void CMFCTestView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CMenu menu;
	CMenu *PopMenu;
    menu.LoadMenu(IDR_MyMenu);//載入選單資源
    PopMenu = menu.GetSubMenu(2);//取得第3個選單的指標
    PopMenu->TrackPopupMenu(TPM_CENTERALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);//建立蹦現選單
    menu.Detach();       

}


void CMFCTestView::OnExit()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CMainFrame *main;
	main = (CMainFrame *)AfxGetMainWnd();	//取得目前視窗框架物件
	if(main->m_Menu_Version==1)
	  MessageBox("It's time to Close.", "Close Window", MB_ICONSTOP);
	else
	 MessageBox("視窗即將關閉.", "關閉視窗", MB_ICONSTOP);
     AfxGetMainWnd()->PostMessage(WM_CLOSE);
}
