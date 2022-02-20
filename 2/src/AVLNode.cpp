/** 
* @file         AVLNode.cpp
* @description  Contains the implementation of AVL's Node
* @course       Data Structures 1B
* @assignment   2. Odev
* @date         23/12/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/
#include "AVLNode.hpp"

AVLNode::AVLNode(const LineQueue &data, AVLNode *left, AVLNode *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
    this->length = data.getLength();
}