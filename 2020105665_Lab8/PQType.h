//
//  PQType.h
//  Lab08
//
//  Modified by Jeman Park on 2023/11/21.
//


#include "Heap.h"
#include "SortedType.h"

using namespace std;
enum HEAP_TYPE{MAX_HEAP, MIN_HEAP, MAX_NONRECURSIVE, SORTED_LIST};

template<class ItemType>
class PQType
{
public:
    PQType(int, ItemType, HEAP_TYPE);
    ~PQType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    void Print();
private:
    int length;
    // "items" is for HEAP-based priority queue
    HeapType<ItemType> items;
    // "items_list" is for SORTED_LIST-based priority queue
    SortedType<ItemType> items_list;
    int maxItems;
    HEAP_TYPE heap_type;
    ItemType null_val;
};


template<class ItemType>
PQType<ItemType>::PQType(int max, ItemType val, HEAP_TYPE type)
{
    maxItems = max;
    items.elements = new ItemType[max];
    for(int i=0; i<max; i++){
        items.elements[i] = val;
    }
    items.numElements = 0;
    items.null_val = val;
    null_val = val;
    length = 0;
    heap_type = type;
}


template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    length = 0;
}


template<class ItemType>
PQType<ItemType>::~PQType()
{
    delete [] items.elements;
}


template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
{
    if (length == 0){
        cout << "PQ is Empty" << endl;
        return;
    }
    else
    {
        
        if (heap_type == SORTED_LIST){
            /* Implement the function here (Exercise 8-3) */
            // "items_list" is the descending-order sorted (linked) list that stores the item -> (8, 7, 6, 5, 4, ..... )
            // You need to use PUBLIC functions in SortedType.h to implement this.
            // This extracts (gets and deletes) the MAX item from the "items_list" and returns it using "item" (return by reference)

             items_list.GetNextItem(item); //1
             items_list.DeleteItem(item); //n
            
            // What is O(n) of this Dequeue( )?
            // Answer: O(N)
            // What is O(n) of HEAP-based Dequeue( ) below?
            // Answer: O(logN)
            
        }
        else{
            item = items.elements[0];
            items.elements[0] = items.elements[length-1];
            items.elements[length-1] = null_val;
            
            items.numElements--;
            
            if (heap_type == MAX_HEAP){
                items.MAX_ReheapDown(0, length-1);
            }
            else if (heap_type == MIN_HEAP){
                items.MIN_ReheapDown(0, length-1);
            }
            else if (heap_type == MAX_NONRECURSIVE){
                items.MAX_ReheapDown_NonRecursive(0, length-1);
            }
        }
        length--;
    }
}


template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
{
    if (length == maxItems){
        cout << "PQ is Full" << endl;
        return;
    }
    else
    {
        length++;
        if (heap_type == SORTED_LIST){
            /* Implement the function here (Exercise 8-3) */
            // "items_list" is the descending-order sorted (linked) list that stores the item -> (8, 7, 6, 5, 4, ..... )
            // You need to use PUBLIC functions in SortedType.h to implement this.
            // This adds "newItem" to the "items_list"

            items_list.InsertItem(newItem);
            
            
            // What is O(n) of this Enqueue( )?
            // Answer: O(N)
            // What is O(n) of HEAP-based Enqueue( ) below?
            // Answer: O(logN)
            
            
        }
        else{
            items.numElements++;
            items.elements[length-1] = newItem;
            
            if(heap_type == MAX_HEAP){
                items.MAX_ReheapUp(0, length-1);
            }
            else if (heap_type == MIN_HEAP){
                items.MIN_ReheapUp(0, length-1);
            }
            else if (heap_type == MAX_NONRECURSIVE){
                items.MAX_ReheapUp_NonRecursive(0, length-1);
            }
        }
    }
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
{
    return length == maxItems;
}


template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
{
    return length == 0;
}


template<class ItemType>
void PQType<ItemType>::Print()
{
    if (heap_type != SORTED_LIST){
        items.Print();
    }
    else{
        items_list.printList();
    }
    
}
