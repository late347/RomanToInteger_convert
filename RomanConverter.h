#pragma once
#include <string>
#include <stack>
#include <deque>
#include <climits>
#include <map>
#include <string>
#include <unordered_map>

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

	std::string intToRoman(int num)
	{
		std::map<int, std::string> ArabicvalueToRomans
		{
			{1000, "M"},
			{900, "CM"},
			{500, "D"},
			{400, "CD"},
			{100, "C"},
			{90, "XC"},
			{50, "L"},
			{40, "XL"},
			{10, "X"},
			{9, "IX"},
			{8, "VIII"},
			{7, "VII"},
			{6, "VI"},
			{5, "V"},
			{4, "IV"},
			{3, "III"},
			{2, "II"},
			{1, "I"}
		};

		std::vector<int> romanSpecials{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 8,7,6,5,4,3,2,1 };

		int arabic = num;
		std::string result = "";
		while (arabic > 0)
		{
			int d = seekLargestPossible(romanSpecials, arabic);
			int r = arabic % d;
			std::string characters = processToRoman(d, ArabicvalueToRomans);
			arabic -= d;
			result += characters;
		}
		return result;
	}


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
		int i = s.length() - 1;
		while (i >= 0)
		{
			char current = s[i];
			int curVal = oneSizeRomans(current);
			// compoare stack top to currrent and decide
			int stacked = thestack.top();
			if (curVal >= stacked)
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

	int seekLargestPossible(std::map<int, std::string>& mapRef, int a)
	{

		// input bigger than biggest divisor so use 1000
		if (a >= 1000)
		{
			return 1000;
		}

		//// find exact divisor match
		//auto exact = mapRef.find(a);
		//if (exact != mapRef.end())
		//{
		//	return exact->first;
		//}


		// seek the biggest divisor that is smallerorequal than the A inputvalue
		// iterate in reversed because keys were sorted ascending in regular map
		for (auto iter = mapRef.rbegin(); iter != mapRef.rend(); iter++)
		{
			int key = iter->first;
			if (key <= a)
			{
				return key;
			}
		}
		throw "something went bad in seekLargestPossible";
	}

	int seekLargestPossible(std::vector<int>& vecRef, int a)
	{

		// input bigger than biggest divisor so use 1000
		if (a >= 1000)
		{
			return 1000;
		}



		// seek the biggest divisor that is smallerorequal than the A inputvalue
		// iterate in reversed because keys were sorted ascending in regular map
		for (auto iter = vecRef.begin(); iter != vecRef.end(); iter++)
		{
			auto key = *(iter);
			if (key <= a)
			{
				return key;
			}
		}
		throw "something went bad in seekLargestPossible";
	}



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
			throw "bad things one size romans func";
			break;
		}
	}

	std::string processToRoman(int value, std::map<int, std::string>& mapRef)
	{
		// if cannot access romanstr in map with key, throws which is good
		// shuldnt be happening tho
		std::string s = mapRef.at(value);
		return s;
	}
};

