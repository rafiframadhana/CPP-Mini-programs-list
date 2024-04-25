#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class CircularLinkedList {
private:
    Node *head, *tail;

public:
    CircularLinkedList() {
        head = tail = NULL;
    }

    void insertAtBegin(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = head;
        if (head == NULL) {
            head = tail = temp;
            temp->next = head;
        } else {
            tail->next = temp;
            head = temp;
        }
    }

    void insertAtEnd(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = head;
        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void deleteFromBegin() {
        if (head == NULL) {
             cout << "The list is empty." << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
             cout << "The list is empty." << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }

    void searchElement(int value) {
        Node *temp = head;
        int index = 0;
        while (temp->next != head) {
            index++;
            if (temp->data == value) {
                 cout << "Element found at index: " << index << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->data == value) {
             cout << "Element found at index: " << index + 1 << endl;
            return;
        }
         cout << "Element not found." << endl;
    }

    void displayList() {
        Node *temp = head;
        if (head == NULL) {
             cout << "The list is empty." << endl;
            return;
        }
        while (temp->next != head) {
             cout << temp->data << "   ";
            temp = temp->next;
        }
         cout << temp->data << endl;
    }
};

int main() {
	int choice, value;
    CircularLinkedList cll;
   
    cout << "1.Insert at Beginning" << endl;
    cout << "2.Insert at the End" << endl;
    cout << "3.Delete from Beginning" << endl;
    cout << "4.Delete from last" << endl;
    cout << "5.Search an element" << endl;
    cout << "6.Display" << endl;
    cout << "7.Exit" << endl;
        
    do{ 
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                cll.insertAtBegin(value);
                break;
            case 2:
                cout << "Enter the value: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 3:
                cll.deleteFromBegin();
                break;
            case 4:
                cll.deleteFromEnd();
                break;
            case 5:
                cout << "Enter the value: ";
                cin >> value;
                cll.searchElement(value);
                break;
            case 6:
                cll.displayList();
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }while(choice != 7);
    return 0;
}
