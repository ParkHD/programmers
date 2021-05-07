#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    vector<int> mathod1 = { 1, 2, 3, 4, 5 };
    vector<int> mathod2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> mathod3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; 

    vector<int> score(3);
    for (int i = 0; i < answers.size(); i++)
    {
        if (mathod1[i%mathod1.size()] == answers[i])
        {
            score[0]++;
        }
        if (mathod2[i % mathod2.size()] == answers[i])
        {
            score[1]++;
        }
        if (mathod3[i % mathod3.size()] == answers[i])
        {
            score[2]++;
        }
    }
    int max = *max_element(score.begin(), score.end());
    for (int i = 0; i < score.size(); i++)
    {
        if (max == score[i])
            answer.push_back(i+1);
    }
    return answer;
}