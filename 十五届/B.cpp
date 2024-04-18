#include <bits/stdc++.h>
using namespace std;

int n;
string d;
vector<int> A;

vector<int> add(const vector<int>& A, const vector<int>& B)
{
	vector<int> C;
	
	int t = 0;
	
	for (int i = 0, j = 0; i < A.size() || j < B.size() || t; i++, j++)
	{
		if (i < A.size()) t += A[i];
		if (j < B.size()) t += B[i];
		
		C.push_back(t % 10);
		
		t /= 10;
	}
	
	return C;
}


int main()
{
	cin >> n >> d;
	
	int k = d.size() - 1;
	while (d[k] != '.') k--;
	d.erase(k, 1);
	
	k = d.size() - k;			// 小数点位数
	
	for (int i = d.size() - 1; i >= 0; i--) A.push_back(d[i] - '0');
	
	while (n--)
	{
		A = add(A, A);
	}
	
	int p = A[k - 1];
	
	reverse(A.begin(), A.end());
	
	while (k--) A.pop_back();
	
	reverse(A.begin(), A.end());
	
	if (p >= 5) A = add(A, {1});
	
	for (int i = A.size() - 1; i >= 0; i--) printf("%d", A[i]);
	
	return 0;
}





//#include <bits/stdc++.h>
//using namespace std;
//
//int n;					// 转换参数 
//string d;				// 浮点数 
//int idx;				// 小数点位数 
//
//vector<int> A;			// 存浮点数 
//vector<int> C(10000000, 0);
//
//// 一个大整数乘一个小整数 
//vector<int> sub1(int n)
//{
//	vector<int> temp;
//	temp.push_back(1);
//	
//	for (int j = 0; j < n; j++)
//	{
//		int t = 0;
//		vector<int> res;
//		
//		for (int i = 0; i < temp.size() || t; i++)
//		{
//			if (i < temp.size()) t += temp[i] * 2;
//		
//			res.push_back(t % 10);
//		
//			t /= 10;
//		}
//	
//		temp = res;	
//	}
//	
//	while (temp.size() > 1 && temp.back() == 0) temp.pop_back();
//	
//	return temp;
//}
//
//vector<int> sub2(vector<int>& A, vector<int>& B)
//{
//	for (int i = 0; i < A.size(); i++)
//		for (int j = 0; j < B.size(); j++)
//			C[i + j] += A[i] * B[j];
//	
//	int lenC = A.size() + B.size() - 1;
//	
//	for (int i = 0; i < lenC; i++)
//	{
//		if (C[i] >= 10)
//		{
//			C[i + 1] += C[i] / 10;
//			C[i] %= 10;
//		}
//	}
//	
//	if (C[lenC]) lenC++;
//	
//	C.resize(lenC);
//	
//	while (C.size() > 1 && C.back() == 0) C.pop_back();
//	
//	return C;
//}
//
//int main()
//{
//	cin >> n >> d;
//	
//	// 处理浮点数
//	for (int i = d.size() - 1; i >= 0; i--)
//	{
//		if (d[i] == '.') 
//		{
//			idx = d.size() - 1 - i;
//			continue;	
//		}
//		A.push_back(d[i] - '0');
//	} 
//	
//	auto B = sub1(n);
//	
//	auto C = sub2(A, B);
//	
//	if (C[idx - 1] <= 4) 
//	{
//		vector<int> res(C.end() - idx, C.end());
//		
//		for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
//	} 
//	else
//	{	
//		vector<int> res(C.begin() + idx, C.end());
//		
//		res[0]++;
//		
//		for (int i = 0; i < res.size() - 1; i++)
//		{
//			if (res[i] >= 10)
//			{
//				res[i + 1] += res[i] / 10;
//				res[i] %= 10;
//			}
//		}
//		
//		if (res[res.size() - 1] >= 10)
//		{
//			int temp = res[res.size() - 1] / 10;
//			res[res.size() - 1] %= 10;
//			
//			res.push_back(temp);
//		}
//		
//		for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
//	}
//	
//	return 0;
//}
