#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h> 

void Swap(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

int Partition(int arr[], int left, int right)
{
	int i, j;
	i = left;
	j = right;
	int x = arr[left];
	while (1) {
		while (i < j && x <= arr[j])
			j--;
		while (i < j && x >= arr[i])
			i++;
		if (i < j)
			Swap(arr, i, j);
		else {
			Swap(arr, left, j);
			break;
		}
	}
	return j;
}


void QuickSort(int arr[], int left, int right)
{

	if (left < right) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot-1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main()
{
	int n, i;
	int a[100];

	printf("몇개의 숫자로 정렬하시겠습니까?\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		a[i] = rand() % 1000;

	printf("정렬전 배열 : ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	QuickSort(a, 0, n - 1);

	printf("정렬후 배열 : ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}