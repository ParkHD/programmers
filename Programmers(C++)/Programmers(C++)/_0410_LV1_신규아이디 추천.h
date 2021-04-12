#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) 
{
    //대문자 +32 = 소문자
    //숫자 48~57
    //ch = '-';//45
    //ch = '_';//95
    //ch = '.';//46
    int sLength = new_id.size();

    for (int i = 0; i < new_id.size();)
    {
        if (65 <= new_id[i] && new_id[i] <= 90)
        {
            new_id[i] += 32;
        }
        if ((48 <= new_id[i] && new_id[i] <= 57) || (97 <= new_id[i] && new_id[i] <= 122) || new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 46)
        {}
        else
        {
            new_id.erase(new_id.begin() + i);
            if (new_id.size() == i)
                i--;
            continue;
        }
        if (i - 1 > 0 && new_id[i] == 46 && new_id[i - 1] == 46 )
        {
            new_id.erase(new_id.begin() + i);
            if (new_id.size() == i)
                i--;
            continue;
        }
        if ((i == 0 && new_id[i] == '.') || (i == new_id.size() -1 && new_id[i] == '.'))
        {
            new_id.erase(new_id.begin() + i);
            if (new_id.size() == i)
                i--;
            continue;
        }
        i++;
    }

    if (new_id.size() == 0)
        new_id.push_back('a');
    if (new_id.size() >= 16)
    {
        int size = new_id.size();
        for (int i = 15; i < size; i++)
        {
            new_id.pop_back();
        }
    }
    if (new_id.size() <= 2)
    {
        for (int i = new_id.size(); i < 3; i++)
            new_id.push_back(new_id[new_id.size() - 1]);
    }
    if(new_id[new_id.size()-1]=='.')
        new_id.pop_back();
    return new_id;
}

string solution1(string new_id) {
    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;

    string ret;
    for (char& ch : new_id) {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) 
            ret += ch;
    }

    new_id = ret;
    ret.clear();
    for (char& ch : new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();

    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();

    return ret;
}