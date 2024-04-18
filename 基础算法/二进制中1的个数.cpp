#include <iostream>
using namespace std;

int n, num;
int res;

int lowbit(int n)
{
	return n & -n;
}

int main()
{
	cin >> n;
	
	while (n--)
	{
		scanf("%d", &num);
		
		res = 0;
		
		// for (int i = 0; i < 32; i++) if (num >> i & 1) res++;
		
		while (num) 
		{
			num -= lowbit(num);
			res++;
		}
		
		printf("%d ", res);
	}
	
	return 0;
}
