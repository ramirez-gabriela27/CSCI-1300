// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 8 - Problem # 1

#include <iostream>
#include <vector>

using namespace std;

/*
    combine two input vectors by alternating between values from each vector
    @param vec1 (int vecotr) - vector of integer values
    @param vec2 (int vecotr) - vector of integer values
    @return vecShuffled (int vecotr) - vector of integer values "shuffled"
*/
vector<int> shuffle(vector<int> vec1, vector<int> vec2){
    //create empty vector to fill
    vector<int> vecShuffled;
    // find the size of each vector and make them a variable
    int vec1Size = vec1.size();
    int vec2Size = vec2.size();

    // if the vectors are both empty, return an empty vector
    if(vec1Size == 0 && vec2Size == 0){
        // if they both have length 0, return empty vector
        return vecShuffled;
    }
    // if vec1 is bigger than vec2, fill in starting with vec1
    else if(vec1Size > vec2Size){
        int j = 0;
        for(int i = 0; i < vec1Size; i++){
            vecShuffled.push_back(vec1[i]);
            if(j < vec2Size){
                vecShuffled.push_back(vec2[j]);
                j++;
            }
        }
    }
    // if vec2 is bigger than vec1, fill in starting with vec1
    else if(vec2Size > vec1Size){
        int j = 0;
        for(int i = 0; i < vec2Size; i++){
            vecShuffled.push_back(vec2[i]);
            if(j < vec1Size){
                vecShuffled.push_back(vec1[j]);
                j++;
            }
        }
    }
    else{
        for(int i = 0; i < vec1Size; i++){
            vecShuffled.push_back(vec1[i]);
            vecShuffled.push_back(vec2[i]);
        }
    }
    return vecShuffled;
}

main(){
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // blank output
    vector<int> vecTest1;
    vector<int> vecTest2;
    vector<int> test1Output = shuffle(vecTest1,vecTest2);
    cout << "The vector reads: " << endl;
    for (int i=0; i < test1Output.size(); i++) {
        cout << test1Output[i] << " ";
    }

    cout << "================================" << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // 1 8 9 4
    vector<int> vecTest3{1,9};
    vector<int> vecTest4{8,4};
    vector<int> test2Output = shuffle(vecTest3,vecTest4);
    cout << "The vector reads: " << endl;
    for (int i=0; i < test2Output.size(); i++) {
        cout << test2Output[i] << " ";
    }

    return 0;
}
