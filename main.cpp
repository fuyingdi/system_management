/*/////////////////////////////////////////
��Ա����ϵͳ��ʵ����ɾ�Ĳ�Ĺ��ܣ�������洢
*//////////////////////////////////////////

#include <iostream>
#include<string>
#include<stdlib.h>
#include<CList.h>
#include<fstream>
#include<map>

using namespace std;

CList *mainlib=NULL;
size_t default_width = 30;  //���ڸ�ʽ�����
void keep_screen()
{
    char ch;
    cin>>ch;
}
// ʵ��һ�����ڸ�ʽ������ĺ���

class UserInterface
{
    void show_title()
    {
        cout<<"\n\n";
        cout<<format_output("", 35)<<"============================================"<<endl;
        cout<<format_output("", 35)<<format_output("|����")<<format_output("|����")<<format_output("|�Ա�")<<endl;
        cout<<format_output("", 35)<<"============================================"<<endl;
    }
    void show_pad()
    {
        cout<<format_output("", 35)<<"============================================"<<endl;
    }
    void show()
    {
        if(mainlib == NULL)
            cout<<"\n\n\n"<<format_output("", 30)<<"��ǰû����Ա��Ϣ"<<"\n\n\n\n\n\n\n\n"<<endl;
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
        cout<<format_output("", default_width)<<"����Ҫɾ�������֣�"<<endl;
        string name;
        cin>>name;
        Node *target = mainlib->Find_by_Name(name);
        if(target!=NULL)
        {
            //����ͷҲ����β
            if((target->pPre!=NULL)&&(target->pNext!=NULL))
            {
                Node *pre = target->pPre;
                pre->pNext = target->pNext;
                Node *next = target->pNext;
                next->pPre = target->pPre;
                cout<<"�Ȳ���ͷҲ����βɾ��"<<endl;
            }
            //��ͷ
            else if(target->pPre==NULL)
            {
                mainlib->RemoveHead();
                // cout<<"dev: ͷɾ��"<<endl;
            }
            //��β
            else if(target->pNext==NULL)
            {
                mainlib->RemoveTail();
                // cout<<"dev: βɾ��"<<endl;
            }
            // cout<<"dev:";mainlib->Print();
            cout<<"ɾ���ɹ�"<<endl;
            delete target;
            target = NULL;
        }
        else
        {
            cout<<"����Ҫɾ���Ķ��󲻴���"<<endl;
        }
        system("pause");

    }
    void modify()
    {
        cout<<format_output("", default_width)<<"����Ҫ�޸ĵ����֣�"<<endl;
        string name;
        cin>>name;
        Node *target = mainlib->Find_by_Name(name);
        if(target!=NULL)
        {
            show_title();
            target->print();
            cout<<"\n";
            show_pad();
            cout<<"Ҫ�޸ĵ���ϢΪ\n1.����2.����3.�Ա�"<<endl;
            char ch;
            cin>>ch;
            string new_info;
            switch(ch)
            {
            case '1':
                cout<<"������Ϊ:";
                cin>>new_info;
                target->data["1.����"] = new_info;
                break;
            case '2':
                cout<<"������Ϊ:";
                cin>>new_info;
                target->data["2.����"] = new_info;
                break;
            case '3':
                cout<<"���Ա�Ϊ:";
                cin>>new_info;
                target->data["3.�Ա�"] = new_info;
                break;
            }
        }
        else
            cout<<"����"<<endl;

        system("pause");
    }
    void check()
    {
         cout<<format_output("", default_width)<<"����Ҫ��ѯ�����֣�"<<endl;
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
        cout<<format_output("", default_width)<<"----                A.��ʾԱ����Ϣ                ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                S.�����Ա��                  ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                D.ɾ��Ա����Ϣ                ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                F.�޸�Ա����Ϣ                ----"<<endl;
        cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
        cout<<format_output("", default_width)<<"----                G.��ѯָ��Ա����Ϣ            ----"<<endl;
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
            cout<<format_output("", default_width)<<"||                 ��ʾԱ����Ϣ:                    ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            show();break;
        case 'S':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||                 �����Ա��:                      ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            add();break;
        case 'D':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||                ɾ��Ա����Ϣ:                    ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            del();break;
        case 'F':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||                �޸�Ա����Ϣ:                    ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            modify();break;
        case 'G':
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            cout<<format_output("", default_width)<<"||               ��ѯָ��Ա����Ϣ:                  ||"<<endl;
            cout<<format_output("", default_width)<<"------------------------------------------------------"<<endl;
            check();break;
        }

    }
};


int main()
{
    mainlib = new CList;
    mainlib->AddTail("��ӳ��", "24", "animal");
    mainlib->AddTail("fu", "2", "man");
    UserInterface main;
    while(true)
    {
        system("cls");
        main.menu();

    }
}
