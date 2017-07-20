//#include<iostream>
//#include<iomanip>
//
//using namespace std;
//
//int main(){
//	int n, T, C;
//	cin >> n;
//	cin >> T >> C;
//	int *t, *c;
//	t = new int[n];
//	c = new int[n];
//	int temp_t, temp_c;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp_t >> temp_c;
//		t[i] = temp_t;
//		c[i] = temp_c;
//	}
//	int min_t = t[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (t[i]<min_t)
//		{
//			min_t = t[i];
//		}
//	}
//	double sum_C = 0.0;
//	for (int i = 0; i < n; i++)
//	{
//		sum_C += ((min_t - t[i])*c[i]) / (T - min_t);
//	}
//	if (sum_C<=C)
//	{
//		cout << "Possible" << endl;
//		cout << fixed << setprecision(4) << (double)min_t << endl;
//	}
//	else
//	{
//		cout << "Impossible" << endl;
//	}
//	return 0;
//}