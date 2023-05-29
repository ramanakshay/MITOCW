#include <iostream>
using namespace std;

int sum(const int a, const int b) {
    return a + b;
}

double sum(const double a, const double b) {
    return a + b;
}

int sum(const int a, const int b, const int c) {
    return a + b + c;
}

int sum(const int a, const int b, const int c, const int d) {
    return a + b + c + d;
}

int sum(const int a, const int b, const int c = 0, const int d = 0) {
    return a + b + c + d;
}

int sum(const int arr[], int n) {
    int total = 0;
    for (int i=0;i<n;i++)
        total += arr[i];
    return total;
}

int sum(const int arr[], int n) {
    if (n==0)
        return 0;
    else
        return arr[n-1] + sum(arr,n-1);
}

int main()
{
    cout << sum(3.5,5.0) << "\n";
    
    sum(1,10.0);
    /*
    a is an integer and b is a double. The compiler doesn't know which
    input to promote/demote.
    */
    
    cout << sum(3,5,7);
    /*
    An error is thrown since the compiler cannot choice between the functions.
    */
    
    int arr[6] = {1,2,3,4,5,6};
    cout << sum(arr,6);
    
    return 0;
}