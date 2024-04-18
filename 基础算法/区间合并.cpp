#include <climits>
#include <vector>
#include <iostream>
using namespace std;

int n, l, r;
vector<pair<int, int>> arr;

int merge()
{
	int res = 0;
	
	int st = INT_MIN, ed = INT_MIN;
	
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].first > ed)
		{
			res++;
			
			st = arr[i].first, ed = arr[i].second;
		}
		else 
		{
			ed = max(ed, arr[i].second);
		}
	}
	
	return res;
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &l, &r);
		
		arr.push_back({l, r});
	}
	
	cout << merge() << endl;
	
	return 0;
}
