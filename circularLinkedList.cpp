#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() : head(NULL) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (!head) {
            newNode->next = newNode; // Point to itself
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (!head) {
            newNode->next = newNode; // Point to itself
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
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
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head && position != 2) {
            cout << "Position out of range" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
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
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head) {
            cout << "Position out of range" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
int search(int value) {
    if (!head) {
        return -1; // List is empty
    }

    Node* temp = head;
    int position = 1; // Position starts at 1

    do {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head); // Loop until we circle back to the head

    return -1; // Value not found
}

    void display() {
        if (!head) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtBeginning(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtPosition(15, 2);
    cout << "Circular Linked List: ";
    cll.display();

    // cll.deleteFromBeginning();
    // cout << "After deleting from beginning: ";
    // cll.display();

    // cll.deleteFromEnd();
    // cout << "After deleting from end: ";
    // cll.display();

    // cll.deleteFromPosition(2);
    // cout << "After deleting from position 2: ";
    // cll.display();
   int target = 20;
    int pos = cll.search(target);
    if (pos != -1) {
        cout << "Element " << target << " found at position: " << pos << endl;
    } else {
        cout << "Element " << target << " not found in the list" << endl;
    }

    target = 50;
    pos = cll.search(target);
    if (pos != -1) {
        cout << "Element " << target << " found at position: " << pos << endl;
    } else {
        cout << "Element " << target << " not found in the list" << endl;
    }
    return 0;
}
