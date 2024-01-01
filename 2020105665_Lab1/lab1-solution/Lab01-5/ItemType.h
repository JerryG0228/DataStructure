//
//  ItemType.h
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

#ifndef ITEMTYPE_H
#define ITEMTYPE_H


const int MAX_ITEMS = 20;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType
{
public:
    ItemType();
    ItemType(int);
    RelationType ComparedTo(ItemType) const;
    void Print() const;
    void Initialize(int number);
private:
    int value;
};

#endif // !1
