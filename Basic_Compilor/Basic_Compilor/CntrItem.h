
// CntrItem.h : CBasic_CompilorCntrItem ��Ľӿ�
//

#pragma once

class CBasic_CompilorDoc;
class CBasic_CompilorView;

class CBasic_CompilorCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CBasic_CompilorCntrItem)

// ���캯��
public:
	CBasic_CompilorCntrItem(REOBJECT* preo = NULL, CBasic_CompilorDoc* pContainer = NULL);
		// ע��: ���� pContainer Ϊ NULL ������ IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE Ҫ������д���
		//  �����Ĺ��캯����OLE ��ͨ������
		//  �� NULL �ĵ�ָ�빹���

// ����
public:
	CBasic_CompilorDoc* GetDocument()
		{ return reinterpret_cast<CBasic_CompilorDoc*>(CRichEditCntrItem::GetDocument()); }
	CBasic_CompilorView* GetActiveView()
		{ return reinterpret_cast<CBasic_CompilorView*>(CRichEditCntrItem::GetActiveView()); }

// ʵ��
public:
	~CBasic_CompilorCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

