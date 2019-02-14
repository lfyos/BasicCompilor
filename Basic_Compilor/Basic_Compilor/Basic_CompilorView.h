
// Basic_CompilorView.h : CBasic_CompilorView ��Ľӿ�
//

#pragma once

class CBasic_CompilorCntrItem;

class CBasic_CompilorView : public CRichEditView
{
protected: // �������л�����
	CBasic_CompilorView();
	DECLARE_DYNCREATE(CBasic_CompilorView)

// ����
public:
	CBasic_CompilorDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CBasic_CompilorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChange();
	afx_msg void OnRunProgram();
	afx_msg void OnDebugProgram();
	afx_msg void OnTermination();
};

#ifndef _DEBUG  // Basic_CompilorView.cpp �еĵ��԰汾
inline CBasic_CompilorDoc* CBasic_CompilorView::GetDocument() const
   { return reinterpret_cast<CBasic_CompilorDoc*>(m_pDocument); }
#endif

