#include <stdio.h>

struct queue
{
    int data;
    int priority;
} q[100], temp;

int front1 = -1, front2 = -1, rear1 = -1, rear2 = -1, size;

void enqueue()
{
    if (rear1 == size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        int data, priority;
        printf("Enter data and priority\n");
        scanf("%d %d", &data, &priority);
        if (front1 == -1)
        {
            front1 = 0;
            front2 = 0;
            q[++rear1].data = data;
            q[++rear2].priority = priority;
        }
        else
        {
            q[++rear1].data = data;
            q[++rear2].priority = priority;
            for (int i = rear2; i > front2; i--)
            {
                if (q[i].priority < q[i - 1].priority)
                {
                    temp = q[i];
                    q[i] = q[i - 1];
                    q[i - 1] = temp;
                }
            }
        }
        display();
    }
}

void dequeue()
{
    if (front1 == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int item = q[front1].data;
        printf("Deleted element: %d\n", item);
        if (front1 == rear1)
        {
            front1 = front2 = rear1 = rear2 = -1;
        }
        else
        {
            front1++;
            front2++;
        }
        display();
    }
}

void display()
{
    if (front1 == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: \n");
        for (int i = front1; i <= rear1; i++)
        {
            printf("%d ", q[i].data);
        }
        printf("\n");
    }
}

void main()
{
    int choice;
    printf("Enter the size of the queue\n");
    scanf("%d", &size);
    do
    {
        printf("Enter your choice 1 for enqueue 2 for dequeue 3 for display 4 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Ending current queue\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
}]
