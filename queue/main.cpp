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
node* last=NULL;
node* Enqueue(node* q,node* newnode)
 {
    if(q==NULL)
    {
        q=newnode;
        last=newnode;
    }
    else
    {
        last=last->next;
        last=newnode;
    }
    cout<<" item added successfully ";
    return q;
}
node* Dequeue (node* q)
 {
    if(q==NULL)
    {
        cout<<"The queue is null";
    }
    else
    {
        node* ptr=q;
        q=q->next;
        delete(ptr);
        cout<<"item deleted successfully";
    }
    return q;
}
void print(node* q)
 {
     node* ptr=q;
    if(q==NULL)
    {
        cout<<"queue is null";
    }
    else
    {
        while(ptr!=NULL)
        {
            cout<<ptr->data;
            ptr=ptr->next;
        }

    }
}
int main()
 {
    node* q=NULL;
    char choice;
     while(true)
     {
        cout<<"\n""a-push\nb-pop\np-print\ne-exit";
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
          case ('a'):
          case ('A'):
           {
              cout << "Enter number :";
		      node* newnode=createnode();
              q=Enqueue(q, newnode);
	       }break;
          case 'b':
          case 'B':
           {

		      q=Dequeue(q);
	       }break;
          case 'P':
          case 'p':
	       {
	     	print(q);
	       }break;
          case 'e':
          case 'E':
            {
                return 0;
            } break;
           default : cout<<"choose a valid operation "<<endl;
           }
        }
    return 0;
}
