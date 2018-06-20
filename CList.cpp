#include<CList.h>
#include<iostream>

// 实现一个用于格式化输出的函数
string format_output(string original_string, size_t target_size)
{
    original_string.resize(target_size, ' ');
    return original_string;
}

CList::CList()
    {
        head = new Node;
        head->set_pre(NULL);
        head->set_next(NULL);
        tail = head;
    }
CList::~CList()
    {
        RemoveAll();
    }
Node *CList::GetHead()
    {
        return head;
    }
Node *CList::GetTail()
    {
        Node *ptr = head;
        for(int i=0;i<length;i++)
        {
            ptr = ptr->pNext;
        }
        return ptr;
    }
int CList::RemoveHead()
    {
        head = head->pNext;
        delete head->pPre;
        head->pPre = NULL;
    }
int CList::ReamoveTail()
    {
        tail = GetTail();
        tail = tail->pPre;
        delete tail->pNext;
    }
CList::AddTail()
    {
        Node* newnode = new Node;
        newnode->pPre = tail;
        newnode->pNext =NULL;
        tail->pNext = newnode;
        tail = newnode;
    }
CList::AddHead()
    {

    }
CList::RemoveAll()
    {

    }
CList *CList::operator+()
    {

    }
Node *CList::GetAt(int i)
    {

    }
void CList::SetAt(int i)
    {

    }
void CList::RemoveAt(int i)
    {

    }
void CList::InsertBefore(int i)
    {

    }
void CList::InsertAfter(int i)
    {

    }
int CList::Find(string data)
    {

    }


Node::Node()
{
    string name,age,sex;
    cout<<"输入名称"<<endl;
    cin>>name;
    cout<<"输入年龄"<<endl;
    cin>>age;
    cout<<"输入性别"<<endl;
    cin>>sex;
    map<string,string> info = {
                    {"1.姓名", name},
                    {"2.年龄", age},
                    {"3.性别", sex}};
    set_data(info);
    cout<<"添加完毕！"<<endl;
}
void Node::print()
    {
        map<string,string>::iterator iter;
        cout<<format_output("", 35);
        for(iter=data.begin();iter!=data.end();++iter)
        {
            cout<<format_output(("|"+iter->second));
        }
    }
void Node::set_data(map<string,string> userdata)
    {
        data = userdata;
    }
void Node::set_pre(Node *pre)
    {
        pPre = pre;
    }
void Node::set_next(Node *next)
    {
        pNext = next;
    }



