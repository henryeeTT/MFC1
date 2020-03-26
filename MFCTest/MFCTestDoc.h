
// MFCTestDoc.h : CMFCTestDoc ���O������
#pragma once
#include "BaseStruct.h"
class CMFCTestDoc : public CDocument
{
protected: // �ȱq�ǦC�ƫإ�
	CMFCTestDoc();
	DECLARE_DYNCREATE(CMFCTestDoc)

// �ݩ�
public:
    CArray <MyPoint, MyPoint &> pArray; //�I�}�C�e��
    CArray <MyLine, MyLine &>   lArray; //�u�}�C�e��
    int shapenum;     //�t�δX��s��   0:�I 1:�u
    COLORREF Obj_Color;   //�t�δX���C��
    int P_Type;    //�t���I�`��  0:�I 1:���I
void RemoveAll() 
    { 
        pArray.RemoveAll();
        lArray.RemoveAll();
    }

// �@�~
public:

// �мg
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �{���X��@
public:
	virtual ~CMFCTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ���j�M�B�z�`���]�w�j�M���e�� Helper �禡
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
