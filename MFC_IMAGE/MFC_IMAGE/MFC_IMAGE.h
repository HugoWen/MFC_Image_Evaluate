
// MFC_IMAGE.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_IMAGEApp: 
// �йش����ʵ�֣������ MFC_IMAGE.cpp
//

class CMFC_IMAGEApp : public CWinApp
{
public:
	CMFC_IMAGEApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_IMAGEApp theApp;