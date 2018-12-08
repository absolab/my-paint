// CMenuBar.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "CMenuBar.h"

#include "MainFrm.h"
#include "Setting.h"

#include "ColorDlg.h"
#include "TypeDlg.h"

#define WM_TYPEBTN WM_USER+1
#define WM_COLORBTN WM_USER+2
#define WM_FILLBTN WM_USER+3

// CMenuBar

IMPLEMENT_DYNAMIC(CMenuBar, CWnd)

CMenuBar::CMenuBar(Setting *set)
{
	btn = new CMFCButton*[7];
	this->set = set;
}

CMenuBar::~CMenuBar()
{
}


BEGIN_MESSAGE_MAP(CMenuBar, CWnd)
	ON_WM_CREATE()
	ON_COMMAND(WM_TYPEBTN, OnTypeBtnClick)
	ON_COMMAND(WM_COLORBTN, OnColorBtnClick)
	ON_COMMAND(WM_FILLBTN, OnFillBtnClick)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()



// CMenuBar 메시지 처리기
int CMenuBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	btn[0] = new CMFCButton();
	btn[0]->Create(L"열기", WS_CHILD | WS_VISIBLE, CRect(5, 5, 55, 55), this, 999);

	btn[1] = new CMFCButton();
	btn[1]->Create(L"저장", WS_CHILD | WS_VISIBLE, CRect(60, 5, 110, 55), this, 888);

	btn[2] = new CMFCButton();
	btn[2]->Create(L"도구", WS_CHILD | WS_VISIBLE, CRect(115, 5, 165, 55), this, WM_TYPEBTN);

	btn[3] = new CMFCButton();
	btn[3]->Create(L"두께", WS_CHILD | WS_VISIBLE, CRect(170, 5, 220, 55), this, 666);

	btn[4] = new CMFCButton();
	btn[4]->Create(NULL, WS_CHILD | WS_VISIBLE, CRect(235, 5, 265, 35), this, WM_COLORBTN);
	btn[4]->SetFaceColor(RGB(0, 0, 0), TRUE);

	btn[5] = new CMFCButton();
	btn[5]->Create(L"채움", WS_CHILD | WS_VISIBLE, CRect(280, 5, 330, 55), this, WM_FILLBTN);

	return 0;
}


void CMenuBar::OnColorBtnClick()
{
	// 컬러 선택 다이얼로그 띄우기
	ColorDlg *p_colorDlg = new ColorDlg(set);
	p_colorDlg->DoModal();
	btn[4]->SetFaceColor(set->GetColor());
}

void CMenuBar::OnTypeBtnClick()
{
	// 타입 선택 다이얼로그 띄우기
	TypeDlg *p_typeDlg = new TypeDlg(set);
	p_typeDlg->DoModal();
}

void CMenuBar::OnFillBtnClick()
{
	// 채우기 동작
	set->FillShape();

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();

}
