#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    Node* head;
    public:
        LinkedList() : head(NULL){}
        
        void insertAtBeginning(int value){
           Node* newNode = new Node();
           newNode->data = value;
           newNode->next = head;
           head = newNode;
        }
        void insertAtEnd(int value){
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;

            if(!head){
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next){
               temp = temp->next;
            }
            temp->next = newNode;
        }
        void insertAtPosition(int value,int position){
            if(position < 1){
                cout << "the position should be greater than 1"<<endl;
                return;
            }
            if(position == 1){
                insertAtBeginning(value);
                return;
            }
            Node* newNode = new Node();
            newNode->data = value;
            
            Node* temp = head;
            for(int i=1;i<position-1 && temp;i++){
                temp = temp->next;
            }
            if(!temp){
                cout << "Position out of range "<<endl;
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        void deleteFromBeginning(){
            if(!head){
                cout<<"The List is empty"<<endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        void deleteFromEnd(){
            if(!head){
                cout << "The linked List is empty"<<endl;
                return;
            }
            if(!head->next){
                delete head;
                head = NULL;
                return;
            }
            //Go to the second-last node
            Node* temp = head;
            while (temp->next->next){ //The loop stops when the next pointer of the next node to the current is null hence the current node is set to the second last node
                temp = temp->next;
            }
            delete temp->next;
            //set the second last's next pointer to null to make it the last node
            temp->next = NULL;
        }
        void deleteFromPosition(int position){
            if(position < 1){
                cout << "Position must be greater than 1"<<endl;
            }
            if(position == 1){
                deleteFromBeginning();
            }
            Node* temp = head;
            for(int i = 1; i < position -1 && temp;i++){
                temp = temp->next;
            }
            if(!temp || !temp->next){
                cout << "Position out of range"<<endl;
                return;
            }
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }

        void display(){
             if(!head){
                cout << "Linked List is empty"<<endl;
             }
                Node* temp = head;
                while(temp){
                  cout << temp->data << " -> ";
                  temp = temp->next;
                }
                cout << " NULL "<<endl;
        }
};

int main() {
    // Initialize a new linked list
    LinkedList list1;

    // Insert elements at the end
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);

    // Insert element at the beginning
    list1.insertAtBeginning(5);

    // Insert element at a specific position
    list1.insertAtPosition(15, 3);

    cout << "Linked list after insertions: ";
    list1.display();

    // Delete element from the beginning
    list1.deleteFromBeginning();
    cout << "Linked list after deleting from beginning: ";
    list1.display();

    // Delete element from the end
    list1.deleteFromEnd();
    cout << "Linked list after deleting from end: ";
    list1.display();

    // Delete element from a specific position
    list1.deleteFromPosition(2);
    cout << "Linked list after deleting from position 2: ";
    list1.display();

    return 0;
}