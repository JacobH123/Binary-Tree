#ifndef CBINARY_NODE_TPP
#define CBINARY_NODE_TPP

//default constructor 
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode() : 
m_leftChildPtr(nullptr), m_rightChildPtr(nullptr) {}


//Type constructor sets value of m_item
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode(const ItemType& item) : 
m_item(item), m_leftChildPtr(nullptr), m_rightChildPtr(nullptr) {}


//Constructor sets values of child ptrs
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode(const ItemType& item, CBinaryNode<ItemType>* leftChildPtr, CBinaryNode<ItemType>* rightChildPtr)
    : m_item(item), m_leftChildPtr(leftChildPtr), m_rightChildPtr(rightChildPtr) {}


template<class ItemType>
void CBinaryNode<ItemType>::SetItem(const ItemType& item) {
    m_item = item;
}

template<class ItemType>
ItemType CBinaryNode<ItemType>::GetItem() const {
    return m_item;
}

//Checks if node is a leaf
template<class ItemType>
bool CBinaryNode<ItemType>::IsLeaf() const {
    return (m_leftChildPtr == nullptr && m_rightChildPtr == nullptr);
}

template<class ItemType>
CBinaryNode<ItemType>* CBinaryNode<ItemType>::GetLeftChildPtr() const {
    return m_leftChildPtr;
}

template<class ItemType>
CBinaryNode<ItemType>* CBinaryNode<ItemType>::GetRightChildPtr() const {
    return m_rightChildPtr;
}

template<class ItemType>
void CBinaryNode<ItemType>::SetLeftChildPtr(CBinaryNode<ItemType>* leftChildPtr) {
    m_leftChildPtr = leftChildPtr;
}

template<class ItemType>
void CBinaryNode<ItemType>::SetRightChildPtr(CBinaryNode<ItemType>* rightChildPtr) {
    m_rightChildPtr = rightChildPtr;
}

#endif