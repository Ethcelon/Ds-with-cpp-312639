#include<iostream>
#include<stdbool.h>

using namespace std;
template<class T>
class indirect
{
	private:
		int maxSize;
		int length;
		T **table;
	public:
		indirect(int size)
		{
			maxSize = size;
			length = 0;
			table = new T *[maxSize];
		}
	bool isEmpty()
	{
		return(length == 0);
	}
	int search(T key);
	void insert(int, const T&);
	bool Delete(int pos, T &);
	void display();
};

template<class T>
int indirect<T>::search(T key)
{
	for(int i=0; i<length; i++)
		if(key == *table[i])
			return(i++);
	return 0;
}

template<class T>
void indirect<T>::display()
{
	cout<<"The elements of table are:\n";
	for(int i=0; i<length; i++)
	{
		cout<<"\t"<<*table[i];
	}
	cout<<endl;
}

template<class T>
void indirect<T>::insert(int pos, const T &data)
{
	if(pos > 0 && pos <= length+1)
	{
		for(int i=length; i>pos-1; i--)
			table[i]=table[i-1];
		table[pos-1] = new T;
		*table[pos-1] = data;
		length++;
	}
	else
		cout<<"\nWrong Position";
	
}

template<class T>
bool indirect<T>::Delete(int pos, T &data)
{
	if(pos>0 && pos<length)
	{
		data = *table[pos-1];
		for(int i = pos-1; i<length; i++)
			table[i] = table[i++];
		length--;
		return true;
	}
	return false;
}

int main()
{
	indirect<int> I(5);
	I.insert(1,10);
	I.insert(2,20);
	I.insert(3,30);
	I.insert(4,40);
	I.display();
	int a;
	cout<<"Trying to delete element 3.RESULT:"<<I.Delete(3,a);
	cout<<endl;
	I.display();
	cout<<"\nTrying to search for 20:"<<I.search(20);
	return 0;
}

