
#include <iostream>
using namespace std;
int main() {
    short number;
    cout << "Enter a number: "; cin >> number;
    
    if (number < 0) {
        cout << "Number is negative.\n";
        return 1;
    }
    
    cout << "The factorial of " << number << " is "; 
    
    long long accumulator = 1;
    for(; number > 0; accumulator *= number--);
    
    cout << accumulator << ".\n";
        
    return 0;
}