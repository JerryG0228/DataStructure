#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main() {
	UnsortedType<int> listData;

	listData.InsertItem(4);
	listData.InsertItem(1);
	listData.InsertItem(7);
	listData.InsertItem(3);
    listData.printList();
    // 1    3    4    7
    
    listData.InsertItem(1);
    listData.printList();
    // 1    1    3    4    7
	
    listData.InsertItem(4);
    listData.printList();
    // 1    1    3    4    4    7

	return 0;
}
