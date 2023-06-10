#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *prev;
    int data;
    node *next;
} ;

node* createnode()
{
    node* node1 = new node();
    node1->prev=NULL;
    cin>>node1->data;
    node1->next=NULL;
    return node1;
}

node* insertnode(node* mylist,node* newnode)
{
    node* ptr=mylist;
    if (mylist==NULL)
    {
        mylist=newnode;
        cout << "Insert item at first in empty list  \n";
    }
    else if (mylist->data>=newnode -> data)
    {
        newnode->next=mylist;
        mylist->prev=newnode;
        mylist=newnode;
        cout << "Insert item in none empty list  \n";
    }
    else
    {
        while(ptr->next != NULL&&ptr -> data<newnode-> data)
        {
            ptr=ptr->next;
        }

         if(ptr -> data>= newnode -> data)
        {
            newnode -> next=ptr ;
            newnode->prev=ptr-> prev;
            ptr -> prev->next=newnode;
            ptr -> prev=newnode;
            cout << "Insert item at middle  \n";
        }
        else
        {
            ptr->next=newnode;
            newnode->prev=ptr;
            cout << "Insert item at last  \n";
        }
    }
    return mylist;
}

node* deletnode(node* mylist,int value)
{
    node* ptr=mylist;
    if (mylist==NULL)
    {
        cout << " list is null \n";
    }
    else if (mylist->data== value)
    {
        mylist = mylist->next;
        delete(ptr);
        cout << "first item deleted \n";
    }
    else
    {
        while((ptr->next != NULL)&&(ptr->data< value))
        {
            ptr=ptr->next;
        }

        if ((ptr->next==NULL)&&(ptr->data==value))
        {
            ptr->prev->next=NULL;
            delete(ptr);
            cout<<" last item deleted ";
        }
        else if (ptr->data==value)
        {

            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            delete(ptr);
            cout <<"middle item deleted \n";
        }
        else
            cout<<" not found";
    }
    return mylist;
}

void print(node* mylist)
   {
      node*ptr=mylist;
      if(mylist==NULL)
       {
        cout<<"The list is null\n";
       }
       else
      {
        while (ptr!=NULL)
         {
            cout <<ptr->data<<" ";
			ptr=ptr->next;
         }
      }
    }

int main()
   {
     int value;
     char choice ;
     node* MyList=NULL;
     while(true)
     {
        cout<<"\na- Add node.\nd- Delete node.\np- Print All.\ne- Exit. \n";
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
          case ('a'):
          case ('A'):
           {
              cout << "Enter number :";
		      node* newnode=createnode();
              MyList=insertnode(MyList, newnode);
	       }break;
          case 'd':
          case 'D':
           {
              cout << "Enter number:";
		      cin>>value;
		      MyList=deletnode(MyList,value);
	       }break;
          case 'P':
          case 'p':
	       {
	     	print(MyList);
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
