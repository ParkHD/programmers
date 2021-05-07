#pragma once
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int selecNum = nums.size() / 2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    answer = nums.size() > selecNum ? selecNum : nums.size();
   
    return answer;
}
int solution1(vector<int> nums)
{
    unordered_map<int, int> hash;

    for (auto num : nums) 
    {
        hash[num] += 1;
    }

    return min(hash.size(), nums.size() / 2);
}