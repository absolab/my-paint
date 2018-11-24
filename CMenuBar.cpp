// CMenuBar.cpp: 구현 파일

#include "stdafx.h"
#include "My.h"
#include "CMenuBar.h"


// CMenuBar

IMPLEMENT_DYNAMIC(CMenuBar, CWnd)

CMenuBar::CMenuBar()
{
	btn = new CButton*[6];
}

CMenuBar::~CMenuBar()
{
}


BEGIN_MESSAGE_MAP(CMenuBar, CWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CMenuBar 메시지 처리기




int CMenuBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	btn[0] = new CButton();
	btn[0]->Create(L"열기", WS_CHILD | WS_VISIBLE, CRect(0, 0, 90, 30), this, 999);

	btn[1] = new CButton();
	btn[1]->Create(L"저장", WS_CHILD | WS_VISIBLE, CRect(100, 0, 190, 30), this, 888);

	btn[2] = new CButton();
	btn[2]->Create(L"도구 선택", WS_CHILD | WS_VISIBLE, CRect(200, 0, 290, 30), this, 777);

	btn[3] = new CButton();
	btn[3]->Create(L"두께 조절", WS_CHILD | WS_VISIBLE, CRect(300, 0, 390, 30), this, 666);

	btn[4] = new CButton();
	btn[4]->Create(L"색깔 선택", WS_CHILD | WS_VISIBLE, CRect(400, 0, 490, 30), this, 555);

	return 0;
}
