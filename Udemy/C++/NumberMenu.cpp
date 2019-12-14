#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    char selection{};
    int addedNumber{};
    int total{};
    vector<int> storedNumbers;
    
    do {
        
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl << endl << "Enter your choice: ";
        cin >> selection;
        if (selection == 'p' || selection == 'P'){
            cout << "[ ";
            for (auto val: storedNumbers){
                cout << val << ", ";
            }
            cout << " ]";
            cout << endl;
        } else if (selection == 'a' || selection == 'A'){
            cout << "Enter an integer to add to the list: ";
            cin >> addedNumber;
            storedNumbers.push_back(addedNumber);
            cout << addedNumber << " added" << endl;
        } else if (selection == 'm' || selection == 'M'){
            if (storedNumbers.size() == 0){
                cout << "Unable to calculate --  no data";
            } else {
                for (auto numbers: storedNumbers) {
                    total += numbers;
                }
            cout << "The mean is : " << static_cast<double> (total)/storedNumbers.size() << endl;
            }
            
        } else if (selection == 'S' || selection == 's') {
            int smallest = storedNumbers.at(0);
            if (storedNumbers.size() == 0){
                cout << "Unable to calculate --  no data";
            } else {
                for (auto num: storedNumbers) {
                    if (num < smallest){
                        smallest = num;
                    }
                }
                cout << "The smallest number is: " << smallest << endl;
            }
        } else if (selection == 'l' || selection == 'L') {
            int largest = storedNumbers.at(0);
            if (storedNumbers.size() == 0){
                cout << "Unable to calculate --  no data";
            } else {
                for (auto num: storedNumbers) {
                    if (num > largest){
                        largest = num;
                    }
                }
                cout << "The largest number is: " << largest << endl;
            }
            
        } else if (selection == 'q' || selection == 'Q') {
            
        } else
            cout << "try again" << endl;
    
    } while (selection != 'q' && selection != 'Q');
    
    cout << endl;
    return 0;
}
