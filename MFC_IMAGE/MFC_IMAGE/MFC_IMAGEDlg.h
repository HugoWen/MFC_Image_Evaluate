
// MFC_IMAGEDlg.h : 头文件
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

// CMFC_IMAGEDlg 对话框
class CMFC_IMAGEDlg : public CDialogEx
{
// 构造
public:
	CMFC_IMAGEDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_IMAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:

	double getBright(IplImage *img1);						//返回亮度
	//int getMatch(IplImage *img1, IplImage *img2);			//返回特征点匹配个数比
	int getMatch(Mat img1, Mat img2, Mat img3, Mat img4);	//返回特征点匹配个数比
	double getPSNR(IplImage *img1, IplImage *img2);			//返回峰值信噪比
	double getStruc(IplImage *imgY, IplImage *imgC, double &brightY, double &brightC);	//返回图像结构失真度量值

	void DrawPicToHDC(IplImage *img, UINT ID);
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonLtest();
	afx_msg void OnBnClickedButtonRtest();
};
