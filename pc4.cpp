//ft n inches 3 constructors default copy parameterized fn addn (2 ob in 1 out) and disp fn


#include<iostream>
#include<stdlib.h>
using namespace std;

class Distance 
{
	private:
		int feet;
		int inches;
	public:
		friend Distance addition(Distance d1,Distance d2);
		
		Distance()
		{
		}
		
		Distance(int ft, int in)
		{
			feet = ft;
			inches = in;
		}
		
		Distance(Distance& d)
		{
			feet = d.feet;
			inches = d.inches;
		}
		void display();
};

//class functions

void Distance::display()
{
	cout<<"The distance is:"<<feet<<"ft and "<<inches<<"in\n";
}

//friend function

Distance addition(Distance d1,Distance d2)
{
	Distance d;
	d.feet = d1.feet + d2.feet;
	d.inches = d1.inches + d2.inches;
	return d;
}

void check(int a, int b)
	{
		try
		{
			if(a < 0 || b < 0)
				throw 1;
		}
		catch(int)
			{
			cout<<"\nNO NEGATIVES!\n";
			exit(0);
			}
	}	
//Main

int main()
{	int a,b;
	cout<<"\nEnter the first distance in > ft in :";
	cin>>a>>b;
	check(a,b);
	Distance d1(a,b);
	//cout<<"\nEnter the second distance in > ft in :";
//	cin>>a>>b;
	//check(a,b);
	Distance d2(d1);
	Distance d3;
        d3 = addition(d1,d2);
	d3.display();
}
	
	
