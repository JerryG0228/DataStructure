//
//  SortedType.h
//  Lab04-3
//
//  Modified by Jeman Park on 2023/10/17.
//

#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include<iostream>


template <class ItemType>
struct NodeType;

template <class ItemType>
class SortedType
{
public:
    SortedType();
    ~SortedType();
    bool IsFull();
    int  LengthIs();
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    ItemType DeleteItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType&);
    void printList();
    
private:
    NodeType<ItemType>* listData;
    int length;
    NodeType<ItemType>* currentPos;
};


template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};


template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData = NULL;
}


template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    
    /* Implement the function here */
    // Deallocate all nodes in the queue.
    // Set Front and Rear pointers properly (NULL).
    while(length!=0){
        NodeType<ItemType>* tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
        length--;
    }
    
    std::cout << "LIST is completely deleted." << std::endl;
}


template<class ItemType>
bool SortedType<ItemType>::IsFull()
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}


template <class ItemType>
int SortedType<ItemType>::LengthIs()
{
    return length;
}


template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    NodeType<ItemType>* location;
    
    location = listData;
    found = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found)
    {
        if (location->info < item)
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
        else if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else{
            moreToSearch = false;
        }
    }
}


template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    
    /* Implement the function here */
    // Insert the new item into the sorted list.
    // * Find the proper position
    // * Insert new item by creating and linking a new node
    // Hint: You may need 2 pointers to find the proper position (ch5 slides 94-100)
    NodeType<ItemType>* tempPtr = new NodeType<ItemType>;
    tempPtr->info = item;

    if(listData == nullptr){
        listData = tempPtr;
        length++;
    }
    else{
        if(listData->info > item){
            tempPtr->next = listData;
            listData = tempPtr;
            length++;
        }
        else{
            currentPos = listData;
            NodeType<ItemType>* prev = nullptr;
            while(currentPos != nullptr && currentPos->info < item){
                prev = currentPos;
                currentPos = currentPos->next;
            }
            prev->next = tempPtr;
            tempPtr->next = currentPos;
            length++;
        }

    }
}


template <class ItemType>
ItemType SortedType<ItemType>::DeleteItem(ItemType item)
{
    ItemType ret;
    /* Implement the function here */
    // Delete the item from the sorted list.
    // * Find the item
    // * If found, set "ret" to "item"
    // * If the item does not exist, return -1
    // * Delete the item from the list and maintain the list properly
    // * Deallocate the deleted node
    
    // Hint: You need to handle two cases:
    // 1) when the item exists at the first position
    // 2) the item exists at other position (ch5 slide 87)

    currentPos = listData;
    NodeType<ItemType>* prev = nullptr;
    NodeType<ItemType>* tempPtr = nullptr;
    while(currentPos != nullptr && currentPos->info != item){
        prev = currentPos;
        currentPos = currentPos->next;
    }
    if( currentPos == listData){
        tempPtr = listData;
        listData = listData->next;
        ret = tempPtr->info;
        delete tempPtr;
        length--;
    }
    else if(currentPos == nullptr){
        ret = -1;
    }
    else{
        tempPtr = currentPos;
        prev->next = currentPos->next;
        ret = tempPtr->info;
        delete tempPtr;
        length--;
    }

    return ret;
}


template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = NULL;
}


template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
    if (currentPos == NULL){
        currentPos = listData;
    }
    item = currentPos->info;
    currentPos = currentPos->next;
} 



template <class ItemType>
void SortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = listData;
    
    std::cout << "[\t";
    while (tempPtr != NULL)
    {
        std::cout << tempPtr->info << "\t";
        tempPtr = tempPtr->next;
    }
    
    std::cout << "]" << std::endl;
    
}

#endif
