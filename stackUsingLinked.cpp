#include<iostream>
#include<stdbool.h>
using namespace std;
template<class T> //for class Node
class Node
{
	public:
		T data;
		Node<T> *bottom;
		Node(){}
		Node(T d)
		{
			data = d;
		}
		void display()
		{
			cout<<data;
		}

};

template<class T>
class stack
{
	private:
		Node<T> *top; //begining of the stack
	public:
		stack()
		{
			top = 0; //null pointer
		}
		bool isEmpty()
		{
			return(top == 0);
		}

		//	T getTop();
		void push(T data);
		T pop();
		void displayStack();
};

	template<class T>
void stack<T>::push(T data)
{
	Node<T> *temp = new Node<T>(data);
	if(isEmpty())
	{
		top = temp;
		temp->bottom = 0;
	}	
	else
	{
		temp->bottom = top;
		top = temp;
	}
}
template<class T>

T stack<T>::pop()
{
	if(!isEmpty())
	{	
		Node<T> *temp = new Node<T>;
		temp = top;
		top = top->bottom;
		T temp2;
		temp2 = temp->data;
		delete temp;
		return temp2;
	}
	else
	{
		cout<<"stack underflow!";
		return 0;

	}
}

	template<class T>
void stack<T>::displayStack()
{
	Node<T> *curr = top;
	cout<<"\nTop :\n";
	while(curr != 0)
	{
		cout<<"|\t";
		curr->display();
		cout<<"\t|";
		cout<<"\n";
		curr = curr->bottom;

	}
	for(int y=0;y<17;y++)
		cout<<"-";
	cout<<endl;
}

int main()
{
	stack<int> s;
	cout<<s.isEmpty()<<endl;
	s.displayStack();
	cout<<"\nPushing to stack\n";
	s.push(10);
	s.displayStack();
	s.push(20);
	s.displayStack();
	s.push(30);
        s.displayStack();
	cout<<"\nPopping from stack\n";
	cout<<"popped:"<<s.pop()<<endl;
	s.displayStack();
	cout<<"popped:"<<s.pop()<<endl;
	s.displayStack();
	cout<<"popped:"<<s.pop()<<endl;
	s.displayStack();
	cout<<"popped:"<<s.pop()<<endl;
	return 0;
}
