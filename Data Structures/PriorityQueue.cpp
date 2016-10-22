#include <iostream>
#define MAX_QUEUE_SIZE 1000

using namespace std;

class Item
{
    private: 
        int item;
    public:
        int GetItem() { return item };
        int priority;
};

class PriorityQueue
{
    private:
        int Queue[MAX_QUEUE_SIZE];
    public: 
        void Insert(int data);
        int GetHighestPriority();
        void DeleteHighestPriority();
}

int main() 
{
    
}