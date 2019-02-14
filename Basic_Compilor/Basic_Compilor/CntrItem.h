
// CntrItem.h : CBasic_CompilorCntrItem 类的接口
//

#pragma once

class CBasic_CompilorDoc;
class CBasic_CompilorView;

class CBasic_CompilorCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CBasic_CompilorCntrItem)

// 构造函数
public:
	CBasic_CompilorCntrItem(REOBJECT* preo = NULL, CBasic_CompilorDoc* pContainer = NULL);
		// 注意: 允许 pContainer 为 NULL 以启用 IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE 要求类具有带零
		//  参数的构造函数。OLE 项通常是用
		//  非 NULL 文档指针构造的

// 特性
public:
	CBasic_CompilorDoc* GetDocument()
		{ return reinterpret_cast<CBasic_CompilorDoc*>(CRichEditCntrItem::GetDocument()); }
	CBasic_CompilorView* GetActiveView()
		{ return reinterpret_cast<CBasic_CompilorView*>(CRichEditCntrItem::GetActiveView()); }

// 实现
public:
	~CBasic_CompilorCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

