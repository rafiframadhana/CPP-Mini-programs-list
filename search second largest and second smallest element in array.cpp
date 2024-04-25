#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	
	cout<<"Enter number of elements: ";
	cin>>n;
	
	int a[n];
	cout<<"Enter the elements of array: "<< endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	sort(a, a+n);
	
	cout<<"The second largest element in array is: "<< a[n-2]<<endl;
	cout<<"The second smallest element in array is: "<< a[1]<<endl;
}
