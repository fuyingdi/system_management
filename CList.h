#ifndef CLIST_H_INCLUDED
#define CLIST_H_INCLUDED
#include<string>
#include<map>

using namespace std;

string format_output(string original_string, size_t target_size=15);
class Node
{

public:
    Node();
    Node(string name, string age, string sex);
    void print();
    void set_data(map<string,string> userdata);
    void set_pre(Node *pre);
    void set_next(Node *next);
    map<string,string> data;
    Node *pNext,*pPre;
};


class CList
{
public:
    CList();
    ~CList();
    Node* GetHead();
    Node* GetTail();
    int RemoveHead();
    int RemoveTail();
    int AddTail();
    int AddTail(string name, string age, string sex);
    int AddHead();
    int RemoveAll();
    CList* operator+();
    Node* GetAt(int i);
    void SetAt(int i);
    void RemoveAt(int i);
    void InsertBefore(int i);
    void InsertAfter(int i);
    // find_by_name£¬·µ»ØNode
    Node *Find_by_Name(string data);
    void Print();
private:
    Node *head;
    Node *tail;
    int length = 0;
};

#endif // CLIST_H_INCLUDED
