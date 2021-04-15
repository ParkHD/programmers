#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool compare(char a, char b)
{
	return a > b;
}
string solution(string s)
{
	sort(s.begin(), s.end(), compare);
	return s;
}


string solution1(string s) {
	sort(s.begin(), s.end(), greater<char>());
	return s;
}

string solution2(string s)	{
	sort(s.rbegin(), s.rend());
	return s;
}