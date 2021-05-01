#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.resize(3, -1);

    vector<string> sortVec = gems;
    sort(sortVec.begin(), sortVec.end());
    sortVec.erase(unique(sortVec.begin(), sortVec.end()), sortVec.end());

    vector<string> backupKind = sortVec;
    for (int start = 0; start < gems.size() - sortVec.size() + 1; start++)
    {
        for (int i = start; i < gems.size(); i++)
        {
            if (sortVec.size() > gems.size() - i)
                break;
            for (int j = 0; j < sortVec.size(); j++)
            {
                if (gems[i] == sortVec[j])
                {
                    sortVec.erase(sortVec.begin() + j);
                    break;
                }
            }
            if (sortVec.size() == 0)
            {
                if (i - start < answer[2] || answer[2] == -1)
                {
                    answer[0] = start+1;
                    answer[1] = i+1;
                    answer[2] = i - start;
                }
                break;
            }
        }
        sortVec = backupKind;
    }
    answer.erase(answer.begin() + 2);
    return answer;
}


vector<int> solution1(vector<string> gems) 
{
    vector<int> answers;
    vector<string> kindGems = gems;
    sort(kindGems.begin(), kindGems.end());
    kindGems.erase(unique(kindGems.begin(), kindGems.end()), kindGems.end());

    int kindsize = kindGems.size();

    int prevSum;

    if (gems.size() == kindsize)
    {
        answers.push_back(1);
        answers.push_back(gems.size());
        return answers;
    }
    for (int start = 0; start < gems.size() - kindsize + 1; start++)
    {
        int finish = 0;
        int count = 0; // 맞춘개수
        for (int i = 0; i < kindsize; i++)
        {
            for (int j = start; j < gems.size(); j++)
            {
                if (gems[j] == kindGems[i])
                {
                    finish = finish > j ? finish : j;
                    count++;
                    break;
                }
            }
        }
        if (count >= kindsize && (answers.size() <= 0 || prevSum > (finish - start)))
        {
            answers.clear();
            answers.push_back(start + 1);
            answers.push_back(finish + 1);
            prevSum = finish - start;
        }
    }
    return answers;
}

vector<int> solution2(vector<string> gems)
{
    set<string> kindGems;
    for (int i = 0; i < gems.size(); i++)
    {
        kindGems.insert(gems[i]);
    }

    vector<int> output;
    for (int start = 0; start < gems.size() - kindGems.size() + 1; start++)
    {
        set<string> answers;
        int end;
        for (int i = 0; i < kindGems.size(); i++)
        {
            answers.insert(gems[start + i]); 
            end = start + i;
        }

        while (end < gems.size())
        {
            if (answers.size() < kindGems.size())
            {
                end++;
                if (end < gems.size())
                    answers.insert(gems[end]);
            }
            else if (answers.size() == kindGems.size())
            {
                if (output.size() <= 0 || (end - start < output[2]))
                {
                    output.clear();
                    output.push_back(start + 1);
                    output.push_back(end + 1);
                    output.push_back(end - start);
                    break;
                }
                else
                    break;
            }
        }
        
    }
    output.erase(output.begin() + 2);

    return output;
}

// 배열 연속 될때 투포인트 알고리즘쓰자
vector<int> solution3(vector<string> gems)
{
    set<string> kindGems(gems.begin(),gems.end());

    if (gems.size() == kindGems.size())
        return vector<int>{1, (int)kindGems.size()};

    vector<string> answers;
    for (int i = 0; i < kindGems.size(); i++)
    {
        answers.push_back(gems[i]);
    }

    int start = 0;
    int end = kindGems.size() - 1;

    vector<int> result(2);
    int preValue = -1;

    set<string> temp;
    while (end < gems.size())
    {
        
        temp = set<string>(answers.begin(), answers.end());
        if (temp.size() < kindGems.size())
        {
            end++;
            if(end < gems.size())
                answers.push_back(gems[end]);
        }
        else if (temp.size() == kindGems.size())
        {
            if (preValue < 0 || preValue > end - start)
            {
                result[0] = start + 1;
                result[1] = end + 1;
                preValue = end - start;
            }
            answers.erase(answers.begin());
            start++;
            if (gems.size() - start < kindGems.size())
                break;
        }
        temp.clear();
    }

    return result;
}
vector<int> solution4(vector<string> gems)
{
    set<string> kindGems(gems.begin(), gems.end());

    if (gems.size() == kindGems.size())
        return vector<int>{1, (int)kindGems.size()};

    int start = 0;
    int end = kindGems.size() - 1;

    vector<int> result(2);
    int preValue = 10000;

  

    while (end < gems.size())
    {
        set<string> temp(gems.begin() + start , gems.begin() + end + 1);

        for (int i = end; i < gems.size(); i++)
        {
            if (kindGems.size() == temp.size())
            {
                end = i;
                break;
            }
        }
        for (int i = start; i <= end; i++)
        {
            if (kindGems.size() != temp.size())
            {
                start = i;
                break;
            }
        }

        if (temp.size() < kindGems.size())
        {
            if(end < gems.size())
                end++;
        }
        else if (temp.size() == kindGems.size())
        {
            if (preValue > end - start)
            {
                result[0] = start + 1;
                result[1] = end + 1;
                preValue = end - start;
            }
            start++;
            if (start >= end)
                end++;
            if (gems.size() - start < kindGems.size())
                break;
        }
    }

    return result;
}

#include <unordered_map>

vector<int> solution5(vector<string> gems) 
{
    set<string> kind(gems.begin(), gems.end());                 // set으로 정리함으로써 종류 추리기

    unordered_map<string, int> countKind;                       // 종류에 따른 개수 초기화

    int start = 0;
    int end = 0;


    int preValue = 100000;
    vector<int> answers(2, 0);

    while (true)
    {
        // 사이즈 비교시 같으면 그 사이즈의 개수를 --를 하고 만약 개수가 0이라면 없앤다 그리고 start++한다
        if (countKind.size() == kind.size())
        {
            if (preValue > end - start)
            {
                answers[0] = start + 1;
                answers[1] = end;
                preValue = end - start;
            }

            countKind[gems[start]]--;
            if (countKind[gems[start]] == 0)
            {
                countKind.erase(gems[start]);
            }
            start++;
        }
        else if (countKind.size() < kind.size())
        {
            if (end >= gems.size())
                break;
            if (countKind.find(gems[end]) != countKind.end())
            {
                countKind[gems[end]]++;
            }
            else
            {
                countKind.insert({ gems[end], 1 });
            }
            end++;
        }
    }
    return answers;
}

vector<int> solution6(vector<string> gems)
{
    set<string> kind(gems.begin(), gems.end());                 // set으로 정리함으로써 종류 추리기

    unordered_map<string, int> countKind;                       // 종류에 따른 개수 초기화

    int start = 0;
    int end = 0;
    for (int i = 0; i < gems.size(); i++)
    {
        if (countKind.find(gems[i]) != countKind.end())
        {
            countKind[gems[i]]++;
        }
        else
        {
            countKind.insert({ gems[i], 1 });
        }
        // start=0부터 모든 종류를 가지고있는 end값 찾기
        if (countKind.size() == kind.size())
        {
            end = i;
            break;
        }
    }

    int preValue = 100000;
    vector<int> answers(2, 0);

    while (true)
    {
        // 사이즈 비교시 같으면 그 사이즈의 개수를 --를 하고 만약 개수가 0이라면 없앤다 그리고 start++한다
        if (countKind.size() == kind.size())
        {
            if (preValue > end - start)
            {
                answers[0] = start + 1;
                answers[1] = end + 1;
                preValue = end - start;
            }

            countKind[gems[start]]--;
            if (countKind[gems[start]] == 0)
            {
                countKind.erase(gems[start]);
            }
            start++;
        }
        else if (countKind.size() < kind.size())
        {
            end++;
            if (end >= gems.size())
                break;
            if (countKind.find(gems[end]) != countKind.end())
            {
                countKind[gems[end]]++;
            }
            else
            {
                countKind.insert({ gems[end], 1 });
            }
        }
    }
    return answers;
}