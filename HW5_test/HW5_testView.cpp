
// HW5_testView.cpp : implementation of the CHW5_testView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HW5_test.h"
#endif

#include "HW5_testDoc.h"
#include "HW5_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define VK_LEFT 0x25
#define VK_UP 0x26
#define VK_RIGHT 0x27
#define VK_DOWN 0x28
#define VK_A    0x41
#define VK_D    0x44
#define VK_S    0x53
#define VK_W    0x57
#define VK_SPACE 0x20
int PLAYER1_SYM =3;
int PLAYER2_SYM =3;
int RunningState=0;


// CHW5_testView

IMPLEMENT_DYNCREATE(CHW5_testView, CView)

BEGIN_MESSAGE_MAP(CHW5_testView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHW5_testView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CHW5_testView construction/destruction

CHW5_testView::CHW5_testView()
{
	// TODO: add construction code here

}

CHW5_testView::~CHW5_testView()
{
}

BOOL CHW5_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHW5_testView drawing

void CHW5_testView::OnDraw(CDC* pDC)
{
	
	CHW5_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
/////////////////////////////////////////////////////// Assigning chart background color //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	CBrush aBrush(RGB(238,203,173));
	pDC->SelectObject(aBrush);
//////////////////////////////////////// Calculating dimensions of the window,plus assigning chart border /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	CRect R1;
	GetClientRect(&R1);
///////////////////////////////////////////////////////////// remove flicker //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Create an in-memory DC compatible with the
		// display DC we're using to paint
		CDC dcMemory;
		dcMemory.CreateCompatibleDC(pDC);
		dcMemory.FillSolidRect(R1,0x000000);

		CBitmap bmp;
		bmp.CreateCompatibleBitmap(pDC,R1.Width(),R1.Height());
		

		// Select the bitmap into the in-memory DC
		CBitmap* pOldBitmap = dcMemory.SelectObject(&bmp);
		CDC *p1;
		p1=&dcMemory;
//////////////////////////////////////////////!!////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	R1.DeflateRect(10,40,5,5);
	int w=R1.Width();
	int h=R1.Height();
	CPoint point1(R1.TopLeft());
	int k1=0;
	int k2=0;
////////////////////////////////////////////////////////// Drawing the checkerd page //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i=0;point1.x+(R1.Height()/ROW)+i*R1.Height()/ROW<=(point1.x+R1.Width());i++)
		for(int j=0;point1.y+ (R1.Height())/ROW + j*((R1.Height())/ROW)<(point1.y+R1.Height());j++)
		{CRect Recto(point1.x+i*((R1.Height())/ROW) ,point1.y+j*((R1.Height())/ROW), point1.x+R1.Height()/ROW +i*((R1.Height())/ROW), point1.y+ (R1.Height())/ROW + j*((R1.Height())/ROW));
		 /*pDC*/p1->Rectangle(&Recto);
     	k1=i;k2=j;
	    }
	for(int j=0;j<=k2+1;j++)
		 {pDoc->wall3.points[j].x=1;pDoc->wall3.points[j].y=j+1;}
	      pDoc->wall3.point_num=k2+1;
	for(int j=0;j<=k2+1;j++)
		 {pDoc->wall4.points[j].x=k1+1;pDoc->wall4.points[j].y=j+1;}
	      pDoc->wall4.point_num=k2+1;
	for(int i=0;i<=k1+1;i++)
		 {pDoc->wall1.points[i].x=i+1;pDoc->wall1.points[i].y=1;}
	      pDoc->wall1.point_num=k1+1;
	for(int i=0;i<=k1+1;i++)
		 {pDoc->wall2.points[i].x=i+1;pDoc->wall2.points[i].y=k2+1;}
	      pDoc->wall2.point_num=k1+1;
	

//////////////////////////////////////////////// Writing the name of players,plus drawing their life :D ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	COLORREF player1_color=0x0000ff;
	COLORREF player2_color=0xb22222;
	/*pDC*/p1->SetTextColor(player1_color);
	/*pDC*/p1->TextOut(25,10,CString("Player1 ::"));
	/*pDC*/p1->SetTextColor(player2_color);
	/*pDC*/p1->TextOut(25+R1.Width()/2,10,CString("Player2 ::"));
	HFONT font=CreateFont(30,0,0,0,FW_THIN,0,0,0,SYMBOL_CHARSET,0,0,0,0,_T("Wingdings"));
	/*pDC*/p1->SelectObject(font);
		for(int i=0;i<PLAYER1_SYM;i++) 
		{/*pDC*/p1->SetTextColor(player1_color);/*pDC*/p1->TextOut(100+i*30,5,CString("J"));}
	for(int j=0;j<PLAYER2_SYM;j++)   
	{/*pDC*/p1->SetTextColor(player2_color);/*pDC*/p1->TextOut(R1.Width()/2+100+30*j,5,CString("J"));}
	
	pDoc->Player1.draw(R1.Height(),R1.TopLeft(),p1,0x0000ff,ROW);
	pDoc->Player2.draw(R1.Height(),R1.TopLeft(),p1,0xff0000,ROW);
	pDoc->lock1.draw(R1.Height(),R1.TopLeft(),p1,0x000000,ROW);
	pDoc->lock2.draw(R1.Height(),R1.TopLeft(),p1,0x000000,ROW);
	pDoc->lock3.draw(R1.Height(),R1.TopLeft(),p1,0x000000,ROW);
	pDoc->lock4.draw(R1.Height(),R1.TopLeft(),p1,0x000000,ROW);
	pDoc->lock5.draw(R1.Height(),R1.TopLeft(),p1,0x000000,ROW);
	pDoc->lock6.draw(R1.Height(),R1.TopLeft(),p1,0x000000,ROW);
	SetTimer(1,200,NULL);
	// TODO: add draw code for native data here
	/////////////////////////////////////////////!!///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	pDC->BitBlt(0,0,R1.Width(),R1.Height(), &dcMemory, 
		     0,0, SRCCOPY);
		dcMemory.SelectObject(pOldBitmap);

		bmp.DeleteObject();
	///////////////	//////////////////////////////////////////!!//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}


// CHW5_testView printing


void CHW5_testView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHW5_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHW5_testView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{

	// TODO: add extra initialization before printing
}

void CHW5_testView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHW5_testView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHW5_testView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHW5_testView diagnostics

#ifdef _DEBUG
void CHW5_testView::AssertValid() const
{
	CView::AssertValid();
}

void CHW5_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW5_testDoc* CHW5_testView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW5_testDoc)));
	return (CHW5_testDoc*)m_pDocument;
}
#endif //_DEBUG


// CHW5_testView message handlers


void CHW5_testView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{   CHW5_testDoc* pDoc;
	pDoc=GetDocument();
	// TODO: Add your message handler code here and/or call default

	///////////////////////////assigning direction of each player//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (nChar==VK_LEFT || nChar== VK_UP || nChar==VK_RIGHT || nChar==VK_DOWN )
	{if ( (nChar==VK_LEFT && pDoc->Player2.MoveDir=='R') || (nChar==VK_RIGHT && pDoc->Player2.MoveDir=='L') || (nChar==VK_UP && pDoc->Player2.MoveDir=='D') ||(nChar==VK_DOWN && pDoc->Player2.MoveDir=='U')) 
	{ RunningState=~RunningState; int MsgBoxID= MessageBox((LPCWSTR)L"Your Movement Is Not Allowed!!",(LPCWSTR)L"Warning!",  0x00000005L);RunningState=~RunningState;}
     else pDoc->Player2.ChangeDir(nChar,2);}	

	 if (nChar==VK_A || nChar== VK_D || nChar==VK_S || nChar==VK_W )
	{if((nChar==VK_A && pDoc->Player1.MoveDir=='r') || (nChar==VK_D && pDoc->Player1.MoveDir=='l') || (nChar==VK_W && pDoc->Player1.MoveDir=='d') ||(nChar==VK_S && pDoc->Player1.MoveDir=='u'))
	 {RunningState=~RunningState;int MsgBoxID= MessageBox((LPCWSTR)L"Your Movement Is Not Allowed!!",(LPCWSTR)L"Warning!",  0x00000005L);RunningState=~RunningState;}
	else pDoc->Player1.ChangeDir(nChar,1);}
	 //////////////////////// Control Key For Running State ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 if (nChar==VK_SPACE)
		 RunningState=~RunningState;
		 
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CHW5_testView::OnTimer(UINT_PTR nIDEvent)
{
	//// TODO: Add your message handler code here and/or call default
	CHW5_testDoc* pDoc;
	pDoc=GetDocument();
	if(RunningState==0)
	{
	pDoc->Player2.Move(2);

	////////////////////////////////////////////////CheckCollision For Player/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	CPoint last_point1=pDoc->Player1.Move(1);
	CPoint last_point2=pDoc->Player2.Move(1);
	Invalidate(false);
	
	if
	( pDoc->Player1.check_point(pDoc->Player2.HeadPoint())|| 
	  pDoc->lock1.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->lock2.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->lock3.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->lock4.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->lock5.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->lock6.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->wall1.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->wall2.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->wall3.check_point(pDoc->Player2.HeadPoint())  ||
	  pDoc->wall4.check_point(pDoc->Player2.HeadPoint())  )
	{
		PLAYER2_SYM--;
		RunningState=1;
		if  (PLAYER2_SYM==0 && PLAYER1_SYM==1 &&  pDoc->Player1.check_point(pDoc->Player2.HeadPoint())
			&& pDoc->Player2.check_point(pDoc->Player1.HeadPoint()))
		{int MsgBoxID= MessageBox((LPCWSTR)L"NO Winner,press retry if you want to start new game",(LPCWSTR)L"Game Over",  0x00000005L); PLAYER2_SYM=3;PLAYER1_SYM=3;}
		else if  (PLAYER2_SYM==0 && PLAYER1_SYM>0)
		{int MsgBoxID= MessageBox((LPCWSTR)L"Player1 Is The Winner,press retry if you want to start new game",(LPCWSTR)L"Game Over",  0x00000005L); PLAYER2_SYM=3;PLAYER1_SYM=3;}
		else if ( pDoc->Player1.check_point(pDoc->Player2.HeadPoint()) && pDoc->Player2.check_point(pDoc->Player1.HeadPoint()) )
		{PLAYER1_SYM--;int MsgBoxID= MessageBox((LPCWSTR)L"Players,You Lost One Of Your chances!!:D",(LPCWSTR)L"",  0x00000005L);}
		else
	    int MsgBoxID= MessageBox((LPCWSTR)L"Player2,You Lost One Of Your chances!!:D",(LPCWSTR)L"",  0x00000005L);

	   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		pDoc->Player1.read("a1.nib");
	    pDoc->Player2.read("a2.nib");
		pDoc->Player1.MoveDir='r';
	    pDoc->Player2.MoveDir='L';
	    RunningState=0;
	}
		if
	( pDoc->Player2.check_point(pDoc->Player1.HeadPoint())|| 
	  pDoc->lock1.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->lock2.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->lock3.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->lock4.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->lock5.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->lock6.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->wall1.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->wall2.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->wall3.check_point(pDoc->Player1.HeadPoint())  ||
	  pDoc->wall4.check_point(pDoc->Player1.HeadPoint())   )
	{
		PLAYER1_SYM--;
		RunningState=1;
		if  (PLAYER1_SYM==0 && PLAYER2_SYM>0)
        {int MsgBoxID= MessageBox((LPCWSTR)L"Player2 Is The Winner,press retry if you want to start new game",(LPCWSTR)L"Game Over",  0x00000005L); PLAYER2_SYM=3;PLAYER1_SYM=3;}
		else int MsgBoxID= MessageBox((LPCWSTR)L"Player1,You Lost One Of Your chances!!:D",(LPCWSTR)L"",  0x00000005L);
		pDoc->Player1.read("a1.nib");
	    pDoc->Player2.read("a2.nib");
		pDoc->Player1.MoveDir='r';
	    pDoc->Player2.MoveDir='L';
	    RunningState=0;
		
	}
	}
	CView::OnTimer(nIDEvent);
} 

 