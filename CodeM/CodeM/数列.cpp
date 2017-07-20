//#include<iostream>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//int maxy(int a, int b)
//{
//	int min, max, r;
//	max = a>b ? a : b;
//	min = a<b ? a : b;
//	if (max%min == 0)
//		return min;
//	else
//	{
//		r = max%min;
//		max = min;
//		min = r;
//
//	}
//	return min;
//}
//int main(){
//	int n, m;
//	cin >> n >> m;
//	int *a, *l, *r, *k;
//	a = new int[n];
//	l = new int[m];
//	r = new int[m];
//	k = new int[m];
//	int temp_a;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp_a;
//		a[i] = temp_a;
//	}
//	int temp_l, temp_r, temp_k;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> temp_l >> temp_r >> temp_k;
//		l[i] = temp_l;
//		r[i] = temp_r;
//		k[i] = temp_k;
//	}
//	set<int> temp_value;
//	vector<int> temp_middle;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = l[i]-1; j <= r[i]-1; j++)
//		{
//			temp_value.insert(a[j]);
//			temp_middle.push_back(a[j]);
//		}
//		int answerCount = 0;
//		for (set<int>::iterator iter = temp_value.begin(); iter != temp_value.end(); iter++)
//		{
//			int num = count(temp_middle.begin(), temp_middle.end(), *iter);
//			if (maxy(num,k[i])==1)
//			{
//				answerCount++;
//			}
//		}
//		cout << answerCount << endl;
//		temp_middle.clear();
//		temp_value.clear();
//	}
//	delete[] a;
//	delete[] l;
//	delete[] r;
//	delete[] k;
//	return 0;
//}