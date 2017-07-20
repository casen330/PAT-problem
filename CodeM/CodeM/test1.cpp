//#include<iostream>
//#include<vector>
//#include<math.h>
//using namespace std;
//
//int main(){
//	int n, m;
//	vector<int> a, b;
//	cin >> n;	
//	int temp;
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		cin >> temp;
//		b.push_back(temp);
//	}
//	cin >> m;	
//	for (i = 0; i < m; i++)
//	{
//		cin >> temp;
//		a.push_back(temp);
//	}
//	vector<int>::iterator ita = a.begin();
//
//	long  sum = 0;
//	long  minSum = 2147483647;
//	int size = a.size() - b.size();
//	for (int i=0; i<size; i++,ita++)
//	{
//		for (vector<int>::iterator flag = ita, itb = b.begin(); itb != b.end(); itb++, flag++)
//		{
//			sum += pow((*flag - *itb), 2);
//		}
//		if (sum<minSum)
//		{
//			minSum = sum;
//		}
//		sum = 0;
//	}
//	cout << minSum << endl;
//	return 0;
//}