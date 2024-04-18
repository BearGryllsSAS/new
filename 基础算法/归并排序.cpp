#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int arr[N];
int temp[N];

void mergeSort(int l, int r)
{
	if (l >= r) return;
	
	int mid = l + r >> 1;
	
	mergeSort(l, mid), mergeSort(mid + 1, r);
	
	int index = 0, i = l, j = mid + 1;
	
	while (i <= mid && j <= r) temp[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	
	while (i <= mid) temp[index++] = arr[i++];
	while (j <= r) temp[index++] = arr[j++];
	
	for (int i = l, j = 0; i <= r; i++, j++) arr[i] = temp[j];
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	mergeSort(0, n - 1);
	
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	
	return 0;
}
