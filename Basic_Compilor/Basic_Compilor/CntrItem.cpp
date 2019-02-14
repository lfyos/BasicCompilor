
// CntrItem.cpp : CBasic_CompilorCntrItem 类的实现
//

#include "stdafx.h"
#include "Basic_Compilor.h"

#include "Basic_CompilorDoc.h"
#include "Basic_CompilorView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBasic_CompilorCntrItem 的实现

IMPLEMENT_SERIAL(CBasic_CompilorCntrItem, CRichEditCntrItem, 0)

CBasic_CompilorCntrItem::CBasic_CompilorCntrItem(REOBJECT* preo, CBasic_CompilorDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: 在此添加一次性构造代码
}

CBasic_CompilorCntrItem::~CBasic_CompilorCntrItem()
{
	// TODO: 在此处添加清理代码
}


// CBasic_CompilorCntrItem 诊断

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

