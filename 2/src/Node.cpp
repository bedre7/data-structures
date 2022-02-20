/** 
* @file         Node.cpp
* @description  Contains LineQueue's Node implemetation
* @course       Data Structures 1B
* @assignment   2. Odev
* @date         23/12/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/

#include "Node.hpp"

Node::Node(const Point &point, Node *next)
{
    this->point = point;
    this->next = next;
}

