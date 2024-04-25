#include<iostream>
using namespace std;

class Hello{
	public:
		Hello(){
			cout<<"Constructor is called"<<endl;
		}
		~Hello(){
			cout<<"Destructor is called"<<endl;
		}
		void display(){
			cout<<"Hello world"<<endl;
		}
};

int main(){
	Hello ob1;
	ob1.display();
}