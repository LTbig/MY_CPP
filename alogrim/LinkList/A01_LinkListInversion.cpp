#include<iostream>
struct Linklist
{
    int data;
    Linklist * next;
};

Linklist * reverse_list(Linklist * head);

//链表原地逆置的核心代码
Linklist * reverse_list(Linklist * head)
{
    Linklist * new_head = NULL;//指向新链表节点的头指针
    
    while (head)
    {
        Linklist * next = head->next;//保存下一个链表地址
        head->next = new_head;//更新head->next
        new_head = head;//移动new->head

        head = next;//遍历
    }
    
    return new_head;
}

//这里的测试条件有点问题？
int main(int argc, char const *argv[])
{
    Linklist * l1 = new Linklist;
    l1->data = 1;
    Linklist * l2 = new Linklist;
    l1->next = l2;
    l2->data = 2;
    Linklist * l3 = new Linklist;
    l2->next = l3;
    l3->data = 3;
    l3->next = NULL;

    using namespace std;

    cout << "before:\n";

    Linklist * head = l1;

    while (l1)
    {
        cout << "& = " << l1 << ",value = " << l1->data << endl;
        l1 = l1->next;
    }

    cout << endl;

    cout << "after:\n";
    head = reverse_list(head);
    while (head)
    {
        cout << "& = " << head << ",value = " << head->data << endl;
        head = head->next;
    }
    
    //释放内存
    delete(l1);
    delete(l2);
    delete(l3);
    delete(head);

    return 0;
}


