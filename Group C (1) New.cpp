#include<iostream>
using namespace std;

class Node
{
    public:
    
    int id;
    float amount;
    Node *next;
    
    Node(int val, float amt)
    {
        id=val;
        amount=amt;
        next=NULL;
    }
};

class HashTable
{
    public:
    
    static const int size = 10;
    Node *HTable[size];
    
    int hashfunction(int key)
    {
        return key%size;
    }
    
    HashTable()
    {
        for(int i=0;i<size;i++)
        {
            HTable[i]=NULL;
        }
    }
    
    void insert(int x, float y)
    {

        int index = hashfunction(x);
        Node *n=new Node(x,y);
        
        if(HTable[index]==NULL)
        {
            HTable[index]=n;
        }
        else
        {
            Node *t=HTable[index];
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=n;
        }
    }
    
    void display()
    {
        for(int i=0;i<size;i++)
        {
            Node *t=HTable[i];
            cout<<i<<":";
            if(t==NULL)
            {
                cout<<"NULL";
            }
            else
            {
                while(t!=NULL)
                {
                    cout<<t->id<<"|"<<t->amount<<"|-->";
                    t=t->next;
                }
            }
            cout<<"\n";
        }
    }
    
    void search()
    {
        int key,flag=0;
        
        cout<<"Which id to search :";
        cin>>key;
        
        for(int i=0;i<size;i++)
        {
            Node *t=HTable[i];
            if(t==NULL)
            {
                cout<<"\nNo entry...";
            }
            else
            {
                while(t!=NULL)
                {
                    if(t->id==key)
                    {
                        cout<<"\nFound at:"<<i;
                        flag=1;
                        break;
                    }
                    else
                    {
                        t=t->next;
                    }
                }
                if(flag==1)
                {
                    break;
                }
            }
        }
        if(flag==0)
        {
            cout<<"\nNot found...";
        }
    }
    
    void del_search()
    {
        int key,flag=0;
        
        cout<<"\nWhich id to delete :";
        cin>>key;
        
        for(int i=0;i<size;i++)
        {
            Node *t=HTable[i];
            Node *p=NULL;
            
            if(t==NULL)
            {
                cout<<"\nNo entry...";
            }
            else
            {
                while(t!=NULL)
                {
                    if(key==t->id)
                    {
                        if(p==NULL)
                        {
                            HTable[i]=t->next;
                        }
                        else
                        {
                            p->next=t->next;
                        }
                        flag=1;
                        delete t;
                        break;
                    }
                    else
                    {
                        p=t;
                        t=t->next;
                    }
                }
                if(flag==1)
                {
                    break;
                }
            }
        }
        if(flag==0)
        {
            cout<<"\nNot found...";
        }
    }
};

int main()
{
    HashTable h;
    int ch;
    char choice;
    int a;
    float b;
    
    do
    {
        cout<<"\n1.Insert\n2.Display\n3.Search\n4.Delete\n";
        cout<<"\nEnter ur choice:";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
            cout<<"\nEnter id:";
            cin>>a;
            cout<<"\nEnter amount:";
            cin>>b;
            
            h.insert(a,b);
            break;
            
            case 2:
            h.display();
            break;
            
            case 3:
            h.search();
            break;
            
            case 4:
            h.del_search();
            break;
        }
        
        cout<<"\nDo u want to continue:";
        cin>>choice;
    }while(choice=='Y'||choice=='y');
}