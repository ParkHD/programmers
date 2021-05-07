#pragma once
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    while(progresses.size() > 0)
    {
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }
        if (progresses[0] >= 100)
        {
            int count = 0;
            for (int k = 0; k < progresses.size() && progresses[k] >= 100; k++)
            {
                count++;
            }
            progresses.erase(progresses.begin(),progresses.begin()+count);
            speeds.erase(speeds.begin(), speeds.begin() + count);
           
            answer.push_back(count);
        }
    } 
    return answer;
}//1½Ã°£

vector<int> solution1(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}