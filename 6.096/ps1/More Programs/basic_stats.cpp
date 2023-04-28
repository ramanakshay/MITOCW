#include <iostream>
using namespace std;

int main() {
    int N;
    int max,min,range;
    double mean = 0;
    
    cin>>N;
    
    int value;
    cin >> value;
    
    // handle first value seperately
    mean += value;
    max = value;
    min = value;
    

    for (int i=0;i<N-1;i++) {
        cin >> value;
        
        mean += value;
        
        if (value > max)
            max = value;
            
        if (value < min)
            min = value;
    }
    
    mean /= N;
    range = max - min;
    
    cout << "Mean:" << mean << "\n";
    cout << "Max:" << max << "\n";
    cout << "Min:" << min << "\n";
    cout << "Range:" << range << "\n";
}