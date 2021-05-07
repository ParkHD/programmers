#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    int sLength = s.size();

    answer = sLength % 2 == 1 ? s.substr(sLength / 2, 1) : s.substr(sLength / 2 - 1, 2);
    return answer; 
}