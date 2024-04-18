#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

char op[2];
int a, b;

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	
	return p[x];
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) p[i] = i;
	
	while (m--)
	{
		scanf("%s %d %d", op, &a, &b);
		
		if (op[0] == 'M')
		{
			p[find(a)] = find(b);
		}
		if (op[0] == 'Q')
		{
			printf(find(a) == find(b) ? "Yes\n" : "No\n");
		}
	}
	
	return 0;
}
