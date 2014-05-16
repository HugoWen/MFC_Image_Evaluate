
// MFC_IMAGEDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_IMAGE.h"
#include "MFC_IMAGEDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFC_IMAGEDlg �Ի���



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


// CMFC_IMAGEDlg ��Ϣ�������

BOOL CMFC_IMAGEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_IMAGEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_IMAGEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��ʾͼ��
void CMFC_IMAGEDlg::DrawPicToHDC(IplImage *img, UINT ID)
{
	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	CvvImage cimg;
	cimg.CopyOf(img);	//����ͼƬ
	cimg.DrawToHDC(hDC, &rect);		//��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC(pDC);
	
}

//������ͼ
void CMFC_IMAGEDlg::OnBnClickedButtonLeft()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IplImage *imagel = NULL;		//����ͼͼ��
	if (imagel)
		cvReleaseImage(&imagel);
	imagel = cvLoadImage("F:\\yl.jpg");
	DrawPicToHDC(imagel, IDC_STATIC_Left);
}

//������ͼ
void CMFC_IMAGEDlg::OnBnClickedButtonRight()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IplImage *imager = NULL;		//����ͼͼ��
	if (imager)
		cvReleaseImage(&imager);
	imager = cvLoadImage("F:\\yr.jpg");
	DrawPicToHDC(imager, IDC_STATIC_Right);
}

//��ȡͼ��ƽ������
double CMFC_IMAGEDlg::getBright(IplImage *img)
{
	double brightValue = 0.000;
	Mat mat(img, false);		//��IplImageͼ��ת����Mat��ʽ
	//Mat mat1 = Mat::zeros(mat.size(), mat.type);	//��mat����0��ʼ��Ϊmat1
	//Mat mat = imread("F:\\2.jpg");
	for (int x = 0; x < mat.rows; x++)
	{
		for (int y = 0; y < mat.cols; y++)
		{
			//����ÿһ�����ص��ۼӺ�
			brightValue = brightValue + mat.at<Vec3b>(x, y)[0] * 0.299 + mat.at<Vec3b>(x, y)[1] * 0.587 + mat.at<Vec3b>(x, y)[2] * 0.114;
		}
	}

	brightValue = brightValue / mat.rows / mat.cols;	//����ƽ������ֵ
	return brightValue;		//����ƽ������ֵ
}

//��ʼ���⴦��
void CMFC_IMAGEDlg::OnBnClickedButtonStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	double brightcl, brightcr, brightyl, brightyr;
	int matchy, matchc;
	double strucL, strucR, LumaLR, HVSL, HVSR;
	int Match = 0;
	double score = 0.000;

	//����ͼ��
	//Ϊ�˷�����ԣ�����ֱ��д������ģ������޸ĳɿ�ѡ���ļ���ʽ
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
	LumaLR *= 5;	//5����

	brightyl = getBright(imgyl);
	brightyr = getBright(imgyr);
	//strucL = getStruc(imgyl, imgcl, brightyl, brightcl);
	//strucR = getStruc(imgyr, imgcr, brightyr, brightcr);


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	double brightValueYL = 0.000;	//ԭͼ�������ֵ
	double brightValueCL = 0.000;	//����ͼ�������ֵ
	double brightPixelYL = 0.000;	//ԭͼ�����ص�����ֵ
	double brightPixelCL = 0.000;	//����ͼ�����ص�����ֵ
	double brightValueYCL = 0.000;
	double lL, cL, sL, ssimL;

	Mat matYL(imgyl, false);		//��IplImageͼ��ת����Mat��ʽ
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
	brightValueYL = sqrt(brightValueYL);		//ԭͼ��ƽ�����ȱ�׼��

	brightValueCL = brightValueCL / (matCL.rows - 1) / (matCL.cols - 1);
	brightValueCL = sqrt(brightValueCL);		//����ͼ��ƽ�����ȱ�׼��

	brightValueYCL = brightValueYCL / (matCL.rows - 1) / (matCL.cols - 1);	//Э����

	lL = 2 * brightyl * brightcl / (brightyl * brightyl + brightcl * brightcl);	//���ȱȽϺ���ֵ
	cL = 2 * brightValueYL * brightValueCL / (brightValueYL * brightValueYL + brightValueCL * brightValueCL);	//�ԱȶȱȽϺ���ֵ
	sL = brightValueYCL / brightValueYL / brightValueCL;	//�ṹ�����ԱȽϺ���ֵ

	ssimL = lL * cL * sL;	//�ṹʧ�������ֵ


	double brightValueYR = 0.000;	//ԭͼ�������ֵ
	double brightValueCR = 0.000;	//����ͼ�������ֵ
	double brightPixelYR = 0.000;	//ԭͼ�����ص�����ֵ
	double brightPixelCR = 0.000;	//����ͼ�����ص�����ֵ
	double brightValueYCR = 0.000;
	double lR, cR, sR, ssimR;

	Mat matYR(imgyr, false);		//��IplImageͼ��ת����Mat��ʽ
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
	brightValueYR = sqrt(brightValueYR);		//ԭͼ��ƽ�����ȱ�׼��

	brightValueCR = brightValueCR / (matCR.rows - 1) / (matCR.cols - 1);
	brightValueCR = sqrt(brightValueCR);		//����ͼ��ƽ�����ȱ�׼��

	brightValueYCR = brightValueYCR / (matCR.rows - 1) / (matCR.cols - 1);	//Э����

	lR = 2 * brightyl * brightcl / (brightyl * brightyl + brightcl * brightcl);	//���ȱȽϺ���ֵ
	cR = 2 * brightValueYR * brightValueCR / (brightValueYR * brightValueYR + brightValueCR * brightValueCR);	//�ԱȶȱȽϺ���ֵ
	sR = brightValueYCR / brightValueYR / brightValueCR;	//�ṹ�����ԱȽϺ���ֵ

	ssimR = lR * cR * sR;	//�ṹʧ�������ֵ
	
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

	//����Mat��ʽ�Ҷ�ͼ��
	//ͬ��ֱ��д�������޸�
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


	//�������
	score = (strucL + strucR + LumaLR + HVSL + HVSR) * Match / 5 / 5;

	//��ʾ����
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

//���������ͼ
void CMFC_IMAGEDlg::OnBnClickedButtonLtest()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IplImage *imagel = NULL;		//����ͼͼ��
	if (imagel)
		cvReleaseImage(&imagel);
	imagel = cvLoadImage("F:\\cl.jpg");
	DrawPicToHDC(imagel, IDC_STATIC_LTest);
}

//���Ҳ�����ͼ
void CMFC_IMAGEDlg::OnBnClickedButtonRtest()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IplImage *imagel = NULL;		//����ͼͼ��
	if (imagel)
		cvReleaseImage(&imagel);
	imagel = cvLoadImage("F:\\cr.jpg");
	DrawPicToHDC(imagel, IDC_STATIC_RTest);
}


//��ȡ����ͼ��ƥ������
//int CMFC_IMAGEDlg::getMatch(IplImage *img1, IplImage *img2)
int CMFC_IMAGEDlg::getMatch(Mat img1, Mat img2, Mat img3, Mat img4)
{
	//Mat mat1(img1, false);		//��IplImageͼ��ת����Mat��ʽ
	//Mat mat2(img2, false);

	int pointCounts1 = 0;	//���������
	int pointCounts2 = 0;

	//���surf������
	std::vector<KeyPoint> keypoints1, keypoints2;
	int minHessian = 400;
	SurfFeatureDetector detector1(minHessian);
	detector1.detect(img1, keypoints1);
	detector1.detect(img3, keypoints2);

	//����surf������
	SurfDescriptorExtractor surfDesc1;
	Mat descriptros1, descriptros2;
	surfDesc1.compute(img1, keypoints1, descriptros1);
	surfDesc1.compute(img3, keypoints2, descriptros2);

	pointCounts1 = keypoints1.size();
	pointCounts2 = keypoints2.size();

	return pointCounts1 / pointCounts2;

	/*
	//����ƥ�����
	BruteForceMatcher<L2<float>>matcher;
	std::vector<DMatch> matches;
	matcher.match(descriptros1, descriptros2, matches);
	//std::nth_element(matches.begin(), matches.begin() + 24, matches.end());		//����������
	//matches.erase(matches.begin() + 25, matches.end());		//����25֮��������
	//for (int i = matches.begin(); i < matches.end(); i++)
	int matchCount = 0;
	matchCount = matches.end() - matches.begin();	//ƥ������
	return 0
	*/
}

//��ȡ��ֵ�����
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

//��ȡͼ��ṹʧ�������ֵ
double getStruc(IplImage *imgY, IplImage *imgC, double &brightY, double &brightC)
{
	double brightValueY = 0.000;	//ԭͼ�������ֵ
	double brightValueC = 0.000;	//����ͼ�������ֵ
	double brightPixelY = 0.000;	//ԭͼ�����ص�����ֵ
	double brightPixelC = 0.000;	//����ͼ�����ص�����ֵ
	double brightValueYC = 0.000;
	double l, c, s, ssim;

	Mat matY(imgY, false);		//��IplImageͼ��ת����Mat��ʽ
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
	brightValueY = sqrt(brightValueY);		//ԭͼ��ƽ�����ȱ�׼��

	brightValueC = brightValueC / (matC.rows - 1) / (matC.cols - 1);
	brightValueC = sqrt(brightValueC);		//����ͼ��ƽ�����ȱ�׼��

	brightValueYC = brightValueYC / (matC.rows - 1) / (matC.cols - 1);	//Э����

	l = 2 * brightY * brightC / (brightY * brightY + brightC * brightC);	//���ȱȽϺ���ֵ
	c = 2 * brightValueY * brightValueC / (brightValueY * brightValueY + brightValueC * brightValueC);	//�ԱȶȱȽϺ���ֵ
	s = brightValueYC / brightValueY / brightValueC;	//�ṹ�����ԱȽϺ���ֵ

	ssim = l * c * s;	//�ṹʧ�������ֵ

	return ssim;
}