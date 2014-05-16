
// MFC_IMAGEDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_IMAGE.h"
#include "MFC_IMAGEDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_IMAGEDlg 对话框



CMFC_IMAGEDlg::CMFC_IMAGEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_IMAGEDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_IMAGEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_IMAGEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Left, &CMFC_IMAGEDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_Right, &CMFC_IMAGEDlg::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_Start, &CMFC_IMAGEDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_LTest, &CMFC_IMAGEDlg::OnBnClickedButtonLtest)
	ON_BN_CLICKED(IDC_BUTTON_RTest, &CMFC_IMAGEDlg::OnBnClickedButtonRtest)
END_MESSAGE_MAP()


// CMFC_IMAGEDlg 消息处理程序

BOOL CMFC_IMAGEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_IMAGEDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_IMAGEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_IMAGEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//显示图像
void CMFC_IMAGEDlg::DrawPicToHDC(IplImage *img, UINT ID)
{
	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	CvvImage cimg;
	cimg.CopyOf(img);	//复制图片
	cimg.DrawToHDC(hDC, &rect);		//将图片绘制到显示控件的指定区域内
	ReleaseDC(pDC);
	
}

//打开左视图
void CMFC_IMAGEDlg::OnBnClickedButtonLeft()
{
	// TODO:  在此添加控件通知处理程序代码
	IplImage *imagel = NULL;		//左视图图像
	if (imagel)
		cvReleaseImage(&imagel);
	imagel = cvLoadImage("F:\\yl.jpg");
	DrawPicToHDC(imagel, IDC_STATIC_Left);
}

//打开右视图
void CMFC_IMAGEDlg::OnBnClickedButtonRight()
{
	// TODO:  在此添加控件通知处理程序代码
	IplImage *imager = NULL;		//右视图图像
	if (imager)
		cvReleaseImage(&imager);
	imager = cvLoadImage("F:\\yr.jpg");
	DrawPicToHDC(imager, IDC_STATIC_Right);
}

//获取图像平均亮度
double CMFC_IMAGEDlg::getBright(IplImage *img)
{
	double brightValue = 0.000;
	Mat mat(img, false);		//将IplImage图像转换成Mat格式
	//Mat mat1 = Mat::zeros(mat.size(), mat.type);	//对mat进行0初始化为mat1
	//Mat mat = imread("F:\\2.jpg");
	for (int x = 0; x < mat.rows; x++)
	{
		for (int y = 0; y < mat.cols; y++)
		{
			//计算每一点像素的累加和
			brightValue = brightValue + mat.at<Vec3b>(x, y)[0] * 0.299 + mat.at<Vec3b>(x, y)[1] * 0.587 + mat.at<Vec3b>(x, y)[2] * 0.114;
		}
	}

	brightValue = brightValue / mat.rows / mat.cols;	//计算平均亮度值
	return brightValue;		//返回平均亮度值
}

//开始评测处理
void CMFC_IMAGEDlg::OnBnClickedButtonStart()
{
	// TODO:  在此添加控件通知处理程序代码

	double brightcl, brightcr, brightyl, brightyr;
	int matchy, matchc;
	double strucL, strucR, LumaLR, HVSL, HVSR;
	int Match = 0;
	double score = 0.000;

	//载入图像
	//为了方便测试，我是直接写死在这的，可以修改成可选择文件形式
	IplImage *imgyl = cvLoadImage("F:\\yl.jpg");
	IplImage *imgyr = cvLoadImage("F:\\yr.jpg");
	IplImage *imgcl = cvLoadImage("F:\\cl.jpg");
	IplImage *imgcr = cvLoadImage("F:\\cr.jpg");

	IplImage *imgyl0 = cvLoadImage("F:\\yl.jpg", 0);
	IplImage *imgyr0 = cvLoadImage("F:\\yr.jpg", 0);
	IplImage *imgcl0 = cvLoadImage("F:\\cl.jpg", 0);
	IplImage *imgcr0 = cvLoadImage("F:\\cr.jpg", 0);

	brightcl = getBright(imgcl);
	brightcr = getBright(imgcr);
	LumaLR = brightcl / brightcr;
	LumaLR *= 5;	//5分制

	brightyl = getBright(imgyl);
	brightyr = getBright(imgyr);
	//strucL = getStruc(imgyl, imgcl, brightyl, brightcl);
	//strucR = getStruc(imgyr, imgcr, brightyr, brightcr);


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	double brightValueYL = 0.000;	//原图像的亮度值
	double brightValueCL = 0.000;	//测试图像的亮度值
	double brightPixelYL = 0.000;	//原图像像素点亮度值
	double brightPixelCL = 0.000;	//测试图像像素点亮度值
	double brightValueYCL = 0.000;
	double lL, cL, sL, ssimL;

	Mat matYL(imgyl, false);		//将IplImage图像转换成Mat格式
	Mat matCL(imgcl, false);

	for (int x = 0; x < matYL.rows; x++)
	{
		for (int y = 0; y < matYL.cols; y++)
		{
			brightPixelYL = matYL.at<Vec3b>(x, y)[0] * 0.299 + matYL.at<Vec3b>(x, y)[1] * 0.587 + matYL.at<Vec3b>(x, y)[2] * 0.114 - brightyl;
			brightPixelCL = matCL.at<Vec3b>(x, y)[0] * 0.299 + matCL.at<Vec3b>(x, y)[1] * 0.587 + matCL.at<Vec3b>(x, y)[2] * 0.114 - brightyl;

			brightValueYCL = brightValueYCL + brightPixelYL * brightPixelCL;

			brightValueYL = brightValueYL + brightPixelYL * brightPixelYL;
			brightValueCL = brightValueCL + brightPixelCL * brightPixelCL;

		}
	}

	brightValueYL = brightValueYL / (matYL.rows - 1) / (matYL.cols - 1);
	brightValueYL = sqrt(brightValueYL);		//原图像平均亮度标准差

	brightValueCL = brightValueCL / (matCL.rows - 1) / (matCL.cols - 1);
	brightValueCL = sqrt(brightValueCL);		//测试图像平均亮度标准差

	brightValueYCL = brightValueYCL / (matCL.rows - 1) / (matCL.cols - 1);	//协方差

	lL = 2 * brightyl * brightcl / (brightyl * brightyl + brightcl * brightcl);	//亮度比较函数值
	cL = 2 * brightValueYL * brightValueCL / (brightValueYL * brightValueYL + brightValueCL * brightValueCL);	//对比度比较函数值
	sL = brightValueYCL / brightValueYL / brightValueCL;	//结构相似性比较函数值

	ssimL = lL * cL * sL;	//结构失真度评价值


	double brightValueYR = 0.000;	//原图像的亮度值
	double brightValueCR = 0.000;	//测试图像的亮度值
	double brightPixelYR = 0.000;	//原图像像素点亮度值
	double brightPixelCR = 0.000;	//测试图像像素点亮度值
	double brightValueYCR = 0.000;
	double lR, cR, sR, ssimR;

	Mat matYR(imgyr, false);		//将IplImage图像转换成Mat格式
	Mat matCR(imgcr, false);

	for (int x = 0; x < matYR.rows; x++)
	{
		for (int y = 0; y < matYR.cols; y++)
		{
			brightPixelYR = matYR.at<Vec3b>(x, y)[0] * 0.299 + matYR.at<Vec3b>(x, y)[1] * 0.587 + matYR.at<Vec3b>(x, y)[2] * 0.114 - brightyr;
			brightPixelCR = matCR.at<Vec3b>(x, y)[0] * 0.299 + matCR.at<Vec3b>(x, y)[1] * 0.587 + matCR.at<Vec3b>(x, y)[2] * 0.114 - brightyr;

			brightValueYCR = brightValueYCR + brightPixelYR * brightPixelCR;

			brightValueYR = brightValueYR + brightPixelYR * brightPixelYR;
			brightValueCR = brightValueCR + brightPixelCR * brightPixelCR;

		}
	}

	brightValueYR = brightValueYR / (matYR.rows - 1) / (matYR.cols - 1);
	brightValueYR = sqrt(brightValueYR);		//原图像平均亮度标准差

	brightValueCR = brightValueCR / (matCR.rows - 1) / (matCR.cols - 1);
	brightValueCR = sqrt(brightValueCR);		//测试图像平均亮度标准差

	brightValueYCR = brightValueYCR / (matCR.rows - 1) / (matCR.cols - 1);	//协方差

	lR = 2 * brightyl * brightcl / (brightyl * brightyl + brightcl * brightcl);	//亮度比较函数值
	cR = 2 * brightValueYR * brightValueCR / (brightValueYR * brightValueYR + brightValueCR * brightValueCR);	//对比度比较函数值
	sR = brightValueYCR / brightValueYR / brightValueCR;	//结构相似性比较函数值

	ssimR = lR * cR * sR;	//结构失真度评价值
	
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

	strucL = ssimL;
	strucR = ssimR;

	if (strucL < 1 && strucL > 0)
		strucL *= 5;
	else strucL = 5;
	if (strucR < 1 && strucR > 0)
		strucR *= 5;
	else strucR = 5;

	//载入Mat形式灰度图像
	//同样直接写死，可修改
	Mat matyl = imread("F:\\yl.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat matyr = imread("F:\\yr.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat matcl = imread("F:\\cl.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat matcr = imread("F:\\cr.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	//matchy = getMatch(matyl, matyr);
	//matchy = 1;
	//matchc = getMatch(matcl, matcr);
	//Match = matchy / matchc;
	Match = getMatch(matyl, matyr, matcl, matcr);
	Match *= 5;

	HVSL = getPSNR(imgyl0, imgcl0);
	HVSR = getPSNR(imgyr0, imgcr0);
	if (HVSL <= 45)
		HVSL = HVSL / 45 * 5;
	else HVSL = 5;
	if (HVSR <= 45)
		HVSR = HVSR / 45 * 5;
	else HVSR = 5;


	//计算分数
	score = (strucL + strucR + LumaLR + HVSL + HVSR) * Match / 5 / 5;

	//显示处理
	CString CstrucL, CstrucR, CLumaLR, CHVSL, CHVSR, CMatch, Cscore;
	CstrucL.Format(_T("%3f"), strucL);
	CstrucR.Format(_T("%3f"), strucR);
	CLumaLR.Format(_T("%3f"), LumaLR);
	CHVSL.Format(_T("%3f"), HVSL);
	CHVSR.Format(_T("%3f"), HVSR);
	CMatch.Format(_T("%d"), Match);
	Cscore.Format(_T("%3f"), score);

	CEdit *pEditStrucL, *pEditStrucR, *pLumaLR, *pEditHVSL, *pEditHVSR, *pEditMatch, *pEditScore;

	pEditStrucL = (CEdit*)GetDlgItem(IDC_EDIT_StrucL);
	pEditStrucL->SetWindowTextW(CstrucL);
	pEditStrucR = (CEdit*)GetDlgItem(IDC_EDIT_StrucR);
	pEditStrucR->SetWindowTextW(CstrucR);
	pEditHVSL = (CEdit*)GetDlgItem(IDC_EDIT_HVSL);
	pEditHVSL->SetWindowTextW(CHVSL);
	pEditHVSR = (CEdit*)GetDlgItem(IDC_EDIT_HVSR);
	pEditHVSR->SetWindowTextW(CHVSR);
	pEditMatch = (CEdit*)GetDlgItem(IDC_EDIT_Match);
	pEditMatch->SetWindowTextW(CMatch);
	pLumaLR = (CEdit*)GetDlgItem(IDC_EDIT_LumaLR);
	pLumaLR->SetWindowTextW(CLumaLR);
	pEditScore = (CEdit*)GetDlgItem(IDC_EDIT_Score);
	pEditScore->SetWindowTextW(Cscore);
	

}

//打开左测试视图
void CMFC_IMAGEDlg::OnBnClickedButtonLtest()
{
	// TODO:  在此添加控件通知处理程序代码
	IplImage *imagel = NULL;		//左视图图像
	if (imagel)
		cvReleaseImage(&imagel);
	imagel = cvLoadImage("F:\\cl.jpg");
	DrawPicToHDC(imagel, IDC_STATIC_LTest);
}

//打开右测试视图
void CMFC_IMAGEDlg::OnBnClickedButtonRtest()
{
	// TODO:  在此添加控件通知处理程序代码
	IplImage *imagel = NULL;		//左视图图像
	if (imagel)
		cvReleaseImage(&imagel);
	imagel = cvLoadImage("F:\\cr.jpg");
	DrawPicToHDC(imagel, IDC_STATIC_RTest);
}


//获取两幅图像匹配点个数
//int CMFC_IMAGEDlg::getMatch(IplImage *img1, IplImage *img2)
int CMFC_IMAGEDlg::getMatch(Mat img1, Mat img2, Mat img3, Mat img4)
{
	//Mat mat1(img1, false);		//将IplImage图像转换成Mat格式
	//Mat mat2(img2, false);

	int pointCounts1 = 0;	//特征点个数
	int pointCounts2 = 0;

	//检测surf特征点
	std::vector<KeyPoint> keypoints1, keypoints2;
	int minHessian = 400;
	SurfFeatureDetector detector1(minHessian);
	detector1.detect(img1, keypoints1);
	detector1.detect(img3, keypoints2);

	//描述surf特征点
	SurfDescriptorExtractor surfDesc1;
	Mat descriptros1, descriptros2;
	surfDesc1.compute(img1, keypoints1, descriptros1);
	surfDesc1.compute(img3, keypoints2, descriptros2);

	pointCounts1 = keypoints1.size();
	pointCounts2 = keypoints2.size();

	return pointCounts1 / pointCounts2;

	/*
	//计算匹配点数
	BruteForceMatcher<L2<float>>matcher;
	std::vector<DMatch> matches;
	matcher.match(descriptros1, descriptros2, matches);
	//std::nth_element(matches.begin(), matches.begin() + 24, matches.end());		//特征点排序
	//matches.erase(matches.begin() + 25, matches.end());		//擦除25之后特征点
	//for (int i = matches.begin(); i < matches.end(); i++)
	int matchCount = 0;
	matchCount = matches.end() - matches.begin();	//匹配点个数
	return 0
	*/
}

//获取峰值信噪比
double CMFC_IMAGEDlg::getPSNR(IplImage *img1, IplImage *img2)
{
	IplImage *dst = cvCreateImage(cvGetSize(img1), 8, 1);
	cvAbsDiff(img1, img2, dst);
	CvScalar stddev;
	cvAvgSdv(dst, NULL, &stddev);
	double psnr = 20 * log10(255 / stddev.val[0]);
	//cvReleaseImage(&dst);
	return psnr;
}

//获取图像结构失真度评价值
double getStruc(IplImage *imgY, IplImage *imgC, double &brightY, double &brightC)
{
	double brightValueY = 0.000;	//原图像的亮度值
	double brightValueC = 0.000;	//测试图像的亮度值
	double brightPixelY = 0.000;	//原图像像素点亮度值
	double brightPixelC = 0.000;	//测试图像像素点亮度值
	double brightValueYC = 0.000;
	double l, c, s, ssim;

	Mat matY(imgY, false);		//将IplImage图像转换成Mat格式
	Mat matC(imgC, false);

	for (int x = 0; x < matY.rows; x++)
	{
		for (int y = 0; y < matY.cols; y++)
		{
			brightPixelY = matY.at<Vec3b>(x, y)[0] * 0.299 + matY.at<Vec3b>(x, y)[1] * 0.587 + matY.at<Vec3b>(x, y)[2] * 0.114 - brightY;
			brightPixelC = matC.at<Vec3b>(x, y)[0] * 0.299 + matC.at<Vec3b>(x, y)[1] * 0.587 + matC.at<Vec3b>(x, y)[2] * 0.114 - brightC;
			
			brightValueYC = brightValueYC + brightPixelY * brightPixelC;

			brightValueY = brightValueY + brightPixelY * brightPixelY;
			brightValueC = brightValueC + brightPixelC * brightPixelC;

		}
	}

	brightValueY = brightValueY / (matY.rows - 1) / (matY.cols - 1);	
	brightValueY = sqrt(brightValueY);		//原图像平均亮度标准差

	brightValueC = brightValueC / (matC.rows - 1) / (matC.cols - 1);
	brightValueC = sqrt(brightValueC);		//测试图像平均亮度标准差

	brightValueYC = brightValueYC / (matC.rows - 1) / (matC.cols - 1);	//协方差

	l = 2 * brightY * brightC / (brightY * brightY + brightC * brightC);	//亮度比较函数值
	c = 2 * brightValueY * brightValueC / (brightValueY * brightValueY + brightValueC * brightValueC);	//对比度比较函数值
	s = brightValueYC / brightValueY / brightValueC;	//结构相似性比较函数值

	ssim = l * c * s;	//结构失真度评价值

	return ssim;
}