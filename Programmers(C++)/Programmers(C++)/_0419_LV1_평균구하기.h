#pragma once
#include <string>
#include <vector>
#include <numeric>
using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        answer += arr[i];
    }
    answer /= arr.size();
    return answer;
}

double solution1(vector<int> arr) 
{
    double answer = accumulate(arr.begin(), arr.end(), 0);// 마지막 인수는 초기값설정(answer의 타입을 따라간다 longlong형이면 마지막인수 0LL)

    return answer / arr.size();
}
//<numeric> 