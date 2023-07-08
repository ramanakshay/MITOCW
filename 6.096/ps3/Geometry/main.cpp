
#include <iostream>
using namespace std;

#include "geometry.h"

void printAttributes(Polygon *p) {
    cout << "Area: " << p->area() << "\n";
    cout << "Points: ";
    
    const PointArray *pa = p->getPoints();
    int size = pa->getSize();
    
    for (int i=0; i<size; i++) {
        cout << "(" << pa->get(i)->getX() << "," << pa->get(i)->getY() << ")";
        if (i!=size-1)
            cout << ", ";
    }
    cout << "\n";
}

int main() {
    
    cout << "Rectangle: " << "\n\n";
    
    int x,y;
    cout << "Enter lower left coordinates:\n";
    cin >> x >> y;
    Point ll = Point(x,y);
    
    cout << "Enter upper right coordinates:\n";
    cin >> x >> y;
    Point ur = Point(x,y);
    
    Rectangle rect = Rectangle(ll, ur);
    printAttributes(&rect);
    
    cout << "\n";
    
    cout << "Triangle: " << "\n\n";
    
    cout << "Enter Point 1 coordinates:\n";
    cin >> x >> y;
    Point pt1 = Point(x,y);
    
    cout << "Enter Point 2 coordinates:\n";
    cin >> x >> y;
    Point pt2 = Point(x,y);
    
    cout << "Enter Point 3 coordinates:\n";
    cin >> x >> y;
    Point pt3 = Point(x,y);
    
    Triangle tri = Triangle(pt1, pt2, pt3);
    printAttributes(&tri);
    return 0;
}
