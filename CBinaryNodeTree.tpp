
#include <iostream>
#include <queue


//Recursively copies the data from a tree

template <typename ItemType>
CBinaryNode<ItemType> *CBinaryNodeTree<ItemType>::CopyTree(const CBinaryNode<ItemType> *oldTreeRootPtr) const
{
    if (oldTreeRootPtr == nullptr)
    {
        return nullptr;
    }
    CBinaryNode<ItemType> *newTreeRootPtr = new CBinaryNode<ItemType>(oldTreeRootPtr->GetItem());
    newTreeRootPtr->SetLeftChildPtr(CopyTree(oldTreeRootPtr->GetLeftChildPtr()));
    newTreeRootPtr->SetRightChildPtr(CopyTree(oldTreeRootPtr->GetRightChildPtr()));
    return newTreeRootPtr;
}

//recursively deletes all nodes from a tree
template <typename ItemType>
void CBinaryNodeTree<ItemType>::DestroyTree(CBinaryNode<ItemType> *subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        DestroyTree(subTreePtr->GetLeftChildPtr());
        DestroyTree(subTreePtr->GetRightChildPtr());
        delete subTreePtr;
    }
}


//default constructor
template <typename ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree()
{
    m_rootPtr = nullptr;
}

//sets m_rootPtr equal to a new CBinaryNode with the value of rootItem
template <typename ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType &rootItem)
{
    m_rootPtr = new CBinaryNode<ItemType>(rootItem);
}

template <typename ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType &rootItem, const CBinaryNodeTree<ItemType> *leftTreePtr,
                                           const CBinaryNodeTree<ItemType> *rightTreePtr)
{
    m_rootPtr = new CBinaryNode<ItemType>(rootItem, leftTreePtr->m_rootPtr, rightTreePtr->m_rootPtr);
}

template <typename ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const CBinaryNodeTree<ItemType> &tree)
{
    m_rootPtr = CopyTree(tree.m_rootPtr);
}

template <typename ItemType>
CBinaryNodeTree<ItemType>::~CBinaryNodeTree()
{
    DestroyTree(m_rootPtr);
}

template <typename ItemType>
bool CBinaryNodeTree<ItemType>::IsEmpty() const
{
    return (m_rootPtr == nullptr);
}

template <typename ItemType>
int CBinaryNodeTree<ItemType>::GetHeight() const
{
    return GetHeightHelper(m_rootPtr);
}


template <typename ItemType>
int CBinaryNodeTree<ItemType>::GetNumberOfNodes() const
{
    return GetNumberOfNodesHelper(m_rootPtr);
}

template <typename ItemType>
ItemType CBinaryNodeTree<ItemType>::GetRootData() const throw(PrecondViolatedExcept)
{
    if (m_rootPtr == nullptr)
    {
        throw PrecondViolatedExcept("Tree is empty");
    }
    return m_rootPtr->GetItem();
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::SetRootData(const ItemType &newData)
{
    if (m_rootPtr == nullptr)
    {
        m_rootPtr = new CBinaryNode<ItemType>(newData);
    }
    else
    {
        m_rootPtr->SetItem(newData);
    }
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::Clear()
{
    DestroyTree(m_rootPtr);
    m_rootPtr = nullptr;
}

template <typename ItemType>
bool CBinaryNodeTree<ItemType>::Contains(const ItemType &anEntry) const
{
    return ContainsHelper(m_rootPtr, anEntry);
}

template <typename ItemType>
CBinaryNodeTree<ItemType> &CBinaryNodeTree<ItemType>::operator=(const CBinaryNodeTree<ItemType> &rhs)
{
    if (this != &rhs)
    {
        Clear();
        m_rootPtr = CopyTree(rhs.m_rootPtr);
    }
    return *this;
}

template <typename ItemType>
bool CBinaryNodeTree<ItemType>::ContainsHelper(CBinaryNode<ItemType>* subTreePtr, const ItemType &target)const
{
    if(subTreePtr == nullptr){
    
        return false;
    }else if(subTreePtr->GetItem() == target){
        return true;    
    }else{
        return ContainsHelper(subTreePtr->GetLeftChildPtr(), target) || ContainsHelper(subTreePtr->GetRightChildPtr(), target);
    }

}





template <typename ItemType>
void CBinaryNodeTree<ItemType>::PreorderTraverse(void Visit(const ItemType &item)) const
{
    Preorder(Visit, m_rootPtr);
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::InorderTraverse(void Visit(const ItemType &item)) const
{
    Inorder(Visit, m_rootPtr);
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::PostorderTraverse(void Visit(const ItemType &item)) const
{
    Postorder(Visit, m_rootPtr);
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::LevelorderTraverse(void Visit(const ItemType &item)) const
{
    for (int level = 1; level <= GetHeight(); ++level)
    {
        Levelorder(Visit, m_rootPtr, level);
    }
}



template <typename ItemType>
CBinaryNode<ItemType> *CBinaryNodeTree<ItemType>::GetRootPtr() const
{
    return m_rootPtr;
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::SetRootPtr(CBinaryNode<ItemType> *rootPtr)
{
    m_rootPtr = rootPtr;
}





template <typename ItemType>
CBinaryNode<ItemType> *CBinaryNodeTree<ItemType>::GetParentNode(CBinaryNode<ItemType> *subTreePtr, CBinaryNode<ItemType> *nodePtr) const
{
    if (subTreePtr == nullptr || subTreePtr->IsLeaf())
    {
        return nullptr;
    }
    if ((subTreePtr->GetLeftChildPtr() != nullptr && subTreePtr->GetLeftChildPtr() == nodePtr) ||
        (subTreePtr->GetRightChildPtr() != nullptr && subTreePtr->GetRightChildPtr() == nodePtr))
    {
        return subTreePtr;
    }

    CBinaryNode<ItemType> *leftResult = GetParentNode(subTreePtr->GetLeftChildPtr(), nodePtr);
    if (leftResult != nullptr)
    {
        return leftResult;
    }

    return GetParentNode(subTreePtr->GetRightChildPtr(), nodePtr);
}

template <typename ItemType>
int CBinaryNodeTree<ItemType>::GetHeightHelper(CBinaryNode<ItemType> *subTreePtr) const
{
    if (subTreePtr == nullptr)
    {
        return 0;
    }
    int leftHeight = GetHeightHelper(subTreePtr->GetLeftChildPtr());
    int rightHeight = GetHeightHelper(subTreePtr->GetRightChildPtr());

    return 1 + std::max(leftHeight, rightHeight);
}

template <typename ItemType>
int CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper(CBinaryNode<ItemType> *subTreePtr) const
{
    if (subTreePtr == nullptr)
    {
        return 0;
    }
    return 1 + GetNumberOfNodesHelper(subTreePtr->GetLeftChildPtr()) + GetNumberOfNodesHelper(subTreePtr->GetRightChildPtr());
}

template <typename ItemType>
CBinaryNode<ItemType> *CBinaryNodeTree<ItemType>::FindMinNode(CBinaryNode<ItemType> *subTreePtr)
{
    if (subTreePtr == nullptr)
    {
        return nullptr;
    }
    CBinaryNode<ItemType> *current = subTreePtr;
    while (current->GetLeftChildPtr() != nullptr)
    {
        current = current->GetLeftChildPtr();
    }
    return current;
}

template <typename ItemType>
CBinaryNode<ItemType> *CBinaryNodeTree<ItemType>::FindMaxNode(CBinaryNode<ItemType> *subTreePtr)
{
    if (subTreePtr == nullptr)
    {
        return nullptr;
    }
    CBinaryNode<ItemType> *current = subTreePtr;
    while (current->GetRightChildPtr() != nullptr)
    {
        current = current->GetRightChildPtr();
    }
    return current;
}





template <typename ItemType>
void CBinaryNodeTree<ItemType>::Preorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const
{
    if (treePtr != nullptr)
    {
        Visit(treePtr->GetItem());
        Preorder(Visit, treePtr->GetLeftChildPtr());
        Preorder(Visit, treePtr->GetRightChildPtr());
    }
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::Inorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const
{
    if (treePtr != nullptr)
    {
        Inorder(Visit, treePtr->GetLeftChildPtr());
        Visit(treePtr->GetItem());
        Inorder(Visit, treePtr->GetRightChildPtr());
    }
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::Postorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const
{
    if (treePtr != nullptr)
    {
        Postorder(Visit, treePtr->GetLeftChildPtr());
        Postorder(Visit, treePtr->GetRightChildPtr());
        Visit(treePtr->GetItem());
    }
}

template <typename ItemType>
void CBinaryNodeTree<ItemType>::Levelorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr, int level) const
{
    if (treePtr == nullptr)
    {
        return;
    }
    if (level == 0)
    {
        Visit(treePtr->GetItem());
    }
    else if (level > 1)
    {
        Levelorder(Visit, treePtr->GetLeftChildPtr(), level - 1);
        Levelorder(Visit, treePtr->GetRightChildPtr(), level - 1);
    }
}

