#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int word = arr[0];
    answer.push_back(word);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == word)
        {
            continue;
        }
        word = arr[i];
        answer.push_back(word);
    }

    return answer;
}

vector<int> solution1(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()),arr.end());
    return arr;
}