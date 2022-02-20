/** 
* @file         AVL.cpp
* @description  Contains the implementation of AVL tree functions
* @course       Data Structures 1B
* @assignment   2. Odev
* @date         23/12/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/

#include "AVL.hpp"

AVLNode* AVL::add(AVLNode* subNode, const LineQueue &item)
{
    if(subNode == NULL) subNode = new AVLNode(item);
    else if(item.getLength() <= subNode->length)                
    {
        subNode->left = add(subNode->left, item);

        if( !isBalanced(subNode))
        {
            if(item.getLength() <= subNode->left->length)           //LL-imbalance case
                subNode = RotateRight(subNode);
            else                                                    
            {                                                       //LR-imbalance case
                subNode->left = RotateLeft(subNode->left);
                subNode = RotateRight(subNode);
            }
        }
    }
    else
    {
        subNode->right = add(subNode->right, item);
        
        if( !isBalanced(subNode))                                     
        {
            if(subNode->right->length < item.getLength())           //RR-imbalance case
                subNode = RotateLeft(subNode);
            else                                                    
            {                                                       //RL-imbalance case
                subNode->right = RotateRight(subNode->right);
                subNode = RotateLeft(subNode);
            }
        }
    }
    return subNode;
}
int AVL::Height(AVLNode* subNode)
{
    if(subNode != NULL)
    {
        return  1 + max(Height(subNode->left), Height(subNode->right));
    }
    return -1;
}
//This finds out whether the sub-tree is balanced or not using absolute value
bool AVL::isBalanced(AVLNode *subNode)
{
    return abs(Height(subNode->left) - Height(subNode->right)) < 2;
}
//This is used to correct LL and LR imbalances
AVLNode* AVL::RotateRight(AVLNode *subNode)
{
    AVLNode *newSubRoot = subNode->left;
    subNode->left = newSubRoot->right;
    newSubRoot->right = subNode;
    return newSubRoot;
}
//This is used to correct RR and RL imbalances
AVLNode* AVL::RotateLeft(AVLNode *subNode)
{
    AVLNode *newSubRoot = subNode->right;
    subNode->right = newSubRoot->left;
    newSubRoot->left = subNode;
    return newSubRoot; 
}
void AVL::postorder(AVLNode *subNode)
{
    if(subNode != NULL)
    {
        postorder(subNode->left);
        postorder(subNode->right);
        subNode->data.printQueue();
    }
}
//All nodes are deleted in postorder traversal recursively
void AVL::DeleteNodes(AVLNode *&subNode)
{
    if(subNode == NULL) return;
    DeleteNodes(subNode->left);
    DeleteNodes(subNode->right);
    delete subNode;
    subNode = NULL;
}
AVL::AVL()
{
    root = NULL;
}
void AVL::add(const LineQueue &item)
{
    root = add(root, item);
}
int AVL::Height()
{
    return Height(root);
}
void AVL::postorder()
{
    postorder(root);
}
bool AVL::isEmpty()
{
    return root == NULL;
}
AVL::~AVL()
{
    DeleteNodes(root);
}