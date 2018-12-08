#pragma once

// CMenuBar
class Setting;

class CMenuBar : public CWnd
{
	DECLARE_DYNAMIC(CMenuBar)

public:
	Setting *set;
	CMFCButton **btn;

	CMenuBar(Setting *set);
	virtual ~CMenuBar();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColorBtnClick();
	afx_msg void OnTypeBtnClick();
	afx_msg void OnFillBtnClick();
};


