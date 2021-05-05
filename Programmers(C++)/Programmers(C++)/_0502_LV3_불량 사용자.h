#pragma once
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void DFS(vector<string> user_id, vector<string> banned_id, map<string, bool> visited, int count, set<vector<string>>& combination , vector<string> temp)
{
	if (count >= banned_id.size())
	{
		sort(temp.begin(), temp.end());
		combination.insert(temp);
		return;
	}
	for (int i = 0; i < user_id.size(); i++)
	{
		if (banned_id[count].size() != user_id[i].size())
			continue;
		if (visited[user_id[i]] == true)
			continue;

		bool isSame = true;
		for (int length = 0; length < banned_id[count].size(); length++)
		{
			if (banned_id[count][length] != user_id[i][length])
			{
				if (banned_id[count][length] == '*')
					continue;
				isSame = false;
				break;
			}
		}
		if (isSame)
		{
			temp[count] = user_id[i];
			visited[user_id[i]] = true;
			DFS(user_id, banned_id, visited, count+1, combination, temp);
			visited[user_id[i]] = false;
		}
		
	}
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
	set<vector<string>> combination;
	map<string, bool> visited;
	for (int i = 0; i < user_id.size(); i++)
	{
		visited.insert({ user_id[i], false });
	}
	vector<string> temp(banned_id.size(), "");
	int count = 0;
	DFS(user_id, banned_id, visited, count, combination, temp);
	return combination.size();
}
