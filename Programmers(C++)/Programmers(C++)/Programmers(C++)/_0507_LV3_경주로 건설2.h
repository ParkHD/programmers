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
    int money;
    vector2()
    {

    }
    vector2(int x, int y)
    {
        this->x = x;
        this->y = y;
        dir = "";
        money = 100000;
    }
    vector2 operator +(vector2 a)
    {
        return vector2(this->x + a.x, this->y + a.y);
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
int solution2(vector<vector<int>> board) {
    int size = board.size();
    int minCost = 1000000;
    vector2 startPos(0, 0);
    startPos.money = 0;
    vector2 endPos(size - 1, size - 1);
    vector<vector2> dir{ {1,0}, {-1,0}, {0, -1}, {0, 1} };
    queue<vector2> route;
    vector2 prePos;
    route.push(startPos);
    while (!route.empty())
    {
        vector2 nowPos = route.front();
        route.pop();
        if (nowPos == endPos)
        {
            if (nowPos.money < minCost)
            {
                minCost = nowPos.money;
                continue;
            }
        }
        for (int i = 0; i < dir.size(); i++)
        {
            vector2 nextPos(nowPos + dir[i]);
            if (nextPos.x < 0 || nextPos.x >= size)
                continue;
            if (nextPos.y < 0 || nextPos.y >= size)
                continue;
            if (board[nextPos.x][nextPos.y] == 1)
                continue;
            if (nowPos != startPos)
            {
                if (prePos == nextPos)
                    continue;
            }
            prePos = nowPos;
            if (i == 0 || i == 1)
                nextPos.dir = "UD";
            else if (i == 2 || i == 3)
                nextPos.dir = "LR";

            if (nowPos == startPos)
                nowPos.dir = nextPos.dir;

            int temp;
            temp = nowPos.money + 100;
            if (nowPos.dir != nextPos.dir)
            {
                temp += 500;
            }
            if (nextPos.money > temp)
                nextPos.money = temp;

            if (nextPos.money > minCost)
                continue;
            route.push(nextPos);
        }
        
    }
    return minCost;
}