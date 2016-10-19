#include <iostream>
#include <limits>
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
        Node() {
            this->data = 0;
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
        Node<T>* DeleteNodeByData(T data);
        void Reverse();
        Node<T>* DeleteNodeByPosition(int pos);
        Node<T>* FindLastNode();
        void Print();
        LinkedList() {
            head = tail = NULL;
        }
};

template <class T>
Node<T>* MergeSortedLists(Node<T> *headA, Node<T>* headB)
{
    Node<T> *head, *tail;
    head = new Node<T>();
    
    if(headA->data > headB->data) {
        head->data = headB->data;
        head->next = NULL;
        tail = head;
        headB = headB->next;
    } else {
        head->data = headA->data;
        head->next = NULL;
        tail = head;
        headA = headA->next;
    }
  while(headA != NULL || headB != NULL) {
      
      int data;
      int dataA, dataB;

      dataA = headA ? headA->data :: numeric_limits<int>::max();
      dataB = headB ? headB->data :: numeric_limits<int>::max();

      if(dataA < dataB) {
          data = headA->data;
          headA= headA->next;
      } else {
          data = headB->data;
          headB = headB->next;
      }
      tail->next = new Node<T>();
      tail->next->data = data;
      tail = tail->next;
      tail->next = NULL;
  }
    
    return head;
}

template <class T>
void LinkedList<T> :: Reverse(){
    Node<T>* curr = head;
    Node<T>* prev;

    while(curr != NULL) {
        Node<T>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;    
    }
    head = prev;
}

template <class T>
Node<T>* LinkedList<T> :: DeleteNodeByData(T data) {
    Node<T>* ptr = head;

    // If Head is null..  list is empty
    if(ptr == NULL) return NULL;

    // head is the required node
    if(ptr->data == data) {
        Node<T>* x = ptr;
        delete ptr;
        head = x->next;
        return x;
    }

    while((ptr->next != NULL) && (ptr->next->data != data)) {
        ptr = ptr->next;    
    }

    if(ptr->next == NULL) return NULL;

    Node<T> * deletedNode;
    if(ptr->next->data == data) {
        deletedNode = ptr->next;
        delete ptr->next;
        ptr->next = ptr->next->next;
        return deletedNode;
    }
}

template <class T>
Node<T>* LinkedList<T> :: DeleteNodeByPosition(int pos){
    Node<T>* ptr = head;

    if(ptr == NULL) return NULL;

    int i = 0;
    while(ptr->next != NULL || i < pos - 1 ) {
        ptr = ptr->next;
    }

    if(i == pos) {
        Node<T>* temp = ptr->next;
        delete ptr->next;
        ptr->next = ptr->next->next;
        return temp;
    }

    return NULL;
}

template <class T>
Node<T>* LinkedList<T> :: DeleteFromHead()
{
    if(head == NULL) return NULL;

    Node<T>* ptr = head;
    head = head->next;
    
    return ptr;
}

template <class T>
Node<T>* LinkedList<T> :: DeleteFromTail() {
    if(head == NULL) return NULL;

    Node<T>* ptr = head;
    while(ptr->next != tail)
    {
        ptr = ptr->next;
    }

    tail = ptr;

    delete ptr->next;

    return tail->next;
}

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
    int choice; string printStatement;

    LinkedList<int> list;

    // Sample Data
    list.InsertAtHead(5);
    list.InsertAtHead(10);
    list.InsertAtHead(15);
    list.InsertAtHead(20);
    list.InsertAtHead(25);

    cout << "LINKED LIST\n";

    while(true) {
        cout << "1. At a node to head\n";
        cout << "2. Add a node to tail\n";
        cout << "3. Delete head\n";
        cout << "4. Delete from tail\n";
        cout << "5. Print List\n";
        cout << "6. Find Last Node\n";
        cout << "7. Delete node by data\n";
        cout << "8. Delete node by position\n";
        cout << "9. Reverse the linked list\n";
        cout << "10. Merge Two Sorted Lists\n";
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
                cout << "Enter data for the node\n";
                cin >> data;
                list.InsertAtTail(data); 
                break;

            case 3: 
            {
                Node<int>* node = list.DeleteFromHead();
                if(node) cout << node->data << " deleted\n";
                break;
            }

            case 4:
            {
                Node<int>* node = list.DeleteFromTail();
                if(node) cout << node->data << " deleted\n";
                break;
            } 

            case 5:
                list.Print();
                break;
            
            case 6:
                list.FindLastNode();
                break;
            case 7:
            {
                cout << "Enter the data\n";
                cin >> data;
                Node<int>* node = list.DeleteNodeByData(data);
                if(node) cout << node->data << " deleted\n";
                break;
            }
            case 8:
            {
                cout << "Enter the position\n";
                cin >> data;
                Node<int>* node = list.DeleteNodeByPosition(data);
                if(node) cout << node->data << " deleted\n";
                break; 
            }
            case 9:
                list.Reverse();
                break;
            case 10:
                {
                    LinkedList<int> listA;
                    listA.InsertAtTail(1);
                    listA.InsertAtTail(3);
                    listA.InsertAtTail(5);
                    listA.InsertAtTail(6);
                    
                    LinkedList<int> listB;  
                    listB.InsertAtTail(2);
                    listB.InsertAtTail(4);
                    listB.InsertAtTail(7);

                    Node<int> *head = MergeSortedLists(listA.head, listB.head);
                    break;
                }
            default: return 0;
        }
    }
}