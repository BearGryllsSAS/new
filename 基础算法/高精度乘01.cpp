#include <string>
#include <vector>
#include <iostream>
using namespace std;

string a;
int b;

vector<int> A;

vector<int> mul(const vector<int>& A, int b)
{
	vector<int> C;
	
	int t = 0;
	
	for (int i = 0; i < A.size() || t; i++)
	{
		if (i < A.size()) t += A[i] * b;
		
		C.push_back(t % 10);
		
		t /= 10;
	}
	
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	
	return C;
}

int main()
{
	cin >> a >> b;
	
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	
	auto C = mul(A, b);
	
	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	
	return 0;
}
