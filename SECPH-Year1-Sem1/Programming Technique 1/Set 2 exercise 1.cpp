#include<iostream>
using namespace std;

int main(){
	int number;
	int sum=0;
	cout<<"Enter an integer number : ";
	cin>>number;
	
	// Calculate sum
	int nextNumber=number;
	
	while (number!=0)
	{
		sum+=(number%10);
		number/=10;
	}
	
	//Display sum
	while (nextNumber!=0)
	{
		if (nextNumber!=0)
		{
			cout<<nextNumber%10;
			cout<<"+";
			nextNumber/=10;
		}	
	}
	cout<<"="<<sum<<endl;
	
	//Determine number
	bool remainder=(sum%2!=0);
	bool multiples4=(sum%4==0);
	bool multiples5=(sum%5==0);
	
	if (remainder)
	{
		cout<<sum<<" is odd number";
	
		if (multiples5)
		{
			cout<<" & multiples of 5";
		}
	}
	else
	{
		cout<<sum<<" is even number ";
		if (multiples4)
		{
			cout<<"& multiples of 4"; 
			if (multiples5)
			{
				cout<<" and 5";
			if (!multiples5)
			{
				cout<<" & multiples of 5";
			}
			}
		}
		
	}
	return 0;
}	
