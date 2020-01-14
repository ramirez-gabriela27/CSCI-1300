// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 5 - Problem # 5

#include <iostream>
#include <string>
using namespace std;

/*
    encrypt and decrypt a message input by the user using vigenere cipher (with input key)
    @param message(string), key(string), falg(bool) - All are determined by user (were flag == true means encrypt and flag == false means decrypt)
    @return resultingString(string) - the message after it has been encrypted/decrypted
*/
string vigenereCipher (string message, string key, bool falg){
    char letterTest;
    string newLetter;
    string resultingString;

    //between 65 and 90

    //encrypting
    // newLetter = ((message[i]-65)+ keyNew) %26 + 65;


    // decrypt
    // newLetter = ((message[i]+65)-keyNew) %26 + 65;

    return "Sorry, I can't figure this out ):";
}

int main(){
    string message;
    string key;
    bool flag;
    string cryptKind;

    cout << "Please enter the sentence you want to encrypt/decrypt: " << endl;
    getline(cin,message);

    cout << "Please enter the key you want to encrypting/decrypt by: " << endl;
    getline(cin,key);

    cout << "Do you want to encrypt or decrypt? (E or D) " << endl;
    cin >> cryptKind;

    //true encrypting
    //false decrypting
    if (cryptKind == "e" || cryptKind == "E"){
        flag = true;
    }
    else if(cryptKind == "d" || cryptKind == "D"){
        flag = false;
    }
    else{
        cout << "Invalid input. Please try again" << endl;
        cin >> cryptKind;
    }

    string resultingString = vigenereCipher(message,key,flag);

    cout << resultingString << endl;

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // UIZQRG
    resultingString = vigenereCipher("BATMAN","TIGER",true);
    cout << resultingString << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // UNICORNS
    resultingString = vigenereCipher("NVOGFKVY","TIGER",false);
    cout << resultingString << endl;

    return 0;
}
