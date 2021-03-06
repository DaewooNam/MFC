
// Button_Control_2Dlg.h: 헤더 파일
//

#pragma once


// CButtonControl2Dlg 대화 상자
class CButtonControl2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CButtonControl2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUTTON_CONTROL_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnTest();
	afx_msg void OnBnClickedBtnVisibleon();
	afx_msg void OnBnClickedBtnVisibleoff();
	afx_msg void OnBnClickedBtnActiveon();
	afx_msg void OnBnClickedBtnActiveoff();

	CButton m_BTNCtrlTest; // 마법사가 연결해줌

	afx_msg void OnBnClickedBtnLeft();
	afx_msg void OnBnClickedBtnRight();
};
