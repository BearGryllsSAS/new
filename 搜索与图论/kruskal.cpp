#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

struct Edge
{
	int u, v, w;
	
	bool operator < (const Edge& e) const 
	{
		return w < e.w;
	}
	
} edges[2 * N];

int n, m, u, v, w;
int p[N];

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	
	return p[x];
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		
		edges[i] = {u, v, w};
	}
	
	sort(edges, edges + m);
	
	for (int i = 1; i <= n; i++) p[i] = i;
	
	int res = 0, cnt = 0;
	
	for (int i = 0; i < m; i++)
	{
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		
		int a = find(u), b = find(v);
		
		if (a != b)
		{
			p[a] = b;
			
			res += w, cnt++;
		}
	}
	
	printf(cnt != n - 1 ? "impossible\n" : "%d\n", res);
	
	return 0;
}
