#include<iostream>
using namespace std;

class Queue{
    int q[5];
    int f,r,size,val;
    
    public:
    Queue(){
        f=-1;
        r=-1;
        size=5;
    }
    
    void enqueue(int val){
        if(r==size-1){
            cout<<"\nqueue overflow...";
        }
        else if(f==-1&&r==-1){
            f++;
            r++;
            q[r]=val;
        }
        else{
            r++;
            q[r]=val;
        }
    }
    
    void dequeue(){
        if(f==-1||f>r){
            cout<<"\nqueue underflow";
        }
        else{
            cout<<"\ndeleted element"<<q[f];
            f++;
        }
    }
    
    void peek(){
        if(f==-1||f>r){
            cout<<"\nqueue underflow";
        }
        else{
            cout<<"\nCurrent element:"<<q[f];
        }
    }
};

int main(){
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    
    q1.dequeue();
    q1.dequeue();
    
    q1.peek();
    
    q1.dequeue();
    
    q1.peek();
    
    return 0;
}