#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> vec = arr;
    sort(vec.begin(), vec.end());
    int max = vec[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == max)
        {
            arr.erase(arr.begin() + i);
            break;
        }
    }
    if (arr.size() == 0)
        arr.push_back(-1);
    return arr;
}
vector<int> solution1(vector<int> arr) 
{
    vector<int> answer = arr;

    int nMin = *min_element(arr.begin(), arr.end());
    int pos = find(answer.begin(), answer.end(), nMin) - answer.begin();
    answer.erase(answer.begin() + pos);

    return answer.empty() ? vector<int>(1, -1) : answer;
}