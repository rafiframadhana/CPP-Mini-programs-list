#include<iostream>
using namespace std;

bool isPrime(int n){
	for(int i=2 ; i*i<=n; i++){
		if(n%i==0)
			return false;
	}
	return true;
}

int main (){
	int n;
	
	cout<<"Enter the upper limit: ";
	cin>>n;
	
	cout<<"Prime numbers between 1 and "<< n <<" is : ";
	
	for(int i=2; i<=n; i++){
		if(isPrime(i))
			cout<<i<<" ";
	}cout<<endl;
}
