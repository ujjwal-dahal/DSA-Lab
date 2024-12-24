#include <iostream>
using namespace std;

#define maxsize 5

class Stack
{
private:
  int stack[maxsize];
  int top;

public:
  Stack()
  {
    top = -1;
  }

  void push(int value)
  {
    if (top >= maxsize - 1)
    {
      cout << "Stack Overflow i.e Cannot Push This Value : " << value << "." << endl;
    }
    else
    {
      top = top + 1;
      stack[top] = value;
      cout << value << " : Pushed onto the Stack." << endl;
    }
  }

  void pop()
  {
    if (top == -1)
    {
      cout << "No any element to Pop" << endl;
    }

    else
    {
      cout << "Poped Element : " << stack[top] << endl;
      top = top - 1;
    }
  }

  void displayTop()
  {
    if (top < 0)
    {
      cout << "Stack is Empty" << endl;
    }
    else
    {
      cout << "Top Element : " << stack[top] << endl;
    }
  }

  void displayAll()
  {
    if (top < 0)
    {
      cout << "Stack is Empty" << endl;
    }
    else
    {
      cout << "Stack Elements From Top to Bottm is : " << endl;
      for (int i = top; i >= 0; i--)
      {
        cout << stack[i] << endl
             << "____" << endl;
      }

      cout << endl;
    }
  }
};

int main()
{

  Stack stack;
  int choice, value;

  do
  {
    cout << "\n Stack Operations Menu : ";
    cout << "\n 1. Push Operation";
    cout << "\n 2. Pop Operation";
    cout << "\n 3. Display Top Element";
    cout << "\n 4. Display All Elements";
    cout << "\n 5. Exit";

    cout << "\n Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {

    case 1:
      cout << "\n Enter Value to Push : ";
      cin >> value;
      stack.push(value);
      break;

    case 2:
      stack.pop();
      break;

    case 3:
      stack.displayTop();
      break;

    case 4:
      stack.displayAll();
      break;

    case 5:
      cout << " \n Exiting Program !!";
      break;

    default:
      cout << 'Invalid Choise' << endl;
      break;
    }
  } while (choice != 5);

  return 0;
}