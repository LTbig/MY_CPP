#include "010_stack.h"
//默认的不带参数的构造函数
Stack::Stack()//create an empty stack
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}
//入栈
bool Stack::push(const Item & item)
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
bool Stack::pop(Item & item)
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