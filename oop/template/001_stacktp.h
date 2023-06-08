#ifndef STACKTP_H_
#define STACKTP_H_


template <class Type>
class Stack
{
private:
    enum {MAX = 10};//constan specific to class
    Type items[MAX];//holds stack items
    int top;//index for top stack item
public:
    Stack();
    // ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Type & item);//add item to stack
    bool pop(Type & item);//pop top into item
};

template <class Type>
Stack<Type>::Stack()//create an empty stack
{
    top = 0;
}
template <class Type>
bool Stack<Type>::isempty() const
{
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull() const
{
    return top == MAX;
}
//入栈
template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < MAX)
    {
        items[top++] = item;//先入栈,然后top+1
        return true;
    }
    else
    {
        return false;
    }
}
//出栈
template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top];//top先减一,然后出栈
        return true;
    }
    else
    {
        return false;
    }
    
}
#endif