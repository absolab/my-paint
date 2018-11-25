#pragma once

// CMenuBar

class Setting;

class CMenuBar : public CWnd
{
	DECLARE_DYNAMIC(CMenuBar)

public:
	CButton **btn;
	Setting *set;

	CMenuBar();
	virtual ~CMenuBar();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColorBtnClick();
};


