
// Basic_CompilorView.cpp : CBasic_CompilorView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CBasic_CompilorView ����/����

CBasic_CompilorView::CBasic_CompilorView()
{
	// TODO: �ڴ˴���ӹ������

}

CBasic_CompilorView::~CBasic_CompilorView()
{
}

BOOL CBasic_CompilorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRichEditView::PreCreateWindow(cs);
}

void CBasic_CompilorView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// ���ô�ӡ�߾�(720 � = 1/2 Ӣ��)
	SetMargins(CRect(720, 720, 720, 720));
}


// CBasic_CompilorView ��ӡ


void CBasic_CompilorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBasic_CompilorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}


void CBasic_CompilorView::OnDestroy()
{
	// ����ʱͣ�ô������
	// ʹ�ò����ͼʱ�ǳ���Ҫ 
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


// CBasic_CompilorView ���

#ifdef _DEBUG
void CBasic_CompilorView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CBasic_CompilorView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CBasic_CompilorDoc* CBasic_CompilorView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBasic_CompilorDoc)));
	return (CBasic_CompilorDoc*)m_pDocument;
}
#endif //_DEBUG


// CBasic_CompilorView ��Ϣ�������

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

