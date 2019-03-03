#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
    node(int a,node* b){
        data = a;
        next = b;
    }
};

typedef struct node* link;

class Stack{
    public:
        Stack(int max);
        bool push(int data);
        void pop();
        void display();

    private:
        link top;
        link head;
        int size;
        int capacity;
};

Stack::Stack(int max){
    top = head = NULL;
    size =0;
    capacity = max;
}

bool Stack::push(int data){
    if(size>capacity){
        cout<<"Stack is full. Cannot add more items\n";
        return false;
    }
    link temp = new node(data,NULL);
    if(temp==NULL)
        return false;
    if(top==NULL){
        top = head= temp;
        size++;
        return true;
    }
    top->next = temp;
    top = temp;
    size++;
    return true;
}

void Stack::pop(){
    if(size==0){
        cout<<"Stack is empty\n";
        return;
    }
    link temp=head;
    while(temp->next!=top){
        temp =temp->next;
    }
    temp->next = NULL;
    top = temp;
    size--;
}

void Stack::display(){
    if(size==0)
        cout<<"Stack is empty\n";
    link temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Stack* s = new Stack(10);
    s->push(001);
    s->push(002);
    s->push(303);
    s->display();
    s->pop();
    s->display();
}