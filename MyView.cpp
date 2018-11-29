
// MyView.cpp: CMyView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "My.h"
#endif

#include "MyDoc.h"
#include "MyView.h"

#include "MainFrm.h"

#include "Setting.h"
#include "Shape.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMyView 생성/소멸

CMyView::CMyView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	set = NULL;
	
}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.style |= WS_SIZEBOX;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	size = CRect(0, 60, 1000, 700);

	return CView::PreCreateWindow(cs);
}

// CMyView 그리기

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	MoveWindow(size);

	if (set != NULL) {

		// 도형 그리기
		int count = set->GetCount();

		for (int i = 0; i < count; i++) {

			Shape shape = set->GetShape(i);
			CRect rt = shape.GetRect();

			CPen pen, *oldPen;
			pen.CreatePen(PS_SOLID, shape.GetThickness(), shape.GetLineColor());	// 색깔을 객체에서 받아올 수 있는 함수 제작
			oldPen = pDC->SelectObject(&pen);

			int fill_color = shape.GetFillColor();
			int type = shape.GetType();

			if (fill_color != -1) {	// -1일 경우 채우기 색 없음

				CBrush br, *oldBr;
				br.CreateSolidBrush(fill_color);
				oldBr = pDC->SelectObject(&br);

				pDC->Rectangle(rt);

				pDC->SelectObject(oldPen);
				pDC->SelectObject(oldBr);

				pen.DeleteObject();
				br.DeleteObject();

			}
			else {
				
				if (type == 1) {

					pDC->Rectangle(rt);
				}
				else if (type == 2) {

					pDC->Ellipse(rt);
				}
				pDC->SelectObject(oldPen);

				pen.DeleteObject();

			}
		}

		// 크기 변경 버튼 그리기
		if (set->IsSelected()) {

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
	}

	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMyView 인쇄

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMyView 진단

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG



void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	mouse_down_pos = point;

	CView::OnLButtonDown(nFlags, point);
}

void CMyView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CMainFrame *p_Frame;
	p_Frame = ((CMainFrame*)AfxGetMainWnd());
	set = p_Frame->set;

	mouse_up_pos = point;

	set->Drag(mouse_down_pos, mouse_up_pos);
	set->SelectShape(point);
	
	Invalidate();
	UpdateWindow();

	CView::OnLButtonUp(nFlags, point);
}


int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	

	return 0;
}


void CMyView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	
}
