#pragma once
#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    bool answer = true;
    string s = to_string(x);
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum += s[i] - '0';
    }
    answer = x % sum == 0 ? true : false;

    return answer;
}