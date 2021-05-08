#include <string>
#include <vector>
#include <queue>
using namespace std;
struct vector2
{
    int x;
    int y;
    int count;
    vector2(int x, int y)
    {
        this->x = x;
        this->y = y;
        count = 0;
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
vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;
    vector<vector2> dir{ {1,0}, {-1,0}, {0, -1}, {0, 1} };
    for (int i = 0; i < places.size(); i++)                     // ¸Ê
    {
        vector<string> map = places[i];
        for (int j = 0; j < map.size(); j++)              // ¸Ê¾È¿¡ ÁÙ
        {
            for (int index = 0; index < map[j].size(); index++)   // ÁÙ¾È¿¡ ÀÎµ¦½º
            {
                if (map[j][index] == 'P')
                {
                    vector2 startPos(j, index);
                    queue<vector2> route;
                    route.push(startPos);

                    while (!route.empty())
                    {
                        vector2 nowPos = route.front();
                        route.pop();

                        if (nowPos.count >= 2)
                            continue;

                        for (int i = 0; i < dir.size(); i++)
                        {
                            vector2 nextPos(nowPos + dir[i]);
                            nextPos.count = nowPos.count + 1;
                            if (nextPos.x < 0 || nextPos.x >= 5)
                                continue;
                            if (nextPos.y < 0 || nextPos.y >= 5)
                                continue;
                            if (map[nextPos.x][nextPos.y] == 'X')
                                continue;

                            if (map[nextPos.x][nextPos.y] == 'P')
                            {
                                if (nextPos == startPos)
                                    continue;
                                answer.push_back(0);
                                goto stop;
                            }
                            route.push(nextPos);
                        }
                    }
                }
            }
        }
        answer.push_back(1);
    stop: continue;
    }
    return answer;
}
