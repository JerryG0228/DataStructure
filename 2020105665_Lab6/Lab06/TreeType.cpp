
#include "TreeType.h"
#include <iostream>

using namespace std;


TreeType::TreeType(){

    root = NULL;
}



void Destroy(TreeNode*& tree);

TreeType::~TreeType(){

    Destroy(root);
}

void Destroy(TreeNode*& tree){

    if (tree != NULL){
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}


void CopyTree(TreeNode*& copy, const TreeNode* originalTree){

    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

TreeType::TreeType(const TreeType& originalTree){

    CopyTree(root, originalTree.root);
}

// Operator overloading
void TreeType::operator= (const TreeType& originalTree){
    if (&originalTree == this){
        return;
    }

    Destroy(root);
    CopyTree(root, originalTree.root);

}


bool TreeType::IsFull(){

    TreeNode* location;
    try
    {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}


bool TreeType::IsEmpty(){

    return root == NULL;
}


void Retrieve(TreeNode* tree, ItemType& item, bool& found){

    if (tree == NULL){
        found = false;
    }
    else if (item < tree->info){
        Retrieve(tree->left, item, found);
    }
    else if (item > tree->info){
        Retrieve(tree->right, item, found);
    }
    else{
        item = tree->info;
        found = true;
    }
}


void TreeType::RetrieveItem(ItemType& item, bool& found){

    Retrieve(root, item, found);
}


int CountNodes(TreeNode* tree){
    /* Implement the member function here (exercise #2) */
    /* Return the number of nodes */
    /* This function should be implemented in a "recursive way" */

    if(tree == nullptr) return 0;
    else{
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
    }

}


int TreeType::LengthIs(){

    return CountNodes(root);
}


void Insert(TreeNode*& tree, ItemType item){
    /* Implement the function here (Exercise #1) */
    /* Insert the Item into the PROPER place (based on how Binary Search Tree works) */
    /* This functon should be implement in a "recursive way" (NOT iterative way) */
    /* HINT: You may refer to chap08-1 (pp. 54). */
    if(tree == nullptr){
        tree = new TreeNode;
        tree->info = item;
    }
    else if(tree->left== nullptr && tree->right == nullptr){
        if(tree->info>item){
            tree->left = new TreeNode;
            tree->left->info = item;
        }else{
            tree->right = new TreeNode;
            tree->right->info = item;
        }
    }else{
        if(tree->info>item) Insert(tree->left, item);
        else Insert(tree->right, item);
    }

}

void TreeType::InsertItem(ItemType item){

    Insert(root, item);
}


void TreeType::InsertItemNonBST(ItemType item){
    /* Implement the function here (Exercise #4) */
    /* Insert the Item into the FIRST empty place (left-most side) */
    /* This functon should be implement in an "iterative way" (NOT recursive way) */
    /* We do NOT consider DELETE in nonBST tree */
    /* HINT: You may need to use "QUEUE" to implement this. */
    /* You can refer to printBinaryTree() below to see how to perform Breadth-First Search in Tree. */
    TreeNode* tempPtr;
    if(root == nullptr){
        tempPtr = new TreeNode;
        tempPtr->info = item;
        root = tempPtr;
    }
    else{
        QueType temp;
        temp.Enqueue(root);

        while(true){
            tempPtr = temp.Dequeue();
            if(tempPtr->left == nullptr){
                tempPtr->left = new TreeNode;
                tempPtr->left->info = item;
                break;
            }
            else if(tempPtr->right == nullptr){
                tempPtr->right = new TreeNode;
                tempPtr->right->info = item;
                break;
            }else{
                temp.Enqueue(tempPtr->left);
                temp.Enqueue(tempPtr->right);
            }
        }

    }

}


void GetPredecessor(TreeNode* tree, ItemType& data){
    /* Implement the function here (Exercise #3) */
    while(tree->right != nullptr) tree = tree->right;
    data = tree->info;
}

void GetSuccessor(TreeNode* tree, ItemType& data){
    /* Implement the function here (Exercise #3) */
    while(tree->left != nullptr) tree = tree->left;
    data = tree->info;
}

void DeleteNode(TreeNode*& tree, int adjust_policy);

void Delete(TreeNode*& tree, ItemType item, int adjust_policy){

    if (tree == NULL){
        return;
    }

    if (item < tree->info){
        Delete(tree->left, item, adjust_policy);
    }
    else if (item > tree->info){
        Delete(tree->right, item, adjust_policy);
    }
    else{
        DeleteNode(tree, adjust_policy);
    }
}

void DeleteNode(TreeNode*& tree, int adjust_policy){
    /* Implement the function here (Exercise #3) */
    /* Delete the node and reshape the BST accordingly. */
    /* You can refer to ch.08-1 pp.63*/
    /* But, this function has one more parameter "adjust_policy", which means how we decide the node to be moved */
    /* adjust_policy must be either PREDECESSOR (int 1) or SUCCESSOR (int 2) */
    /* Based on the value of adjust_policy (1 or 2), this function should call "GetPredecessor()" or "GetSuccessor()" function */
    TreeNode* tempPtr;

    if (tree->left == nullptr){
        tempPtr = tree;
        tree = tree->left;
        delete tempPtr;
    }
    else if (tree->right == nullptr){
        tempPtr = tree;
        tree = tree->left;
        delete tempPtr;
    }
    else{
        ItemType item;
        if(adjust_policy == 1){
            GetPredecessor(tree->left, item);
            Delete(tree, item, adjust_policy);
            tree->info = item;
        }
        else if(adjust_policy == 2){
            GetSuccessor(tree->right, item);
            Delete(tree, item, adjust_policy);
            tree->info = item;
        }
    }
}


void TreeType::DeleteItem(ItemType item, int adjust_policy)
{
    Delete(root, item, adjust_policy);
}

void printSpace(double n, TreeNode* removed)
{
    for (; n > 0; n--) {
        cout << "\t";
    }
    if (removed == NULL) {
        cout << " ";
    }
    else {
        cout << removed->info;
    }
}

int heightOfTree(TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    return 1 + max(heightOfTree(root->left),
                 heightOfTree(root->right));
}

void printBinaryTree(TreeNode* root)
{
    QueType treeLevel, temp;
    treeLevel.Enqueue(root);
    int counter = 0;
    int height = heightOfTree(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;

    while (counter <= height) {
        TreeNode* removed = treeLevel.Dequeue();
        if (temp.IsEmpty()) {
            printSpace(numberOfElements
                           / pow(2, counter + 1),
                       removed);
        }
        else {
            printSpace(numberOfElements / pow(2, counter),
                       removed);
        }

        if (removed == NULL) {
            temp.Enqueue(NULL);
            temp.Enqueue(NULL);
        }
        else {
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


void PrintTree(TreeNode* tree){
    if (tree != NULL)
    {
        PrintTree(tree->left);
        cout << tree->info << "\t";
        PrintTree(tree->right);
    }
}

void TreeType::Print(){
    printBinaryTree(root);
//    PrintTree(root);
    cout << endl;
}
