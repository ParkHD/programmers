#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> chatRoom;
    vector<vector<string>> data;
    for (int i = 0; i < record.size(); i++)
    {
        vector<string> underData;
        //underData[0] : 명령어 underData[1] 유저아이디 : underData[2] : 유저닉네임
        string temp;
        for (int j = 0; j < record[i].size(); j++)
        {
            if (isalnum(record[i][j]))
            {
                temp += record[i][j];
            }
            else
            {
                underData.push_back(temp);
                temp.clear();
                continue;
            }
        }
        underData.push_back(temp);
        data.push_back(underData);
    }

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][0] == "Enter")
        {
            if (chatRoom.find(data[i][1]) != chatRoom.end())
            {
                chatRoom[data[i][1]] = data[i][2];
                continue;
            }
            chatRoom.insert({ data[i][1], data[i][2] });
        }
        else if (data[i][0] == "Leave")
        {
        }
        else if (data[i][0] == "Change")
        {
            chatRoom[data[i][1]] = data[i][2];
        }
    }

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][0] == "Enter")
        {
            answer.push_back(chatRoom[data[i][1]] + "님이 들어왔습니다.");
        }
        else if (data[i][0] == "Leave")
        {
            answer.push_back(chatRoom[data[i][1]] + "님이 나갔습니다.");
        }
    }
    return answer;
}