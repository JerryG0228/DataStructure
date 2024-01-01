//
//  StackType.h
//  Lab09
//
//  Modified by Jeman Park on 2023/11/28.
//


#ifndef STACKTYPE_H
#define STACKTYPE_H

template <class ItemType>
class StackType
{
public:
    
    StackType();
    ~StackType();
    StackType(const StackType& anotherStack);
    void operator=(const StackType& originalStack);
    bool IsFull();
    bool IsEmpty();
    void Push(ItemType newItem);
    void Pop(ItemType& item);
    void printStack();
    
private:
    NodeType<ItemType>* topPtr;
};

template <class ItemType>
StackType<ItemType>::StackType()
{
    topPtr = NULL;
}

template <class ItemType>
StackType<ItemType>::~StackType()
{
    NodeType<ItemType>* tempPtr;
    
    while (topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
    if (IsFull()){
        std::cout << "[ERROR] Stack is full. PUSH failed." << std::endl;
        return;
    }
    else
    {
        NodeType<ItemType>* newNode;
        newNode = new NodeType<ItemType>;
        newNode->info = newItem;
        newNode->next = topPtr;
        topPtr = newNode;
    }
}

template <class ItemType>
void StackType<ItemType>::Pop(ItemType& item)
{
    if (IsEmpty()){
        std::cout << "[ERROR] Stack is empty. POP failed." << std::endl;
        return;
    }
    else
    {

        NodeType<ItemType>* tempPtr;
        tempPtr = topPtr;
        item = topPtr->info;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    
//    return ret;
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty()
{
    return (topPtr == NULL);
}

template <class ItemType>
bool StackType<ItemType>::IsFull()
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc)
    {
        return true;
    }
}
//
//template <class ItemType>
//void CopyStack(NodeType*& copy, const NodeType* originalStack){
//    
//    if (originalStack == NULL)
//        copy = NULL;
//    else
//    {
//        copy = new NodeType;
//        copy->info = originalStack->info;
//        CopyStack(copy->next, originalStack->next);
//    }
//}
//
//template <class ItemType>
//void StackType<ItemType>::operator= (const StackType& originalStack){
//    if (&originalStack == this){
//        return;
//    }
//    
//    this->~StackType();
//    CopyStack(topPtr, originalStack.topPtr);
//    
//}
//
//template <class ItemType>
//StackType<ItemType>::StackType(const StackType& anotherStack){
//    CopyStack(topPtr, anotherStack.topPtr);
//}


//template <class ItemType>
//void StackType::printStack(){
//    NodeType* temp = topPtr;
//    std::cout << std::endl;
//
//    std::cout << "STACK: ";
//    while (temp != NULL) {
//        std::cout << temp->info->info << "\t";
//        temp = temp->next;
//    }
//    std::cout << std::endl;
//}

#endif
