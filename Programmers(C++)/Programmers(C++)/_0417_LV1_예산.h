#pragma once
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    sort(d.begin(), d.end());
    for (int i = 0; budget>0; i++)
    {
        budget -= d[i];
        if (budget <= 0)
        {
            break;
        }
        answer++;
    }
    return answer;
}