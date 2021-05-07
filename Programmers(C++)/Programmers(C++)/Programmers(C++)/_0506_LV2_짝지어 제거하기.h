#pragma once
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
	//Ω∫≈√
	stack<char> stackC;

	stackC.push(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (stackC.size() > 0)
		{
			if (stackC.top() == s[i])
			{
				stackC.pop();
				continue;
			}
		}
		stackC.push(s[i]);
	}
	return stackC.size() > 0 ? 0 : 1;
}