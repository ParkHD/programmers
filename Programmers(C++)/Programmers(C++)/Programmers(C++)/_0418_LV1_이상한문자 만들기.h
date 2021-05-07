#pragma once
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            if (count % 2 == 0)
            {
                s[i] = toupper(s[i]);
            }
            count++;
            continue;
        }
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            if (count % 2 == 1)
            {
                s[i] = tolower(s[i]);
            }
            count++;
            continue;
        }
        else
            count = 0;
    }
    return s;
}
string solution1(string s) {
    string answer = "";
    int nIndex = 1;
    for (int i = 0; i < s.size(); i++, nIndex++)
    {
        if (s[i] == ' ')
        {
            nIndex = 0;
            answer += " ";
        }
        else
            nIndex & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }

    return answer;
}