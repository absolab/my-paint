// CBoard.cpp: 구현 파일

#include "stdafx.h"
#include "My.h"
#include "CBoard.h"


// CBoard

IMPLEMENT_DYNAMIC(CBoard, CWnd)

CBoard::CBoard()
{
	
}

CBoard::~CBoard()
{
}


BEGIN_MESSAGE_MAP(CBoard, CWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CBoard 메시지 처리기




int CBoard::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	MoveWindow(CRect(0, 0, 400, 400));

	return 0;
}
