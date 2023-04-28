#include <iostream>
using namespace std;

int main()
{
    while (true) {
        int N;
        cin >> N;
        
        if (N>=0 && N%5==0)
            cout << N/5 << "\n";
        else if (N>=0)
            continue;
        else
            break;
    }
    cout << "Goodbye!\n";
    return 0;
}
