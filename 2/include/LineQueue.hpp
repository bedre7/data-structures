#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP

#include "Node.hpp"
#include <iostream>
using namespace std;

class LineQueue
{
    private:
        Node *front;
        Node *back;
        Point lastPoint;
        int size;
        int lineLength;
        
        int FindDistanceBetween(Point , Point );
        void ExtendLine(const Point &);
    public:
        LineQueue();
        const int getLength() const;
        bool isEmpty() const;
        void enqueueInOrder(const Point &);
        Point peek() const;
        void dequeue();
        void printQueue();
        void clear();
        ~LineQueue();
};
#endif
