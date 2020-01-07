#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#define INF 999999
#define root -1
#define WHITE -1
#define GRAY 0
#define BLACK 1


void print(int* P, int size) {
	int* stack = (int*)malloc(size * sizeof(int));
	stack[0] = 0;
	int count = 0;
	int final_point = size - 1;
	int finish = size - 1;
	while (finish != 0) {
		stack[0]++;
		stack[stack[0]] = finish;
		finish = P[finish];
	}
	printf("1");
	while (stack[0] != 0) {
		int vertex = stack[stack[0]];
		stack[0]--;
		printf(" %d", vertex + 1);
	}
}

void Bellman_ford(int size, const int** M) {
	int* parent = (int*)malloc(size * sizeof(int)); //배열 동적할당
	int* distance = (int*)malloc(size * sizeof(int)); //배열 동적할당
	int i, j, k, min_value, min_index = 0;
	int fail;
	for (i = 0; i < size; i++) {
		distance[i] = INF;
		parent[i] = root;
	} //초기화
	distance[0] = 0;
	min_value = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			for (k = 0; k < size; k++) {
				if (M[j][k] != INF) {
					if (distance[k] > distance[j] + M[j][k]) {
						distance[k] = distance[j] + M[j][k];
						parent[k] = j;  //값 갱신 
					}

				}
			}
		}
	}
	int* visit = (int*)malloc(size * sizeof(int));
	int* d = (int*)malloc(size * sizeof(int));
	int u;
	for (i = 0; i < size; i++) { //dfs진행 시작
		visit[i] = WHITE;
		d[i] = INF;
	}
	visit[0] = GRAY;
	d[0] = 0;
	int* S = (int*)malloc((size + 1) * sizeof(int));
	S[0] = 1;
	S[1] = 0;
	while (S[0] != 0) {
		u = S[S[0]];
		S[0]--;
		for (i = 0; i < size; i++) {
			if (M[u][i] != INF) {
				if (visit[i] == WHITE) {
					visit[i] = GRAY;
					d[i] = d[u] + M[u][i];
					S[0]++;
					S[S[0]] = i;
				}
			}
		}
		visit[u] = BLACK;
	}  //dfs 진행완료
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (M[i][j] != INF) {
				if (distance[j] > distance[i] + M[i][j]) {
					if (d[i] != INF) { // positive cycle과 출발점의 연결여부 확인
						printf("-1");
						return;
					}
				}
			}
		}
	}
	if (d[size - 1] != INF) {
		print(parent, size);
	}
	else {
		printf("-1");
	}
}

int main() {
	int num_vertex, num_edge;
	int source, dest, dist;
	int i, j, k = 0;
	scanf("%d%d", &num_vertex, &num_edge);
	int** W;
	W = (int**)malloc(num_vertex * sizeof(int*));
	for (i = 0; i < num_vertex; i++)
		W[i] = (int*)malloc(num_vertex * sizeof(int)); //2차원 배열 동적할당
	for (i = 0; i < num_vertex; i++) {
		for (j = 0; j < num_vertex; j++) {
			W[i][j] = INF;  //배열 초기화
		}
	}
	while (k < num_edge) {
		scanf("%d%d%d", &source, &dest, &dist);
		W[source - 1][dest - 1] = -dist; //edge입력
		k++;
	}
	Bellman_ford(num_vertex, W);
	return 0;
}