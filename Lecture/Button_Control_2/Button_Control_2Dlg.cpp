
// Button_Control_2Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Button_Control_2.h"
#include "Button_Control_2Dlg.h"
#include "afxdialogex.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int main()
{


}


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CButtonControl2Dlg 대화 상자



CButtonControl2Dlg::CButtonControl2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BUTTON_CONTROL_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonControl2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_TEST, m_BTNCtrlTest); // 속성을 변경(control) -> connnect 여러 버튼 중에 하나의 변수를 연결 시켜줌
	// button 클릭을 통해서 무엇을 할당항지
	// 그러면 이 때 어떤 버튼을 선택할지
	// 즉 위 doDatatexchange 함수안에 값을 추가해서 속성과 버튼 선택을 가능 할 수 있다. 이때, 변수를 이용해 속성을 변경 시켜 줄 수 있음

}

BEGIN_MESSAGE_MAP(CButtonControl2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TEST, &CButtonControl2Dlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_VISIBLEON, &CButtonControl2Dlg::OnBnClickedBtnVisibleon)
	ON_BN_CLICKED(IDC_BTN_VISIBLEOFF, &CButtonControl2Dlg::OnBnClickedBtnVisibleoff)
	ON_BN_CLICKED(IDC_BTN_ACTIVEON, &CButtonControl2Dlg::OnBnClickedBtnActiveon)
	ON_BN_CLICKED(IDC_BTN_ACTIVEOFF, &CButtonControl2Dlg::OnBnClickedBtnActiveoff)
	ON_BN_CLICKED(IDC_BTN_LEFT, &CButtonControl2Dlg::OnBnClickedBtnLeft)
	ON_BN_CLICKED(IDC_BTN_RIGHT, &CButtonControl2Dlg::OnBnClickedBtnRight)
END_MESSAGE_MAP()


// CButtonControl2Dlg 메시지 처리기

BOOL CButtonControl2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CButtonControl2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CButtonControl2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CButtonControl2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CButtonControl2Dlg::OnBnClickedBtnTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CButtonControl2Dlg::OnBnClickedBtnVisibleon()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//TRACE("OnBnClickedBtnVisibleOn()\n");
	m_BTNCtrlTest.ShowWindow(SW_SHOW);

}


void CButtonControl2Dlg::OnBnClickedBtnVisibleoff()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//TRACE("OnBnClickedBtnVisibleOff()\n");
	m_BTNCtrlTest.ShowWindow(SW_HIDE);
}


void CButtonControl2Dlg::OnBnClickedBtnActiveon()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//TRACE("OnBnClickedBtnActiveOn()\n");
	m_BTNCtrlTest.EnableWindow(true);
}


void CButtonControl2Dlg::OnBnClickedBtnActiveoff()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//TRACE("OnBnClickedBtnActiveOff()\n");
	m_BTNCtrlTest.EnableWindow(false);
}


void CButtonControl2Dlg::OnBnClickedBtnLeft()
{
	
	//LPRECT pt2; // LP 값이 붙으면 무조건 포인터
	//m_BTNCtrlTest.GetClientRect(&pt);


	RECT pt;
		
	m_BTNCtrlTest.GetWindowRect(&pt); // 윈도우 모니터 기준(좌측 상단)


	TRACE("RECT(left:%d, top:%d, right:%d, bottod:%d)",pt.left, pt.top,pt.right,pt.bottom);


	pt.left  =pt.left- 10;
	pt.right = pt.right - 10;
	
	ScreenToClient(&pt); // 화면에서 프로그램 좌표계 변환 (pt좌표를 두고 바꿔줌)
	
	//위치 이동시 SWP_NOSIZE 값이 필요함
	//m_BTNCtrlTest.SetWindowPos(&CWnd::wndTop,pt.left,pt.top,0,0,SWP_SHOWWINDOW | SWP_NOSIZE|SWP_NOZORDER);

	m_BTNCtrlTest.SetWindowPos(&CWnd::wndTop, pt.left, pt.top, pt.right-pt.left, pt.bottom - pt.top, SWP_SHOWWINDOW | SWP_NOZORDER); //showwindow 다시 그리기 , nosize-> 크기 고정 
	
	
}


void CButtonControl2Dlg::OnBnClickedBtnRight()
{
	RECT pt;

	m_BTNCtrlTest.GetWindowRect(&pt);

	pt.left = pt.left + 10;
	ScreenToClient(&pt);

	m_BTNCtrlTest.SetWindowPos(&CWnd::wndTop, pt.left, pt.top, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);


}
