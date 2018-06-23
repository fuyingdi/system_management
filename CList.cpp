#include<CList.h>
#include<iostream>
#include<stdlib.h>

// ʵ��һ�����ڸ�ʽ������ĺ���
string format_output(string original_string, size_t target_size)
{
    original_string.resize(target_size, ' ');
    return original_string;
}

CList::CList()
    {
        head = new Node{"�����", "10", "��"};
        //head = new Node;
        head->set_pre(NULL);
        head->set_next(NULL);
        tail = head;
    }
CList::~CList()
    {
        RemoveAll();
    }
void CList::Print()
{
    Node *cursor = head;
    while(cursor!=0)
    {
        cout<<cursor<<"->";
        cursor = cursor->pNext;
    }
    cout<<" -end-"<<endl;
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
        // delete head->pPre;
        head->pPre = NULL;
        // cout<<"dev:ɾ��ͷ�ɹ�"<<endl;
        return 1;
    }
int CList::RemoveTail()
    {
        tail = tail->pPre;
        // delete tail->pNext;
        tail->pNext = NULL;
        // cout<<"dev:ɾ��β�ɹ�"<<endl;
        return 1;
    }
CList::AddTail()
    {
        Node* newnode = new Node;
        newnode->pPre = tail;
        newnode->pNext =NULL;
        tail->pNext = newnode;
        tail = newnode;
    }
CList::AddTail(string name, string age, string sex)
{
    Node* newnode = new Node{name, age, sex};
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
Node *CList::Find_by_Name(string name)
    {
        int i = 0;
        Node *cursor = head;
        while(cursor!=NULL)
        {
            auto iter = cursor->data.find("1.����");
            //cout<<"dev:find"<<iter->second<<endl;
            if(iter!=cursor->data.end())
            {
                if(iter->second==name)
                {
                    // cout<<"dev:finded:"<<name<<endl;
                    return cursor;
                }
            }
            else i++;
            cursor=cursor->pNext;
        }
        cout<<"����ʧ�ܣ������ڴ���Ϣ"<<endl;
        return NULL;
    }


Node::Node()
{
    string name,age,sex;
    cout<<"��������"<<endl;
    cin>>name;
    cout<<"��������"<<endl;
    cin>>age;
    cout<<"�����Ա�"<<endl;
    cin>>sex;
    map<string,string> info = {
                    {"1.����", name},
                    {"2.����", age},
                    {"3.�Ա�", sex}};
    set_data(info);
    cout<<"�����ϣ�"<<endl;
}
Node::Node(string name, string age, string sex)
{
    map<string,string> info = {
                    {"1.����", name},
                    {"2.����", age},
                    {"3.�Ա�", sex}};
    set_data(info);
    // cout<<"dev:add"<<endl;
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
ostream& operator<<(ostream &out, const Node& node)
{
    map<string, string> data;
    data = node.data;
    out<<data["1.����"].c_str();
}



