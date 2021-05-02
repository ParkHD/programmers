#pragma once
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    vector<vector<string>> vec;
    for (int i = 0; i < banned_id.size(); i++)
    {
        vector<string> candidate
        for (int j = 0; j < user_id.size(); j++)
        {
            if (banned_id[i].size() == user_id[j].size())   // 불량의 글자수와 일반의 글자수 비교
            {
                for (int index = 0; banned_id[i].size(); index++)
                {
                    if (banned_id[i][index] == '*')
                        continue;
                    if (banned_id[i][index] != user_id[j][index])
                    {
                        break;
                    }
                }
                vector<string> temp;
                temp
            }
        }
    }

    return answer;
}