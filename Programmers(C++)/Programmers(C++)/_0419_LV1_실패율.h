#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    
    vector<double> vec;
    for (int j = 1; j < N+1; j++)
    {
        double failP = 0;
        double challengeP = 0;
        for (int i = 0; i < stages.size(); i++)
        {
            if (stages[i] >= j)
            {
                challengeP++;
            }
            if (stages[i] == j)
            {
                failP++;
            }
        }
        if (challengeP == 0)
        {
            vec.push_back(0);
        }
        else
        {
            vec.push_back(failP / challengeP);
        }
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        double failMax = *max_element(vec.begin(), vec.end());
        for (int j = 0; j < vec.size(); j++)
        {
            if (failMax == vec[j])
            {
                answer.push_back(j+1);
                vec[j] = -1;
                break;
            }
        }
    }
    return answer;
}
// �ƽ��� ���ϰ� �� index�� answer�� �ִ´� �׸������� ���� �ݺ� ������

bool comp(pair<int, double> a, pair<int, double> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<int> solution1(int N, vector<int> stages)
{
    vector<int> answer;

    vector<pair<int, double>> vec;
    for (int j = 1; j < N + 1; j++)
    {
        double failP = 0;
        double challengeP = 0;
        for (int i = 0; i < stages.size(); i++)
        {
            if (stages[i] >= j)
            {
                challengeP++;
            }
            if (stages[i] == j)
            {
                failP++;
            }
        }
        if (challengeP == 0)
        {
            vec.push_back(make_pair(j, 0));
        }
        else
        {
            vec.push_back(make_pair(j, failP / challengeP));
        }
    }
    sort(vec.begin(), vec.end(), comp);
    for (int i = 0; i < vec.size(); i++)
    {
        answer.push_back(vec[i].first);
    }
    return answer;
}