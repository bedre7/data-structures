/** 
* @file         Node.cpp
* @description  Node class implementation
* @course       Data Structures 1B
* @assignment   1. Odev
* @date         14/11/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/
#include "Node.hpp"

Node::Node(const string &data, Node *next, Node *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}