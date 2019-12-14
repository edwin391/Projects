#include <iostream>
#include <string>

using namespace std;

int main() {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string secretMessage{};
    string encryptedMessage{};
    cout << "Enter your secret message: ";
    getline(cin, secretMessage);
    cout << "\nEncrypting message..." << endl;
    for(char c: secretMessage) {
        size_t position = alphabet.find(c);
        if(position != string::npos) {
            char newChar {key.at(position)};
            encryptedMessage += newChar;
        }else {
            encryptedMessage += c;
        }
    }
    cout << "\nEncrypted message: " << encryptedMessage << endl;
    string decryptedMessage{};
    cout << "\nDecrypting message..." << endl;
    for (char c: encryptedMessage) {
        size_t position = key.find(c);
        if(position != string::npos) {
            char newChar {alphabet.at(position)};
            decryptedMessage += newChar;
        }else {
            decryptedMessage += c;
        }
    }
    cout << "\nDecrypted message: " << decryptedMessage << endl;
    
    cout << endl;
    return 0;
}
