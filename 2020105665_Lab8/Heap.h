//
//  Heap.h
//  Lab08
//
//  Modified by Jeman Park on 2023/11/21.
//

#include <math.h>

template<class ItemType>
void swap(ItemType &one, ItemType &two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.

struct HeapType {
    void MAX_ReheapDown(int root, int bottom);

    void MAX_ReheapDown_NonRecursive(int root, int bottom);

    void MAX_ReheapUp(int root, int bottom);

    void MAX_ReheapUp_NonRecursive(int root, int bottom);

    void MIN_ReheapDown(int root, int bottom);

    void MIN_ReheapUp(int root, int bottom);

    void Print();

    ItemType *elements;   // Array to be allocated dynamically
    int numElements;
    ItemType null_val;
};

template<class ItemType>
void Swap(ItemType &one, ItemType &two) {
    ItemType temp;
    temp = one;
    one = two;
    two = temp;
}

template<class ItemType>
void HeapType<ItemType>::MAX_ReheapUp(int root, int bottom) {
    /* Implement the function here (Exercise 8-1 (1)) */
    // Implement "MAX_ReheapUp( )" function for MAX heap (recursive).
    // This starts from the bottom and recursively swaps nodes to maintain the order property of MAX HEAP.
    // ReHeapUp( ) is used by "Enqueue( )" in PQType.h
    // You can refer to Ch09 (pp. 21)

    int parent;

    if (bottom > root) {
        parent = (bottom - 1) / 2;
        if (elements[parent] < elements[bottom]) {
            Swap(elements[parent], elements[bottom]);
            MAX_ReheapUp(root, parent);
        }
    }

}


template<class ItemType>
void HeapType<ItemType>::MAX_ReheapDown(int root, int bottom) {
    int maxChild;
    int rightChild = root * 2 + 2;
    int leftChild = root * 2 + 1;

    /* Implement the function here (Exercise 8-1 (1)) */
    // Implement "MAX_ReheapDown( )" function for MAX heap (recursive).
    // This starts from the root and recursively swaps nodes to maintain the order property of MAX HEAP.
    // ReHeapDown( ) is used by "Dequeue( )" in PQType.h
    // You can refer to Ch09 (pp. 15-16)



    if (leftChild <= bottom) {
        if(elements[leftChild]==null_val) return;
        if (leftChild == bottom)
            maxChild = leftChild;
        else
            maxChild = elements[leftChild] <= elements[rightChild] ? rightChild : leftChild;

        if (elements[root] < elements[maxChild]) {
            Swap(elements[root], elements[maxChild]);
            MAX_ReheapDown(maxChild, bottom);
        }
    }
}


template<class ItemType>
void HeapType<ItemType>::MIN_ReheapUp(int root, int bottom) {
    int parent;

    /* Implement the function here (Exercise 8-1 (2)) */
    // Implement "MIN_ReheapUp( )" function for MIN heap (recursive).
    // This starts from the bottom and recursively swaps nodes to maintain the order property of MIN HEAP.
    // ReHeapUp( ) is used by "Enqueue( )" in PQType.h
    // You can use and edit MAX_ReheapUP( ) to implment it.

    if (bottom > root) {
        parent = (bottom - 1) / 2;
        if (elements[parent] > elements[bottom]) {
            Swap(elements[parent], elements[bottom]);
            MIN_ReheapUp(root, parent);
        }
    }
}


template<class ItemType>
void HeapType<ItemType>::MIN_ReheapDown(int root, int bottom) {
    int minChild;
    int rightChild = root * 2 + 2;
    int leftChild = root * 2 + 1;

    /* Implement the function here (Exercise 8-1 (2)) */
    // Implement "MIN_ReheapDown( )" function for MIN heap (recursive).
    // This starts from the bottom and recursively swaps nodes to maintain the order property of MIN HEAP.
    // ReHeapDown( ) is used by "Dequeue( )" in PQType.h
    // You can use and edit MAX_ReheapDown( ) to implment it.

    if (leftChild <= bottom) {
        if(elements[leftChild]==null_val) return;
        if (leftChild == bottom)
            minChild = leftChild;
        else
            minChild = elements[leftChild] >= elements[rightChild] ? rightChild : leftChild;

        if (elements[root] > elements[minChild]) {
            Swap(elements[root], elements[minChild]);
            MIN_ReheapDown(minChild, bottom);
        }
    }

}

template<class ItemType>
void HeapType<ItemType>::MAX_ReheapUp_NonRecursive(int root, int bottom) {
    int parent;

    /* Implement the function here (Exercise 8-2) */
    // Implement "MAX_ReheapUp_NonRecursive( )" function for MAX heap (iterative -- while).
    // This starts from the bottom and iteratively swaps nodes to maintain the order property of MAX HEAP.
    // MAX_ReheapUp_NonRecursive( ) is used by "Enqueue( )" in PQType.h

    while (root < bottom) {
        parent = (bottom - 1) / 2;
        if (elements[parent] < elements[bottom]) {
            Swap(elements[parent], elements[bottom]);
            bottom = parent;
        } else break;
    }

}


template<class ItemType>
void HeapType<ItemType>::MAX_ReheapDown_NonRecursive(int root, int bottom) {
    int maxChild, leftChild, rightChild;

    /* Implement the function here (Exercise 8-2) */
    // Implement "MAX_ReheapDown_NonRecursive( )" function for MAX heap (iterative -- while).
    // This starts from the root and iteratively swaps nodes to maintain the order property of MAX HEAP.
    // MAX_ReheapDown_NonRecursive( ) is used by "Enqueue( )" in PQType.h

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    while (leftChild <= bottom) {
        if(elements[leftChild]==null_val) break;
        if (leftChild == bottom) {
            maxChild = leftChild;
        } else {
            maxChild = elements[leftChild] < elements[rightChild] ? rightChild : leftChild;
        }
        if (elements[root] < elements[maxChild]) {
            Swap(elements[root], elements[maxChild]);
            root = maxChild;
            leftChild = root * 2 + 1;
            rightChild = root * 2 + 2;
        } else break;
    }

}

template<class ItemType>
void printSpace(double n, ItemType item, ItemType null_val) {
    for (; n > 0; n--) {
        cout << "\t";
    }
    if (item == null_val) {
        cout << " ";
    } else {
        cout << item;
    }
}

template<class ItemType>
void printHeap(ItemType *elements, int numElements, ItemType null_val) {

    int counter = 0;

    int height = log2(numElements);

    int max_row = pow(2, (height + 1)) - 1;

    while (counter <= height) {
        int height_max = pow(2, counter);
        int height_counter = pow(2, counter) - 1;

        for (int i = 0; i < height_max; i++) {
            printSpace(max_row / pow(2, counter) + 1, elements[height_counter], null_val);
            height_counter++;
        }

        counter++;
        cout << endl << endl;
    }
}

template<class ItemType>
void HeapType<ItemType>::Print() {
    printHeap(elements, numElements, null_val);
    cout << endl;
}
