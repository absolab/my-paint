#pragma once


// TypeDlg 대화 상자

class Setting;

class TypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TypeDlg)

public:
	TypeDlg(Setting *set, CWnd* pParent = nullptr);
	virtual ~TypeDlg();

	Setting *set;
	CMFCButton btn[6];		// 도형 선택 버튼
	CImage image[6];		// 버튼의 이미지

	int select;				// 사용자 

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TYPE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedRectBtn();
	afx_msg void OnBnClickedCircleBtn();
	afx_msg void OnBnClickedTriBtn();
	afx_msg void OnBnClickedPentaBtn();
	afx_msg void OnBnClickedHexBtn();
	afx_msg void OnBnClickedOctaBtn();
};
