// ColorDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "ColorDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Setting.h"

// ColorDlg 대화 상자

IMPLEMENT_DYNAMIC(ColorDlg, CDialogEx)

ColorDlg::ColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COLOR_DLG, pParent)
{
	set = ((CMainFrame*)AfxGetMainWnd())->set; 
}

ColorDlg::~ColorDlg()
{
}

void ColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ColorDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RED_BTN, &ColorDlg::OnBnClickedRedBtn)
	ON_BN_CLICKED(IDC_BLUE_BTN, &ColorDlg::OnBnClickedBlueBtn)
END_MESSAGE_MAP()


// ColorDlg 메시지 처리기


void ColorDlg::OnBnClickedRedBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	set->SetSelectedColor(RGB(255, 0, 0));
}


void ColorDlg::OnBnClickedBlueBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	set->SetSelectedColor(RGB(0, 0, 255));
}
