//
//  isUnique.cpp
//  1.1 cracking the coding
//
//  Created by Edwin Melendez on 10/31/19.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool uniqueString(string s);

int main() {
    string s1 = "GeeksforGeeks";
    string s2 = "abc";
    if(uniqueString(s1)) {
        cout << "The string " << s1 << " has all unique characters\n";
    }
    else {
        cout << "The String " << s1 << " has duplicate characters\n";
    }
    
    return 0;
}

bool uniqueString(string s){
    for (int i = 0; i < s.length() - 1; i++){
        for (int j = i + 1; j< s.length(); j++) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}
