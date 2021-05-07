#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    vector<int> students;
    students.assign(n, 1);

    for (int i : reserve)
    {
        students[i-1]++;
    }
    for (int i : lost)
    {
        students[i - 1]--;
    }

    for (int i = 0; i < students.size(); i++)
    {
        if (students.size()>1&&students[i] == 0)
        {
            if (i <= 0 && students[i + 1] == 2)
            {
                students[i]++;
                students[i + 1]--;
                continue;
            }
            if (i > 0 && students[i-1] == 2)
            {
                students[i]++;
                students[i - 1]--;
                continue;
            }
            if (i+1 < students.size() && students[i + 1] == 2)
            {
                students[i]++;
                students[i + 1]--;
                continue;
            }
        }
    }
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i] >= 1)
        {
            answer++;
        }
    }	

    return answer;
}