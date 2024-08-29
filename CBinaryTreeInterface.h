#pragma
#ifndef CBINARY_TREE_INTERFACE_HEADER
#define CBINARY_TREE_INTERFACE_HEADER


template<class ItemType>
class CBinaryTreeInterface
{
public:
	virtual bool IsEmpty() const = 0;

	virtual int GetHeight() const = 0;

	virtual int GetNumberOfNodes()const = 0;

	virtual ItemType GetRootData()const = 0;

	virtual void SetRootData(const ItemType& newData) = 0;

	virtual bool Add(const ItemType& newData) = 0;

	virtual bool Remove(const ItemType& data) = 0;

	virtual bool Contains(const ItemType& anEntry)const = 0;

	virtual void PreorderTraverse(void Visit(const ItemType& item))const = 0;
	virtual void InorderTraverse(void Visit(const ItemType& item))const = 0;
	virtual void PostorderTraverse(void Visit(const ItemType& item))const = 0;
	virtual void LevelorderTraverse(void Visit(const ItemType& item))const = 0;

	virtual ~CBinaryTreeInterface() {}




};


#endif