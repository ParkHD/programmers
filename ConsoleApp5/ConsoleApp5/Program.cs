using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp5
{
    public class Solution
    {
        public int[] solution(int[] test)
        {
            List<int> player1 = new List<int>() { 1, 2, 3, 4, 5 };
            List<int> player2 = new List<int>() { 2, 1, 2, 3, 2, 4, 2, 5 };
            List<int> player3 = new List<int>() { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

            
            int[,] rank = { { 1, 0 }, { 2, 0 } ,{3 , 0 } };
            int count1 = 0;
            int count2 = 0;
            int count3 = 0;

            int p1N = 0;
            int p2N = 0;
            int p3N = 0;

            for (int i =0;i<test.Length;i++)
            {
                if (test[i] == player1[p1N])
                {
                    count1++;
                }
                if (test[i] == player2[p2N])
                {
                    count2++;
                }
                if (test[i] == player3[p3N])
                {
                    count3++;
                }
                p1N++;
                p2N++;
                p3N++;
                if(p1N == player1.Count)
                {
                    p1N = 0;
                }
                if (p2N == player2.Count)
                {
                    p2N = 0;
                }
                if (p3N == player3.Count)
                {
                    p3N = 0;
                }
            }
            rank[0, 1] = count1;
            rank[1, 1] = count2;
            rank[2, 1] = count3;

            
            int max = count1>=count2?count1:count2;
            max = (max >= count3 ? max : count3);


            List<int> output = new List<int>();
            for(int i =0; i<3; i++)
            {
                if(max == rank[i,1])
                {
                    output.Add(rank[i, 0]);
                }
            }

            return output.ToArray();
        }
        public int[] solution1(int[] test)
        {
            int[] player1 = { 1, 2, 3, 4, 5 };
            int[] player2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
            int[] player3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

            int[] score = new int[3];
            for(int i =0;i<test.Length;i++)
            {
                if (test[i] == player1[i % player1.Length]) score[0]++;
                if (test[i] == player2[i % player2.Length]) score[1]++;
                if (test[i] == player2[i % player3.Length]) score[2]++;
            }
            List<int> answer = new List<int>();
            if (score[0] == score.Max()) answer.Add(1);
            if (score[1] == score.Max()) answer.Add(2);
            if (score[2] == score.Max()) answer.Add(3);

            return answer.ToArray();

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution1 = new Solution();
            int[] list = { 1, 3, 2, 4, 2 };
            for(int i =0; i< solution1.solution1(list).Length; i++)
            {
                Console.WriteLine(solution1.solution1(list)[i]);
            }
        }
    }
}
