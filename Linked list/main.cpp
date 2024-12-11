#include <iostream>
#include <stdexcept>

using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class Linked_list {
    Node* head;
    Node* tail;
public:
    Linked_list() {
     this->head=NULL;
     this->tail=NULL;}

    Node* GetNode(int _data){
        Node* current = head;
        while (current != NULL) {
            if (current->data == _data)
                return current;
            current = current->next;
        }
        return NULL;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;}
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }}

    void insertAfter(int data, int afterData) {
        Node* preNode = GetNode(data);
        if (preNode == NULL) {
            cout << "Data not found" << endl;
            return;
        }

        Node* newNode = new Node(afterData);
        newNode->next = preNode->next;
        newNode->prev = preNode;
        preNode->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;}
        else {
            newNode->next->prev = newNode;}}

    void insertBefore(int data, int beforeData) {
        Node* curNode = GetNode(data);
        if (curNode == NULL) {
            cout << "Data not found" << endl;
            return;
        }
        Node* newNode = new Node(beforeData);
        newNode->next = curNode;
        newNode->prev = curNode->prev;

        if (curNode->prev != NULL) {
            curNode->prev->next = newNode;

        } else {
            head = newNode;
        }
        curNode->prev = newNode;
    }

    int getcount() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    int getDataByIndex(int index) {
        int countt = 0;
        Node* current = head;
        while (current != NULL) {

            if (countt == index) {
                return current->data;
            }
            current = current->next;
            countt++;
        }
        throw out_of_range("Index out of bounds");
    }

    void display() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};
int main() {
     Linked_list L;

        L.append(10);
        L.append(20);
        L.append(30);
        cout << " List before: ";
        L.display();
        L.insertAfter(30, 35);
        cout << " Insert 30 after 35: " <<endl;
        L.insertAfter(10, 15);
        cout << " Insert 10 after 15: " <<endl;
        L.insertBefore(10, 5);
        cout << " Insert 5 before 10: " <<endl;

        L.insertBefore(100, 50);
        cout<<"------------------"<<endl;
        L.display();
        cout<<"------------------"<<endl;
        cout << "Number of Nodes: " << L.getcount() << endl;
        cout << "Data at index 2: " << L.getDataByIndex(2) << endl;
        cout << "Data at index 10: " << L.getDataByIndex(10) << endl;
    return 0;
}
