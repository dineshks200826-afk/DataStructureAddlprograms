#include<iostream>
using namespace std;

class stack
{
    int car[10];
    int top;
public:
    stack()
    {
        top=-1;
    }

    void push(int);
    int pop();
    void display();
};
void stack::push(int value)
{
    top++;
    car[top]=value;
}

int stack::pop()
{
    int temp;

    if(top==-1)
    {
        cout<<"Parking is empty";
        exit(1);
    }

    temp=car[top];
    top--;

    return(temp);
}
void stack::display()
{
    int i;

    if(top==-1)
    {
        cout<<"Parking is empty";
        return;
    }

    cout<<"Cars in parking:";

    for(i=top;i>=0;i--)
    {
        cout<<car[i]<<" ";
    }
}
int main()
{
    stack s;
    int ch,num1,num2;
    do
    {
        cout<<"\n1.Car enters";
        cout<<"\n2.Car leaves";
        cout<<"\n3.Display cars";
        cout<<"\n4.Exit";

        cout<<"\nEnter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter the car number:";
                cin>>num1;

                s.push(num1);

                cout<<"Car entered";
                break;

            case 2:
                num2=s.pop();

                cout<<"The car leaving the parking:"<<num2;
                break;

            case 3:
                s.display();
                break;

            case 4:
                exit(0);
        }
    }while(ch!=4);
    return 0;
}
