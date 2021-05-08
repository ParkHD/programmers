#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;
struct vector2
{
    int pos;
    int y;
    vector2(int x, int y)
    {
        this->pos = x;
        this->y = y;
    }
    bool operator ==(vector2 a)
    {
        return this->y == a.y;
    }
};
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<vector2> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(vector2(i, i));
    }
    vector<vector2> origin = vec;
    int index = k;
    stack<vector2> ctrlZ;
    for (int i = 0; i < cmd.size(); i++)
    {
        int temp;
        if (cmd[i][0] == 'D')
        {
            temp = cmd[i][2] - '0';
            index += temp;
        }
        else if (cmd[i][0] == 'U')
        {
            temp = cmd[i][2] - '0';
            index -= temp;
        }
        else if (cmd[i][0] == 'C')
        {
            vec[index].pos = index;
            ctrlZ.push(vec[index]);
            vec.erase(vec.begin() + index);
            if (index == vec.size())
                index -= 1;
        }
        else if (cmd[i][0] == 'Z')
        {
            vector2 tempVec2 = ctrlZ.top();
            ctrlZ.pop();
            vec.insert(vec.begin() + tempVec2.pos, tempVec2);
            if (tempVec2.pos <= index)
                index += 1;
        }
    }
    
    for (int i = 0; i < origin.size(); i++)
    {
        bool isHave = false;
        for (int j = 0; j < vec.size(); j++)
        {
            if (origin[i] == vec[j])
            {
                isHave = true;
                break;
            }
        }
        string temp = isHave ? "O" : "X";
        answer = answer + temp;
    }
    return answer;
}