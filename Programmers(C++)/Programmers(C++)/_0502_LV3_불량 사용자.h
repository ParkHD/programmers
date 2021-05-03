//#pragma once
//#include <string>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//int solution(vector<string> user_id, vector<string> banned_id) {
//    int answer = 0;
//
//    vector<vector<string>> vec;
//    for (int i = 0; i < banned_id.size(); i++)
//    {
//        vector<string> temp;
//        for (int j = 0; j < user_id.size(); j++)
//        {
//            if (banned_id[i].size() == user_id[j].size())   // 불량의 글자수와 일반의 글자수 비교
//            {
//                bool same = true;
//                for (int index = 0; index < banned_id[i].size(); index++)
//                {
//                    if (banned_id[i][index] == '*')
//                        continue;
//                    if (banned_id[i][index] != user_id[j][index])
//                    {
//                        same = false;
//                        break;
//                    }
//                }
//                if(same)
//                    temp.push_back(user_id[j]);                 // 글자가 같다고 나오면 temp에 불량글자 후보저장
//            }
//        }
//        vec.push_back(temp);                                // 불량글자 후보명단 vec에 저장
//    }
//
//    for (int a = 0; a < vec[0].size(); a++)
//    {
//        for (int b = 0; b < vec[1].size(); b++)
//        {
//            for (int c = 0; c < vec[2].size(); c++)
//            {
//                for (int d = 0; d < vec[3].size(); d++)
//                {
//
//                }
//            }
//        }
//    }
//}
//set<set<string>> recursion(vector<vector<string>> vec, int count)
//{
//    set<set<string>> answer;
//    set<string> s;
//    for (int i = 0; i < vec[count].size(); i++)
//    {
//        s.insert(vec[count][i]);
//        if (count == vec.size() - 1)
//        {
//            if (s.size() == vec.size())
//            {
//                answer.insert(s);
//                s.clear();
//            }
//        }
//        int temp = count;        
//        recursion(vec, ++temp);
//    }
//    
//}
