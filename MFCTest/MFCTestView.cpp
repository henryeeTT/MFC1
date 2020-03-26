
// MFCTestView.cpp : CMFCTestView ���O����@
//

#include "stdafx.h"
// SHARED_HANDLERS �i�H�w�q�b��@�w���B�Y�ϩM�j�M�z�����B�z�`����
// ATL �M�פ��A�ä��\�P�ӱM�צ@�Τ��{���X�C
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

// CMFCTestView �غc/�Ѻc

CMFCTestView::CMFCTestView()
{
	// TODO: �b���[�J�غc�{���X
     color=RGB(255,0,0);
}

CMFCTestView::~CMFCTestView()
{
}

BOOL CMFCTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �b���g�ѭק� CREATESTRUCT cs 
	// �F��ק�������O�μ˦����ت�

	return CView::PreCreateWindow(cs);
}

// CMFCTestView �yø

void CMFCTestView::OnDraw(CDC* pDC)
{	
	// TODO: �b���[�J��͸�ƪ��yø�{���X
		CMFCTestDoc *doc = (CMFCTestDoc *)GetDocument();
  	   int Pnum;
	   int i;
	   Pnum=doc->pArray.GetSize();  // ���o CMFCTestDoc �� pArray �`�I��
	   for(i=0;i<Pnum;i++)
	   {
		 if(doc->pArray[i].Tpye==0)
	      pDC->SetPixel(doc->pArray[i].point,doc->pArray[i].color );
	     else
          pDC->Ellipse(doc->pArray[i].point.x - 3, doc->pArray[i].point.y - 3, doc->pArray[i].point.x + 3, doc->pArray[i].point.y + 3);
	   }
}


// CMFCTestView �E�_

#ifdef _DEBUG
void CMFCTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTestDoc* CMFCTestView::GetDocument() const // ���O�D��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTestDoc)));
	return (CMFCTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTestView �T���B�z�`��


void CMFCTestView::OnDrawPoint()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
	CMFCTestDoc *doc = (CMFCTestDoc *)GetDocument();//���o CMFCTestDoc ���Ъ���
    doc->shapenum=0;  //�e�I
  //  doc->Obj_Color=RGB(0,0,255);  //�����C��
    doc->Obj_Color=color;  //�����C��
	doc->P_Type=0; //�t���I�`��  0:�I 1:���I
}



void CMFCTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	CView::OnLButtonDown(nFlags, point);

	SetCapture();
	   
	//templine.StartPnt=point;
}


void CMFCTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��

	CView::OnLButtonUp(nFlags, point);
	 CClientDC aDC(this);
	 ReleaseCapture();
	// templine.EndPnt=point;
	// templine.draw(aDC);
}


void CMFCTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
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
	   ////�N�t�ΰѼƶǵ� //Carray temp point
	   temppoint.point=point;	   
	   temppoint.color=doc->Obj_Color;
	   temppoint.Tpye=doc->P_Type;
	   doc->pArray.Add(temppoint); //�O���b CMFCTestDoc pArray ��*/
	  }
}



void CMFCTestView::OnRed()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
	color=RGB(255,0,0);
}


void CMFCTestView::OnGreen()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
	color=RGB(0,255,0);
}

void CMFCTestView::OnBlue()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
	color=RGB(0,0,255);
}

void CMFCTestView::OnUpdateRed(CCmdUI *pCmdUI)
{
	// TODO: �b���[�J�z���R�O��s UI �B�z�`���{���X
	 pCmdUI->SetCheck(color == RGB(0,0,255)); 
}


void CMFCTestView::OnUpdateGreen(CCmdUI *pCmdUI)
{
	// TODO: �b���[�J�z���R�O��s UI �B�z�`���{���X
	 pCmdUI->SetCheck(color == RGB(0,255,0)); 
}


void CMFCTestView::OnUpdateBlue(CCmdUI *pCmdUI)
{
	// TODO: �b���[�J�z���R�O��s UI �B�z�`���{���X
	 pCmdUI->SetCheck(color == RGB(0,0,255)); 
}


void CMFCTestView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X
	CMenu menu;
	CMenu *PopMenu;
    menu.LoadMenu(IDR_MyMenu);//���J���귽
    PopMenu = menu.GetSubMenu(2);//���o��3�ӿ�檺����
    PopMenu->TrackPopupMenu(TPM_CENTERALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);//�إ��۲{���
    menu.Detach();       

}


void CMFCTestView::OnExit()
{
	// TODO: �b���[�J�z���R�O�B�z�`���{���X
	CMainFrame *main;
	main = (CMainFrame *)AfxGetMainWnd();	//���o�ثe�����ج[����
	if(main->m_Menu_Version==1)
	  MessageBox("It's time to Close.", "Close Window", MB_ICONSTOP);
	else
	 MessageBox("�����Y�N����.", "��������", MB_ICONSTOP);
     AfxGetMainWnd()->PostMessage(WM_CLOSE);
}
