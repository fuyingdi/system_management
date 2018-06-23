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
    void show_title()
    {
        cout<<"\n\n";
        cout<<format_output("", 35)<<"============================================"<<endl;
        cout<<format_output("", 35)<<format_output("|姓名")<<format_output("|年龄")<<format_output("|性别")<<endl;
        cout<<format_output("", 35)<<"============================================"<<endl;
    }
    void show_pad()
    {
        cout<<format_output("", 35)<<"============================================"<<endl;
    }
    void show()
    {
        if(mainlib == NULL)
            cout<<"\n\n\n"<<format_output("", 30)<<"当前没有人员信息"<<"\n\n\n\n\n\n\n\n"<<endl;
        else
        {
            Node *cursor = mainlib->GetHead();
            //Node *tail = mainlib->GetTail();
            //cout<<head->pNext;
            show_title();
            while(cursor!=NULL)
            {
                cursor->print();
                cout<<endl;
                cursor = cursor->pNext;
            }
            cout<<format_output("", 35)<<"============================================"<<"\n\n\n\n\n\n"<<endl;
        }
        cout<<"\n\n\n\n";
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
        cout<<format_output("", default_width)<<"输入要删除的名字："<<endl;
        string name;
        cin>>name;
        Node *target = mainlib->Find_by_Name(name);
        if(target!=NULL)
        {
            //不是头也不是尾
            if((target->pPre!=NULL)&&(target->pNext!=NULL))
            {
                Node *pre = target->pPre;
                pre->pNext = target->pNext;
                Node *next = target->pNext;
                next->pPre = target->pPre;
                cout<<"既不是头也不是尾删除"<<endl;
            }
            //是头
            else if(target->pPre==NULL)
            {
                mainlib->RemoveHead();
                // cout<<"dev: 头删除"<<endl;
            }
            //是尾
            else if(target->pNext==NULL)
            {
                mainlib->RemoveTail();
                // cout<<"dev: 尾删除"<<endl;
            }
            // cout<<"dev:";mainlib->Print();
            cout<<"删除成功"<<endl;
            delete target;
            target = NULL;
        }
        else
        {
            cout<<"错误：要删除的对象不存在"<<endl;
        }
        system("pause");

    }
    void modify()
    {
        cout<<format_output("", default_width)<<"输入要修改的名字："<<endl;
        string name;
        cin>>name;
        Node *target = mainlib->Find_by_Name(name);
        if(target!=NULL)
        {
            show_title();
            target->print();
            cout<<"\n";
            show_pad();
            cout<<"要修改的信息为\n1.姓名2.年龄3.性别"<<endl;
            char ch;
            cin>>ch;
            string new_info;
            switch(ch)
            {
            case '1':
                cout<<"新姓名为:";
                cin>>new_info;
                target->data["1.姓名"] = new_info;
                break;
            case '2':
                cout<<"新年龄为:";
                cin>>new_info;
                target->data["2.年龄"] = new_info;
                break;
            case '3':
                cout<<"新性别为:";
                cin>>new_info;
                target->data["3.性别"] = new_info;
                break;
            }
        }
        else
            cout<<"返回"<<endl;

        system("pause");
    }
    void check()
    {
         cout<<format_output("", default_width)<<"输入要查询的名字："<<endl;
         string name;
         cin>>name;
         Node *target = mainlib->Find_by_Name(name);
         show_title();
         target->print();
         cout<<"\n";
         show_pad();
         system("pause");
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
    mainlib = new CList;
    mainlib->AddTail("付映迪", "24", "animal");
    mainlib->AddTail("fu", "2", "man");
    UserInterface main;
    while(true)
    {
        system("cls");
        main.menu();

    }
}
