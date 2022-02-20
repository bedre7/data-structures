#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include "AVL.hpp"

class FileReader
{
    private:
        int *lineArray;
        LineQueue *LineQueues;
        AVL *tree;
        
        void createQueue(LineQueue &, int *, int );
        int getArraySize(string );
        int getFileSize(string );
        void createTree(int );
    public: 
        void readFile(string );
        void printPostOrder();
        ~FileReader();          //!Both LineQueue array and tree are freed here
};

#endif