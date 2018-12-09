#pragma once


// TypeDlg 대화 상자

class Setting;

class TypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TypeDlg)

public:
	TypeDlg(Setting *set, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~TypeDlg();

	Setting *set;
	CMFCButton btn[6];		// 버튼들
	CImage image[6];		// 각 버튼의 이미지
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TYPE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void TypeDlg::OnTriangleBtnClick();
	void TypeDlg::OnRectBtnClick();
	void TypeDlg::OnPentagonBtnClick();
	void TypeDlg::OnHexagonBtnClick();
	void TypeDlg::OnOctagonBtnClick();
	void TypeDlg::OnCircleBtnClick();
};
