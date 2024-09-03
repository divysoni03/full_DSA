#include<iostream>
using namespace std;

int main() {
    int count = 0;
    string str = "Hello, World!!";
    string word = "";
    for(int i =0; i<str.length();i++) {
        for(int j=32;j<=126; j++) {
            cout << word << (char)j << endl;
            if((char)j == str[count]) {
                word += (char)j;
                count++;
                break;
                cout << endl;
            }
        }
    }
    return 0;
}