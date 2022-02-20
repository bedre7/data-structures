/** 
* @file         DoublyLinkedList.cpp
* @description  This file includes the linkedlist method's implementations
* @course       Data Structures 1B
* @assignment   1. Odev
* @date         14/11/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/
#include "DoublyLinkedList.hpp"
#include <iomanip>


Node* DoublyLinkedList::FindNodeAt(int index)
{
    int i = 0;
    Node *itr = head;
    while(i < index && itr->next != NULL)
    {
        itr = itr->next;
        i++;
    }
    return itr;
}

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    size = 0;
}

bool DoublyLinkedList::isEmpty() const
{
    return size == 0;
}

void DoublyLinkedList::insert(const string data, int index)
{
    //if the index doesn't exist the data is inserted at the end
    if(index < 0 || index > size) 
    {
        insert(data, size);
        return;
    }
    if(isEmpty())
    {
        head = new Node(data);
    }
    else
    {
        Node *last = FindNodeAt(size - 1);
        last->next = new Node(last->data, NULL, last);
        
        Node *inserted = FindNodeAt(index);
        
        //this is the Shifiting Procedure
        //each node AFTER the provided index is shifted to the RIGHT 
        for(Node *itr = last->next; itr != inserted; itr = itr->prev)
        {
            itr->data = itr->prev->data;
        }
        //data inserted
        inserted->data = data;
    }
    size++;
}

void DoublyLinkedList::removeAt(int index)
{
    //if the index doesn't exist the last element is deleted
    if(index < 0 || index >= size) 
    {
        removeAt(size - 1);
        return;
    }

    //The node next to the node to be deleted
    Node *nextNode = FindNodeAt(index)->next;

    //this is the Shifting Procedure
    //each node AFTER the provided index is shifted to the LEFT 
    while(nextNode != NULL)
    {
        nextNode->prev->data = nextNode->data;
        nextNode = nextNode->next;
    }

    //the last node is modified
    Node *last = FindNodeAt(size - 1);
    if(last == head)
        head = NULL;  
    else
        last->prev->next = NULL;

    delete last;
    size--;
}

ostream &operator<<(ostream &screen, DoublyLinkedList &right)
{
    for(Node *itr = right.head; itr != NULL; itr = itr->next)
    {
        screen << itr->data;
        if(itr->next != NULL) screen << "  <-->  ";
    }   
    if(right.isEmpty())
        screen << "The list is empty!";
    
    return screen;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while(!isEmpty())
    {
        removeAt(0);
    }
}