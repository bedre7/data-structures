#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Node.hpp"

class DoublyLinkedList
{
private:
    Node *head;    
    int size;

    Node* FindNodeAt(int ); 
public:
    DoublyLinkedList();
    bool isEmpty() const;

    void insert(const string , int );
    void removeAt(int );
    friend ostream &operator<<(ostream &, DoublyLinkedList &);

    ~DoublyLinkedList();
};

#endif