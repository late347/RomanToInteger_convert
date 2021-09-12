// RomanToInteger_convert.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RomanConverter.h"


int main()
{
    using namespace std;


    RomanConverter rc;
    auto res0 = rc.fasterRomanToInt("XIV");
    const int e0 = 14;

    auto res1 = rc.fasterRomanToInt("X");
    const int e1 = 10;


    auto res2 = rc.fasterRomanToInt("XXIV");
    const int e2 = 24;

    cout << "Hello World, welcome to Roman converter to INT !\n";
    cout << "result was == " << res0 << " , expected == " << e0 << endl;
    cout << "result was == " << res1 << " , expected == " << e1 << endl;
    cout << "result was == " << res2 << " , expected == " << e2 << endl;


    auto newres0 = rc.intToRoman(1994);
    auto newe0 = "MCMXCIV";

    cout << " result was == " << newres0 << " expected == " << newe0 << endl;
}
