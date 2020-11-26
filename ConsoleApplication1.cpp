
#include <iostream>
#include <fstream>
#include "ConsoleApplication1.h"
using namespace std;

int main()
{
    
    int maxBufferSize = 10000;
    int sSize = 0;
    int inputSize = 0;
    int timesToIterate = 0;
    string inp = "Hi";
    char s[1000] = { '\0' };
    char* input = new char[maxBufferSize]{ '\0' };
    ofstream writeTo("Resulted.txt", ios::out);  
    cout << "enter a word" <<  endl;    
    cin >> s;  
    for (int i = 0; i < maxBufferSize; i++) {
        ++sSize;
        if (s[i] == '\0') {
            s[i] = ' ';
            break;
        }
    }
    cout << "number of occurance in the middle(widest) string" << endl;
    cin >> timesToIterate;
    for (int i = 0; i < timesToIterate*2-1; i++) {
        if (i < timesToIterate) {
            inp = strcat_s(input, maxBufferSize, s);
            inp = input;
            writeTo << inp << endl;
            inputSize = sSize*(i+1);
        }
        if (i >= timesToIterate) {
            inputSize -= sSize;
            inp.erase(inputSize - sSize + 1, sSize);
            writeTo << inp << endl;
        }
        cout << inp << endl;
    }
    cout << "see results in Resulted.txt" << endl;
}