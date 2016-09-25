#include <iostream>
#include <stdexcept>
using namespace std;
#define MAX_STACK_SIZE 1000


template <class T>
class Stack 
{
    private: 
        T stack[MAX_STACK_SIZE];
        int stack_pointer;

    public: 
        void Push(T);
        T Pop();
        bool IsFull();
        bool IsEmpty();
        void Print();
        Stack()
        {
            stack_pointer = 0;
        }
};

int main()
{
    cout << "Stack Up\n";

    //Variables
    Stack<int> stack;

    do {
        int choice;
        cout << "Select and operation\n";

        //Operations
        cout << "1. Push and Element into the stack" << endl;
        cout << "2. Pop an element out of the stack" << endl;
        cout << "3. Check if Stack is empty or not" << endl;
        cout << "4. Print the whole stack " << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice\n";;
        cin >> choice;

        switch(choice)
        {
            case 1: //Push
            {
                int el;
                cout << "Enter the value for the element\t";
                cin >> el;
                //Push the element into stack array
                stack.Push(el);

                break;
            }
            case 2: //Pop 
            {
                int popped_element = stack.Pop();

                break;
            }
            case 3: 
            {
                string x = "The stack is ";
                x += stack.IsEmpty() ? "empty" : "not empty";

                cout << x << endl;
                break;
            }
            case 4: //Print the whole stack 
            {
                stack.Print(); // 
                break;
            }
            case 0: 
                return 0;
        }

    } while(true);
}

template <class T>
bool Stack<T> :: IsFull()
{
    return stack_pointer == MAX_STACK_SIZE;
}

template <class T>
void Stack<T>:: Push(T element)
{
    if(IsFull())
    {
        throw out_of_range("Stack Overflow");
    }
    
    stack[stack_pointer++] = element; //incrementing the stack_pointer and assigning element to the top 
}

template <class T>
T Stack<T> :: Pop()
{
    if(IsEmpty())
    {
        throw out_of_range("Stack Empty");
    }
    else 
    {
        stack[stack_pointer--] = 0;
    }
}

template <class T>
bool Stack<T> :: IsEmpty()
{
    return stack_pointer == 0;
}

template <class T>
void Stack<T> :: Print()
{   
    int i;
    cout << "Your stack goes like this\n";
    for(i = 0; i < stack_pointer; i++)
    {
        cout << stack[i] << "\n";
    }

    string end_statement = "";
    end_statement = i == 0 ? "Stack Empty" : "Stack End";

    cout << end_statement << endl;  
} 
