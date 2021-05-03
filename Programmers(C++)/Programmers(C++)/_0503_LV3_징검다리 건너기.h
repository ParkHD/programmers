#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int start = 0;
    int end = k - 1;

    int number = 200000000;
    cout << number;
    while (true)
    {
        int min = *max_element(stones.begin() + start, stones.begin() + end + 1);

        if (number > min)
        {
            number = min;
        }
        start++;
        end++;
        answer = number;
        if (end >= stones.size() - 1)
            break;
    }
    return answer;
}

//ÀÌºÐÅ½»ö
int solution1(vector<int> stones, int k)
{
    int max = *max_element(stones.begin(), stones.end());
    int min = *min_element(stones.begin(), stones.end());

    vector<int> vec = stones;
    while (true)
    {
        int mid = (max + min) / 2;
        stones = vec;
        for (int i = 0; i < stones.size(); i++)
        {
            stones[i] -= mid;
        }
        int count = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (stones[i] < 0)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (count >= k)
            {
                max = mid - 1;
                break;
            }
            if (i == stones.size() - 1)
            {
                min = mid + 1;
                break;
            }
        }
        if (max < min)
            break;
    }
    return max;
}