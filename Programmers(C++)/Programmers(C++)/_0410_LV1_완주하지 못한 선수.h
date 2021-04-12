#pragma once
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution1(vector<string> participant, vector<string> completion)
{   
    int pSize = participant.size();
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < pSize; i++)
    {
        for (int j = i; j < pSize - 1; j++)
        {
            if (participant[i] == completion[j])
            {
                if(i + 1 == pSize - 1)
                    return participant[i+1];
                break;
            }
            if (pSize-1 && participant[i] != completion[j])
            {
                if (j + 1 == pSize - 1 || participant[i] != completion[j+1])
                {
                    return participant[i];
                }
            }
        }
    }
}
string solution2(vector<string> participant, vector<string> completion)
{
    int pSize = participant.size();
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < pSize; i++)
    {
        if (i == pSize - 1)
            return participant[pSize - 1];
        if (participant[i] != completion[i])
        {
            return participant[i];
        }
    }

    //return participant[pSize-1];
}