#include <iostream>
#include <stdexcept>
using namespace std;

#define QUEUE_MAX_SIZE 1000


template <class T>
class Queue
{
    private: 
        int queue[QUEUE_MAX_SIZE];
        int head;
        int tail;

    public: 
        void Enqueue(T);
        T Dequeue();
        void Print();
        bool IsFull();
        bool IsEmpty();
        Queue()
        {
            tail = head = 0;
        }
};

int main()
{
    cout << "Queue Up\n";

    //Variables
    Queue<int> q;

    do {
        int choice;
        cout << "Select and operation\n";

        //Operations
        cout << "1. Enqueue an Element into the queue" << endl;
        cout << "2. Dequeue an element out of the queue" << endl;
        cout << "3. Check if Queue is empty or not" << endl;
        cout << "4. Print the whole queue" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice\n";;
        cin >> choice;

        switch(choice)
        {
            case 1: //Enqueue
            {
                int el;
                cout << "Enter the value for the element\t";
                cin >> el;
                //Push the element into queue
                q.Enqueue(el);

                break;
            }
            case 2: //Dequeue
            {
                int dequeued_element = q.Dequeue();

                break;
            }
            case 3: 
            {
                string x = "The Queue is ";
                x += q.IsEmpty() ? "empty" : "not empty";

                cout << x << endl;
                break;
            }
            case 4: //Print the whole Queue 
            {
                q.Print(); // 
                break;
            }
            case 0: 
                return 0;
        }

    } while(true);
}


template <class T>
void Queue<T> :: Enqueue(T element)
{
    if(IsFull()) 
    {
        throw out_of_range("Queue Empty");
    }
    else
    {
        cout << "Enqueue\n";
        cout << head << " " << tail << endl << element << endl;
        queue[tail++] = element; //incrementing the tail pointer and assigning the element
        cout << head << " " << tail << endl; 
    }
} 

template <class T>
T Queue<T> :: Dequeue()
{
    if(IsEmpty())
    {
        throw out_of_range("Queue Empty");
    }
    else 
    {
        queue[head++] = 0;
    }
}


template <class T>
bool Queue<T> :: IsFull()
{
    return tail == QUEUE_MAX_SIZE;
}

template <class T>
bool Queue<T> :: IsEmpty()
{
    return ((head == tail) && (tail == 0));
}

template <class T>
void Queue<T> :: Print()
{   
    int i;
    cout << head << " " <<  tail << endl;
    cout << "Your Queue goes like this\n";
    for(i = head; i < tail; i++)
    {
        cout << queue[i] << "\n";
    }

    string end_statement = "";
    end_statement = i == 0 ? "Queue Empty" : "Queue End";

    cout << end_statement << endl;  
} 
