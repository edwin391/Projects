//
//  checkPermutation.cpp
//  1.2 cracking the coding
//
//  Created by Edwin Melendez on 10/31/19.
//

#include <iostream>
#include <string>
using namespace std;

bool isPermutation(string s1, string s2);

int main(){
    string s1 = "test";
    string s2 = "ttes";
    if(isPermutation(s1,s2))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}

bool isPermutation(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    if(n1 != n2)
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(int i = 0; i < n1; i++){
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}
