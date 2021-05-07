#pragma once
#include <iostream>
#include <vector>

using namespace std;


void solution(vector<int> vector, int m)
{
	int answer = 0;

	int start = 0;
	int end = 0;
	int sum = vector[0];
	int n = vector.size();
	while (end < n)
	{
		if(sum < m)
		{
			end++;
			if (end < n)
				sum += vector[end];
		}
		else if (sum > m)
		{
			sum -= vector[start];
			start++;
		}
		else if (sum == m)
		{
			sum -= vector[start];
			start++;
			end++;
			if (end < n)
				sum += vector[end];
			answer++;
		}
	}

}