//Array formula based representation

#include<iostream>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;

template<class T> //class template
class linearList
{
private:
	T *element;
	int maxSize;
	int n; //number of elements
public:
	linearList(int msize = 10);
	~linearList();
	int getMaxSize();	
	bool isEmpty();
	T find(int pos);
	int search(T x);
	void insert(int pos, T x);
	T deleteIt(int pos);
	void display();
};//class linearList

//creation
template<class T>
linearList<T>::linearList(int msize)
{
	maxSize = msize;
	n = 0;
	element = new T[maxSize];
}

//destruction
template<class T>
linearList<T>::~linearList()
{
	delete[] element;		//tocheck;
}

//check for empty
template<class T>
bool linearList<T>::isEmpty()
{
	return(n==0);
}

//Find the element 
template<class T>
T linearList<T>::find(int pos)
{
	if(pos > n)
		return -1;  //check return type
	else
		return(element[pos-1]);
}


//search
template<class T>
int linearList<T>::search(T x)
{
	for(int i=0; i<n; i++)
	{
		if(element[i] == x)
			return(i+1);
	}
	return -1;
}

//insert
template<class T>
void linearList<T>::insert(int pos, T x)
{
	if(n==maxSize)
		cout<<"list is full\n";
	else if(pos>0 && n < maxSize)
	{
		for(int i=n; i>pos-1; i--)
			element[i]=element[i-1];
		element[pos-1]=x;
		n++;
	}
	else
		cout<<"\nsorry, wrong position\n";

}

//delete an element
template<class T>
T linearList<T>::deleteIt(int pos)
{
	if(pos<n)
	{
		T ele = element[pos-1]; //deleted item
		for(int i = pos-1; i<n; i++)
		{
			element[i] = element[i+1];
		}
		n--;
		return ele;
	}

	else
	{
		cout<<"\nsorry! wrong pos\n";
		return -1;
	}
}

//display
template<class T>
void linearList<T>::display()
{
	cout<<"\nThe elements are:\n";
	for(int i=0; i<n; i++)
	{
		cout<<element[i]<<"\t";
	}
}

//main

template<class T>
int linearList<T>::getMaxSize()
{
	return maxSize;
}
int main()
{
	for(int i=0; i<40; i++)
		cout<<"*";
	cout<<"\ntesting with an integer\n";
	linearList<int> l1(5);
	cout<<"\nchecking for empty:"<<l1.isEmpty();
	for(int j=0;j<=l1.getMaxSize();j++)
		{
		l1.insert(j,j);
		}
	l1.display();
	cout<<"\nchecking for empty:"<<l1.isEmpty();
	
	cout<<"\n Trying to find:"<<l1.find(2);
	cout<<"\ndoing a search for 5 in list:"<<l1.search(5);
	cout<<"\ndeleting:"<<l1.deleteIt(3);
	l1.display();

        
	linearList<float> l2;
	cout<<"\ntesting with a float\n";
	cout<<"\nchecking for empty:"<<l2.isEmpty();
        l2.insert(1,2.3);
	l2.insert(2,3.3);
	l2.insert(3,4.3);
        l2.display();
        cout<<"\nchecking for empty:"<<l2.isEmpty();

        cout<<"\n Trying to find:"<<l2.find(2.3);
        cout<<"\ndoing a search for 5 in list:"<<l2.search(5.3);
        cout<<"\ndeleting:"<<l2.deleteIt(3.3);
        l2.display();
	cout<<"\nTESTS SUCCESFULL\n";
	for(int i=0; i<40; i++)
                cout<<"*";

	cout<<endl;
	return 0;

}
