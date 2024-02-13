#include<stdio.h>
#include<stdlib.h>
#define N 5

int S1[N], S2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data) {
    if (top1 == N - 1) {
        printf("Queue is full");
    }
    else {
        top1++;
        S1[top1] = data;
    }
}

void push2(int data) {
    if (top2 == N - 1) {
        printf("Queue is full");
    }
    else {
        top2++;
        S2[top2] = data; // Corrected
    }
}

int pop1() {
    return S1[top1--];
}

int pop2() {
    return S2[top2--]; // Corrected
}

void enqueue(int x) {
    push1(x);
    count++;
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue empty");
    }
    else {
        for (int i = 0; i < count; i++) {
            int a = pop1();
            push2(a);
        }
        int b = pop2();
        printf("The Dequeued element is %d\n", b); // Added newline character
        count--;
        for (int i = 0; i < count; i++) {
            int c = pop2();
            push1(c);
        }
     // Updated top2
    }
}
void display() {
    for (int i = 0; i <= top1; i++) {
        printf("%d ", S1[i]); // Added space character
    }
    printf("\n"); // Added newline character
}

int main() {
    int ch,e;
    printf("=========MENU========\n");
    printf("1.Enqueue\n2.Dequeue\n3.display\n");
    do{
    printf("Enter the choice:\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter element to equeue");
            scanf("%d",&e);
            enqueue(e);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
                break;
    }
    }while(ch<=3);
    return 0;
}
