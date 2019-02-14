
// Basic_CompilorDoc.cpp : CBasic_CompilorDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Basic_Compilor.h"
#endif

#include "Basic_CompilorDoc.h"
#include "CntrItem.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBasic_CompilorDoc

IMPLEMENT_DYNCREATE(CBasic_CompilorDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CBasic_CompilorDoc, CRichEditDoc)
	// ����Ĭ�ϵ� OLE ����ʵ��
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_FILE_SEND_MAIL, &CBasic_CompilorDoc::OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, &CBasic_CompilorDoc::OnUpdateFileSendMail)
END_MESSAGE_MAP()


// CBasic_CompilorDoc ����/����

CBasic_CompilorDoc::CBasic_CompilorDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CBasic_CompilorDoc::~CBasic_CompilorDoc()
{
}

BOOL CBasic_CompilorDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}

CRichEditCntrItem* CBasic_CompilorDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CBasic_CompilorCntrItem(preo, const_cast<CBasic_CompilorDoc*>(this));
}




// CBasic_CompilorDoc ���л�

void CBasic_CompilorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}

	// ���û��� CRichEditDoc ������
	//  �����ĵ��� COleClientItem ��������л���
	// TODO: �����Ϊ�ı��������л��������� CRichEditDoc::m_bRTF = FALSE
	CRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CBasic_CompilorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CBasic_CompilorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CBasic_CompilorDoc::SetSearchContent(const CString& value)
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

// CBasic_CompilorDoc ���

#ifdef _DEBUG
void CBasic_CompilorDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CBasic_CompilorDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// CBasic_CompilorDoc ����
