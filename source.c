#pragma warning(disable: 4996)
#include <stdio.h>

#define INF 99
#define N 5
#define Visited 1
#define Unvisited 0

int W[N][N]; //�ʱ� N*N ��� ���¿� �׷����� �Էµ˴ϴ�.

int find_min(int V[], int R[]); //�湮���� ���� �ε��� �� �ּ� ���� ���� �ε��� return

void dijkstra(int n, const int W[][N]) {
	int visit[N], dist[N], parent[N], result[N]; //�������Լ��� � ������ �� �𸣰ھ �迭�� ��ü
	int min_index, min_value;
	int i, j, count = 0;
	for (i = 0; i < n; i++) {
		dist[i] = W[0][i];
		if (dist[i] != INF)
			parent[i] = 0;
		else {
			parent[i] = -1;
			count++;
		}
		visit[i] = Unvisited;
		result[i] = dist[i];
	} 
	visit[0] = Visited;
	parent[0] = -(N - count);
	
	for (i = 1; i < n; i++) {
		count = 0;
		min_index = find_min(visit, result);
		min_value = result[min_index];
		visit[min_index] = Visited;
		
		for (j = 0; j < n; j++) {
			dist[j] = W[min_index][j];
			if (result[j] > min_value + dist[j]) {
				result[j] = min_value + dist[j];
				parent[j] = min_index;
			}
			if (parent[j] == -1)
				count++;
		}
		parent[0] = -(N - count);
	}
	printf("������ ���� F�� ��� \n");
	for (i = N - 1; i >= 1; i--) {
		printf("(v%d - v%d) \n", parent[i] + 1, i+1);
	}
	
}

int find_min(int V[], int R[]) {
	int min, min_index, k;
	int count = 0;
	for (k = 0; k < N; k++) {
		if (V[k] != 1) {
			if (count == 0) {
				min = R[k];
				min_index = k;
				count++;
			}
			if (R[k] < min) {
				min = R[k];
				min_index = k;
			}
		}
	}
	return min_index;
}

int main()
{
	int i, j;
	int W[N][N];
	printf("����ġ �׷����� ���ҵ��� �Է��ϼ��� : \n");
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			scanf("%d", &W[i][j]);
		}
	printf("\n");
	dijkstra(N, W);
	return 0;
}