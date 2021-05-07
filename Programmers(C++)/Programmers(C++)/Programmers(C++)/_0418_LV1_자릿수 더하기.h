#pragma once
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    int x = n;
    while (true)
    {
        if (x / 10 == 0)
        {
            answer += x;
            break;
        }
        if (x / 10 != 0)
        {
            answer += x % 10;
            x = x / 10;
        }
    }
    return answer;
}
int solution1(int n)
{
    int answer = 0;
    while (n > 0) {
        answer += n % 10;
        n /= 10;
    }
    return answer;
}
int solution2(int n)
{
    int answer = 0;
    string s = to_string(n);

    for (int i = 0; i < s.size(); i++) 
        answer += (s[i] - '0');

    return answer;
}