#include <iostream>
#include "TextEditor.h"
using namespace std;


int main() {

	TextEditor editor;

	char text1[80] = "Hello\0";
	char text2[80] = "World\0";
	editor.InsertItem(text1);
    editor.printList();
//    Top
//    Hello
//    Bottom
    
	editor.InsertItem(text2);
    editor.printList();
//    Top
//    Hello
//    World
//    Bottom
    
    
    
    editor.DeleteItem(1);
    editor.printList();
//    Top
//    World
//    Bottom

    char text3[80] = "Data Structure\0";
    editor.InsertItem(text3);
    editor.printList();
//    Top
//    World
//    Data Structure
//    Bottom
    
    editor.DeleteItem(2);
    editor.printList();
//    Top
//    World
//    Bottom
    
    editor.DeleteItem(2); // DeleteItem cannot delete "head" and "tail", so it does nothing.
    editor.printList();
//    Top
//    World
//    Bottom
    
    editor.DeleteItem(1);
    editor.printList();
//    Top
//    Bottom
	
	return 0;
}
