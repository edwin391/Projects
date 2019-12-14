//
//  URLify.cpp
//  
//
//  Created by Edwin Melendez on 10/31/19.
//

#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000;

int replaceSpaces(char s[]);

int main(){
    char s[MAX] = "Mr John Smith    ";
    int newLength = replaceSpaces(s);
    for(int i=0; i<newLength; i++)
        cout << s[i];
    cout << endl;
    return 0;
}

int replaceSpaces(char s[]){
    int n=0;
    int i;
    for(i = 0; s[i]; i++){
        if(s[i] == ' '){
            n++;
        }
    }
    while (s[i-1] == ' '){
        n--;
        i--;
    }
    int newLength = i + n * 2 + 1;
    if(newLength > MAX)
        return -1;
    int index = newLength - 1;
    s[index--] = '\0';
    for (int j = i-1; j>=0; j--){
        if(s[j] == ' '){
            s[index] = '0';
            s[index - 1] = '2';
            s[index - 2] = '%';
            index = index - 3;
        }
        else{
            s[index] = s[j];
            index--;
        }
    }
    return newLength;
}
