#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, num;
int st[N], tt;

int main()
{
	cin >> n;
	
	while (n--)
	{
		scanf("%d", &num);
		
		while (tt && st[tt] >= num) tt--;
		
		if (tt) printf("%d ", st[tt]);
		else printf("-1 ");
		
		st[++tt] = num;
	}
	
	return 0;
}
