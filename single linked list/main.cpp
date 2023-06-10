#include <bits/stdc++.h>
using namespace std;
 struct node
   {
    int data;
    node *next;
 };
 node *createnode()
   {
        node* node1=new node ();
        cin>>node1->data;
        node1->next=NULL;
        return node1;
   }
 node* insertnode(node* mylist,node* newnode)
   {
        node* ptr1=NULL;
        node* ptr2=mylist;

       if(mylist == NULL)
      {
        mylist=newnode;
        cout<<"Insert item at first at an empty list \n";
      }

       else if (mylist->data >= newnode->data)
      {
        newnode->next=mylist;
        mylist=newnode;
        cout<<"Insert item at first \n";
      }

       else
      {
        while((ptr2!=NULL) && (ptr2->data<newnode->data))
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(ptr2==NULL)
        {
            ptr1->next=newnode;
            cout<<"Insert item at last \n";
        }
        else
        {
            newnode->next=ptr2;
            ptr1->next=newnode;
            cout<<"Insert item at middle \n";
        }
      }
        return mylist;
    }
 node* deletnode(node* mylist,int value)
   {
    node* ptr1=NULL;
    node* ptr2=mylist;
    if(mylist==NULL)
    {
        cout<<"The list is null\n";
    }
    else if(mylist->data==value)
    {
       ptr1=mylist;
       mylist=mylist->next;
       delete(ptr1);
       cout<<"first Item deleted \n";
    }
    else
    {
        while ((ptr2!=NULL)&&(ptr2->data<value))
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
         if((ptr2==NULL)||(ptr2->data>value))
         {
             cout<<"not found\n";
         }
         else
         {
             ptr1->next=ptr2->next;
             delete(ptr2);
             cout<<"deleted item from middle\n";
         }
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
