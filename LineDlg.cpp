// LineDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "My.h"
#include "LineDlg.h"
#include "afxdialogex.h"
#include "string.h"
#include "Setting.h"

// LineDlg 대화 상자

IMPLEMENT_DYNAMIC(LineDlg, CDialogEx)

LineDlg::LineDlg(Setting *set, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LINE_DLG, pParent)
{
	this->set = set;
}

LineDlg::~LineDlg()
{
}

void LineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER2, Slider);
}


BEGIN_MESSAGE_MAP(LineDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LineDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LineDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &LineDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &LineDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &LineDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &LineDlg::OnBnClickedButton6)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, &LineDlg::OnNMReleasedcaptureSlider)
END_MESSAGE_MAP()


// LineDlg 메시지 처리기


void LineDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_SOLID;
}


void LineDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_DASH;
}


void LineDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_DOT;
}


void LineDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_DASHDOT;
}


void LineDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_DASHDOTDOT;
}


void LineDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	line_opt = PS_NULL;
}


void LineDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	set->SetLineOpt(line_opt);

	GetParent()->Invalidate();
	GetParent()->UpdateWindow();

	CDialogEx::OnOK();
}


BOOL LineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	Slider.SetRange(0, 10);
	Slider.SetRangeMin(0);
	Slider.SetRangeMax(10);
	Slider.SetTicFreq(1);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void LineDlg::OnNMReleasedcaptureSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	 nPos = Slider.GetPos();
	 set->SetThickness(nPos);
	*pResult = 0;
}
