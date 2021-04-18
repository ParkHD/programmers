#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
bool compare(char a, char b)
{
    return a > b;
}
long long solution(long long n) 
{
    long long answer = 0;
    string s = to_string(n);
    sort(s.begin(), s.end(), compare);
    for (int i = 0; i < s.size(); i++)
    {
        answer += (s[i]-'0') * pow(10, s.size() - i - 1);
    }
    return answer;
}
long long solution(long long n)
{
    long long answer = 0;
    string s = to_string(n);
    sort(s.begin(), s.end(), compare);
    answer = stoll(s);
    return answer;
}
//stoi int stol long stoll long long