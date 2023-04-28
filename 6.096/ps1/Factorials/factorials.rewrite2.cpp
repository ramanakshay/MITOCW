
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
    
    switch (number)
    {
        case 0:
        case 1:
            cout << "1\n" ;
            break ;
        case 2:
            cout << "2\n" ;
            break ;
        case 3:
            cout << "6\n" ;
            break ;
        case 4:
            cout << "24\n" ;
            break ;
        case 5:
            cout << "120\n" ;
            break ;
        case 6:
            cout << "720\n" ;
            break ;
        case 7:
            cout << "5040\n";
            break ;
        case 8:
            cout << "40320\n" ;
            break ;
        case 9:
            cout << "362880\n" ;
            break ;
        case 10:
            cout << "3628800\n" ;
            break ;
        default :
            cout << "Input not supported !\n" ;
            break ;
    }
    
    return 0;
}
    
