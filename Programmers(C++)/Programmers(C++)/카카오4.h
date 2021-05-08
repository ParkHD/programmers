#pragma once
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct vector2
{
    int x;
    int y;
    string dir;
    int cost;
    vector2(int x, int y)
    {
        this->x = x;
        this->y = y;
        cost = 0;
    }
    bool operator ==(vector2 a)
    {
        return this->x == a.x && this->y == a.y;
    }
    bool operator !=(vector2 a)
    {
        return this->x != a.x || this->y != a.y;
    }
};
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {

    int startPos = start - 1;
    int endPos = end - 1;

    vector<vector<int>> costVec(n, vector<int>(n, 0));
   
    for (int i = 0; i < roads.size(); i++)
    {
        costVec[roads[i][0] - 1][roads[i][1] - 1] = roads[i][2];
        costVec[roads[i][1] - 1][roads[i][0] - 1] = roads[i][2];
    }

    map<pair<int, int>, bool> possible;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            possible.insert({ { i ,j }, false });
        }
    }
    for (int i = 0; i < roads.size(); i++)
    {
        possible[{roads[i][0] - 1, roads[i][1] - 1}] = true;
    }
    queue<int> route;
    route.push(startPos);
    map<int, int> cost;
    for (int i = 0; i < n; i++)
        cost.insert({ i,1000000000 });
    cost[0] = 0;
    int nowPos;  // f node s cost
    while (!route.empty())
    {
        nowPos = route.front();
        route.pop();
        for (int i = 0; i < traps.size(); i++)
        {
            if (nowPos == traps[i]-1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (possible[{j, nowPos}] == true)
                    {
                        possible[{j, nowPos}] = false;
                        possible[{nowPos, j}] = true;
                    }
                    else if (possible[{nowPos, j}] == true)
                    {
                        possible[{j, nowPos}] = true;
                        possible[{nowPos, j}] = false;
                    }
                }
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            int nextPos = i;
            if (possible[{nowPos, nextPos}])
            {
                if (cost[nextPos] > cost[nowPos] + costVec[nowPos][nextPos])
                {
                    cost[nextPos] = cost[nowPos] + costVec[nowPos][nextPos];
                }
                else
                    continue;
              
                route.push(i);
            }
        }
    }
    return cost[endPos];
  
}