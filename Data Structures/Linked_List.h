#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Node{
    public: 
        Node<T>* next;
        T data;
        Node(T data, Node<T>* next = NULL) {
            this->data = data;
        }
};

template <class T>
class LinkedList {
    private: 
        Node<T>* head; Node<T>* tail;
        Node<T>* FindLastNode();
        Node<T>* FindPreviousNode(T data);
    public:
        
        LinkedList() {
            head = tail = NULL;
        }
        void Insert(T data);
        void Delete(T data);
        void Search(T data);
        void Print();
};

template <class T>
void LinkedList<T> :: Print()
{

    Node<T>* curr = head;
    while(curr != NULL)
    {
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}

template <class T>
Node<T>* LinkedList<T> :: FindPreviousNode(T data) 
{
    Node<T>* prev = head;
    Node<T>* curr = head->next;

    while(curr != NULL)
    {
        prev = prev->next;
        curr = curr->next;

        if(curr->data = data) break;
    }

    cout << prev->data;
    cout << curr->data;

    return prev;
}

template <class T>
Node<T>* LinkedList<T> :: FindLastNode()
{
    Node<T>* prev = head;
    Node<T>* curr = head->next;
    while(curr != NULL) 
    {
        curr = curr->next;
        prev = prev->next;
    }
    return prev;
}

template <class T>
void LinkedList<T> :: Insert(T data) 
{
    if (head == NULL) 
    {
        head = new Node<T>(data);
        return;
    }

    Node<T>* lastNode = FindLastNode();
    lastNode->next = new Node<T>(data);
}

template <class T>
void LinkedList<T> :: Delete(T data) 
{
    Node<T>* node = FindPreviousNode(data); //return previous node than the one to delete
    // Node<T>* temp = node->next; //the node to delete
    // node->next = temp->next;
    // delete temp;
}