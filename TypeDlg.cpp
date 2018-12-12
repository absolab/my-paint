// TypeDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "TypeDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Setting.h"

// TypeDlg 대화 상자
#define		WM_TOOL_TRIANGLE_BTN		WM_USER+11
#define		WM_TOOL_RECT_BTN			WM_USER+12
#define		WM_TOOL_PENTAGON_BTN		WM_USER+13
#define		WM_TOOL_HEXAGON_BTN			WM_USER+14
#define		WM_TOOL_OCTAGON_BTN			WM_USER+15
#define		WM_TOOL_CIRCLE_BTN			WM_USER+16

IMPLEMENT_DYNAMIC(TypeDlg, CDialogEx)

TypeDlg::TypeDlg(Setting *set, CWnd* pParent /*=nullptr*/) : CDialogEx(IDD_TYPE_DLG, pParent)
{
	this->set = set;
}

TypeDlg::~TypeDlg()
{
}

void TypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TypeDlg, CDialogEx)
	ON_COMMAND(WM_TOOL_TRIANGLE_BTN, OnTriangleBtnClick)
	ON_COMMAND(WM_TOOL_RECT_BTN, OnRectBtnClick)
	ON_COMMAND(WM_TOOL_PENTAGON_BTN, OnPentagonBtnClick)
	ON_COMMAND(WM_TOOL_PENTAGON_BTN, OnHexagonBtnClick)
	ON_COMMAND(WM_TOOL_OCTAGON_BTN, OnHexagonBtnClick)
	ON_COMMAND(WM_TOOL_CIRCLE_BTN, OnCircleBtnClick)
END_MESSAGE_MAP()


// TypeDlg 메시지 처리기
void TypeDlg::OnTriangleBtnClick()
{
}

void TypeDlg::OnRectBtnClick()
{
	set->SetType(1);
}

void TypeDlg::OnPentagonBtnClick()
{
}

void TypeDlg::OnHexagonBtnClick()
{
}

void TypeDlg::OnOctagonBtnClick()
{
}

void TypeDlg::OnCircleBtnClick()
{
	set->SetType(2);
}

BOOL TypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	image[0].Load(L"Data/ButtonImage/Tool_triangle.png");
	image[1].Load(L"Data/ButtonImage/Tool_rect.png");
	image[2].Load(L"Data/ButtonImage/Tool_pentagon.png");
	image[3].Load(L"Data/ButtonImage/Tool_hexagon.png");
	image[4].Load(L"Data/ButtonImage/Tool_octagon.png");
	image[5].Load(L"Data/ButtonImage/Tool_circle.png");

	btn[0].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(5, 8, 0, 0), this, WM_TOOL_TRIANGLE_BTN);
	btn[0].SetImage(image[0].Detach());
	btn[0].SizeToContent();

	btn[1].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(60, 8, 0, 0), this, WM_TOOL_RECT_BTN);
	btn[1].SetImage(image[1].Detach());
	btn[1].SizeToContent();

	btn[2].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(115, 8, 0, 0), this, WM_TOOL_PENTAGON_BTN);
	btn[2].SetImage(image[2].Detach());
	btn[2].SizeToContent();

	btn[3].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(170, 8, 0, 0), this, WM_TOOL_HEXAGON_BTN);
	btn[3].SetImage(image[3].Detach());
	btn[3].SizeToContent();

	btn[4].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(225, 8, 0, 0), this, WM_TOOL_OCTAGON_BTN);
	btn[4].SetImage(image[4].Detach());
	btn[4].SizeToContent();

	btn[5].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(280, 8, 0, 0), this, WM_TOOL_CIRCLE_BTN);
	btn[5].SetImage(image[5].Detach());
	btn[5].SizeToContent();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

