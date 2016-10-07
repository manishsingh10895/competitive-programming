#include <iostream>
using namespace std;

template <class T>
class Node {
    public: 
        int data;
        Node<T> *next;
        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
};

template <class T>
class LinkedList {
    public:
        Node<T> *head, *tail;

        void InsertAtHead(T data);
        void InsertAtTail(T data);
        Node<T>* DeleteFromHead();
        Node<T>* DeleteFromTail();
        Node<T>* FindLastNode();
        void Print();
        LinkedList() {
            head = tail = NULL;
        }
};

template <class T>
void LinkedList<T> :: InsertAtHead(T data)
{
    if(head == NULL) {
        head = new Node<T>(data);
        tail = head;
        return;
    }

    Node<T> *ptr = new Node<T>(data);
    ptr->next = head;
    head = ptr;

    return;
}

template <class T>
Node<T>* LinkedList<T> :: FindLastNode() 
{
    Node<T> *ptr = head;
    Node<T> *curr = head->next;
    while(curr !=NULL) {
        curr = curr->next;
        ptr = ptr->next; 
    }

    cout << "The last node is \t";
    cout << ptr->data << "\n";  
    return ptr;
}

template <class T>
void LinkedList<T> :: InsertAtTail(T data) 
{
    if(head == NULL) {
        head = new Node<T>(data);
        tail = head;
        return;
    }

    Node<T> *ptr = new Node<T>(data);

    tail->next = ptr;
    tail = tail->next;
}

template <class T>
void LinkedList<T> :: Print()
{
    cout << endl;
    Node<T> *ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int choice, string printStatement;

    LinkedList<int> list;

    cout << "LINKED LIST\n";

    while(true) {
        cout << "1. At a node to head\n";
        cout << "2. Add a node to tail\n";
        cout << "3. Delete head\n";
        cout << "4. Delete from tail\n";
        cout << "5. Print List\n";
        cout << "6. Find Last Node\n";
        cout << "\n 0. Exit\n";

        cout << "Enter your choice\n";
        cin >> choice;

        int data; 

        switch(choice) {
            case 1: 
                cout << "Enter the data for the node\n";
                cin >> data;
                list.InsertAtHead(data);
                break;

            case 2: 
                break;

            case 3: 
                break;

            case 4: 
                break;

            case 5:
                list.Print();
                break;
            
            case 6:
                list.FindLastNode();
                break;

            default: return 0;
        }
    }
}