//#include<iostream>
//
//using namespace std;
//
//int compare(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	int *mem = new int[n];
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		mem[i] = temp;
//	}
//	int count = 0;
//	while (1)
//	{
//
//		if (mem[0]<mem[1])
//		{
//			count -= 1;
//			break;
//		}
//		int c = pow(2, count);
//		for (int i = 0; i < n; i=i+c)
//		{			
//			mem[i] = compare(mem[i], mem[c]);
//		}
//		count++;
//	}
//
//	cout << count - 1 << endl;
//	return 0;
//}