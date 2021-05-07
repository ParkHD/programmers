#pragma once
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

struct vector2
{
    int x;
    int y;
    string dir;
    vector2()
    {

    }
    vector2(int x, int y)
    {
        this->x = x;
        this->y = y;
        dir = "";
    }
    vector2 operator +(vector2 a)
    {
        return vector2(this->x + a.x, this->y + a.y);
    }
    bool operator ==(vector2 a)
    {
        return this->x == a.x && this->y == a.y;
    }
};
int minMoney = 1000000;
vector<vector2> dir{ {1,0}, {-1,0}, {0,-1}, {0,1} };
vector<int> cost;
void dfs(vector<vector<int>> board, stack<vector2>& route, map<pair<int, int>, bool> visited, int size, int money)
{
    if (route.empty())
        return;
    if (minMoney < money)
        return;
    vector2 nowPos = route.top();
    route.pop();
    if (nowPos == vector2(board.size() - 1, board.size() - 1))
    {
        minMoney = minMoney > money ? money : minMoney;
        return;
    }
    vector2 nextPos;

    for (int i = 0; i < dir.size(); i++)
    {
        nextPos = nowPos + dir[i];
        if (nextPos.x < 0 || nextPos.x >= size)
            continue;
        if (nextPos.y < 0 || nextPos.y >= size)
            continue;
        if (board[nextPos.x][nextPos.y] == 1)
            continue;
        if (visited[{nextPos.x, nextPos.y}] == true)
            continue;
        
        if (i == 0 || i == 1)
            nextPos.dir = "UD";
        else if (i == 2 || i == 3)
            nextPos.dir = "LR";
        route.push(nextPos);

        money = money + 100;
        if (nowPos.dir != nextPos.dir)
            money = money + 500;
        
        
        visited[{nextPos.x, nextPos.y}] = true; 
        if (minMoney < money)
            return;
        dfs(board, route, visited, size, money);
        visited[{nextPos.x, nextPos.y}] = false;

        money = money - 100;
        if (nowPos.dir != nextPos.dir)
            money = money - 500;
    }
}
int solution(vector<vector<int>> board) 
{
    int money = -500;

    vector2 startPos(0, 0);
    stack<vector2> route;
    map<pair<int, int>, bool> visited;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            visited.insert({{i,j},false});
        }
    }
    visited[{startPos.x, startPos.y}] = true;
    route.push(startPos);

    dfs(board, route, visited, board.size(), money);

    return minMoney;
}