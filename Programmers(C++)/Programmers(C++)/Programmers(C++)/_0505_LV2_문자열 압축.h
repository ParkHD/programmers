#pragma once
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int solution(string s) 
{
    int interval = 1;
    vector<int> lengthVec;
    while (interval <= s.size()/2)
    {
        int count = 1;
        int length = 0;
        string now = s.substr(0, interval);
        for (int i = interval; i < s.size(); i = i + interval)
        {
            string next = s.substr(i, interval);
            if (now != next)
            {
                for (int i = 1; i < 10; i++)
                {
                    if (count >= pow(10, i))
                    {
                        length += i;
                    }
                }
                length += interval + (count > 1 ? 1 : 0);
                count = 1;
            }
            else
            {
                count++;
            }
            if (i + interval >= s.size())
            {
                for (int i = 1; i < 10; i++)
                {
                    if (count >= pow(10, i))
                    {
                        length += i;
                    }
                }
                length += next.size() + (count > 1 ? 1 : 0);
            }
            now = next;
        }
        lengthVec.push_back(length);
        interval++;
    }
    lengthVec.push_back(s.size());
    return *min_element(lengthVec.begin(),lengthVec.end());
}