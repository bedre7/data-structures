#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>

using namespace std;
class Node
{
public:
    string data;
    Node *next;
    Node *prev;

    Node(const string&, Node *nx = NULL, Node *prv = NULL);
    
};
#endif