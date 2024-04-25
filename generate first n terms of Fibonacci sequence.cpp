#include<iostream>
using namespace std;

int main(){
	int t1=0, t2=1, t3, n;
	
	cout<<"Enter the n terms: ";
	cin>>n;
	cout<<"Fibonacci series: ";
	
	for(int i=0; i<n; i++){
		if(i<=1){
			t3=i;
		}else{
			t3=t1+t2;
			t1=t2;
			t2=t3;
		}
		cout<<t3<<"  ";
	}
}