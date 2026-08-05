#include<iostream>
using namespace std;

int main(){

    string str1 = "Hello";
    string str2 = "World";

    // Concatenation
    string str3 = str1 + " " + str2;
    cout << "Concatenated String: " << str3 << endl;

    // Length of the string
    cout << "Length of str3: " << str3.length() << endl;

    // Accessing characters
    cout << "First character of str3: " << str3[0] << endl;

    // Substring
    string subStr = str3.substr(6, 5); // Extracts "World"
    cout << "Substring: " << subStr << endl;

    // Finding a substring
    size_t found = str3.find("World");
    if (found != string::npos)
        cout << "'World' found at index: " << found << endl;
    else
        cout << "'World' not found" << endl;

    return 0;
}