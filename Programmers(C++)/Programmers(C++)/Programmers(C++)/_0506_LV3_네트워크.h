#pragma once
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    queue<int> route;
    set<int> network;
    route.push(0);
    
    while(true)
    {
        if (route.empty())
        {
            answer++;
            if (network.size() == n)
                break;
            for (int i = 0; i < n; i++)
            {
                if (network.find(i) == network.end())
                {
                    route.push(i);
                    break;
                }
            }
        }
        int i = route.front();
        network.insert(i);
        route.pop();
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (j == i)
                continue;
            if (visited[i][j])
                continue;
            if (computers[i][j] == 1)
            {
                route.push(j);
                visited[i][j] = true;
            }
        }
    }
    return answer;
}