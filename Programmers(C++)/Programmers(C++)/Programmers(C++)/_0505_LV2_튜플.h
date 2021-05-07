#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
bool compare(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}
vector<int> solution(string s) 
{
	int count = 0;
	string temp;
	vector<int> tempVec;
	vector<vector<int>> vec;

	for (int i = 1; i < s.size() - 1; i++)
	{
		if (s[i] == '{')
		{
			count--;
			continue;
		}
		if (count == -1)
		{
			if (s[i] == ','|| s[i] == '}')
			{
				tempVec.push_back(stoi(temp));
				temp = "";
			}
			if(isalnum(s[i]))
				temp += s[i];
		}
		if (s[i] == '}')
		{
			count++;
			vec.push_back(tempVec);
			tempVec.clear();
			continue;
		}
	}
	sort(vec.begin(), vec.end(), compare);

	vector<int> answer;
	set<int> tempS;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (tempS.find((vec[i])[j]) == tempS.end())
			{
				tempS.insert(vec[i][j]);
				answer.push_back(vec[i][j]);
				break;
			}
		}
	}
	
	return answer;
}
#include <map>

bool compare1(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
vector<int> solution1(string s) {
	string temp;
	map<int, int> tempMap;
	for (int i = 1; i < s.size() - 1; i++)
	{
		if (isalnum(s[i]))
		{
			temp += s[i];
		}
		else
		{
			if (temp.size() > 0)
			{
				int x = stoi(temp);
				if (tempMap.find(x) == tempMap.end())
				{
					tempMap.insert({ x, 1 });
				}
				else
				{
					tempMap[x]++;
				}
				temp.clear();

			}
		}
	}
	vector<pair<int, int>> vec(tempMap.begin(), tempMap.end());
	sort(vec.begin(), vec.end() ,compare1);

	vector<int> answer;
	for (int i = 0; i < vec.size(); i++)
	{
		answer.push_back(vec[i].first);
	}

	return answer;
}