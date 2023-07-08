#include <iostream>
#include <cmath>
using namespace std;
#include "geometry.h"


PointArray::PointArray() {
    points = new Point[0];
    size = 0;
}

PointArray::PointArray(const Point points[], const int size) {
    this->size = size;
    this->points = new Point[size];
    for (int i=0; i<size; i++) {
        this->points[i] = points[i];
    }
}

PointArray::PointArray(const PointArray& pv) {
    size = pv.size;
    points = new Point[size];
    for (int i=0; i<size; i++) {
        points[i] = pv.points[i];
    }
}

PointArray::~PointArray() {
    delete[] points;
}

void PointArray::resize(int n) {
    Point * pts = new Point[n];
    int min_size = (n > size) ? size : n;
    
    for (int i=0; i<min_size; i++) {
        pts[i] = points[i];
    }
    
    delete[] points;
    points = pts;
    size = n;
}

void PointArray::push_back(const Point &p) {
    resize(size+1);
    points[size-1] = p;
}

void PointArray::insert(const int position, const Point &p) {
    resize(size+1);
    
    for (int i=size-1;i>position;i--) {
        points[i] = points[i-1];
    }
    
    points[position] = p;
}

void PointArray::remove(const int position) {
    for (int i=position;i<size-1;i++) {
        points[i] = points[i+1];
    }
    
    resize(size-1);
}

const int PointArray::getSize() const {
    return size;
}

void PointArray::clear() {
    resize(0);
}

Point *PointArray::get(const int position) {
    return (position>=0 && position < size) ? points + position : NULL;
}

const Point *PointArray::get(const int position) const {
    return (position>=0 && position < size) ? points + position : NULL;
}

/*

const version for get returns a read-only point so that no modifications
can be made on the point (memory location).

*/

int Polygon::numPolygons = 0;

Polygon::Polygon(const Point points[], const int size) : points(PointArray(points, size)) {
    numPolygons++;
}

Polygon::Polygon(const PointArray &pointarr) : points(pointarr) {
    numPolygons++;
}

Polygon::~Polygon() {
    numPolygons--;
}

/* 

Since point array is defined in the heap, the default copy constructor will create a polygon
pointing to the same point array.

*/

Point constructorPoints [4];

Point * updateConstructorPoints(const Point & p1, const Point & p2,
        const Point & p3, const Point & p4 = Point(0 ,0)) {
    constructorPoints [0] = p1 ;
    constructorPoints [1] = p2 ;
    constructorPoints [2] = p3 ;
    constructorPoints [3] = p4 ;
    return constructorPoints ;
}

Rectangle::Rectangle(const Point &ll, const Point &ur) : Polygon(
    updateConstructorPoints(ll, Point(ll.getX(), ur.getY()), 
        ur, Point(ur.getX(), ll.getY())), 4) {
}

Rectangle::Rectangle(const int llx, const int lly, const int urx,
    const int ury) : Polygon(updateConstructorPoints(Point(llx, lly),
        Point (llx, ury), Point(urx, ury), Point(urx,lly)), 4) {
            
}

double Rectangle::area() const {
    int length = points.get(3)->getX() - points.get(0)->getX();
    int width = points.get(1)->getY() - points.get(0)->getY();
    return std::abs((double) length * width);
}

Triangle::Triangle(const Point &pt1, const Point &pt2, const Point &pt3) : Polygon(
    updateConstructorPoints(pt1, pt2, pt3), 3) {
}

double Triangle::area() const {
    int dx01, dx12, dx20;
    int dy01, dy12, dy20;
    
    dx01 = points.get(0)->getX() - points.get(1)->getX();
    dx12 = points.get(1)->getX() - points.get(2)->getX();
    dx20 = points.get(2)->getX() - points.get(0)->getX();
    
    dy01 = points.get(0)->getY() - points.get(1)->getY();
    dy12 = points.get(1)->getY() - points.get(2)->getY();
    dy20 = points.get(2)->getY() - points.get(0)->getY();
    
    double a = sqrt(dx01*dx01 + dy01*dy01),
    b = sqrt(dx12*dx12 + dy12*dy12),
    c = sqrt(dx20*dx20 + dy20*dy20);
           
    double s = (a+b+c)/2;
    return std::sqrt(s * (s-a) * (s-b) * (s-c));
}

/*

5.6 Questions

1. If Point constructor is private, we would not be able to create it.
    
2. When polygon object is destroyed, the static numPolygons is decremented, and
    the implicit constructor for PointArray is called deallocating the points.
    
3. Polygon fields need to be protected since it is an abstract class and should
    be accessed only from derived classes.

4. The getNumSides of Polygon will be called since it is not virtual (like area).

*/












