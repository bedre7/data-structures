/** 
* @file         Point.cpp
* @description  Contains Point classes methods
                a function that calculates the points distance to origin is included
                ">" operator is overloaded
* @course       Data Structures 1B
* @assignment   2. Odev
* @date         23/12/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/
#include "Point.hpp"

Point::Point(int X, int Y, int Z)
{
    this->X = X;
    this->Y = Y;
    this->Z = Z;
    distanceToOrigin = FindDistance();
}
//This finds out the distance between the point and origin
int Point::FindDistance()
{
    return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
}
//This is used when comparing two points
bool Point::operator > (const Point &right)
{
    return this->distanceToOrigin > right.distanceToOrigin;
}