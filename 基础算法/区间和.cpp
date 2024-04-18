#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3 * 1e5 + 10;

int n, m, x, c, l, r;
int arr[N], srr[N];

vector<int> alls;
vector<pair<int, int>> add, query;

int find(int x)
{
	int l = 0, r = alls.size() - 1, mid = -1;
	
	while (l < r)
	{
		mid = l + r >> 1;
		
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	
	return r + 1;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &c);
		
		add.push_back({x, c});
		
		alls.push_back(x);
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &l, &r);
		
		query.push_back({l, r});
		
		alls.push_back(l), alls.push_back(r);
	}
	
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	for (const auto& ad : add) arr[find(ad.first)] = ad.second;
	
	for (int i = 1; i <= alls.size(); i++) srr[i] = srr[i - 1] + arr[i];
	
	for (const auto& que : query) printf("%d\n", srr[find(que.second)] - srr[find(que.first) - 1]);
	
	return 0;
} 
