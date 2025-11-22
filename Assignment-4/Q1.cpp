// Develop a menu driven program demonstrating the following operations on simple
// Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
// Time Complexity:
// enqueue() - O(1)
// dequeue() - O(1)
// isEmpty() - O(1)
// isFull() - O(1)
// peek() - O(1)
// display() - O(n)
// Space Complexity: O(n)

#include <iostream>
using namespace std;

#define SIZE 100

class Queue
{
  int arr[SIZE];
  int front, rear;

public:
  Queue()
  {
    front = -1;
    rear = -1;
  }

  bool isEmpty()
  {
    return front == -1;
  }

  bool isFull()
  {
    return rear == SIZE - 1;
  }

  void enqueue(int x)
  {
    if (isFull())
    {
      cout << "Queue is Full\n";
      return;
    }
    if (front == -1)
      front = 0;
    arr[++rear] = x;
  }

  void dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty\n";
      return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    if (front == rear)
    {
      front = rear = -1;
    }
    else
    {
      front++;
    }
  }

  void peek()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty\n";
      return;
    }
    cout << "Front Element: " << arr[front] << endl;
  }

  void display()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty\n";
      return;
    }
    for (int i = front; i <= rear; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Queue q;
  int choice, val;
  do
  {
    cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.IsEmpty\n6.IsFull\n7.Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter value: ";
      cin >> val;
      q.enqueue(val);
      break;
    case 2:
      q.dequeue();
      break;
    case 3:
      q.peek();
      break;
    case 4:
      q.display();
      break;
    case 5:
      if (q.isEmpty())
        cout << "Queue is Empty\n";
      else
        cout << "Queue is not Empty\n";
      break;
    case 6:
      if (q.isFull())
        cout << "Queue is Full\n";
      else
        cout << "Queue is not Full\n";
      break;
    case 7:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid Choice\n";
    }
  } while (choice != 7);
  return 0;
}
