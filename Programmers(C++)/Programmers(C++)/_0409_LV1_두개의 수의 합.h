#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include <vector>
#include<set>

using namespace std;
class Sumtwonum
{

public : 
	vector<int> solution(vector<int> numbers)
	{
		vector<int> answer;

		for (int i = 0; i < numbers.size(); i++)
		{
			for (int j = i + 1; j < numbers.size(); j++)
			{
				int count = 0;

				if (answer.size() == 0)
					answer.push_back(numbers[i] + numbers[j]);

				for (int x = 0; x < answer.size(); x++)
				{
					if (answer[x] == numbers[i] + numbers[j])
					{
						break;
					}
					count++;
					if (count == answer.size())
					{
						answer.push_back(numbers[i] + numbers[j]);
						break;
					}
				}

			}
		}
		sort(answer.begin(), answer.end());
		return answer;
	}
	vector<int> solution1(vector<int> numbers)
	{
		vector<int> answer;
		set<int> st;
		for (int i = 0; i < numbers.size(); ++i) {
			for (int j = i + 1; j < numbers.size(); ++j) {
				st.insert(numbers[i] + numbers[j]);
			}
		}
		answer.assign(st.begin(), st.end());
		return answer;
	}
};


vector<int> solution(vector<int> numbers) 
{
	vector<int> answer;
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i+1; j < numbers.size(); j++)
		{
			answer.push_back(numbers[i] + numbers[j]);
		}
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	return answer;
}
vector<int> solution(vector<int> numbers) 
{
	vector<int> answer;
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i+1; j < numbers.size(); j++)
		{
			answer.push_back(numbers[i] + numbers[j]);
		}
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	return answer;
}
