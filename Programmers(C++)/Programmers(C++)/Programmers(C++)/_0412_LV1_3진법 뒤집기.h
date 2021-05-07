#pragma once
#include <string>
#include <vector>
#include <cmath>

using namespace std;
vector<int> Ternary(int number)
{
    vector<int> ternary;

    while (number > 0)
    {
        ternary.push_back(number % 3);
        number = number / 3;
    }
    return ternary;
}
int solution(int n) 
{
    int answer = 0;
    vector<int> vec = Ternary(n);
    for (int i = 0; i < vec.size(); i++)
    {
        answer += vec[i]*pow(3, vec.size()-i-1);
    }
    return answer;
}
