#include <stdio.h>

#define maxSize 5

// Structure to represent the queue
struct Queue
{
    int queue[maxSize];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q)
{
    q->front = 0;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* q)
{
    return q->rear >= maxSize - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q)
{
    return q->front > q->rear;
}

// Function to enqueue an element into the queue
void enqueueElement(struct Queue* q, int userValue)
{
    if (isFull(q))
    {
        printf("Queue is Full. We cannot insert your item.\n");
    }
    else
    {
        q->rear++;
        q->queue[q->rear] = userValue;
        printf("Your Value: %d has been inserted in Queue at Index %d\n", userValue, q->rear);
    }
}

// Function to dequeue an element from the queue
void dequeueElement(struct Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty, no element to remove.\n");
    }
    else
    {
        int item = q->queue[q->front];
        q->front++;
        printf("Your Value: %d has been removed from Queue.\n", item);
    }
}

// Function to display the front element of the queue
void displayFrontElement(struct Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Front Element is: %d\n", q->queue[q->front]);
    }
}

// Function to display all elements in the queue
void displayAllElements(struct Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("\nAll Elements in Queue are:\n");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d\n", q->queue[i]);
        }
    }
}

int main()
{
    struct Queue queue;
    initializeQueue(&queue);

    int choice;
    int userValue;

    do
    {
        printf("\nWhat do you want to do?\n");
        printf("1. Enqueue Element\n");
        printf("2. Dequeue Element\n");
        printf("3. Display Front Element\n");
        printf("4. Display All Elements\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Element to Enqueue: ");
            scanf("%d", &userValue);
            enqueueElement(&queue, userValue);
            break;

        case 2:
            dequeueElement(&queue);
            break;

        case 3:
            displayFrontElement(&queue);
            break;

        case 4:
            displayAllElements(&queue);
            break;

        case 5:
            printf("Thank you!\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
