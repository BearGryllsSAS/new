#include <bits/stdc++.h>
using namespace std;

const int N = 12;

int n, k;
bool isOk;
int g[N][N];
bool visit[N][N];
vector<int> path;

bool xie[11][11][11][11];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int x, int y)
{
	if (isOk) return;
	if (path.size() == n * n - 1) 
	{
		for (int i = 0; i < path.size(); i++) printf("%d", path[i]);
		
		isOk = true;
		
		return;
	}
	
	for (int i = 0; i < 8; i++)
	{
		int tempX = x + dx[i], tempY = y + dy[i];
		
		if (tempX >= 0 && tempX < n && tempY >= 0 && tempY < n && !visit[tempX][tempY])
		{
			if (xie[x][tempY][tempX][y] || xie[tempX][y][x][tempY]) continue;
			
			if (g[tempX][tempY] == (g[x][y] + 1) % k)
			{
				xie[x][y][tempX][tempY] = true;
				xie[tempX][tempY][x][y] = true;
				visit[tempX][tempY] = true;
				path.push_back(i);
				
				dfs(tempX, tempY);
				
				xie[x][y][tempX][tempY] = false;
				xie[tempX][tempY][x][y] = false;
				visit[tempX][tempY] = false;
				path.pop_back();	
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	
	visit[0][0] = true;
	
	dfs(0, 0);
	
	if (!isOk) cout << -1 << endl;
	
	return 0;
}
