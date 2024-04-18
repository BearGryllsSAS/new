#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

long long n;
long long arr[N], srr[N];

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	for (int i = 1; i <= n; i++) srr[i] = srr[i - 1] + arr[i];
	
	long long res = LLONG_MAX;
	
	for (int i = 1; i <= n; i++)
	{
		res = min(res, abs((srr[i] - srr[0]) - (srr[n] - srr[i])));
	}
	
	cout << res << endl;
	
	return 0;
}
