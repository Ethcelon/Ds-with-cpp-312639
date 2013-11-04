#include<iostream>

using namespace std;

template<class t>
class array
{
	private:
		int m;
		int len;
		t *element;
	public:
		array(){}
		array(int s)
		{
			m=s;
			len=0;
			element=new t [m];
		}
		array(array<t> &b)
		{
			element=new t [5]; 
			for(int i=0;i<5;i++)
				element[i]=b.element[i];
		}

		void setdata(t a[]);
		array<t> operator-(array<t>);
		array<t> operator+(array<t>);
		array<t> operator!();
		array<t> operator*(t);
		void operator+=(t);
		void display();
};

	template<class t>
array<t> array<t>::operator+(array<t> k)
{
	array<t> b(5);
	for(int i=0;i<5;i++)
		b.element[i]=k.element[i]+element[i];
	return b;
}

	template<class t>
array<t> array<t>::operator-(array<t> k)
{
	array<t> b(5);
	for(int i=0;i<5;i++)
		b.element[i]= -k.element[i]+element[i];
	return b;
}

	template<class t>
array<t> array<t>::operator!()
{
	array<t> b(5);
	for(int i=0;i<5;i++)
		b.element[i]=-element[i];
	return b;
}

	template<class t>
array<t> array<t>::operator*(t b)
{
	array k(5);
	for(int i=0;i<5;i++)
		k.element[i]=element[i]*b;
	return k;
}


	template<class t>
void array<t>::operator+=(t b)
{
	for(int i=0;i<5;i++)
		element[i]+=b;
}


	template<class t>
void array<t>::display()
{
	cout<<"\nafter calculation:";
	for(int i=0;i<5;i++)
		cout<<element[i]<<"\t";
}


	template<class t>
void array<t>::setdata(t a[5])
{
	for(int i=0;i<5;i++)
		element[i]=a[i];
}

int main()
{
	array<int> arr1(5);
	int x[5]={10,15,16,19,25};
	arr1.setdata(x);
	array<int> arr2(arr1);
	arr1.display();
	array <int> res(5);
	res=arr1+arr2;
	res.display();
	res=arr1-arr2;
	res.display();
	res=!arr1;
	res.display();
	res=arr1*3;
	res.display();
	arr2+=10;
	arr2.display();
}

