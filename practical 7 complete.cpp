#include<iostream>
using namespace std;

struct node{
    int roll;
    char name[10];
    float marks;
    node *next;
};
class LinkedList
{
    node *head;
    public:
    LinkedList()
    {
        head=NULL;
    }
    
    void create()
    {
        char ch;
        node *n,*t;
        
        do{
            n=new node;
            
            cout<<"\nEnter roll no::";
            cin>>n->roll;
            cout<<"\nEnter name::";
            cin>>n->name;
            cout<<"\nEnter marks::";
            cin>>n->marks;
            
            n->next=NULL;
            
            if(head==NULL)
            {
                head=n;
                t=n;
            }
            else{
                t->next=n;
                t=t->next;
            }
            
            cout<<"\nDo u want to continue::";
            cin>>ch;
        }while(ch=='y'||ch=='Y');
    }
    
    void display()
    {
        node *t;
        t=head;
        if(head==NULL)
        {
            cout<<"\nList is empty...";
        }
        else
        {
            while(t!=NULL)
            {
                cout<<t->roll<<"|";
                cout<<t->name<<"|";
                cout<<t->marks<<"|-->";
                t=t->next;
            }
        }
    }
    
    void del_last()
    {
        node *t,*p;
        t=head;
        
        if(head==NULL)
        {
            cout<<"\nList is empty...";
        }
        else
        {
            while(t->next!=NULL)
            {
                p=t;
                t=t->next;
            }
            p->next=NULL;
            delete t;
        }
    }
};

int main()
{
    LinkedList l;
    char choice;
    int ch;
    
    while(true)
    {
        cout<<"\n1.create\n2.display\n3.delete last";
        cout<<"\nEnter ur choice::";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
            l.create();
            break;
            
            case 2:
            l.display();
            break;
            
            case 3:
            l.del_last();
            break;
        }

    }
}