
// MFC_IMAGEDlg.h : ͷ�ļ�
//
#include <stdio.h>
#include <iostream>
#include "cv.h"
#include "highgui.h"
#include "CvvImage.h"
#include <opencv2\nonfree\features2d.hpp>
#include <opencv2\legacy\legacy.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\flann\flann.hpp>

#include "math.h"

#pragma once

using namespace cv;

// CMFC_IMAGEDlg �Ի���
class CMFC_IMAGEDlg : public CDialogEx
{
// ����
public:
	CMFC_IMAGEDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_IMAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:

	double getBright(IplImage *img1);						//��������
	//int getMatch(IplImage *img1, IplImage *img2);			//����������ƥ�������
	int getMatch(Mat img1, Mat img2, Mat img3, Mat img4);	//����������ƥ�������
	double getPSNR(IplImage *img1, IplImage *img2);			//���ط�ֵ�����
	double getStruc(IplImage *imgY, IplImage *imgC, double &brightY, double &brightC);	//����ͼ��ṹʧ�����ֵ

	void DrawPicToHDC(IplImage *img, UINT ID);
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonLtest();
	afx_msg void OnBnClickedButtonRtest();
};
