#include "01_queue.h"
#include <cstdlib>
//Queue methods
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}
//设置一个显示的析构函数来删除剩余的所有节点
Queue::~Queue()
{
    Node * temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

//Add item to queue
bool Queue::enqueue(const Item & item)
{
    if (isfull())
    {
        return false;
    }
    Node * add = new Node;
    add->item = item;//set node pointers
    add->next = nullptr;
    items++;
    if (front == nullptr)
    {
        front = add;
    }
    else
    {
        rear->next = add;
    }
    rear = add;

    return true;
}

bool Queue::dequeue(Item & item)
{
    if (front == nullptr)
    {
        return false;
    }
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
    {
        rear == nullptr;
    }
    
    return true;
}

//customer method
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
