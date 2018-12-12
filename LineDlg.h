#pragma once

class Setting;

// LineDlg 대화 상자

class LineDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LineDlg)

public:
	LineDlg(Setting *set, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~LineDlg();

	Setting *set;
	int line_opt;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	virtual void OnOK();
	CSliderCtrl Slider;
	int nPos;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMReleasedcaptureSlider(NMHDR *pNMHDR, LRESULT *pResult);
	CMFCButton btn[6];		// 도형 선택 버튼
	CImage image[6];		// 버튼의 이미지
};
