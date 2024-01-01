//
//  TreeType.h
//  Lab07
//
//  Modified by Jeman Park on 2023/11/15.
//


#include <string>
#include <fstream>
#include <iostream>
#include "QueType.h"
#include "StackType.h"


#ifndef TREETYPE_H
#define TREETYPE_H

struct TreeNode;


enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
public:
    TreeType();
    ~TreeType();
    TreeType(const TreeType& originalTree);
    void operator=(const TreeType& originalTree);
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    int LengthIs();
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetTree(OrderType order);
    void GetNextItem (ItemType& item, OrderType order, bool& finished);
    QueType Anscestors_iterative(ItemType value);
    StackType Ancestors_re(ItemType value);
    
    void Print();

private:
    TreeNode* root;
    QueType preQue;
    QueType inQue;
    QueType postQue;
};


#endif
