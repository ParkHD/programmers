#include "_0409_LV1_�ΰ��� ���� ��.h";
//#include "_0409_LV1_ũ���������̱�.h";
//#include <list>
//#include "_0410_LV1_�������� ���� ����.h"
//#include "_0410_LV1_�űԾ��̵� ��õ.h"
//#include "_0412_LV1_���ǰ��.h"
//#include "_0412_LV1_K��°.h"
//#include "_0412_LV1_3���� ������.h"
//#include "_0412_LV1_ü����.h"
//#include "_0413_LV1_���ڿ� �� ������� �����ϱ�.h"
#include "_0418_LV1_Ű�е� ������.h"
#include "_0418_LV1_�ִ������� �ּҰ����.h"
void Show(vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}
}	
int i;

bool compare(char a, char b)
{
	return a>b;
}

//vector<string> solution(vector<string> strings, int n) {
//	i = n;
//	sort(strings.begin(), strings.end(), compare);
//	return strings;
//}

int main()
{
#pragma region k��° ����
	//vector<int> array = { 1,2,3,4,5,7,8 };
	//vector<vector<int>> vec = { {2, 5, 3} ,{4, 4, 1},{2, 5, 3} ,{1, 7, 3} };

	//Show(solution(array, vec));
#pragma endregion
#pragma region 3���� ������
	//int x = 45;
	//
	//Show(Ternary(x));
	//cout<< solution(x)<<endl;
#pragma endregion
#pragma region ü����
	//cout << solution(5, { 2,4 }, { 1,3,5 }) << endl;
#pragma endregion
	//vector<int> vec = { 1,1,4,4,4,2,5,5,3 };
	//sort(vec.begin(), vec.end());
	//unique(vec.begin(), vec.end());
	////vec.erase(unique(vec.begin(), vec.end()),vec.end());
	//Show(vec);
	//cout << solution1(20);

	Show(solution(60, 48));

}
