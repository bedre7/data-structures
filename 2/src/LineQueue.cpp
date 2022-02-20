/** 
* @file         LineQueue.cpp
* @description  contains the implemetation of the queue class
                distance calculation function is included as well
* @course       Data Structures 1B
* @assignment   2. Odev
* @date         23/12/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/

#include "LineQueue.hpp"

LineQueue::LineQueue()
{
    front = back = NULL;
    lineLength = size = 0;
}
int LineQueue::FindDistanceBetween(Point a, Point b)
{
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2) + pow(a.Z - b.Z, 2));
}
//Extends the line's length when a new point is added
void LineQueue::ExtendLine(const Point &newPoint)
{
    lineLength += FindDistanceBetween(lastPoint, newPoint);            
}
const int LineQueue::getLength() const
{
    return lineLength;
}
bool LineQueue::isEmpty() const
{
    return size == 0;
}
//This adds Points(Nokta) in a SORTED ORDER
void LineQueue::enqueueInOrder(const Point &newPoint)
{
    Node *newPointNode = new Node(newPoint);
    
    if(isEmpty())
        front = back = newPointNode;
    else
    {
        ExtendLine(newPoint);               //the total length is extended before adding
        Node *tmp = front;

        if(front->point > newPoint)         //if the point is smaller than the front point
        {
            newPointNode->next = front;
            front = newPointNode;
        }
        else
        {                               
            while(tmp->next != NULL)            //this goes until the LARGEST point distance is found
            {
                if(tmp->next->point > newPoint)
                    break;
                tmp = tmp->next;
            }

            newPointNode->next = tmp->next;
            tmp->next = newPointNode;
            
            if(tmp == back) 
                back = newPointNode;
        }
    }
    lastPoint = newPointNode->point;                 //the point that was added at the last time is saved
    size++;
}
//This returns a Point(Nokta) from the front pointer
Point LineQueue::peek() const
{
    return front->point;
}
void LineQueue::dequeue()
{
    if(isEmpty()) return;
    Node *tmp = front;
    if(front == back) back = NULL;
    front = front->next;
    delete tmp;
    size--;
}
//This prints out the LineQueue easily since it is already SORTED
void LineQueue::printQueue()
{
    Node *tmp = front;
    while(tmp != NULL)
    {
        cout << tmp->point.distanceToOrigin << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void LineQueue::clear()
{
    while(isEmpty())
    {
        dequeue();
    }
}
LineQueue::~LineQueue()
{
   clear();
}