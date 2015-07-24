/*
this code was written in c++ language
*/

#include <iostream>
#include<iomanip>
#include <math.h>
using namespace std;

double fun (double v)//function to calculate the value of f(x)
{
	double fx; 
	fx=pow(v,3)+2*pow(v,2)+10*v-20;
	return fx;
}

double diff1(double v)//function to calculate the first derivative of f(x)
{
	double f=3*pow(v,2)+4*v+10;
	return f;
}

double diff2(double v)//function to calculate the second derivative of f(x)
{
	double f=6*v+4;
	return f;
}

int main()
{
	int i=0;//counter
	double x[20],f[20];// arrays to save the values of x & f(X)
	x[0]=2;// initial value of Xo

	cout<<endl<<"n"<<setw(20)<<"Xn"<<setw(20)<<"|f(Xn)|"<<endl<<endl;

	while(abs(fun(x[i]))>=0.000000001 && i <20)//the condition to complete the loop
	{		
		f[i]=fun(x[i]);//determine the value of f(x) and assign it to f[i]

			if(i==0)
				x[i+1]=x[i]-(f[i]/(sqrt(pow(diff1(x[i]),2)-f[i]*diff1(x[i]))));
			else 
				if(i==1)
				x[i+1]=x[i]-(f[i]/(sqrt(pow(diff1(x[i]),2)-f[i]*diff2(x[i]))));
			else 
				if(i==2)
				x[i+1]=x[i]-(f[i]/(sqrt(diff1(x[i])-f[i]*6)));//the third derivative of f(x)=6
			else 
				if(i>=3)
				x[i+1]=x[i]-(f[i]/(sqrt(pow(diff1(x[i]),2))));	
			//the derivative of f(x) that greater than 3 equal 0 

			cout<<i<<setw(20)<<x[i]<<setw(20)<<abs(f[i])<<endl;//print the table
			i++;//increment the counter 
	}
	return 0;
} 