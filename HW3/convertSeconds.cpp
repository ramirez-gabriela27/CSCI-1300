// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 3 - Problem # 7

#include <iostream>
using namespace std;

/*
    Convert input seconds to hour(s), minute(s), and second(s)
    @param seconds (int) - input seconds
    @return N/A
*/
void convertSeconds (int seconds)
{
    int h = 0;
    int m = 0;
    int s = 0;
    while (seconds >= 3600)
    {
        seconds -= 3600;
        h += 1;
    }
    while (seconds >= 60)
    {
        seconds -= 60;
        m += 1;
    }
    while (seconds > 0)
    {
        seconds -= 1;
        s += 1;
    }

    cout << h <<" hour(s) " << m << " minute(s) " << s << " second(s)" << endl;
}

main()
{
    //seconds is initialized and set to the user input
    int seconds;
    cout << "Please input the amount of seconds : " << endl;
    cin >> seconds;
    //call convertSecnods function and use seconds as param
    convertSeconds (seconds);

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // 1 hour(s) 0 minute(s) 0 second(s)
    convertSeconds(3600);

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // 18 hour(s) 12 minute(s) 16 second(s)
    convertSeconds(65536);
    return 0;
}
