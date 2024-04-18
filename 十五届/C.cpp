#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
long long resA, resB, resC;
long long arr[N];

long long res;

long long lcm(long long a, long long b)
{
	// 先求最大公约数
	long long i = min(a, b);
	for (; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0) break;	
	} 
	
	return a * b / i;
}

long long lcm(long long a, long long b, long long c)
{
	long long temp = lcm(a, b);
	
	int i = max(temp, c);
	
	for (; ; i++)
	{
		if (i % a == 0 && i % b == 0 && i % c == 0) break;
	}
	
	return i;
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%ld", &arr[i]);
	
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				{
					double temp = (double)arr[i] * (double)arr[j] * (double)arr[k] * ((double)lcm(arr[i], arr[j], arr[k]) / (double)(lcm(arr[i], arr[j]) * (double)lcm(arr[j], arr[k]) * (double)lcm(arr[i], arr[k])));
					
					cout << "arr[i] = " << arr[i] << ' ' << "arr[j] = " << arr[j] << ' ' << "arr[k] = " << arr[k] << endl;
					cout << "temp = " << temp << endl;
					
					if (res < temp)
					{
						res = temp;
						
						resA = arr[i], resB = arr[j], resC = arr[k];
					}
				}
	
	cout << resA << ' ' << resB << ' ' << resC << endl;
	
	return 0;
}
