#include "Point.hpp"
#include <cmath>
using namespace std;

namespace ariel
{
    Point::Point()
    {
        this->x_p = 0.0;
        this->y_p = 0.0;
    }
    Point::Point(double x_p, double y_p)
    {
        this->x_p = x_p;
        this->y_p = y_p;
    }

    double Point::distance(const Point &other)
    {
        double x = pow((other.x_p-this->x_p),2);
        double y = pow((other.y_p-this->y_p),2);
        return sqrt(x+y);
    }

    string Point::print()
    {
        return "(" + to_string(x_p) + "," + to_string(y_p) + ")";
    }

    Point Point::moveTowards(const Point &src, const Point &dst, double dis)
    {
        double distance = std::sqrt(std::pow(dst.x_p - src.x_p, 2) + std::pow(dst.y_p - src.y_p, 2));

        if (distance <= dis)
        {
            return dst;
        }
        double ratio = dis / distance;
        double newX = src.x_p + (dst.x_p - src.x_p) * ratio;
        double newY = src.y_p + (dst.y_p - src.y_p) * ratio;

        return Point(newX, newY);
    }

}