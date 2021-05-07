#pragma once
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> answer;
    long long input = 0;
    for (int i = 0; i < n; i++)
    {
        input += x;
        answer.push_back(input);
    }
    return answer;
}