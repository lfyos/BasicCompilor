
// CntrItem.cpp : CBasic_CompilorCntrItem ���ʵ��
//

#include "stdafx.h"
#include "Basic_Compilor.h"

#include "Basic_CompilorDoc.h"
#include "Basic_CompilorView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBasic_CompilorCntrItem ��ʵ��

IMPLEMENT_SERIAL(CBasic_CompilorCntrItem, CRichEditCntrItem, 0)

CBasic_CompilorCntrItem::CBasic_CompilorCntrItem(REOBJECT* preo, CBasic_CompilorDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: �ڴ����һ���Թ������
}

CBasic_CompilorCntrItem::~CBasic_CompilorCntrItem()
{
	// TODO: �ڴ˴�����������
}


// CBasic_CompilorCntrItem ���

#ifdef _DEBUG
void CBasic_CompilorCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CBasic_CompilorCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

