#include <bits/stdc++.h>
using namespace std;

int n, res;

bool check(int n)
{
	// ÆæÊý 
	int idx = 1;
	
	while (n)
	{
		if (idx % 2 == 0)
		{
			if ((n % 10) % 2 == 1) return false;
		}
		if (idx % 2 == 1)
		{
			if ((n % 10) % 2 == 0) return false;
		}
		
		idx++;
		n /= 10;	
	} 
	
	return true;
}

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++) if (check(i)) res++;
	
	cout << res << endl;
	
	return 0;
}
