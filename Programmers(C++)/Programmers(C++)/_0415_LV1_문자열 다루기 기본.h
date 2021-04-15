#pragma once
#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    if (s.size() != 4 && s.size() != 6)
    {
        return !answer;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 48 || s[i] > 57)
        {
            return !answer;
        }
    }
    return answer;
}
bool solution1(string s) 
{
    bool answer = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))                                                 //isalpha()
            answer = false;
    }

    return s.size() == 4 || s.size() == 6 ? answer : false;
}