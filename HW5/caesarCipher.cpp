// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 5 - Problem # 4

#include <iostream>
#include <string>
using namespace std;

/*
    encrypt and decrypt a message input by the user using caesar cipher (with input key)
    @param message(string), key(int), falg(bool) - All are determined by user (were flag == true means encrypt and flag == false means decrypt)
    @return resultingString(string) - the message after it has been encrypted/decrypted
*/
string caesarCipher (string message, int key, bool flag){
    if (key < 0 || key > 25){
        return "ERROR";
    }

    char letterTest;
    string newLetter;
    string resultingString;

    // true encrypting
    if (flag == true){
        for (int i = 0; i < message.length(); i++){
            //enrypt using the ASCII values
            letterTest = int(message[i]);
            if (letterTest >= 65 && letterTest <= 90){
                newLetter = ((message[i]-65)+ key) %26 + 65;
            }
            else{
                newLetter = letterTest;
            }
            resultingString += newLetter;
        }
        return resultingString;
    }

    // false decrypting
    else if (flag == false){
        for (int i = 0; i < message.length(); i++){
            //decrypt using the ASCII values
            letterTest = int(message[i]);
            if (letterTest >= 65 && letterTest <= 90){
                newLetter = ((message[i]+65)-key) %26 + 65;
            }
            else{
                newLetter = letterTest;
            }
            resultingString += newLetter;
        }
        return resultingString;
    }
}

int main() {
    string message;
    int key;
    bool flag;
    string cryptKind;

    cout << "Please enter the sentence you want to encrypt/decrypt: " << endl;
    getline(cin,message);

    cout << "Please enter the key you want to encrypting/decrypt by: " << endl;
    cin >> key;

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

    string resultingString = caesarCipher(message,key,flag);

    cout << resultingString << endl;

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // JGNNQ
    resultingString = caesarCipher("HELLO",2,true);
    cout << resultingString << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // HELLO
    resultingString = caesarCipher("JGNNQ",2,false);
    cout << resultingString << endl;
    return 0;
}
