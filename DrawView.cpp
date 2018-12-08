// DrawView.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "DrawView.h"

#include "Setting.h"
#include "Shape.h"

// DrawView

IMPLEMENT_DYNAMIC(DrawView, CWnd)

DrawView::DrawView(Setting *set)
{
	this->set = set;
}

DrawView::~DrawView()
{
	/*
	 * 처리 해야할 목록
	 * 1. 도형 그릴 때 자연스럽게
	 * 2. 도형 움직일 때 자연스럽게
	 * 3. 삼각형, 오각형, 육각형, 팔각형 추가
	 * 4. 선 두께 조절
	 * 5. 색 채우기 마우스 아이콘 제작
	 * 6. 지우기 구현
	 * 7. 되돌리기, 다시실행 구현
	 * 8. 앞,뒤 순서 변경
	 */
}


BEGIN_MESSAGE_MAP(DrawView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.style |= WS_SIZEBOX;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return CWnd::PreCreateWindow(cs);
}

// 크기 조절 버튼을 그린다.
void DrawView::DrawResizeBtn(CDC *pDC)
{
	int count;

	for (int i = 0; i < 4; i++) {

		CRect resizeRect = set->GetResizeRect(i);

		CPen pen, *oldPen;;
		pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		oldPen = pDC->SelectObject(&pen);

		pDC->Rectangle(resizeRect);
		pDC->SelectObject(oldPen);
		pen.DeleteObject();
	}
}


// 도형을 그린다.
void DrawView::DrawShape(Shape shape, CDC * pDC)
{
	CRect rt = shape.GetRect();

	int type = shape.GetType();
	int thickness = shape.GetThickness();
	int line_color = shape.GetLineColor();
	int fill_color = shape.GetFillColor();

	CPen pen;
	pen.CreatePen(PS_SOLID, thickness, line_color);
	pDC->SelectObject(&pen);

	CBrush br;

	if (fill_color == -1) {

		br.CreateHatchBrush(HS_DIAGCROSS, RGB(255, 255, 255));
		pDC->SelectObject(br);
		pDC->SetBkMode(TRANSPARENT);

	} else {

		br.CreateSolidBrush(fill_color);
		pDC->SelectObject(&br);
	}

	// 도형 그리기
	switch (type) {

	case 0:		// 선택한 도형이 없음
		break;

	case 1:		// 사각형
		pDC->Rectangle(rt);
		break;

	case 2:		// 원
		pDC->Ellipse(rt);
		break;

	default:
		break;
	}

	pen.DeleteObject();
	br.DeleteObject();

}


// DrawView 메시지 처리기

void DrawView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CWnd::OnPaint()을(를) 호출하지 마십시오.
	CDC *pDC = GetDC();

	if (set != NULL) {

		// 도형 그리기
		int count = set->GetCount();

		for (int i = 0; i < count; i++) {

			DrawShape(set->GetShape(i), pDC);
		}

		// 크기 변경 버튼 그리기 
		if (set->IsSelected()) {

			DrawResizeBtn(pDC);
		}
	}

	ReleaseDC(pDC);
}

void DrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	mouse_down_pos = point;

	CWnd::OnLButtonDown(nFlags, point);
}

void DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	mouse_up_pos = point;

	set->Drag(mouse_down_pos, mouse_up_pos);
	set->SelectShape(point);

	set->SetType(0);

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();

	CWnd::OnLButtonUp(nFlags, point);
}

BOOL DrawView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (set->GetType()) {

	case 0:
		SetCursor(AfxGetApp()->LoadCursor(MAKEINTRESOURCE(IDC_MOVE)));
		break;

	case 1:
		SetCursor(AfxGetApp()->LoadCursor(MAKEINTRESOURCE(IDC_ADD_RECT)));
		break;

	case 2:
		SetCursor(AfxGetApp()->LoadCursor(MAKEINTRESOURCE(IDC_ADD_CIR)));
		break;

	case 3:
		break;
	}

	return TRUE;
}

void DrawView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	// 뒷 배경은 계속 초기화 시켜주고 싶은데 그게 잘 안되네
	GetParent()->Invalidate();
	GetParent()->UpdateWindow();
}
