#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

double estimate_pi(const int n) {
    int dartsInside = 0;
    for(int i=0;i<n;i++) {
        double x = rand() / (double) RAND_MAX, y = rand() / (double) RAND_MAX;
        double distance = sqrt(x*x+y*y);
        if (distance < 1)
            dartsInside += 1;
    }
    
    double pi = 4.0 * count / n;
    return pi;
}

int main()
{
    srand(time(0));
    cout << estimate_pi(5000000);
    return 0;
}
