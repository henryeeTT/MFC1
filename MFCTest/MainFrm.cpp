
// MainFrm.cpp : CMainFrame 類別的實作
//

#include "stdafx.h"
#include "MFCTest.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_SWITCH_SWITCHMENU, &CMainFrame::OnSwitchSwitchmenu)
	ON_COMMAND(ID_SWITCH_SWITCHMENU2, &CMainFrame::OnSwitchSwitchmenu2)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 狀態列指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 建構/解構

CMainFrame::CMainFrame()
	: m_Menu_Version(0)
{
	// TODO: 在此加入成員初始化程式碼
	 ChMainMenu.LoadMenu(IDR_MAINFRAME);
	 ENMainMenu.LoadMenu(IDR_MyMenu);
	 PopMenu=new CMenu();
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("無法建立狀態列\n");
		return -1;      // 無法建立
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE | WS_SYSMENU;

	return TRUE;
}

// CMainFrame 診斷

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 訊息處理常式

void CMainFrame::OnSwitchSwitchmenu()
{
	// TODO: 在此加入您的命令處理常式程式碼
	// SetMenu(&ENMainMenu);
	// m_Menu_Version=1;

}

void CMainFrame::OnSwitchSwitchmenu2()
{
	// TODO: 在此加入您的命令處理常式程式碼
//	SetMenu(&ChMainMenu);//ChMainMenu
	//m_Menu_Version=0;
}


void CMainFrame::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
//	CMenu menu;	
//	menu.LoadMenu(IDR_MyMenu);	//載入選單資源
//	PopMenu = menu.GetSubMenu(0);	//取得第1個選單的指標
//	PopMenu-> TrackPopupMenu(TPM_CENTERALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);	//建立蹦現選單
  //  menu.Detach();		         
}
