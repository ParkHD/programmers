#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    string ans = "";
    string alpha = "";
    vector<string> vec{ "zero", "one", "two","three","four","five","six","seven","eight","nine" };
    for (int i = 0; i < s.size(); i++)
    {

        if (isdigit(s[i]))
        {
            ans = ans + s[i];
        }
        if (isalpha(s[i]))
        {
            alpha = alpha + s[i];
        }
        if (alpha.size() > 2)
        {
            for (int j = 0; j < vec.size(); j++)
            {
                if (alpha == vec[j])
                {
                    ans = ans + to_string(j);
                    alpha.clear();
                }
            }
        }
    }
    return stoi(ans);
}