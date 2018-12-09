#pragma once

// CMenuBar
class Setting;

class CMenuBar : public CWnd
{
	DECLARE_DYNAMIC(CMenuBar)

public:
	Setting *set;
	CMFCButton btn[10];
	CImage image[10];

	CMenuBar(Setting *set);
	virtual ~CMenuBar();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	void OnOpenBtnClick();
	void OnSaveBtnClick();
	void OnCursorBtnClick();
	void OnFigureBtnClick();
	void OnEraseBtnClick();
	void OnPipetteBtnClick();
	void OnLineBtnClick();
	void OnThicknessBtnClick();
	void OnFillBtnClick();
	void OnColorBtnClick();
};


