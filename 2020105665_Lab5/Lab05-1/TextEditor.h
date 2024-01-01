#include <stddef.h>
#include <string.h>
#include <iostream>

using namespace std;
typedef char ItemType ;

struct LineType
{
    ItemType info[80];
    LineType* next;
    LineType* back;
};

class TextEditor
{
public:
    TextEditor();     // Class constructor
    ~TextEditor();    // Class destructor
    
    bool IsFull() const;
    void MakeEmpty();
    void InsertItem(ItemType* item);
    void DeleteItem(int index);
    void GetItemAndMove(ItemType* item);
    void GoToTop();
    void GoToBottom();
    void printList();
    
private:
    int length;
    LineType* currentLine;
    
    LineType* head;
    LineType* tail;
};



