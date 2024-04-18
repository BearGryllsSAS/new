#include <cstring>
#include <iostream>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m, u, v, w;
int g[N][N], d[N];
bool in[N];

int prim()
{
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	
	int res = 0;
	
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		
		for (int j = 1; j <= n; j++)
		{
			if (!in[j] && (t == -1 || d[t] > d[j])) t = j;
		}
		
		if (d[t] == INF) return INF;
		
		res += d[t];
		
		in[t] = true;
		
		for (int j = 1; j <= n; j++) d[j] = min(d[j], g[t][j]);
	}
	
	return res;
}

int main()
{
	memset(g, 0x3f, sizeof g);
	
	cin >> n >> m;
	
	while (m--)
	{
		scanf("%d %d %d", &u, &v, &w);
		
		g[u][v] = g[v][u] = min(g[v][u], w);
	}
	
	int res = prim();
	
	printf(res > INF / 2 ? "impossible\n" : "%d\n", res);
	
	return 0;
}
