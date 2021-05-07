#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> vec;
    for (int i = 0; i < nums.size()-2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                vec.push_back(nums[i] + nums[k] + nums[j]);
            }
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 2; j < vec[i]; j++)
        {
            if (vec[i] % j == 0)
            {
                answer++;
                break;
            }
        }
    }
    return vec.size() - answer;
}