#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int res;
int arr[N];
int myMap[N];

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	for (int i = 0, j = 0; j < n; i++, j++)
	{
		while (j < n && myMap[arr[j]] == 0) myMap[arr[j]]++, j++;
		
		res = max(res, j - i);
		
		while (arr[i] != arr[j])
		{
			myMap[arr[i]]--;
			i++;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
