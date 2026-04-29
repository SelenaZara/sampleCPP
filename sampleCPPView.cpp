
// sampleCPPView.cpp : implementation of the CsampleCPPView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "sampleCPP.h"
#endif

#include "sampleCPPDoc.h"
#include "sampleCPPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsampleCPPView

IMPLEMENT_DYNCREATE(CsampleCPPView, CView)

BEGIN_MESSAGE_MAP(CsampleCPPView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CsampleCPPView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CsampleCPPView construction/destruction

CsampleCPPView::CsampleCPPView() noexcept
{
	// TODO: add construction code here

}

CsampleCPPView::~CsampleCPPView()
{
}

BOOL CsampleCPPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsampleCPPView drawing

void CsampleCPPView::OnDraw(CDC* /*pDC*/)
{
	CsampleCPPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CsampleCPPView printing


void CsampleCPPView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CsampleCPPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CsampleCPPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CsampleCPPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CsampleCPPView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CsampleCPPView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CsampleCPPView diagnostics

#ifdef _DEBUG
void CsampleCPPView::AssertValid() const
{
	CView::AssertValid();
}

void CsampleCPPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsampleCPPDoc* CsampleCPPView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsampleCPPDoc)));
	return (CsampleCPPDoc*)m_pDocument;
}
#endif //_DEBUG


// CsampleCPPView message handlers
