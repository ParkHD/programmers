#pragma once
#include <string>
#include <ctype.h>
#include <math.h>
#include <vector>
using namespace std;

int solution(string dartResult) 
{
    int answer = 0;
    vector<int> vec;
    vector<int> number;
    for (int i = 0; i < dartResult.size(); i++)
    {
        int x = dartResult[i];
        if (isdigit(x))
        {
            number.push_back(x-'0');
            continue;
        }
        else if (isalpha(x))
        {
            int temp = 0;
            for (int j = 0; j < number.size(); j++)
            {
                temp += number[j] * pow(10, number.size() -1 -j);
            }
            if (x == 'S')
            {
                vec.push_back(pow(temp, 1));
            }
            else if (x == 'D')
            {
                vec.push_back(pow(temp, 2));
            }
            else if (x == 'T')
            {
                vec.push_back(pow(temp, 3));
            }
            number.clear();
        }
        else
        {
            if (x == '*')
            {
                vec[vec.size() - 1] = 2 * vec[vec.size() - 1];
                if (vec.size() > 1)
                {
                    vec[vec.size() - 2] = 2 * vec[vec.size() - 2];
                }
            }
            else if (x == '#')
            {
                vec[vec.size() - 1] = -vec[vec.size()-1];
            }
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        answer += vec[i];
    }
    return answer;
}