#include <stdio.h>

#define SIZE 5
#define FALSE 0
#define TRUE 1

int items[SIZE];
int front = -1, rear = -1; //�ʱ� front, rear��

int isFull() {
	if (rear - front == 4)
		return TRUE;
	else
		return FALSE;
}
// Circular Queue�� ���� �� ������ true, ���� �� ���� ������ false

int isEmpty(void) {
	if (front == -1 && rear == -1)
		return TRUE;
	else
		return FALSE;
}
// Circular Queue�� ��� ������ true, ������� ������ false

void enQueue(int element)
{
	if (front == -1 && rear == -1)
		front++;
	if (isFull()) {
		printf("Queue�� ���� á���ϴ�!!\n"); // isFull�� ȣ���Ͽ� ���� ������ �ÿ��� Queue�� ���� á���ϴٸ� ȣ���մϴ�. 	
		printf("\n");
	}
	else {
		rear++;
		items[rear % SIZE] = element; // ť�� �����͸� �����մϴ�. 
		printf("Inserted -> %d\n", element);
	}
}
int deQueue()
{
	if (isEmpty()) {
		printf("Queue�� ������ϴ�!!\n"); // ���� ť�� ��������� Queue�� ������ϴ�! �� ����մϴ�.
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
	// �ƴ� �ÿ��� element �ϳ��� ���ݴϴ�. 
	// Deleted element�� ����ϰ� return���ݴϴ�.
}
void display()
{
	int i;
	if (front == -1 && rear == -1) {
		printf("Queue�� ������ϴ�! \n");
	}
	else {
		printf("Front��: %d\n", front % SIZE);
		printf("Items ���: ");
		for (i = front; i <= rear; i++) {
			printf("%d ", items[i % SIZE]);
		}
		printf("\n");
		printf("Rear��: %d\n", rear % SIZE);
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