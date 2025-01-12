#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (!head) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be greater than 0" << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of range" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        if (temp->prev) {
            temp->prev->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
    }

    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be greater than 0" << endl;
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of range" << endl;
            return;
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
int search(int value) {
    if (!head) {
        return -1; // List is empty
    }

    Node* temp = head;
    int position = 1; // Position starts at 1

    while (temp) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }

    return -1; // Value not found
}

    void display() {
        if (!head) {
            cout << "Doubly Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtPosition(15, 2);
    cout << "Doubly Linked List: ";
    dll.display();

    // dll.deleteFromBeginning();
    // cout << "After deleting from beginning: ";
    // dll.display();

    // dll.deleteFromEnd();
    // cout << "After deleting from end: ";
    // dll.display();

    // dll.deleteFromPosition(2);
    // cout << "After deleting from position 2: ";
    // dll.display();
    int target = 30;
    int pos = dll.search(target);
    if (pos != -1) {
        cout << "Element " << target << " found at position: " << pos << endl;
    } else {
        cout << "Element " << target << " not found in the list" << endl;
    }

    target = 31;
    pos = dll.search(target);
    if (pos != -1) {
        cout << "Element " << target << " found at position: " << pos << endl;
    } else {
        cout << "Element " << target << " not found in the list" << endl;
    }
    return 0;
}
