#include <iostream>
using namespace std;

int main()
{
    const char * greeting = "Hello, World!";
    int n;
    
    cin >> n;
    
    // for loop
    for (int i=0;i<n;i++)
        cout << greeting << endl;
    cout << endl;
    
    // while loop
    int i = 0;
    while (i<n) {
        cout << greeting << endl;
        i++;
    }
    cout << endl;
    
    // do-while loop
    i = 0;
    do {
        cout << greeting << endl;
        i++;
    } while (i<n);
    cout << endl;

    
    return 0;
}
