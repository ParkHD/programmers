#pragma once
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string s) 
{
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            answer += (s[i]-48) * pow(10, s.size() - 1 - i);
        }
    } 
    if (s[0] == '-')
        answer = -answer;
    return answer;
}
int solution1(string s) 
{
    int answer = stoi(s);
    return answer;
}