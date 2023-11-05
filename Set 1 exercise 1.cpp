#include<iostream>
using namespace std;

//Enter number
int main (){
	int number;
	int sum=0;
	cout<<"Enter an integer number:";
	cin>>number;
	
	//Calculate the sum
	int nextNumber=number;
	while (number!=0)
	{
		sum+=number%10;
		number/=10;
	}
	
	
	//Display the sum
	while (nextNumber!=0)
	{
	cout<<nextNumber%10;
	nextNumber/=10;
	if (nextNumber!=0)
	{
		cout<<" + ";
	}
		
	}
	cout<<"="<<sum<<endl;
	
	//Check is multiple of 3,4 and 5
	bool multiple3=(sum%3==0);
	bool multiple4=(sum%4==0);
	bool multiple5=(sum%5==0);
	
//Display output

if (multiple3||multiple4||multiple5)
{
	
	if((multiple3&&multiple4)&& !multiple5)
	{
		if (multiple3&&!multiple4)
		{
			cout<<sum<<" is a multiples of 3"<<endl;
		}
		else if (multiple4&&!multiple3)
		{
			cout<<sum<<" is a multiples of 4"<<endl;
		}
		else
		{
			cout<<sum<<" is a multiples if 3 and 4"<<endl;
		}
	}
	else if((multiple4&&multiple5)&& !multiple3)
	{
		cout<<sum<<" is a multiples of 4 and 5"<<endl;
	}
	else if(multiple5&&(!multiple3 && !multiple4))
	{
		cout<<sum<<" is a multiples of 5"<<endl;
	}
	else
	{
	cout<<sum<<" is a multiples of 3, 4 and 5"<<endl;
	}
}

	return 0;	
}
