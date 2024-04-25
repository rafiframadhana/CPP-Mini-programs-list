#include <iostream>
using namespace std;
int queue[100], n = 100, front = 0, rear = 0;

void insert_q() {
   int val;
   if (rear == n)
   	cout<<"Queue Overflow"<<endl;
   else {
      if (front == 0)
      front = 1;
      cout<<"Input for insertion: "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}

void delete_q() {
   if (front == 0 || front > rear) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;
   }
}

void display_q() {
   if (front == 0)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}


int main() {
   int ch;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
   
   do {
      cout<<"\nEnter your choice : ";
      cin>>ch;
      switch (ch) {
         case 1: 
		 insert_q();
         break;
         
         case 2: 
		 delete_q();
         break;
         
         case 3: 
		 display_q();
         break;
         
         case 4: 
		 cout<<"Exit"<<endl;
         break;
         
         default: 
		 cout<<"Invalid choice"<<endl;
      }
   } 
   while(ch!=4);
   return 0;
}