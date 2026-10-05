#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
struct node *first=NULL;
struct node *last=NULL;
class linked_list
{
public:
    void insert_begin(int);
    void insert_end(int);
    int deletion(int);
    void print(void);
};
void linked_list::insert_begin(int value)
{
    struct node *ptr;
    ptr=new(struct node);
    ptr->info=value;
    if(first==NULL)
    {
        first=last=ptr;
        ptr->next=NULL;
    }
    else
    {
        ptr->next=first;
        first=ptr;
    }
}
void linked_list::insert_end(int value)
{
    struct node *ptr;

    ptr=new(struct node);
    ptr->info=value;
    ptr->next=NULL;
    if(first==NULL)
    {
        first=last=ptr;
    }
    else
    {
        last->next=ptr;
        last=ptr;
    }
}
int linked_list::deletion(int value)
{
    struct node *temp,*loc;

    if(first==NULL)
        return(-9999);

    loc=first;

    if(first->info==value)
    {
        if(first==last)
            first=last=NULL;
        else
            first=first->next;

        delete(loc);
        return(value);
    }

    while(loc!=NULL && loc->info!=value)
        loc=loc->next;

    if(loc==NULL)
        return(-9999);

    temp=first;

    while(temp->next!=loc)
        temp=temp->next;

    temp->next=loc->next;

    if(loc==last)
        last=temp;

    delete(loc);

    return(value);
}

void linked_list::print()
{
    struct node *ptr;

    if(first==NULL)
    {
        cout<<"empty train";
        return;
    }

    cout<<"Train coaches: ";

    for(ptr=first;ptr!=NULL;ptr=ptr->next)
    {
        cout<<"Coach "<<ptr->info;

        if(ptr->next!=NULL)
            cout<<" -> ";
    }
}
int main()
{
    linked_list l;
    int ch,num1,num2;
    do
    {
        cout<<"\n\n1.Add at beginning";
        cout<<"\n2.Add at end";
        cout<<"\n3.Remove a coach";
        cout<<"\n4.Display all coaches";
        cout<<"\n5.Exit";

        cout<<"\nEnter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter coach number:";
                cin>>num1;
                l.insert_begin(num1);
                cout<<"Coach added";
                break;

            case 2:
                cout<<"Enter coach number:";
                cin>>num1;
                l.insert_end(num1);
                cout<<"Coach added";
                break;

            case 3:
                cout<<"Enter coach number to delete:";
                cin>>num1;

                num2=l.deletion(num1);

                if(num2==-9999)
                    cout<<"Coach is not present";
                else
                    cout<<"Coach is deleted";

                break;

            case 4:
                l.print();
                break;

            case 5:
                exit(1);
                break;

            default:
                cout<<"Invalid choice";
        }

    }while(ch!=5);

    return 0;
}
