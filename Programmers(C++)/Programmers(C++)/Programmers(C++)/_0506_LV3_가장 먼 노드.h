#pragma once
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<bool>> node(n,vector<bool>(n,false));
    for (int i = 0; i < edge.size(); i++)
    {
        
        node[edge[i][0] - 1][edge[i][1] - 1] = true;
        node[edge[i][1] - 1][edge[i][0] - 1] = true;
        
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> distance(n,50000);
    queue<int> route;
    route.push(0);
    distance[0] = 0;
    while (true)
    {
        if (route.empty())
            break;
        int index = route.front();
        route.pop();
        for (int i = 0; i < node[index].size(); i++)
        {
            if (node[index][i] == true && visited[index][i] == false)
            {
                if (distance[i] > distance[index] + 1)
                {
                    route.push(i);
                    distance[i] = distance[index] + 1;
                }
                visited[index][i] = true;
            }
        }
        
    }
    int max = *max_element(distance.begin(), distance.end());

    for (int i = 0; i < distance.size(); i++)
    {
        if (distance[i] == max)
            answer++;
    }
    return answer;
}