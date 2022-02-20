#ifndef POINT_HPP
#define POINT_HPP
#include <cmath>        //for sqrt and pow functions

class Point
{
    private:
        int X;
        int Y;
        int Z;
        int distanceToOrigin;
        
        friend class LineQueue;   //To let LineQueue class access private members of point
        int FindDistance();
    public:
        Point(int X = 0, int Y = 0, int Z = 0);
        bool operator > (const Point &right);
};

#endif