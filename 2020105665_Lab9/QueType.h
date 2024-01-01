//
//  QueType.h
//  Lab09
//
//  Modified by Jeman Park on 2023/11/28.
//

#ifndef QUETYPE_H
#define QUETYPE_H

template <class ItemType>
struct NodeType;

template <class ItemType>
class QueType
{
public:
    QueType();
    ~QueType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);

private:
    NodeType<ItemType>* front;
    NodeType<ItemType>* rear;
};

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};


template <class ItemType>
QueType<ItemType>::QueType()
{
    front = NULL;
    rear = NULL;
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty()
{
    NodeType<ItemType>* tempPtr;
    
    while (front != NULL)
    {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}

template <class ItemType>
QueType<ItemType>::~QueType()
{
    MakeEmpty();
}

template<class ItemType>
bool QueType<ItemType>::IsFull() const
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(const std::bad_alloc& e)
    {
        return true;
    }
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const
{
    return (front == NULL);
}


template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
    if (IsFull()){
        std::cout << "[ERROR] Queue is full. ENQUEUE failed." << std::endl;
        return;
    }
    else
    {
        NodeType<ItemType>* newNode;
        
        newNode = new NodeType<ItemType>;
        newNode->info = newItem;
        newNode->next = NULL;
        if (rear == NULL)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
    if (IsEmpty()){
        std::cout << "[ERROR] Queue is empty. DEQUEUE failed." << std::endl;
        return;
    }
    
    else
    {
        NodeType<ItemType>* tempPtr;
        
        tempPtr = front;
        item = front->info;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tempPtr;
    }
}

#endif
