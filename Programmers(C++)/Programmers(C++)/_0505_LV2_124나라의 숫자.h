#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    vector<string> vec{ "1","2","4" };
    while (n > 0)
    {
        n = n - 1;
        answer = (string)(vec[n%3] + answer);
        n = n / 3;
    }

    return answer;
}