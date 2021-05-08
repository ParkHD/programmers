#pragma once
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> vec(scoville.begin(),scoville.end());

    for (int i = 0; i < vec.size();)
    {
        if (vec.size() < 2)
        {
            break;
        }   
        int first = vec.top();
        if (first >= K)
            return answer;
        vec.pop();
        int second = vec.top();
        vec.pop();

        int temp = first + second * 2;
        vec.push(temp);
        answer++;
    }
    if (vec.top() < K)
        return -1;

    return answer;
}