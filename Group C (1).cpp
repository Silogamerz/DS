#include<iostream>
using namespace std;

class Node
{
    public:
    
    int id;
    float amount;
    Node *next;
    
    Node(int val , float amt)
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
        int i;
        for(i=0;i<size;i++)
        {
            HTable[i]=NULL;
        }
    }
    
    void insert(int x , float y)
    {
        int index = hashfunction(x);
        Node *n=new Node(x,y);
        if(HTable[index]==NULL)
        {
            HTable[index]=n;
        }
        else{
            Node *t=HTable[index];
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=n;
        }
    }
    
    void search()
    {
        int flag=0;
        int key;
        
        cout<<"Enter which id to search:";
        cin>>key;
        
        for(int i=0;i<size;i++)
        {
            Node *t=HTable[i];
            while(t!=NULL)
            {
                if(key==t->id)
                {
                    cout<<"\nfound key at : "<<i;
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
        if(flag==0)
            {
                cout<<"\nNot found...";
            }
    }
    
    void del()
    {
        Node *p;
        int flag=0;
        int key;
        
        cout<<"Enter which id to delete:";
        cin>>key;
        
        for(int i=0;i<size;i++)
        {
            Node *t=HTable[i];
            p=NULL;
            
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
                    delete t;
                    flag=1;
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
        if(flag==0)
            {
                cout<<"\nNot found...";
            }
    }

    void display()
    {
        int i;
        for(i=0;i<size;i++)
        {
            Node *t=HTable[i];
            
            cout<<"\n"<<i<<":";
            
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
        }
    }
};

int main()
{
    HashTable h;
    h.insert(10,1000);
    h.insert(21,2000);
    //h.display();
    h.insert(32,3000);
    //h.display();
    h.insert(42,4000);
    //h.display();
    h.del();
    h.display();
    
    return 0;
}