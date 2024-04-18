#include <iostream>
using namespace std;

const int N = 210, INF = 1e9;

int n, m, k, x, y, z;
int d[N][N];

int floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) d[i][j] = INF;
	
	while (m--)
	{
		scanf("%d %d %d", &x, &y, &z);
		
		d[x][y] = min(d[x][y], z);
	}
	
	floyd();
	
	while (k--)
	{
		scanf("%d %d", &x, &y);
		
		printf(d[x][y] > INF / 2 ? "impossible\n" : "%d\n", d[x][y]);
	}
	
	return 0;
}
