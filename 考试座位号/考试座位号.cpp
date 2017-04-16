#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> num1;
	vector<int> num2, num3;
	string a1;
	int a2, a3;
	for (int i = 0; i < N; i++)
	{
		cin >> a1 >> a2 >> a3;
		num1.push_back(a1);
		num2.push_back(a2);
		num3.push_back(a3);
	}
	int M;
	cin >> M;
	vector<int> countNum;
	int selectNum;
	for (int i = 0; i < M; i++)
	{
		cin >> selectNum;
		countNum.push_back(selectNum);
	}	
	vector<int>::iterator selectIter = countNum.begin();
	for (; selectIter != countNum.end(); selectIter++)
	{
		vector<string>::iterator iter1 = num1.begin();
		vector<int>::iterator iter2 = num2.begin();
		vector<int>::iterator iter3 = num3.begin();
		for (; iter2 != num2.end(); iter2++)
		{
			if (*iter2==*selectIter)
			{
				cout << *iter1 << " " << *iter3 << endl;
			}
			iter1++;
			iter3++;
		}
	}	
	system("pause");
	return 0;
}