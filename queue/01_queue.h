#ifndef QUEUE_H_
#define QUEUE_H_
class Customer
{
private:
    long arrive;//arrival time for customer
    int processtime;//processing time for customer
public:
    Customer(){arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}
};

typedef Customer Item;
class Queue
{
private:
    //class scope definitions
        //Node is nested structure definition local to this class
    struct Node
    {
        Item item;
        struct Node * next;
    };
    enum {Q_SIZE = 10};
    //private class members
    Node * front;//pointer to front of Queue
    Node * rear;//pointer to rear of Queue
    int items;//current number of items in Queue
    const int qsize;//maximum number of items in Queue;qsize是常量一般只能对其进行初始化,不能对其赋值,因为qsize是非静态const成员
    //preemptive definitions to prevent public copying
    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) {return *this;}
public:
    Queue(int qs = Q_SIZE);//create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);//add item to end
    bool dequeue(Item & Item);//remove item from front
};
#endif