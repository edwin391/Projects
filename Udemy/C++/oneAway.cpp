//
//  oneAway.cpp
//  
//
//  Created by Edwin Melendez on 11/1/19.
//

#include <iostream>
#include <string>
using namespace std;

bool oneAway(string s1, string s2);

int main(){
    oneAway("pale", "ple")? cout << "true": cout << "false";
    cout << endl;
    oneAway("pales", "pale")? cout << "true": cout << "false";
    cout << endl;
    oneAway("pale", "bale")? cout << "true": cout << "false";
    cout << endl;
    oneAway("pale", "bake")? cout << "true": cout << "false";
    cout << endl;
    return 0;
}

bool oneAway(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    if (abs(m-n) > 1)
        return false;
    int count = 0;
    int i = 0, j = 0;
    while (i<m && j<n)
    {
        if (s1[i] != s2[j]){
            if (count == 1)
                return false;
            if (m > n)
                i++;
            else if(m < n)
                j++;
            else {
                i++;
                j++;
            }
            count++;
        }
        else {
            i++;
            j++;
        }
    }
    if (i < m || j < n)
        count++;
    return count == 1;
}
