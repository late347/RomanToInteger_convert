#pragma once
#include <string>
#include <stack>
#include <deque>
#include <climits>
class RomanConverter
{

public:

	/*
	Symbol       Value
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000
	
	
	
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

	

	
	IV				4
	V
	IX				9
	X
	XL				40
	L				50
	XC				90
	C				100
	CD				400
	D				500
	CM				900
	M				1000

	Constraints:
	input == string s
	1 <= s.length <= 15
	s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
	It is guaranteed that s is a valid roman numeral in the range [1, 3999].

	I				1
	II				2
	III				3
	IV				4
	V				5
	VI				6
	VII				7
	VIII			8
	IX				9
	X				10
	XI				11
	XII				12
	XIII			13
	XIV				14
	XV				15
	XVI				16
	XVII			17
	XVIII			18
	XIX				19
	XX				20

	*/
	RomanConverter() = default;

	
	// gets the integer value from properly formatted roman value string
	int romanToInt(std::string s) 
	{
		int romanSum = 0;
		
		// special case can be done with switch case
		if (s.size() == 1)
		{
			return (oneSizeRomans(s[0]));
		}

		std::stack<int> thestack;

		// intiialize stack to 1 element == 0
		// to help in calculations
		// so that the first stack.top() returns 0
		thestack.push(0);

		// iterate in reverse thru romanchars
		// get current value of char
		// curchar
		//		'i'
		//		if the nextchar is biggerorsame in value to curchar add that value and advance
		//		if the nextchar is smaller and defined, subtract that value and advance
		//
		//		can use a stack to push the curchar into stack and that way you know latest addedValue to romanSum
		int nextVal = 0;
		int i = s.length() -1;
		while (i >= 0)
		{
			char current = s[i];
			int curVal = oneSizeRomans(current);
			// compoare stack top to currrent and decide
			int stacked = thestack.top();
			if (curVal >= stacked )
			{
				romanSum += curVal;
			}
			else
			{
				romanSum -= curVal;
			}

			thestack.push(curVal);
			i--;
		}
		
		return romanSum;
	}


	int fasterRomanToInt(std::string s)
	{
		int romanSum{ 0 };
		if (s.size() == 1)
		{
			return oneSizeRomans(s[0]);
		}
		else
		{
			int oldval = 0;
			int i = s.length() - 1;
			while (i >= 0)
			{
				char current = s[i];
				int curval = oneSizeRomans(current);
				if (curval >= oldval)
				{
					romanSum += curval;
				}
				else
				{
					romanSum -= curval;
				}
				oldval = curval;
				--i;
			}
			return romanSum;
		}
	}
private:
	
	int oneSizeRomans(char c)
	{
/*	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000*/
		switch (c)
		{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;

		default:
			break;
		}
	}

	
};

