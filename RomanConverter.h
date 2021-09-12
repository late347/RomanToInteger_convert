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


		/*char buf[101] = { 0 };
		char letters[5] = { 0 };*/
		int arabic = num;
		std::string result = "";
		result.reserve(50);
		while (arabic > 0)
		{
			int d = seekLargestPossible(arabic);
			std::string characters = processToRoman(d);
			arabic -= d;
			result += characters;
		}
		return result;
	}


	// gets the integer value from properly formatted roman value string


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


	int seekLargestPossible(int a)
	{
		constexpr int romanSpecials[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 8,7,6,5,4,3,2,1 };
		// input bigger than biggest divisor so use 1000
		if (a >= 1000)
		{
			return 1000;
		}

		// seek the biggest divisor that is smallerorequal than the A inputvalue
		
		for(size_t i = 0; i<18; ++i)
		{
			auto key = romanSpecials[i];
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
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;

		default:
			throw "bad things one size romans func";
			break;
		}
	}

	std::string processToRoman(int value)
	{
		using namespace std;

		switch (value)
		{
		case 1000: return string{ "M" }; break;
		case 900:  return string{ "CM" }; break;
		case 500:  return string{ "D" }; break;
		case 400:  return string{ "CD" }; break;
		case 100:  return string{ "C" }; break;
		case 90:  return string{ "XC" }; break;
		case 50:  return string{ "L" }; break;
		case 40:  return string{ "XL" }; break;
		case 10:  return string{ "X" }; break;
		case 9:  return string{ "IX" }; break;
		case 8:  return string{ "VIII" }; break;
		case 7:  return string{ "VII" }; break;
		case 6:  return string{ "VI" }; break;
		case 5:  return string{ "V" }; break;
		case 4:  return string{ "IV" }; break;
		case 3:  return string{ "III" }; break;
		case 2:  return string{ "II" }; break;
		case 1:  return string{ "I" }; break;
		default:
			throw "something went bad in process to roman func";
			break;
		}
	}
};

