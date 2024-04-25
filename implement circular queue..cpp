#include<iostream>
using namespace std;
#define MAX 50

// global variables - queue_array, front, rear
int queue[MAX];
int front=0,rear=0;


// Utility to Enqueue an element to the Queue
void enqueue(int num){
	if((rear==MAX-1 && front==0) || (front==rear+1)){
		cout<<"Queue is Full\n";
		return;
	}
	
	if(rear == MAX) // front != 0
		rear = 0;
		rear++;
		queue[rear] = num;
	if(front == 0)
		front=1;
}


// Utility to Dequeue an element from Queue
void dequeue(){
	if(front==0){
		cout<<"Queue is Empty\n";
		return;
	}
	int number;
	number = queue[front];
	queue[front] = INT_MAX;
	
	if(front == rear)
	{
		front = 0;
		rear = 0;
	}
	else if(front == MAX) //rear != MAX-1
		front = 1;
	else
		front++;
	
	cout<<"Dequeued element is: "<<number<<"\n";
}


// Utility to display Front of Queue
void queue_front(){
	if(front == 0){
		cout<<"Queue is Empty\n";
		return;
	}
	cout<<"Front of the queue is : "<<queue[front]<<"\n";
}


// Utility to display Rear of Queue
void queue_rear(){
	if(rear == 0){
		cout<<"Queue is Empty\n";
		return;
	}
	cout<<"Rear of the  queue is : "<<queue[rear]<<"\n";
}


// Utility to display entire Queue
void display(){
	if(front == 0){
		cout<<"Queue is Empty\n";
		return;
	}
	cout<<"Queue elements are : ";
	for(int i=1;i<MAX;i++){
		if(queue[i] == INT_MAX)
			continue;	
		cout<<queue[i]<<" ";
	}
	cout<<"\n";
}


// Driver Code
int main(){
	int ch,val;
	
	for(int i=1;i<MAX;i++)
		queue[i] = INT_MAX;
	
	
		cout<<"1. Enqueue\n2. Dequeue\n3. Display Front\n4. Display Rear\n5. Display queue\n6. Exit\n\n";
	
	do{	
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch){
			case 1:
				cout<<"Insert value : ";
				cin>>val;
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				queue_front();
				break;
			case 4:
				queue_rear();
				break;
			case 5:
				display();
				break;
			case 6:
				cout<<"Exit\n"<<endl;
				exit(0);
			default:
				cout<<"Invalid Choice\n";
				break;	
		}
	}while(ch!=6);
	return 0;
}