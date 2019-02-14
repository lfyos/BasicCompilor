
// Basic_CompilorView.cpp : CBasic_CompilorView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Basic_Compilor.h"
#endif

#include "Basic_CompilorDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "Basic_CompilorView.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBasic_CompilorView

IMPLEMENT_DYNCREATE(CBasic_CompilorView, CRichEditView)

BEGIN_MESSAGE_MAP(CBasic_CompilorView, CRichEditView)
	ON_WM_DESTROY()
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBasic_CompilorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_CONTROL_REFLECT(EN_CHANGE, &CBasic_CompilorView::OnEnChange)
	ON_COMMAND(ID_RUN_PROGRAM, &CBasic_CompilorView::OnRunProgram)
	ON_COMMAND(ID_DEBUG_PROGRAM, &CBasic_CompilorView::OnDebugProgram)
	ON_COMMAND(ID_TERMINATION, &CBasic_CompilorView::OnTermination)

	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CBasic_CompilorView 构造/析构

CBasic_CompilorView::CBasic_CompilorView()
{
	// TODO: 在此处添加构造代码

}

CBasic_CompilorView::~CBasic_CompilorView()
{
}

BOOL CBasic_CompilorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRichEditView::PreCreateWindow(cs);
}

void CBasic_CompilorView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// 设置打印边距(720 缇 = 1/2 英寸)
	SetMargins(CRect(720, 720, 720, 720));
}


// CBasic_CompilorView 打印


void CBasic_CompilorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBasic_CompilorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}


void CBasic_CompilorView::OnDestroy()
{
	// 析构时停用此项；这在
	// 使用拆分视图时非常重要 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}


void CBasic_CompilorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBasic_CompilorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBasic_CompilorView 诊断

#ifdef _DEBUG
void CBasic_CompilorView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CBasic_CompilorView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CBasic_CompilorDoc* CBasic_CompilorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBasic_CompilorDoc)));
	return (CBasic_CompilorDoc*)m_pDocument;
}
#endif //_DEBUG


// CBasic_CompilorView 消息处理程序

#include "..\..\Genetator\View_compilor.h"

CString server_name=_T("192.168.1.100");
int server_port_id=2048,program_port_id=2050;

void CBasic_CompilorView::OnEnChange()
{
	View_Compilor(this,10).do_compilation(true);
}
void CBasic_CompilorView::OnRunProgram()
{
	CMainFrame* pFrame;
	if((pFrame=(CMainFrame*)(theApp.m_pMainWnd))==NULL)
		return;
	pFrame->m_wndProperties.cp=&(this->GetRichEditCtrl());

	OnTermination();

	View_Compilor a(this,10);
	a.do_compilation(false);
	if(a.error_number!=0)
		a.display_error_message(pFrame->m_wndProperties.m_wndPropList);
	else{
		program_port_id++;
		Program_controller(server_name,server_port_id,program_port_id).compile_execute_program(a.var_declare_object_program,a.execute_object_program,_T("./basic_program"),false);
	}
}
void CBasic_CompilorView::OnDebugProgram()
{
	CMainFrame* pFrame;
	if((pFrame=(CMainFrame*)(theApp.m_pMainWnd))==NULL)
		return;
	pFrame->m_wndProperties.cp=&(this->GetRichEditCtrl());

	OnTermination();

	View_Compilor a(this,10);
	variable_link_list *var_list=a.do_compilation(false);
	if(a.error_number!=0)
		a.display_error_message(pFrame->m_wndProperties.m_wndPropList);
	else{
		program_port_id++;
		Program_controller(server_name,server_port_id,program_port_id).compile_execute_program(a.var_declare_object_program,a.execute_object_program,_T("./basic_program"),true);
		a.display_variable_list(pFrame->m_wndProperties.cp,pFrame->m_wndProperties.m_wndPropList,var_list,server_name,server_port_id,program_port_id);
	}
}

void CBasic_CompilorView::OnTermination()
{
	Program_controller(server_name,server_port_id,program_port_id).terminate_program();
}

