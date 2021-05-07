#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) 
{
    int x = 0;
    string answer = "�輭���� "+ to_string(x) +"�� �ִ�.";
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
        {
            x = i;
            break;
        }
    }
    return answer;
}


string solution1(vector<string> seoul) 
{
    string answer = "";
    int pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer = "�輭���� " + to_string(pos) + "�� �ִ�";
    return answer;
}