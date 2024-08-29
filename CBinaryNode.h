
#ifndef	CBINARY_NODE_HEADER
#define CBINARY_NODE_HEADER

template<class ItemType>
class CBinaryNode
{
public:

	CBinaryNode();
	CBinaryNode(const ItemType& item);
	CBinaryNode(const ItemType& item, CBinaryNode<ItemType>* leftChildPtr,
		CBinaryNode<ItemType>* rightChildPtr);

	void SetItem(const ItemType& item);
  

	ItemType GetItem()const;

	bool IsLeaf()const;
	CBinaryNode<ItemType>* GetLeftChildPtr()const;
	CBinaryNode<ItemType>* GetRightChildPtr()const;

	void SetLeftChildPtr(CBinaryNode<ItemType>* leftChildPtr);
	void SetRightChildPtr(CBinaryNode<ItemType>* rightChildPtr);


private:

	ItemType	m_item;
	CBinaryNode<ItemType>* m_leftChildPtr;
	CBinaryNode<ItemType>* m_rightChildPtr;
};
#include "CBinaryNode.tpp"


#endif