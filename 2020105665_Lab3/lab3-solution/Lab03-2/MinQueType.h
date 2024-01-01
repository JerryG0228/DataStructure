//
//  MinQueType.h
//  Lab03-2
//
//  Modified by Jeman Park on 2023/10/03.

#ifndef MINQUETYPE_H
#define MINQUETYPE_H

typedef int ItemType;
class QueType
{
public:
    QueType(int max);
    ~QueType();
    bool IsEmpty() const;
    bool IsFull() const;
    
    void Enqueue(ItemType newItem);

    ItemType MinDequeue();
    void printQueue();
private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
    int minPos;
};





#endif /* StackType_hpp */
