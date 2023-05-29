#include <iostream>

using namespace std;

int get_length(char *str) {
    char * character = str;
    int length = 0;
    while (*(character+length) != '\0')
        length++;
        
    return length;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    char word[] = "hello, world!";
    cout << get_length(word) << "\n";
    
    int a=5,b=2;
    cout << a << " " << b << "\n";
    swap(&a,&b);
    cout << a << " " << b << "\n";
    
    int x=5,y=6;
    cout << x << " " << y << "\n";
    int *ptr1 = &x, *ptr2 = &y;
    swap(&ptr1,&ptr2);
    cout << *ptr1 << " " << *ptr2 << "\n\n\n";
    
    
    char *oddOrEven = "Never odd or even";
    char *nthCharPtr = &oddOrEven[5];
    nthCharPtr -= 2;
    cout << *nthCharPtr << "\n";
    char **pointerPtr = &nthCharPtr;
    cout << pointerPtr << "\n";
    cout << **pointerPtr << "\n";
    nthCharPtr++;
    cout << nthCharPtr - oddOrEven << "\n";
    
    
}

