#include <iostream>

using namespace std;

int main() {
    
    const int smallRoomCost {25};
    const int largeRoomCost {35};
    const double salesTax {.06};
    const int valid {30};
    int smallRoomsCleaned {0};
    int largeRoomsCleaned {0};
    double subtotal;
    double total;
    
    cout << "How many small rooms would you like cleaned?";
    cin >> smallRoomsCleaned;
    cout << "How many large rooms would you like cleaned?";
    cin >> largeRoomsCleaned;
    
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << smallRoomsCleaned << endl;
    cout << "Number of large rooms: " << largeRoomsCleaned << endl;
    cout << "price per small room: $" << smallRoomCost << endl;
    cout << "price per large room: $" << largeRoomCost << endl;
    subtotal = (smallRoomCost * smallRoomsCleaned) + (largeRoomCost * largeRoomsCleaned);
    total = (subtotal * salesTax) + subtotal;
    cout << "cost : $" << subtotal << endl;
    cout << "Tax: $" << salesTax << endl;
    cout << "====================" << endl;
    cout << "Total estimate: $" << total << endl;
    cout << "This estimate is valid for " << valid << " days" << endl;
    
}
