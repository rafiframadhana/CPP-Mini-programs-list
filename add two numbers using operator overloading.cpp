#include<iostream>
using namespace std;

class addition{
	private:
		int x;
		int y;
		
	public:
		addition(int a, int b){
			x=a;
			y=b;
		}
		
		int operator+(addition ob){
			return (x + ob.x + y + ob.y);
		}
};

int main(){
	addition a1(5, 8), a2(70, 9);
	
	cout<<"Sum = "<<a1+a2;
	return 0;
}
