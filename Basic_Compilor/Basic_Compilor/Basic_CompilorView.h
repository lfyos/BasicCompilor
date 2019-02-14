
// Basic_CompilorView.h : CBasic_CompilorView 类的接口
//

#pragma once

class CBasic_CompilorCntrItem;

class CBasic_CompilorView : public CRichEditView
{
protected: // 仅从序列化创建
	CBasic_CompilorView();
	DECLARE_DYNCREATE(CBasic_CompilorView)

// 特性
public:
	CBasic_CompilorDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// 实现
public:
	virtual ~CBasic_CompilorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // Basic_CompilorView.cpp 中的调试版本
inline CBasic_CompilorDoc* CBasic_CompilorView::GetDocument() const
   { return reinterpret_cast<CBasic_CompilorDoc*>(m_pDocument); }
#endif

