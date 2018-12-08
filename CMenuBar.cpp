// CMenuBar.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "CMenuBar.h"

#include "MainFrm.h"
#include "Setting.h"

#include "ColorDlg.h"
#include "TypeDlg.h"

#define		WM_OPEN_BTN			WM_USER+1
#define		WM_SAVE_BTN			WM_USER+2
#define		WM_CURSOR_BTN		WM_USER+3
#define		WM_FIGURE_BTN		WM_USER+4
#define		WM_ERASE_BTN		WM_USER+5
#define		WM_PIPETTE_BTN		WM_USER+6
#define		WM_FILL_BTN			WM_USER+7
#define		WM_LINE_BTN			WM_USER+8
#define		WM_THICKNESS_BTN		WM_USER+9
#define		WM_COLOR_BTN		WM_USER+10

// CMenuBar

IMPLEMENT_DYNAMIC(CMenuBar, CWnd)

CMenuBar::CMenuBar(Setting *set)
{
	this->set = set;
}

CMenuBar::~CMenuBar()
{
}


BEGIN_MESSAGE_MAP(CMenuBar, CWnd)
	ON_WM_CREATE()
	ON_COMMAND(WM_OPEN_BTN, OnOpenBtnClick)
	ON_COMMAND(WM_SAVE_BTN, OnSaveBtnClick)
	ON_COMMAND(WM_CURSOR_BTN, OnCursorBtnClick)
	ON_COMMAND(WM_FIGURE_BTN, OnFigureBtnClick)
	ON_COMMAND(WM_ERASE_BTN, OnEraseBtnClick)
	ON_COMMAND(WM_PIPETTE_BTN, OnPipetteBtnClick)
	ON_COMMAND(WM_FILL_BTN, OnFillBtnClick)
	ON_COMMAND(WM_LINE_BTN, OnLineBtnClick)
	ON_COMMAND(WM_THICKNESS_BTN, OnThicknessBtnClick)
	ON_COMMAND(WM_COLOR_BTN, OnColorBtnClick)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()



// CMenuBar 메시지 처리기
int CMenuBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	image[0].Load(L"Data/ButtonImage/Open.png");
	image[1].Load(L"Data/ButtonImage/Save.png");
	image[2].Load(L"Data/ButtonImage/Cursor.png");
	image[3].Load(L"Data/ButtonImage/Figure.png");
	image[4].Load(L"Data/ButtonImage/Erase.png");
	image[5].Load(L"Data/ButtonImage/Pipette.png");
	image[6].Load(L"Data/ButtonImage/Fill.png");
	image[7].Load(L"Data/ButtonImage/Line.png");
	image[8].Load(L"Data/ButtonImage/Thick.png");


	btn[0].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(5, 8, 0, 0), this, WM_OPEN_BTN);
	btn[0].SetImage(image[0].Detach());
	btn[0].SizeToContent();

	btn[1].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(60, 8, 0, 0), this, WM_SAVE_BTN);
	btn[1].SetImage(image[1].Detach());
	btn[1].SizeToContent();

	btn[2].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(115, 8, 0, 0), this, WM_CURSOR_BTN);
	btn[2].SetImage(image[2].Detach());
	btn[2].SizeToContent();

	btn[3].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(170, 8, 0, 0), this, WM_FIGURE_BTN);
	btn[3].SetImage(image[3].Detach());
	btn[3].SizeToContent();

	btn[4].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(225, 8, 0, 0), this, WM_ERASE_BTN);
	btn[4].SetImage(image[4].Detach());
	btn[4].SizeToContent();
	
	btn[5].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(280, 8, 0, 0), this, WM_PIPETTE_BTN);
	btn[5].SetImage(image[5].Detach());
	btn[5].SizeToContent();

	btn[6].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(335, 8, 0, 0), this, WM_FILL_BTN);
	btn[6].SetImage(image[6].Detach());
	btn[6].SizeToContent();

	btn[7].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(390, 8, 0, 0), this, WM_LINE_BTN);
	btn[7].SetImage(image[7].Detach());
	btn[7].SizeToContent();

	btn[8].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(445, 8, 0, 0), this, WM_THICKNESS_BTN);
	btn[8].SetImage(image[8].Detach());
	btn[8].SizeToContent();

	btn[9].Create(NULL, WS_CHILD | WS_VISIBLE, CRect(500, 8, 541, 49), this, WM_COLOR_BTN);
	btn[9].SetFaceColor(RGB(0, 0, 0), TRUE);

	return 0;
}

void CMenuBar::OnOpenBtnClick()
{
}

void CMenuBar::OnSaveBtnClick()
{
}

void CMenuBar::OnCursorBtnClick()
{
	// 일반 커서 선택
	set->SetType(0);
}



void CMenuBar::OnFigureBtnClick()
{
	// 도형 선택 다이얼로그 띄우기
	TypeDlg *p_typeDlg = new TypeDlg(set);
	p_typeDlg->DoModal();
}

void CMenuBar::OnEraseBtnClick()
{
	// 지우기 선택
	set->SetType(10);
}

void CMenuBar::OnPipetteBtnClick()
{
	// 피펫 선택
	set->SetType(11);
}

void CMenuBar::OnFillBtnClick()
{
	// 채우기 선택
	set->SetType(12);
}

void CMenuBar::OnLineBtnClick()
{
	// 선 종류 선택 다이얼로그 띄우기
}

void CMenuBar::OnThicknessBtnClick()
{
	// 두께 선택 다이얼로그 띄우기
}

void CMenuBar::OnColorBtnClick()
{
	// 컬러 선택 다이얼로그 띄우기
	static ColorDlg *p_colorDlg = new ColorDlg(set);
	p_colorDlg->DoModal();
	
	btn[9].SetFaceColor(set->GetColor());
}
