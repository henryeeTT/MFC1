
// MainFrm.cpp : CMainFrame ���O����@
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
	ID_SEPARATOR,           // ���A�C���ܾ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame �غc/�Ѻc

CMainFrame::CMainFrame()
	: m_Menu_Version(0)
{
	// TODO: �b���[�J������l�Ƶ{���X
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
		TRACE0("�L�k�إߪ��A�C\n");
		return -1;      // �L�k�إ�
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �b���g�ѭק� CREATESTRUCT cs 
	// �F��ק�������O�μ˦����ت�

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE | WS_SYSMENU;

	return TRUE;
}

// CMainFrame �E�_

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


// CMainFrame �T���B�z�`��

void CMainFrame::OnSwitchSwitchmenu()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
	// SetMenu(&ENMainMenu);
	// m_Menu_Version=1;

}

void CMainFrame::OnSwitchSwitchmenu2()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
//	SetMenu(&ChMainMenu);//ChMainMenu
	//m_Menu_Version=0;
}


void CMainFrame::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X
//	CMenu menu;	
//	menu.LoadMenu(IDR_MyMenu);	//���J���귽
//	PopMenu = menu.GetSubMenu(0);	//���o��1�ӿ�檺����
//	PopMenu-> TrackPopupMenu(TPM_CENTERALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);	//�إ��۲{���
  //  menu.Detach();		         
}
