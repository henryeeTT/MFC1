
// MFCTestDoc.h : CMFCTestDoc 類別的介面
#pragma once
#include "BaseStruct.h"
class CMFCTestDoc : public CDocument
{
protected: // 僅從序列化建立
	CMFCTestDoc();
	DECLARE_DYNCREATE(CMFCTestDoc)

// 屬性
public:
    CArray <MyPoint, MyPoint &> pArray; //點陣列容器
    CArray <MyLine, MyLine &>   lArray; //線陣列容器
    int shapenum;     //系統幾何編號   0:點 1:線
    COLORREF Obj_Color;   //系統幾何顏色
    int P_Type;    //系統點總類  0:點 1:圓點
void RemoveAll() 
    { 
        pArray.RemoveAll();
        lArray.RemoveAll();
    }

// 作業
public:

// 覆寫
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 程式碼實作
public:
	virtual ~CMFCTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 為搜尋處理常式設定搜尋內容的 Helper 函式
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
