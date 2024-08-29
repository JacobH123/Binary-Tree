#pragma once
#ifndef CBST_HEADER
#define CBST_HEADER

#include "CBinaryTreeInterface.h"
#include "CBinaryNode.h"
#include "CBinaryNodeTree.h"

class CPersonInfo;

template<class ItemType>
class CBST : public CBinaryNodeTree<ItemType>
{
public:
	//Sets m_rootPtr to nullptr
	CBST();
	//Allocates space for CBinaryNode and sets it equal to m_rootPtr
	CBST(const ItemType& rootItem);
	//uses a deep copy by calling CopyTree
	CBST(const CBST<ItemType>& tree);

	virtual ~CBST();
	//Allocate the new node and then call PlaceNode to add the new node to the tree
	virtual bool  Add(const ItemType& newEntry);
	//Removes a node from the tree calls RemoveValue
	virtual bool  Remove(const ItemType& anEntry);
	//used to assign a CBST
	CBST<ItemType>& operator=(const CBST<ItemType>& rhs);

protected:
	//
	CBinaryNode<ItemType>* LeftRotate(CBinaryNode<ItemType>* subTreePtr);
	CBinaryNode<ItemType>* RightRotate(CBinaryNode<ItemType>* subTreePtr);
	CBinaryNode<ItemType>* LeftRightRotate(CBinaryNode<ItemType>* subTreePtr);
	CBinaryNode<ItemType>* RightLeftRotate(CBinaryNode<ItemType>* subTreePtr);

	//removes the target value from the tree and keeps the tree AVL balanced
	virtual CBinaryNode<ItemType>* RemoveValue(CBinaryNode<ItemType>* subTreePtr, const ItemType& target, bool& success)override;

	//Recursively finds where the node should be placed and inserts it. Keeps the tree AVL balanced.
	CBinaryNode<ItemType>* PlaceNode(CBinaryNode<ItemType>* subTreePtr,
		CBinaryNode<ItemType>* newNode);

	//Searches for a value in the tree using preorder
	virtual CBinaryNode<ItemType>* FindNode(CBinaryNode<ItemType>* treePtr, const ItemType& target,
		bool& success)const;



};

#include "CBST.tpp"

#endif 
