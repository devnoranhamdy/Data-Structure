#include <bits/stdc++.h>
using namespace std;
struct node
 {
    int data;
    node* next;
};
node* createnode()
 {
    node* node1=new node();
    node1->next=NULL;
    cin>>node1->data;
    return node1;
}

node* push(node* stack,node* newnode)
 {
    if(stack==NULL)
    {
        stack=newnode;
    }
    else
    {
        newnode->next=stack;
        stack=newnode;
        cout<<" item pushed successfully";
    }

    return stack;
}
node* pop (node* stack)
 {
    node* ptr=stack;
    if(stack==NULL)
    {
        cout<<"The stack is null";
    }
    else
    {
        stack=stack->next;
        delete(ptr);
    }
    return stack;
}
void print(node* stack)
 {
     node* ptr=stack;
    if(stack==NULL)
    {
        cout<<"stack is null";
    }
    else
    {
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }

    }
}
int main()
 {
    node* Mystack=NULL;
    char c;
    while(true)
    {
        cout<<"\na-push\nb-pop\np-print\ne-exit\n";
        cout<<"please enter your choice :";
        cin>>c;
        if(c=='a'||c=='A')
        {
            cout<<"Enter number :";
            node* newnode=createnode();
            Mystack=push(Mystack,newnode);
        }
        else if(c=='b'||c=='B')
        {
            Mystack=pop(Mystack);
        }
        else if(c=='p'||c=='P')
        {
            print(Mystack);
        }
        else if(c=='e'||c=='E')
        {
            return 0;
        }
        else
        {
            cout<<"please enter a valid option";
        }
    }
    return 0;
}
