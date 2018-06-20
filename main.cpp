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
    void show()
    {
        if(mainlib == NULL)
            cout<<"\n\n\n"<<format_output("", 30)<<"��ǰû����Ա��Ϣ"<<"\n\n\n\n\n\n\n\n"<<endl;
        else
        {
            Node *head = mainlib->GetHead();
            //Node *tail = mainlib->GetTail();
            //cout<<head->pNext;
            cout<<"\n\n";
            cout<<format_output("", 35)<<"============================================"<<endl;
            cout<<format_output("", 35)<<format_output("|����")<<format_output("|����")<<format_output("|�Ա�")<<endl;
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

    UserInterface main;
    while(true)
    {
        system("cls");
        main.menu();
    }
}
