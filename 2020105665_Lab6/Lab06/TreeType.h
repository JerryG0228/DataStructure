//#include <string>
#include "QueType.h"

#define PREDECESSOR 1
#define SUCCESSOR 2

class TreeType
{
public:
    TreeType();
    ~TreeType();
    TreeType(const TreeType& originalTree);
    void operator=(const TreeType& originalTree);
    bool IsEmpty();
    bool IsFull();
    int LengthIs();
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void InsertItemNonBST(ItemType item);
    void DeleteItem(ItemType item, int adjust_policy);
    
    void Print();

    
private:
    TreeNode* root;
};

