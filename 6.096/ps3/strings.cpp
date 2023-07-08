#include <iostream>
#include <string>
using namespace std;

const string vowels = "aeiou";

string pigLatinify(const string word) {
    if (word.find("qu") == 0) 
        return word.substr(2) + "-" + word.substr(0,2) + "ay";
    else if (vowels.find(word.front())!=string::npos)
        return word + "-way";
    else
        return word.substr(1) + "-" + word.substr(0,1) + "ay";
    
}

int main() {
    cout << pigLatinify("eva");
}
