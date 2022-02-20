#ifndef AVLNODE_HPP
#define AVLNODE_HPP
#include "LineQueue.hpp"

class AVLNode
{
    public:
        LineQueue data;
        int length;
        AVLNode *left;
        AVLNode *right;
        AVLNode(const LineQueue &data, AVLNode *left = NULL, AVLNode *right = NULL);
};

#endif