#include <iostream>
using namespace std;
#define MAX 100

int front=0,rear=0;
int dq[MAX];

void insert_front()
{
	if(front>0)
	{
		cout<<"Queue Overflow\n";
	}
	else
		cout<<"Insert value to front: ";
		cin>>dq[--front];
}

void insert_rear()
{
	if(MAX<rear)
	cout<<"Queue Overflow\n";
	else
	{
		cout<<"Insert value to rear: ";
		cin>>dq[rear++];
	}
}

void del_front()
{
	if(rear>front)
	cout<<"Deleted element is: "<<dq[front++]<<endl;
	else
	cout<<"Queue Underflow\n";
}

void del_rear()
{
	if(rear>front)
		cout<<"Deleted element is: "<<dq[--rear]<<endl;
		else
		cout<<"Queue Underflow\n";
}

void display()
{   
	int i;
	if(front<rear)
	{
		cout<<"Elements in Queue are: ";
		for(i=front;i<rear;i++)
		{
			cout<<dq[i]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	int ch;
	
	cout<<"1) Insert Front\n";
	cout<<"2) Insert Rear\n";
	cout<<"3) Delete Front\n";
	cout<<"4) Delete Rear\n";
	cout<<"5) Display Queue\n";
	cout<<"6) Exit\n";
	
	do
	{
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			insert_front();
			break;
			
			case 2: 
			insert_rear(); 
			break;
			
			case 3: 
			del_front();
			break;
			
			case 4: 
			del_rear();
			break;
			
			case 5:
			display();
			break;
			
			case 6: 
			cout<<"Exit"<<endl;
			break;
			
			default:
			cout<<"Invalid Choice"<<endl;	
		}
	}
	while(ch!=6);
	return 0;
}

