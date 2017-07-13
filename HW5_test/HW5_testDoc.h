#include "CNibble.h"
// HW5_testDoc.h : interface of the CHW5_testDoc class
#define ROW 40
//#define PLAYER1_SYM 3
//#define PLAYER2_SYM 3
#define INIT_SIZE 4

#if !defined(AFX_NOTESDOC_H__B3A19E54_B441_4395_8325_CFE0B6F89D69__INCLUDED_)
#define AFX_NOTESDOC_H__B3A19E54_B441_4395_8325_CFE0B6F89D69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma once


class CHW5_testDoc : public CDocument
{
protected: // create from serialization only
	CHW5_testDoc();
	DECLARE_DYNCREATE(CHW5_testDoc)

// Attributes
public:

// Operations
public:
   CNibble Player1,Player2,lock1,lock2,lock3,lock4,lock5,lock6;
   CNibble wall1,wall2,wall3,wall4;

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
    virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CHW5_testDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};



#endif // !defined(AFX_NOTESDOC_H__B3A19E54_B441_4395_8325_CFE0B6F89D69__INCLUDED_)