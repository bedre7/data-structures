#ifndef AVL_HPP
#define AVL_HPP
#include "AVLNode.hpp"

class AVL
{
    private:    
        AVLNode *root;
        AVLNode* add(AVLNode* , const LineQueue &);
        int Height(AVLNode* );
        bool isBalanced(AVLNode *);
        AVLNode* RotateRight(AVLNode *);
        AVLNode* RotateLeft(AVLNode *);
        void postorder(AVLNode *);
        void DeleteNodes(AVLNode *&);

    public:
        AVL();
        void add(const LineQueue &);
        int Height();
        void postorder();
        bool isEmpty();
        ~AVL(); 
};
#endif