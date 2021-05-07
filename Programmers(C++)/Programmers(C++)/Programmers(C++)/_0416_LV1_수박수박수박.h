#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(int n) 
{
    string answer = "";
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            answer += "수";
        }
        else
        {
            answer += "박";
        }
    }
    return answer;
}
string solution1(int n) 
{
    string answer = "";

    for (int i = 0; i < n; i++)
        i & 1 ? answer += "박" : answer += "수";

    return answer;
}