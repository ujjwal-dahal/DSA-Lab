// Implementatiom of Linear Queue
/*
Write a Menu driven program to implement linear queue operations.
1. Enqueue
2. Dequeue
3. Display Front Element
4. Display All Elements


|  |  |  |  |  |
F            R

Rear bhaneko Last item ko index
Front bhaneko agadiko index

Initially -> Rear and Front ko Value i.e index same huncha ani Value haldai gaesi "rear" lai increase gardai jane tara front same huncha

initially

#define maxSize 5
front = 0
rear = -1

*/

#include <iostream>

#define maxSize 5

using namespace std;

class Queue
{
private:
  int queue[maxSize];
  int front, rear;
  int item, i;

public:
  Queue()
  {
    front = 0;
    rear = -1;
  }

  void enqueueElement(int userValue)
  {
    if (rear >= maxSize - 1)
    {
      cout << "Queue is Full. We cannot insert your items" << endl;
    }
    else
    {
      rear = rear + 1;
      queue[rear] = userValue;
      cout << "Your Value : " << userValue << " Has Inserted in Queue in Index " << rear << endl;
    }
  }

  void dequeueElement()
  {
    if (front > rear)
    {
      cout << "Queue is Empty so No Element to Remove" << endl;
    }
    else
    {
      item = queue[front];
      front = front + 1;
      cout << "Your Value : " << item << " Has Been Removed From Queue" << endl;
    }
  }

  void displayFrontElement()
  {
    item = queue[front];

    cout << "Front Element is  : " << item << endl;
  }

  void displayAllElements()
  {
    cout << endl
         << "All Elements In Queue Are : " << endl;
    for (i = front; i <= rear; i++)
    {
      cout << queue[i] << endl;
    }
  }
};

int main()
{
  Queue queue;
  int choice;
  int userValue;
  do
  {
    cout << endl
         << "What You Want to Do ? :" << endl;
    cout << "1. Enqueue Element" << endl;
    cout << "2. Dequeue Element" << endl;
    cout << "3. Display Front Element" << endl;
    cout << "4. Display All Elements" << endl;
    cout << "5. Exit " << endl
         << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << endl
           << "Enter Element to Enqueue : " << endl;
      cin >> userValue;
      queue.enqueueElement(userValue);
      break;

    case 2:
      queue.dequeueElement();
      break;

    case 3:
      queue.displayFrontElement();
      break;

    case 4:
      queue.displayAllElements();
      break;

    case 5:
      cout << "Thank You";
      break;

    default:
      cout << "Invalid Choice";
      break;
    }
  } while (choice!=5);


  return 0;
}