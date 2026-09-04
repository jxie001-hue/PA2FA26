/*
 * Name        : Assignment 1
 * Author      : Johnny xie
 * Description : homework n stuff
 * Sources     : me :D
 */

#include "assignment_1.h"
#include <iostream>
#include <string>

using namespace std;

// Write Function Definitions Here (What goes below main)


//return true if parameter is ture alphabet, else return false
bool CheckAlphabetic(const string& Input){
    if (Input.length() == 0) return false;

    bool status = false;
    for (int x = 0; x<Input.length(); x++){
        //checks if current value is in range
        if ((Input[x] >= 'a' && Input[x] <= 'z' ) || (Input[x] >= 'A' && Input[x] <= 'Z')) status = true;
        else status = false;

        if (status == false) return false;
    }
    return true;
}

//caesar cipher shift whatever the fuck over by declear value, return true if string is pure alphabet, else do nothign return false
bool EncryptString(string& input, int ShiftValue){
    //check if it's pure character
    //set character to between 0-25
    ShiftValue %= 26;
    if (ShiftValue < 0) ShiftValue +=26;

    bool status = CheckAlphabetic(input);
    if (status == false) return false;

    //ceaser cither the character
    for(int x = 0; x<input.length(); x++){
        //use %26 to make value of alphabet start form 0-25
        if (input[x] >= 'a' && input[x] <= 'z' )input[x] = 'a' + (input[x] - 'a' + ShiftValue)%26;
        if (input[x] >= 'A' && input[x] <= 'Z' )input[x] = 'A' + (input[x] - 'A' + ShiftValue)%26;
        

    }
    return true;
}

bool DecryptString(string& input, int ShiftValue){
    //same shyt but just -

    //check if it's pure character
    //set character to between 0-25
    ShiftValue %= 26;
    if (ShiftValue < 0) ShiftValue +=26;

    bool status = CheckAlphabetic(input);
    if (status == false) return false;

    //ceaser cither the character
    for(int x = 0; x<input.length(); x++){
        //use %26 to make value of alphabet start form 0-25
        if (input[x] >= 'a' && input[x] <= 'z' )input[x] = 'a' + (input[x] - 'a' - ShiftValue + 26)%26;
        if (input[x] >= 'A' && input[x] <= 'Z' )input[x] = 'A' + (input[x] - 'A' - ShiftValue + 26)%26;
        

    }
    return true;


}

double ComputeAverage(double num[], unsigned int size){
    double total_value = 0;

    for (int x = 0; x< size; x++)total_value+=num[x];
    total_value /= size;
    return total_value;
}

double FindMinValue(double num[], unsigned int size){
    double smallestValue = num[0];

    for (int x = 1; x < size; x++){
        if (smallestValue >= num[x]) smallestValue = num[x];
    }

    return smallestValue;
}

double FindMaxValue(double num[], unsigned int size){
    double BiggestValue = num[0];

    for (int x = 1; x < size; x++){
        if (BiggestValue <= num[x]) BiggestValue = num[x];
    }

    return BiggestValue;
}