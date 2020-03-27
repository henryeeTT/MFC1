
// MFCTest.cpp : 定義應用程式的類別行為。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCTest.h"
#include "MainFrm.h"

#include "MFCTestDoc.h"
#include "MFCTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTestApp

BEGIN_MESSAGE_MAP(CMFCTestApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMFCTestApp::OnAppAbout)
	// 依據文件命令的標準檔案
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// CMFCTestApp 建構

CMFCTestApp::CMFCTestApp()
{
	// TODO: 以唯一的 ID 字串取代下面的應用程式 ID 字串; 建議的
	// 字串格式為 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCTest.AppID.NoVersion"));

	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}

// 僅有的一個 CMFCTestApp 物件

CMFCTestApp theApp;


// CMFCTestApp 初始設定

BOOL CMFCTestApp::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// 需要有 AfxInitRichEdit2() 才能使用 RichEdit 控制項	
	// AfxInitRichEdit2();

	// 標準初始設定
	// 如果您不使用這些功能並且想減少
	// 最後完成的可執行檔大小，您可以
	// 從下列程式碼移除不需要的初始化常式，
	// 變更儲存設定值的登錄機碼
	// TODO: 您應該適度修改此字串
	// (例如，公司名稱或組織名稱)
	SetRegistryKey(_T("本機 AppWizard 所產生的應用程式"));
	LoadStdProfileSettings(4);  // 載入標準 INI 檔選項 (包含 MRU)


	// 登錄應用程式的文件範本。文件範本負責在文件、
	// 框架視窗與檢視間進行連接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
			/*IDR_MAINFRAME*/IDR_MyMenu,
		//IDR_MAINFRAME,
		RUNTIME_CLASS(CMFCTestDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架視窗
		RUNTIME_CLASS(CMFCTestView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// 剖析標準 Shell 命令、DDE、檔案開啟舊檔的命令列
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 在命令列中指定的分派命令。如果已使用 
	// /RegServer、/Register、/Unregserver 或 /Unregister 啟動應用程式，將傳回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	m_pMainWnd->SetWindowText("803220001 吳大二 803220003 游大二 ");
	// 僅初始化一個視窗，所以顯示並更新該視窗
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	// 只有在 SDI 應用程式中有後置字元時，才呼叫 DragAcceptFiles
	// 這會發生於 ProcessShellCommand 之後
	return TRUE;
}

// CMFCTestApp 訊息處理常式


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 執行對話方塊的應用程式命令
void CMFCTestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCTestApp 訊息處理常式



