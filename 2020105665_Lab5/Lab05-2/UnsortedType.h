#include<iostream>

using namespace std;

template<class ItemType>
struct NodeType;

template<class ItemType>
class UnsortedType {
public:
    UnsortedType();

    ~UnsortedType();

    bool IsFull() const;

    void MakeEmpty();

    void RetrieveItem(ItemType &item, bool &found);

    void InsertItem(ItemType item);

    void DeleteItem(ItemType item);

    void Sort(NodeType<ItemType> *location);

    void printList();

protected:
    NodeType<ItemType> *MinLoc(NodeType<ItemType> *location, NodeType<ItemType> *minPtr);

private:
    NodeType<ItemType> *listData;
    int length;
};

template<class ItemType>
struct NodeType {
    ItemType info;
    NodeType *next;
};

template<class ItemType>
UnsortedType<ItemType>::UnsortedType() {
    length = 0;
    listData = NULL;
}

template<class ItemType>
UnsortedType<ItemType>::~UnsortedType() {
    MakeEmpty();
}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const {
    NodeType<ItemType> *location;
    try {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (bad_alloc exception) {
        return true;
    }
}

template<class ItemType>
void UnsortedType<ItemType>::MakeEmpty() {
    NodeType<ItemType> *tempPtr;

    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template<class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType &item, bool &found) {
    bool moreToSearch;
    NodeType<ItemType> *location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found) {
        if (item == location->info) {
            found = true;
            item = location->info;
        } else {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}

template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item) {
    NodeType<ItemType> *location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;

    Sort(listData);
}

template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
    NodeType<ItemType> *location = listData;
    NodeType<ItemType> *tempLocation;

    if (item == listData->info) {
        tempLocation = location;
        listData = listData->next;        // Delete first node.
    } else {
        while (!(item == (location->next)->info)) {
            location = location->next;
        }

        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template<class ItemType>
void UnsortedType<ItemType>::Sort(NodeType<ItemType> *location) {
    // Implement the function here
    // Sort() must use (1) recursion and (2) MinLoc()
    // It returns nothing, but after Sort() the list will be sorted

    // For example, suppose that the list is [43, 21, 14, 26, 17]
    // 1) First *location points to 43 (1st element)
    // 2) Finds the MIN value of the list using MinLoc. (14)
    // 3) Changes their positions -> [14, 21, 43, 26, 17]
    // 4) Recursively call "Sort()" for location->next [21, 43, 26, 17]
    // 5) Finds the MIN value of the list using MinLoc. (17)
    // 6) Changes their positions -> [17, 43, 26, 21]
    // Repeat....

    if (location == nullptr) return;
    ItemType firstItem = location->info;
    NodeType<ItemType> *min = MinLoc(location, location);
    location->info = min->info;
    min->info = firstItem;
    Sort(location->next);

}

template<class ItemType>
NodeType<ItemType> *UnsortedType<ItemType>::MinLoc(NodeType<ItemType> *location, NodeType<ItemType> *minPtr) {
    // Implement the function here
    // MinLoc returns the pointer to the MIN value node.
    // MinLoc "recursively" finds the MIN value.
    // Similar to "recursive InsertItem/DeleteItem in Ch.07 slides pp45-49

    if (location == nullptr) return minPtr;
    if (location->info < minPtr->info) minPtr = location;
    return MinLoc(location->next, minPtr);
}

template<class ItemType>
void UnsortedType<ItemType>::printList() {
    NodeType<ItemType> *tempPtr = listData;

    while (tempPtr != NULL) {
        cout << tempPtr->info << "\t";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}
