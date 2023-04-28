#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    for (int num=2;num<N;num++) {
        
        bool isPrime = true;
        
        for (int factor=2;factor<num;factor++)
            if (num%factor == 0) {
                isPrime = false;
                break;
            }
        
        if (isPrime) 
            cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}