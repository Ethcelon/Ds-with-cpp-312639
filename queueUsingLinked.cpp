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
class queue
{
	private:
		Node<T> *top; //begining of the queue
	public:
		queue()
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
		void displayQueue();
};

	template<class T>
void queue<T>::push(T data)
{
	Node<T> *temp = new Node<T>(data);
	if(isEmpty())
	{
		top = temp;
		temp->bottom = 0;
	}	
	else
	{
		Node<T> *curr = top;
        while(curr->bottom !=0)
            curr = curr->bottom;
        curr->bottom = temp;
	}
}
template<class T>

T queue<T>::pop()
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
		cout<<"\tqueue empty!!!\t";
		return 0;

	}
}

	template<class T>
void queue<T>::displayQueue()
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
	queue<int> s;
	cout<<s.isEmpty()<<endl;
	s.displayQueue();
	cout<<"\nPushing to queue\n";
	s.push(10);
	s.displayQueue();
	s.push(20);
	s.displayQueue();
	s.push(30);
        s.displayQueue();
	cout<<"\nPopping from queue\n";
	cout<<"popped:"<<s.pop()<<endl;
	s.displayQueue();
	cout<<"popped:"<<s.pop()<<endl;
	s.displayQueue();
	cout<<"popped:"<<s.pop()<<endl;
	s.displayQueue();
	cout<<"popped:"<<s.pop()<<endl;
	return 0;
}
