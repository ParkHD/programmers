#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    vector<int> ans1;
    for (int j = 0; j < commands.size(); j++)
    {
        for (int i = commands[j][0] - 1; i < commands[j][1]; i++)
        {
            ans1.push_back(array[i]);
        }
        sort(ans1.begin(), ans1.end());
        answer.push_back(ans1[commands[j][2]-1]);
        ans1.clear();
    }
    return answer;
}
