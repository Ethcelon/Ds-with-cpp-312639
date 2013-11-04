#include<iostream>
#include<stdbool.h>
using namespace std;

template<class T>

class stack
{
	private:
		int maxSize;
		int top;
		T *element;
	public:
		stack(int size)
		{
			maxSize = size;
			top = -1;
			element = new T (maxSize);
		}

		bool isEmpty()
		{
			if(top == -1)
				return true;
			else
				return false;
		}

		bool isFull()
		{
			return top == (maxSize-1);
		}

		bool getTop()
		{
			if(!isEmpty())
				return element[top];
		}

		void push(T data)
		{	
			if(!isFull())
			{
				top++;
				element[top] = data;
			}
			else
				cout<<"\nSTACK OVERFLOW\n";
		}
		T pop()
		{
			if(!isEmpty())
			{
				T data = element[top];
				top--;
				return data;
			}
			else 
				cout<<"\nStack underflow";
				return 0;
		}
};//class over

int main()
{
	stack<int> s(5);
	cout<<"checking empty:"<<s.isEmpty();
	cout<<"\npushing to the stack : 10, 20, 30, 40, 50, 60\n";
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);	
	
	cout<<"\npop-ing from stack\n";
	cout<<s.pop()<<"\t"<<s.pop()<<"\t"<<s.pop()<<"\t"<<s.pop()<<"\t"<<s.pop()<<"\t"<<s.pop()<<"\t";
	cout<<"\nSUCCESS!\n";
	return 0;
}
