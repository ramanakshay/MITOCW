#include <iostream>

using namespace std;

void printArray(const int arr[], const int n) {
    for (int i=0;i<n-1;i++)
        cout << arr[i] << ", ";
    cout << arr[n-1];
}

void reverse(int arr[], const int n) {
    for (int i=0;i<n/2;i++) {
        int temp = arr[n-i-1];
        arr[n-i-1] = arr[i];
        arr[i] = temp;
    }
}

void reverse(int arr[], const int n) {
    for (int i=0;i<n/2;i++) {
        int temp = *(arr + n-i-1);
        *(arr + n-i-1); = *(arr + i);
        *(arr + i) = temp;
    }
}

void transpose(ocnst int input[][LENGTH], int output[][WIDTH]) {
    for (int i=0;i<WIDTH;i++)
        for(int j=0;j<LENGTH;j++)
            output[i][j] = input[j][i];
}

/*
Returns an invalid pointer since the memory is deallocated 
when the function returns.
*/

int main()
{
    int arr[4] = {1,2,3,4};
    reverse(arr,4);
    printArray(arr,4);
}
