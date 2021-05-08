#pragma once
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(string begin, string target, vector<string> words) 
{
    map<string, int> index;
    index.insert({ begin, 0 });
    for (int i = 0; i < words.size(); i++)
    {
        index.insert({ words[i], i+1 });
    }
    vector<vector<bool>> visited(index.size(), vector<bool>(index.size(), false));
    vector<int> distance(index.size(), 0);
    queue<string> route;
    route.push(begin);
    string start;
    while (!route.empty())
    {
        start = route.front();
        route.pop();
        for (int i = 0; i < words.size(); i++)
        {
            int sameCount = 0;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (start[j] == words[i][j])
                {
                    sameCount++;
                }
            }
            if (sameCount == (begin.size() - 1) && visited[index[words[i]]][index[start]] == false)
            {
                route.push(words[i]);
                visited[index[words[i]]][index[start]] = true;
                visited[index[start]][index[words[i]]] = true;
                distance[index[words[i]]] =  distance[index[start]] + 1;
                
                if (words[i] == target)
                    return distance[index[target]];
            }
        }
    }
    return 0;
}