// Header file for Queue ADT. 
#include <new>
#include <cstddef>

typedef int ItemType;

struct NodeType;
struct TreeNode;


class QueType
{
public: 
    QueType();
    ~QueType();
    QueType(const QueType& anotherQue);
    void operator=(const QueType& originalQueue);
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(TreeNode* newItem);
    TreeNode* Dequeue();
    void printQueue();

private:
    NodeType* front;
    NodeType* rear;
};


struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};
