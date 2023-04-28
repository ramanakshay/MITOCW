#include <iostream>
using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        cout << ((N>=0 && N%5==0) ? N/5 : -1) << "\n";
    }
    
    return 0;
}