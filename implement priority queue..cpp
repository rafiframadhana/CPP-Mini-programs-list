#include <iostream>
#include <cstdlib>

using namespace std;
const int MAX = 100;

class PriorityQueue {
private:
    int queue[MAX];
    int front, rear;

public:
    PriorityQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int data, int priority) {
        if (rear >= MAX - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        int i;
        for (i = rear; i >= 0 && priority > queue[i]; i--) {
            queue[i + 1] = queue[i];
        }
        queue[i + 1] = priority;
        queue[i + 2] = data;
        rear++;
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << "Deleted item is: " << queue[rear--] << endl;
    }

    void display() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue with its priority is: " << endl;
        for (int i = front + 1; i <= rear; i++) {
            cout << queue[i + 1] << ".  "<< queue[i + 2]<< endl;
        }
    }
};

int main() {
    int ch, data, priority;
    PriorityQueue pq;

    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
        
    do{
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter data : ";
            cin >> data;
            cout << "Enter its priority: ";
            cin >> priority;
            pq.enqueue(data, priority);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.display();
            break;
        case 4:
        	cout<<"Exit";
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }while(ch != 4);
    return 0;
}
