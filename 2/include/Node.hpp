#ifndef NODE_HPP
#define NODE_HPP
#include <cstddef>
#include "Point.hpp"

class Node
{
    public:
        Point point;
        Node *next;
        Node(const Point &point, Node *next = NULL);
};

#endif