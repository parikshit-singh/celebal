/*Write a program to print sum of the following series:

      1 3 5 7 9 11......

      up to n numbers taking only an integer n as input.*/

#include<iostream>
using namespace std;
int main() 
{ 
	int n,i,sum=0; 
	cout<<"enter n\n";  //enter the no. upto which sum is to be calculated
	cin>>n;
	for(i=1;i<=n;i=i+2)  //incremented by 2 for next odd number
	{
	   sum=sum+i;      
	}
	cout << "Sum of nnumbers is : "<<sum<< endl; 
	return 0; 
}
