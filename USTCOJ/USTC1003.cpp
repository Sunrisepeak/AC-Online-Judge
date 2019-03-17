#include<iostream>
int main()
{
	int n,s,a,b,i;
	while(std::cin>>n)
	{
		s=0;
		a=1;
		b=1;
		if(n>2){
			for(i=3;i<=n;i++)
			{
				s=a+b;
				a=b;
				b=s;
			}
			std::cout<<"The Fibonacci number for "<<n<<" is "<<s<<std::endl;
		}
		else{
			if(n==0)
				std::cout<<"The Fibonacci number for "<<n<<" is "<<0<<std::endl;
			else
				std::cout<<"The Fibonacci number for "<<n<<" is "<<1<<std::endl;
		}	
	}
	return 0;
}
  