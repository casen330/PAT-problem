//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main(){
//	string strInput;
//	cin >> strInput;
//	int n = strInput.length();
//	int minUrglyValue = 0;
//	for (int i = 0; i < n-1; i++)
//	{		
//	
//		if (strInput[i] == '?')
//		{
//			if (strInput[i+1]=='A')
//			{
//				strInput[i] = 'B';
//			}
//			else if (strInput[i + 1] == 'B')
//			{
//				strInput[i] = 'A';
//			}
//			else
//			{
//				strInput[i] = 'A';
//			}
//		}		
//	}	
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (strInput[i]==strInput[i+1])
//		{
//			minUrglyValue++;
//		}
//	}
//	cout << minUrglyValue << endl;
//	return 0;
//}