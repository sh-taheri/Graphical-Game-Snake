
// HW5_testDoc.cpp : implementation of the CHW5_testDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HW5_test.h"
#endif

#include "HW5_testDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHW5_testDoc

IMPLEMENT_DYNCREATE(CHW5_testDoc, CDocument)

BEGIN_MESSAGE_MAP(CHW5_testDoc, CDocument)
END_MESSAGE_MAP()


// CHW5_testDoc construction/destruction

CHW5_testDoc::CHW5_testDoc()
{
	// TODO: add one-time construction code here

}

CHW5_testDoc::~CHW5_testDoc()
{
}

BOOL CHW5_testDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
////////////////////////////////////////////////// Initializing the coordinates of cute nibbles :D /////////////////////////////////////////////////////////////////////////////////////
	Player1.read("a1.nib");
	Player2.read("a2.nib");
	lock1.read("w1.nib");
	lock2.read("w2.nib");
	lock3.read("w3.nib");
	lock4.read("w4.nib");
	lock5.read("w5.nib");
	lock6.read("w6.nib");
	Player1.MoveDir='r';
	Player2.MoveDir='L';
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CHW5_testDoc serialization

void CHW5_testDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CHW5_testDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CHW5_testDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHW5_testDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHW5_testDoc diagnostics

#ifdef _DEBUG
void CHW5_testDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHW5_testDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHW5_testDoc commands
