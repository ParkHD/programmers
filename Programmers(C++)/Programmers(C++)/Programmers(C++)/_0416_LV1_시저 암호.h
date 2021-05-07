#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (s[i] + n) % 25 + 97;
        } 
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (s[i] + n) % 25 + 65;
        }
    }
    return s;
}