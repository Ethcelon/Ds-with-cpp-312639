//complex numbers


#include<iostream>
using namespace std;
class complex
{
	private:
		int real,img;
	public:
		void setdata(int r,int i);
		void putdata();
		complex addition(complex c1,complex c2)
		{
			complex c3;
			c3.real = c1.real + c2.real;
			c3.img = c1.img + c2.img;
			return c3;
		}
		
};

void complex::putdata()
	{
		cout<<"complex no. is:"<<real;
		img>=0?cout<<"+"<<img<<"i":cout<<img<<"i";
	}
void complex::setdata(int r,int i)
	{
	real = r;
	img = i;
	}
int main()
	{
	complex c1,c2,c;
	c1.setdata(2,3);
	c2.setdata(1,4);
	c = c.addition(c1,c2);
	c.putdata();
	}
	
		
