#include "TextEditor.h"

TextEditor::TextEditor()  // Class constructor
{
    length = 2;
    
    head = new LineType;
    tail = new LineType;
    
    currentLine = head;
    
    //    strcpy_s(header->info, sizeof("Top\0"),"Top\0");
    //    strcpy_s(tailer->info, sizeof("Bottom\0"), "Bottom\0");
    // You can use the above codes instead of "strncpy" if your compiler recommends.
    
    strncpy(head->info, "Top\0", sizeof("Top\0"));
    strncpy(tail->info, "Bottom\0", sizeof("Bottom\0"));
    
    /* Implement the function here */
    // You need to make some connections between "head" and "tail
    head->next = tail;
    tail->back = head;
}

TextEditor::~TextEditor()
{
    MakeEmpty();
}


void TextEditor::GoToTop() {
    currentLine = head;
}

void TextEditor::GoToBottom() {
    currentLine = tail;
}

bool TextEditor::IsFull() const
{
    LineType* location;
    try
    {
        location = new LineType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

void TextEditor::MakeEmpty()
{
    LineType* tempPtr;
    
    while(head != NULL)
    {
        tempPtr = head;
        head = head->next;
        delete tempPtr;
    }
    length = 0;
}


void TextEditor::InsertItem(ItemType* item)
{
    if(IsFull()){
        cout << "[ERROR] Cannot assign the space in HEAP" << endl;
        return;
    }
    
    /* Implement the function here */
    // It adds a string ("item") to the list and returns nothing.
    // The new string should be placed at the last position (but before "tail").
    // For example,
    // if TextEditor:  "Top" -> "Hello" -> "World" -> "Bottom"
    // then InsertItem("Nope!) will change it to
    // TextEditor:  "Top" -> "Hello" -> "World" -> "Nope!" -> "Bottom"
    // You also need to adjust "length" properly.
    
    LineType* tempPtr = new LineType;
    strncpy(tempPtr->info, item, sizeof(tempPtr->info));
    tempPtr->back = tail->back;
    tempPtr->next = tail;

    tail->back->next = tempPtr;
    tail->back = tempPtr;
    length++;
}

void TextEditor::DeleteItem(int index)
{
    /* Implement the function here */
    // It deletes a string (at the "index"-th position) from the list and returns nothing.
    // the index of "head" is always 0
    // if TextEditor:  "Top" -> "Hello" -> "World" -> "Bottom"
    // then DeleteItem(1) will remove "Hello"
    // TextEditor:  "Top" -> "World" -> "Bottom"
    // You also need to adjust "length" properly.
    
    // "head" and "tail" CANNOT be deleted.
    // if TextEditor:  "Top" -> "Hello" -> "World" -> "Bottom"
    // DeleteItem(0) and DeleteItem(3) will do NOTHING.
    // Also, DeleteItem(>3) will do NOTHING either.

    if( index <= 0 || index >= length-1) return;
    else{
        GoToTop();
        while(index != 0){
            currentLine = currentLine->next;
            index--;
        }
        currentLine->back->next = currentLine->next;
        currentLine->next->back = currentLine->back;
        delete currentLine;
        length--;
    }

}


void TextEditor::GetItemAndMove(ItemType* item)
{
    int i;
    for (i = 0; currentLine->info[i] != '\0'; i++){
        item[i] = currentLine->info[i];
    }
    item[i] = '\0';
    
    if (currentLine == tail){
        currentLine = head;
    }
    else{
        currentLine = currentLine->next;
    }
}


void TextEditor::printList(){
    GoToTop();
    char text[80];

    for (int i = 0; i < length; i++) {
        GetItemAndMove(text);
        cout << text << endl;
    }
    cout << endl;
}
