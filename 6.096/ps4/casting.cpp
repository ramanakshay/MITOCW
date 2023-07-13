#include <iostream>
#include "geometry.h"

int main()
{
    Rectangle *rect;
    
    //3.1
    Triangle *triangle = reinterpret_cast<Triangle *>(rect)
    Triangle *triangle = static_cast<Triangle *>(rect) // make a copy
    
    // 3.2
    Triangle *triangle = dynamic_cast<Triangle *>(rect);
    
    return 0;
}