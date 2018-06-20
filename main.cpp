/*/////////////////////////////////////////
人员管理系统，实现增删改查的功能，用链表存储
*//////////////////////////////////////////

#include <iostream>
#include<string>
#include<stdlib.h>
#include<CList.h>
#include<fstream>
#include<map>

using namespace std;

CList *mainlib=NULL;
size_t default_width = 30;  //用于格式化输出
void keep_screen()
{
    char ch;
    cin>>ch;
}
// 实现一个用于格式化输出的函数

class UserInterface
{
    void show()
    {
        if(mainlib == NULL)
            cout<<"\n\n\n"<<format_output("", 30)<<"当前没有人员信息"<<"\n\n\n\n\n\n\n\n"<<endl;
        else
        {
            Node *head = mainlib->GetHead();
            //Node *tail = mainlib->GetTail();
            //cout<<head->pNext;
            cout<<"\n\n";
            cout<<format_output("", 35)<<"============================================"<<endl;
            cout<<format_output("", 35)<<format_output("|姓名")<<format_output("|年龄")<<format_output("|性别")<<endl;
            cout<<format_output("", 35)<<"============================================"<<endl;
            while(head!=NULL)
            {

                head->print();
                cout<<endl;
                head = head->pNext;
            }
            cout<<format_output("", 35)<<"============================================"<<"\n\n\n\n\n\n"<<endl;
        }
        system("pause");
    }
    void add()
    {
        if(mainlib == NULL)
            mainlib = new CList;
        else
            mainlib->AddTail();
    }
    void del()
    {

    }
    void modify()
    {

    }
    void check()
    {

    }
public:
    void menu()
    {
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                A.显示员工信息                ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                S.添加新员工                  ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                D.删除员工信息                ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                F.修改员工信息                ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                G.查询指定员工信息            ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        char ch;
        cin>>ch;
        if(ch!='a'&&ch!='s'&&ch!='d'&&ch!='f'&&ch!='g')
        {
            system("cls");
            menu();
        }
        ch = toupper(ch);
        system("cls");
        switch(ch)
        {
        case 'A':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||                 显示员工信息:                    ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            show();break;
        case 'S':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||                 添加新员工:                      ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            add();break;
        case 'D':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||                删除员工信息:                    ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            del();break;
        case 'F':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||                修改员工信息:                    ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            modify();break;
        case 'G':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||               查询指定员工信息:                  ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            check();break;
        }

    }
};


int main()
{

    UserInterface main;
    while(true)
    {
        system("cls");
        main.menu();
    }
}
