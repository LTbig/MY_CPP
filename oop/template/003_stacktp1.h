#ifndef STACKTP1_H_
#define STACKTP1_H_

template <class Type>
class Stack
{
private:
    enum {SIZE = 10};//constan specific to class
    int stacksize;
    Type * items;//holds stack items
    int top;//index for top stack item
public:
    explicit Stack(int ss = SIZE);//explict 避免隐式转换
    Stack(const Stack & st);
    ~Stack(){delete [] items;};
    bool isempty(){return top == 0;}
    bool isfull(){return top == stacksize;}
    bool push(const Type & item);//add item to stack
    bool pop(Type & item);//pop top into item
    Stack & operator=(const Stack & st);
};

template <class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0)//create an empty stack
{
    items = new Type [stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack & st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for (int i = 0; i < top; i++)
    {
        items[i] = st.items[i];
    } 
}
//入栈
template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < stacksize)
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
template<class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
    if (this == &st)
    {
        return * this;
    }
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for (int i = 0; i < top; i++)
    {
        items[i] = st.items[i];
    }
    
    return *this;
}
#endif