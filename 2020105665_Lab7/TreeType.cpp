//
//  TreeType.cpp
//  Lab07
//
//  Modified by Jeman Park on 2023/11/15.
//


#include "TreeType.h"
#include <iostream>

using namespace std;


TreeType::TreeType() {
    root = NULL;
}


void Destroy(TreeNode *&tree);

TreeType::~TreeType() {

    Destroy(root);
}

void Destroy(TreeNode *&tree) {

    if (tree != NULL) {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}


void CopyTree(TreeNode *&copy, const TreeNode *originalTree) {

    if (originalTree == NULL)
        copy = NULL;
    else {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

TreeType::TreeType(const TreeType &originalTree) {

    CopyTree(root, originalTree.root);
}

// Operator overloading
void TreeType::operator=(const TreeType &originalTree) {
    if (&originalTree == this) {
        return;
    }

    Destroy(root);
    CopyTree(root, originalTree.root);

}


bool TreeType::IsFull() {

    TreeNode *location;
    try {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception) {
        return true;
    }
}


bool TreeType::IsEmpty() {

    return root == NULL;
}


void Retrieve(TreeNode *tree, ItemType &item, bool &found) {

    if (tree == NULL) {
        found = false;
    } else if (item < tree->info) {
        Retrieve(tree->left, item, found);
    } else if (item > tree->info) {
        Retrieve(tree->right, item, found);
    } else {
        item = tree->info;
        found = true;
    }
}


void TreeType::RetrieveItem(ItemType &item, bool &found) {

    Retrieve(root, item, found);
}


int CountNodes(TreeNode *tree) {

    if (tree == NULL) {
        return 0;
    } else {
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
    }
}


int TreeType::LengthIs() {

    return CountNodes(root);
}


void Insert(TreeNode *&tree, ItemType item) {
    if (tree == NULL) {
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    } else if (item < tree->info) {
        Insert(tree->left, item);
    } else {
        Insert(tree->right, item);
    }
}

void TreeType::InsertItem(ItemType item) {

    Insert(root, item);
}


void GetPredecessor(TreeNode *tree, ItemType &data) {
    while (tree->right != NULL) {
        tree = tree->right;
    }
    data = tree->info;
}


void DeleteNode(TreeNode *&tree);

void Delete(TreeNode *&tree, ItemType item) {

    if (tree == NULL) {
        return;
    }

    if (item < tree->info) {
        Delete(tree->left, item);
    } else if (item > tree->info) {
        Delete(tree->right, item);
    } else {
        DeleteNode(tree);
    }
}

void DeleteNode(TreeNode *&tree) {

    ItemType data;
    TreeNode *tempPtr;

    tempPtr = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    } else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    } else {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}


void TreeType::DeleteItem(ItemType item) {
    Delete(root, item);
}

void printSpace(double n, TreeNode *removed) {
    for (; n > 0; n--) {
        cout << "\t";
    }
    if (removed == NULL) {
        cout << " ";
    } else {
        cout << removed->info;
    }
}

int heightOfTree(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(heightOfTree(root->left),
                   heightOfTree(root->right));
}

void printBinaryTree(TreeNode *root) {
    QueType treeLevel, temp;
    treeLevel.Enqueue(root);
    int counter = 0;
    int height = heightOfTree(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;

    while (counter <= height) {
        TreeNode *removed = treeLevel.Dequeue();
        if (temp.IsEmpty()) {
            printSpace(numberOfElements
                       / pow(2, counter + 1),
                       removed);
        } else {
            printSpace(numberOfElements / pow(2, counter),
                       removed);
        }

        if (removed == NULL) {
            temp.Enqueue(NULL);
            temp.Enqueue(NULL);
        } else {
            temp.Enqueue(removed->left);
            temp.Enqueue(removed->right);
        }
        if (treeLevel.IsEmpty()) {
            cout << endl << endl;
            treeLevel = temp;

            while (!temp.IsEmpty()) {
                temp.Dequeue();
            }
            counter++;
        }
    }
}


void PrintTree(TreeNode *tree) {
    if (tree != NULL) {
        PrintTree(tree->left);
        cout << tree->info << "\t";
        PrintTree(tree->right);
    }
}

void TreeType::Print() {
    printBinaryTree(root);
    cout << endl;
}


void InOrder(TreeNode *tree, QueType &inQue) {
    /* Implement the function here (Exercise 7-1) */
    // When "ResetTree" (below) calls this function, it RECURSIVELY traverses the tree in In-order, and fills "inQue" with the result.
    // Refer to ch. 08-2 (pp.15)

    if (tree != nullptr) {
        InOrder(tree->left, inQue);
        inQue.Enqueue(tree);
        InOrder(tree->right, inQue);
    }

}


void PostOrder(TreeNode *tree, QueType &postQue) {
    /* Implement the function here (Exercise 7-1) */
    // When "ResetTree" (below) calls this function, it RECURSIVELY traverses the tree in Post-order, and fills "postQue" with the result.
    // Refer to ch. 08-2 (pp.22)

    if (tree != nullptr) {
        PostOrder(tree->left, postQue);
        PostOrder(tree->right, postQue);
        postQue.Enqueue(tree);
    }


}


void PreOrder(TreeNode *tree, QueType &preQue) {
    /* Implement the function here (Exercise 7-1) */
    // When "ResetTree" (below) calls this function, it RECURSIVELY traverses the tree in Pre-order, and fills "preQue" with the result.
    // Refer to ch. 08-2 (pp.25)

    if (tree != nullptr) {
        preQue.Enqueue(tree);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }

}


void TreeType::ResetTree(OrderType order) {
    switch (order) {
        case PRE_ORDER :
            PreOrder(root, preQue);
            break;

        case IN_ORDER  :
            InOrder(root, inQue);
            break;

        case POST_ORDER:
            PostOrder(root, postQue);
            break;
    }
}


void TreeType::GetNextItem(ItemType &item, OrderType order, bool &finished) {
    /* Implement the function here (Exercise 7-1) */
    // Depending on the parameter "order", it dequeus from the corresponding queue and returns it (call by reference "item")
    // Only if the dequeued item is the last item in the queue, it sets "finished" as TRUE. Otherwise, FALSE.
    // Refer to ch. 08-2 (pp.32)

    switch (order) {
        case PRE_ORDER:
            if (!preQue.IsEmpty()) item = preQue.Dequeue()->info;
            else finished = true;
            break;
        case IN_ORDER:
            if (!inQue.IsEmpty()) item = inQue.Dequeue()->info;
            else finished = true;
            break;
        case POST_ORDER:
            if (!postQue.IsEmpty()) item = postQue.Dequeue()->info;
            else finished = true;
            break;
    }

}

QueType TreeType::Anscestors_iterative(ItemType value) {
    bool found = false;
    QueType path;
    /* Implement the function here (Exercise 7-2) */
    // The function ITERATIVELY searches the ancestors of "value" in Binary Search Tree.
    // It retuns if it successfully finds the "value" in the tree (return true or false)
    // While searching (Binary Search), it enqueues ANCESTORS into "path" QUEUEk.
    TreeNode *current = root;

    while (!found) {
        if (current == nullptr) break;

        if (value < current->info) {
            path.Enqueue(current);
            current = current->left;
        } else if (value > current->info) {
            path.Enqueue(current);
            current = current->right;
        } else found = true;
    }


    if (current == nullptr)
        while (!path.IsEmpty()) {
            path.Dequeue();
        }

    return path;

}


bool Ancestors_recursive(TreeNode *tree, ItemType value, StackType &path) {
    bool found = false;
    /* Implement the function here (Exercise 7-3) */
    // The function ITERATIVELY searches the ancestors of "value" in Binary Search Tree.
    // It retuns if it successfully finds the "value" in the tree (return true or false)
    // While searching (Binary Search), it pushes ANCESTORS into "path" STACK.

    if (tree == nullptr) found = false;
    else {
        if (value < tree->info) {
            if (Ancestors_recursive(tree->left, value, path)) {
                path.Push(tree);
                found = true;
            }
        } else if (value > tree->info) {
            if (Ancestors_recursive(tree->right, value, path)) {
                path.Push(tree);
                found = true;
            }
        } else {
            found = true;
        }
    }

    return found;
}

StackType TreeType::Ancestors_re(ItemType value) {
    StackType path;
    if (Ancestors_recursive(root, value, path)) {
        return path;
    } else {
        StackType dummy;
        return dummy;
    }

}


