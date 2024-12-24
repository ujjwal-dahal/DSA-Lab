/*
Implementation Of Circular Queue

Q. Write a menu driven Program to implement Circluar Queue Operations
1. Enqueue
2. Dequeue
3. Display Front Element
4. Display All Elements
*/

#include <stdio.h>

#define max 5

struct CircularQueue
{
  int front, rear;
  int queue[max];
};

// Circular Queue lai Initialize Gareki

/*
The circular queue work as follows:

two pointers FRONT and REAR
-> "FRONT" track the first element of the queue
-> "REAR" track the last elements of the queue
initially, set value of FRONT and REAR to -1
*/
void initializeQueue(struct CircularQueue *p)
{
  p->front = -1;
  p->rear = -1;
}

// Circular Queue Full Chaki Chaina
//  REAR = (REAR + 1)%5 = 0 (start of queue)
/*
Example:
Max Size = 5 cha bhane
If Rear ko Index chai 4 cha Kina ki Index Start From 0 & Front ko Index chai 0 cha
so 4 + 1 % 5 == 0 huncha which is same as index of front so Queue Full Cha
*/

/*
If Rear = Index 4 ma cha & Front is in Index 0 then
Rear + 1 = 5 % max ( 5 ) => 0 which is Equal to Front (0) So Circular Queue is Full
*/
int isFull(struct CircularQueue *p)
{
  if ((p->rear + 1) % max == p->front || (p->front == 0 && p->rear == max - 1))
  {
    return 1;
  }
  return 0;
}

// Checking Circular Queue is Empty
int isEmpty(struct CircularQueue *p)
{
  if (p->front == -1)
  {
    return 1;
  }
  return 0;
}

// Enqueue garne i.e Item lai Add garne Circular Queue ma
void enqueue(struct CircularQueue *q, int value)
{

  if (isFull(q))
  {
    printf("\n Circular Queue is Full");
    return; // Added to prevent further execution if the queue is full
  }

  if (isEmpty(q))
  {
    q->front = 0;
    q->rear = 0;
  }
  else
  {
    q->rear = (q->rear + 1) % max;
    /*
    Case 1 : IF Currently Rear chai Index 3 ma cha bhane
    Next Rear chai Jun ma Value halnu cha bhane => 3 + 1 = 4 and 4 % 5(max) == 4

    Case 2 : If Rear chai Last Index ma cha i.e 4 ma bhane as well as Circular Queue chai Full chaina bhane
    Next Index chai abo Initial Index i.e 0 ma hunu paro

    so 4 + 1 = 5 and 5 % 5 == 0 and Next Rear ko Index 0 huncha jaha Value Enqueue huncha
    */
  }

  // Adding Item to the Queue
  q->queue[q->rear] = value;
  printf("\n %d is Added in Circular Queue in Index %d", value, q->rear);
}

// Dequeue i.e Item nikalne

int dequeue(struct CircularQueue *p)
{
  if (isEmpty(p))
  {
    printf("\n Circular Queue is Empty so No Items to Remove");
    return -1;
  }

  int dequeuedElement = p->queue[p->front]; // Get the Front Element

  // Euta matra Element Cha bhane Queue lai Reset garne
  if (p->front == p->rear)
  {
    p->front = -1;
    p->rear = -1;
  }
  else
  {
    // Abo Front lai Agadi badaune
    // Item remove hune bittikai Front index badcha

    p->front = (p->front + 1) % max;
  }

  printf("\n %d Removed From the Circular Queue", dequeuedElement);
  return dequeuedElement;
}

// Front Element Dekhaune
void displayFront(struct CircularQueue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is Empty! No front element.\n");
  }
  else
  {
    printf("Front Element: %d\n", q->queue[q->front]);
  }
}

// Displaying Queue
void displayQueue(struct CircularQueue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is Empty! No elements to display.\n");
    return;
  }

  printf("Elements in the queue: ");
  int i = q->front;

  // Loop through the elements circularly until rear is reached
  while (1)
  {
    printf("%d ", q->queue[i]);
    if (i == q->rear)
    {
      break;
    }
    i = (i + 1) % max;
  }
  printf("\n");
}

// Main function to run the menu-driven program
void main()
{
  struct CircularQueue q; // Declare a CircularQueue instance
  initializeQueue(&q);    // Initialize the queue
  int choice, value;      // Variables to store user choice and input value

  while (1) // Infinite loop to provide menu options
  {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Front Element\n");
    printf("4. Display All Elements\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: // Enqueue operation
      printf("Enter the value to enqueue: ");
      scanf("%d", &value);
      enqueue(&q, value);
      break;

    case 2: // Dequeue operation
      dequeue(&q);
      break;

    case 3: // Display front element
      displayFront(&q);
      break;

    case 4: // Display all elements
      displayQueue(&q);
      break;

    case 5: // Exit the program
      printf("Exiting...\n");
      return;

    default: // Invalid input handling
      printf("Invalid choice! Please try again.\n");
    }
  }
}
