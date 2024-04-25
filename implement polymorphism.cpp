#include <iostream>  
using namespace std;  

class A {  
    string x; 
	 
    public:  
    	A(){}  
      	A(string i){  
        	x=i;  
        }  
    	void operator+(A);  
    	void display();  
};  
   
void A:: operator+(A a) {  

    string m = x+a.x;  
    cout<<"The result of the addition of two objects is : "<<m;  
}

  
int main()  
{  
    A a1("Lucknow ");  
    A a2("University");  
    a1+a2;  
    return 0;  
}