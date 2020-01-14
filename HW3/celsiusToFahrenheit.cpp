// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 3 - Problem # 9

#include <iostream>
#include <iomanip>
using namespace std;

/*
    Conver input Celsius degrees to Fahrenheit
    @param celsius (int) - input degrees in celsius
    @return N/A
*/
void celsiusToFahrenheit (int celsius)
{
    double fahrenheit;
    fahrenheit = ((9.0/5.0) * celsius) + 32;
    cout << "The temperature of " << celsius << " in Fahrenheit is " << fixed << setprecision(2) << fahrenheit << endl;
}

int main()
{
    //ceslsius is initialized and set to user input
    int celsius;
    cout << "Enter a temperature in Celsius: " << endl;
    cin>> celsius;
    // celsiusToFahrenheit function is called and uses celsius as a param
    celsiusToFahrenheit(celsius);

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // The temperature of 12 in Fahrenheit is 53.60
    celsiusToFahrenheit(12);

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // The temperature of 54 in Fahrenheit is 129.20
    celsiusToFahrenheit(54);
    return 0;
}
