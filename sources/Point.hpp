#pragma once
#include <string>
using namespace std;

namespace ariel
{
    class Point
    {
        double x_p;
        double y_p;

    public:
        Point();
        Point(double x_p, double y_p);       // constructor
        double distance(const Point &other); // calcute the distance between two points
        string print();                      // prints (x,y)
        static Point moveTowards(const Point &src, const Point &dst, double dis);
        double getX(); // returns x_p
        double getY(); // return y_p
    };

}