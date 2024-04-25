#include <iostream>
using namespace std;

inline double CtoF(double c) 
{
    return (c*1.8)+32;
}

inline double FtoC(double f) 
{
    return (f-32)*5/9;
}

int main() {
    double n,c,f,result;
    
    cout<<"DEGREE CONVERSION\n\n1.Celsius to Fahrenheit\n2.Fahrenheit to Celsius";
    cout<<"\n\nEnter your choice: ";
    cin>>n;
    
    if(n==1){
    	cout<<"\nEnter degree in celsius: ";
    	cin>>c;
    	result=CtoF(c);
    	cout<<":"<<result<<" F";
	}
	
	else if(n==2){
    	cout<<"\nEnter degree in fahrenheit: ";
    	cin>>f;
    	result=FtoC(f);
    	cout<<":"<<result<<" C";
	}
	
	else{
		cout<<"Invalid Choice";
	}

    return 0;
}

/*  (Another short type)


#include<iostream>
using namespace std;

inline max(int a, int b){
	return (a>b) ? a:b;
}

int main(){
	int a=13, b=90;
	cout<<"The larger value between "<< a <<" and "<< b <<" is "<<max(a,b);
	return 0;
}

*/