#ifndef CBST_TPP
#define CBST_TPP

#include "CBinaryNodeTree.h"

template<class ItemType>
CBST<ItemType>::CBST() : CBinaryNodeTree<ItemType>() 
{
this->SetRootPtr(nullptr);
}

template<class ItemType>
CBST<ItemType>::CBST(const ItemType &rootItem) : CBinaryNodeTree<ItemType>(rootItem) 
{
    CBinaryNode<ItemType>* newNode = new CBinaryNode<ItemType>(rootItem);  
    newNode->SetLeftChildPtr(nullptr);
    newNode->SetRightChildPtr(nullptr);
    this->SetRootPtr(newNode);
}


template<class ItemType>
CBST<ItemType>::CBST(const CBST<ItemType>& tree) : CBinaryNodeTree<ItemType>(tree)
{
    this->SetRootPtr(this->CopyTree(tree.GetRootPtr()));
}

template<class ItemType>
CBST<ItemType>::~CBST() 
{
 this->Clear();
 this->SetRootPtr(nullptr);

}



template<class ItemType>
CBST<ItemType>& CBST<ItemType>::operator=(const CBST<ItemType>& rhs)
{
    if (this != &rhs)
    {
        this->Clear();
        this->SetRootPtr(this->CopyTree(rhs.GetRootPtr()));
    }
    return *this;
}


template<class ItemType>
bool CBST<ItemType>::Add(const ItemType& newEntry)
{
    CBinaryNode<ItemType>* newNodePtr = new CBinaryNode<ItemType>(newEntry);
    this->SetRootPtr(PlaceNode(this->GetRootPtr(), newNodePtr));
    return true;
}

template<class ItemType>
bool CBST<ItemType>::Remove(const ItemType& anEntry)
{
    bool success = false;
    this->SetRootPtr(RemoveValue(this->GetRootPtr(), anEntry, success));
    return success;
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RemoveValue(CBinaryNode<ItemType>* subTreePtr, const ItemType& target, bool& success)
{
    if (subTreePtr == nullptr)
    {
        success = false;
        return subTreePtr;
    }

    if (target == subTreePtr->GetItem())
    {
        // Node found, perform removal
        CBinaryNode<ItemType>* tempPtr = subTreePtr;

        if (subTreePtr->GetLeftChildPtr() == nullptr)
        {
            // Node has only a right child or no child
            subTreePtr = subTreePtr->GetRightChildPtr();
            delete tempPtr;
        }
        else if (subTreePtr->GetRightChildPtr() == nullptr)
        {
            // Node has only a left child
            subTreePtr = subTreePtr->GetLeftChildPtr();
            delete tempPtr;
        }
        else
        {
            // Node has two children, replace with the in-order successor
            CBinaryNode<ItemType>* minNode = this->FindMinNode(subTreePtr->GetRightChildPtr());
            subTreePtr->SetItem(minNode->GetItem());
            subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), minNode->GetItem(), success));
        }
    }
    else if (target < subTreePtr->GetItem())
    {
        subTreePtr->SetLeftChildPtr(RemoveValue(subTreePtr->GetLeftChildPtr(), target, success));
    }
    else
    {
        subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), target, success));
    }

    return subTreePtr;
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::PlaceNode(CBinaryNode<ItemType>* subTreePtr, CBinaryNode<ItemType>* newNode)
{
    if (subTreePtr == nullptr)
    {
        // Node found, insert the new node here
        return newNode;
    }

    if (newNode->GetItem() < subTreePtr->GetItem())
    {
        // Recursively place the new node in the left subtree
        subTreePtr->SetLeftChildPtr(PlaceNode(subTreePtr->GetLeftChildPtr(), newNode));
    }
    else
    {
        // Recursively place the new node in the right subtree
        subTreePtr->SetRightChildPtr(PlaceNode(subTreePtr->GetRightChildPtr(), newNode));
    }

    // Perform AVL balancing after the insertion
    int balance = this->GetHeightHelper(subTreePtr->GetLeftChildPtr()) - this->GetHeightHelper(subTreePtr->GetRightChildPtr());

    // Left Heavy
    if (balance > 1)
    {
        // Left-Left case
        if (newNode->GetItem() < subTreePtr->GetLeftChildPtr()->GetItem())
        {
            return LeftRotate(subTreePtr);
        }
        // Left-Right case
        else
        {
            return LeftRightRotate(subTreePtr);
        }
    }
    // Right Heavy
    else if (balance < -1)
    {
        // Right-Right case
        if (newNode->GetItem() > subTreePtr->GetRightChildPtr()->GetItem())
        {
            return RightRotate(subTreePtr);
        }
        // Right-Left case
        else
        {
            return RightLeftRotate(subTreePtr);
        }
    }

    return subTreePtr;
}


template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::LeftRotate(CBinaryNode<ItemType>* subTreePtr)
{
    CBinaryNode<ItemType>* newRoot = subTreePtr->GetLeftChildPtr();
    subTreePtr->SetLeftChildPtr(newRoot->GetRightChildPtr());
    newRoot->SetRightChildPtr(subTreePtr);

    return newRoot;
}


template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RightRotate(CBinaryNode<ItemType>* subTreePtr)
{
    CBinaryNode<ItemType>* newRoot = subTreePtr->GetRightChildPtr();
    subTreePtr->SetRightChildPtr(newRoot->GetLeftChildPtr());
    newRoot->SetLeftChildPtr(subTreePtr);

    return newRoot;
}


template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::LeftRightRotate(CBinaryNode<ItemType>* subTreePtr)
{
    subTreePtr->SetLeftChildPtr(RightRotate(subTreePtr->GetLeftChildPtr()));
    return LeftRotate(subTreePtr);
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RightLeftRotate(CBinaryNode<ItemType>* subTreePtr)
{
    subTreePtr->SetRightChildPtr(LeftRotate(subTreePtr->GetRightChildPtr()));
    return RightRotate(subTreePtr);
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::FindNode(CBinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const
{
    if (treePtr == nullptr)
    {
        success = false;
        return nullptr;
    }

    if (target == treePtr->GetItem())
    {
        success = true;
        return treePtr;
    }
    else if (target < treePtr->GetItem())
    {
        return FindNode(treePtr->GetLeftChildPtr(), target, success);
    }
    else
    {
        return FindNode(treePtr->GetRightChildPtr(), target, success);
    }
}






#endif
