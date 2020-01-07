#include <stdio.h>

#define SIZE 5
#define FALSE 0
#define TRUE 1

int items[SIZE];
int front = -1, rear = -1; //초기 front, rear값

int isFull() {
	if (rear - front == 4)
		return TRUE;
	else
		return FALSE;
}
// Circular Queue가 가득 차 있으면 true, 가득 차 있지 않으면 false

int isEmpty(void) {
	if (front == -1 && rear == -1)
		return TRUE;
	else
		return FALSE;
}
// Circular Queue가 비어 있으면 true, 비어있지 않으면 false

void enQueue(int element)
{
	if (front == -1 && rear == -1)
		front++;
	if (isFull()) {
		printf("Queue가 가득 찼습니다!!\n"); // isFull을 호출하여 가득 차있을 시에는 Queue가 가득 찼습니다를 호출합니다. 	
		printf("\n");
	}
	else {
		rear++;
		items[rear % SIZE] = element; // 큐에 데이터를 삽입합니다. 
		printf("Inserted -> %d\n", element);
	}
}
int deQueue()
{
	if (isEmpty()) {
		printf("Queue가 비었습니다!!\n"); // 만약 큐가 비어있으면 Queue가 비었습니다! 를 출력합니다.
		printf("\n");
	}
	else {
		if (front == rear) {
			printf("Deleted element: %d\n", items[front % SIZE]);
			printf("\n");
			front = -1;
			rear = -1;
		}
		else {
			printf("Deleted element: %d\n", items[front % SIZE]);
			printf("\n");
			front++;
		}
	}
	// 아닐 시에는 element 하나를 빼줍니다. 
	// Deleted element를 출력하고 return해줍니다.
}
void display()
{
	int i;
	if (front == -1 && rear == -1) {
		printf("Queue가 비었습니다! \n");
	}
	else {
		printf("Front값: %d\n", front % SIZE);
		printf("Items 출력: ");
		for (i = front; i <= rear; i++) {
			printf("%d ", items[i % SIZE]);
		}
		printf("\n");
		printf("Rear값: %d\n", rear % SIZE);
		printf("\n");
	}
}
int main()
{
	deQueue();
	enQueue(1);
	enQueue(2);
	enQueue(3);
	display();
	enQueue(10);
	enQueue(5);
	display();
	enQueue(6);
	display();
	deQueue();
	display();
	enQueue(5);
	display();
	deQueue();
	enQueue(8);
	display();
	return 0;
}