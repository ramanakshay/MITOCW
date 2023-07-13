#include <iostream>

#define min(a,b) ((a < b) ? a : b)

template <typename T>
T min(const T a, const T b) {
    return (a < b) ? a : b;
    
}

int main()
{
    std::cout << min(8.5,4.9);

    return 0;
}