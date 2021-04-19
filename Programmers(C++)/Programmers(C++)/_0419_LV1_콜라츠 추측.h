#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(int num) 
{
    int answer = 0;
    long long x = num;
    while (true)
    {

        if (x == 1)
            break;
        x = x & 1 ? x * 3 + 1 : x / 2;
        answer++;
        if (answer >= 500)
        {
            answer = -1;
            break;
        }
    }
    return answer;
}