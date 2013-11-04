//LinkedList formula based representation

#include<iostream>
#include<stdbool.h>
using namespace std;
template<class T> //for class Node
class Node
{
		public:
		T data;
		Node<T> *next;
		Node(){}
		Node(T d)
		{
			data =d;
		}
		void display()
		{
			cout<<data;
		}
	
};

template<class T>
class linkedList
{
	private:
		Node<T> *start; //begining of the list
	public:
		linkedList()
		{
			start = 0; //null pointer
		}
		bool isEmpty()
		{
			return(start == 0);
		}
		int getLength();
		bool search(T key);
		void insert(int pos, T data);
		void deleteIt(int pos);
		void displayList();
}; // class linkedList

//to find lenth of the list

template<class T>
int linkedList<T>::getLength()
{
	int count = 0;
	Node<T> *curr = start;
	while(curr != 0 )
	{
		count++;
		curr = curr->next;
	}
	return count;
}

template<class T>
bool linkedList<T>::search(T key)
{
	Node<T> *curr = start;
	while(key != curr->data && curr !=0)
		curr=curr->next;
	if(curr !=0)
		return true;
	return false;
}

//Display the list of nodes.

template<class T>
void linkedList<T>::displayList()
{
	Node<T> *curr = start;
	cout<<"\nStart :\n";
	while(curr != 0)
		{

		curr->display();
		
		cout<<" ";
		curr = curr->next;

		}

}

//Insert new
template<class T>
void linkedList<T>::insert(int pos, T ele)
{
	Node<T> *temp = new Node<T>(ele);
	if(isEmpty())
		start = temp;
	else
	{
		int i = 0;
		Node<T> *curr = start;
		while(i < pos-1 && curr->next !=0)
		{
			i++;
			curr = curr->next;
		}
		if(curr->next !=0)
			temp->next = curr->next;
		curr->next=temp;
	}
}

template<class T>
void linkedList<T>::deleteIt(int pos)
{
	if(isEmpty() || pos > getLength())
		cout<<"\nWRONG POSITION TO DELETE!\n";
	else
	{
		Node<T> *curr,*prev;
		curr = start;
		if(pos==1)
			start = start->next;
		int i=1;
		while(curr->next != 0 && i != pos +1)
		{
			i++;
			prev = curr;
			curr=curr->next;
		}
		if(curr==0|| i!=pos)
			cout<<"\nerror\n";
		prev->next = curr->next;
		cout<<"\ndelete done\n";
		
			
	}
}
int main()
{
	for(int j=0;j<40;j++)
                cout<<"-";
	cout<<"\nTesting for integer.\n";
	linkedList<int> l1;
	cout<<"Checking for empty:"<<l1.isEmpty();
	l1.insert(1,10);
	l1.insert(2,20);
	l1.insert(3,30);
	l1.displayList();
	cout<<"\ntrying to delete position 1";
	l1.deleteIt(1);
	l1.displayList();
	cout<<"Deletesuccess";
	cout<<"\nsearching for 30:"<<l1.search(30);
	cout<<endl;
	for(int j=0;j<40;j++)
                cout<<"-";
	cout<<"\nTesting for float.\n";
	linkedList<float> l2;
	cout<<"Checking for empty:"<<l2.isEmpty();
        l2.insert(1,10.3);
        l2.insert(2,20.3);
        l2.insert(3,30.3);
        l2.displayList();
        cout<<"\ntrying to delete position 1";
        l2.deleteIt(1);
        l2.displayList();
        cout<<"Deletesuccess";
        cout<<"\nsearching for 30.3:"<<l2.search(30.3);
        cout<<endl;
        for(int j=0;j<40;j++)
                cout<<"-";

	cout<<endl;
	
	return 0;
}
	
	

