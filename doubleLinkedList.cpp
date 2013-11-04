//Double linked list
#include<iostream>
#include<stdbool.h>

using namespace std;
template <class T>
class foo;
template<class T>
class Node
{
	private:
	Node<T> *next;
	Node<T> *prev;
	T data;	
    public: 
	Node(){}
	Node(T d)
	{
		
		data=d;
        next=0;
        prev=0;
	}
	void display()
	{
		cout<<data;
	}
    friend class foo<T>; 

};	

template<class T>
class foo
{
	public:
		
	Node<T> *start;
	
	foo()
	{
		start = 0;
	}
	
	bool isEmpty()
	{
		return(start == 0);
	}
	
	int getLength();
	bool search(T key);
	void insert(int pos, T data);
	void Delete(int pos);
	void displayList();
};


template<class T>
int foo<T>::getLength()
{
	int count = 0;
	Node<T> *curr = start;
	while(curr!=0)
	{
		count++;
		curr = curr->next;
	}
	return count;
}

template<class T>
bool foo<T>::search(T key)
{
	Node<T> *curr = start;
	while(key != curr->data && curr!=0)
		curr->prev=curr;
		curr=curr->next;
		
	if(curr !=0)
		return true;
	return false;
}

template<class T>
void foo<T>::insert(int pos,T ele)
{
	Node<T> *temp = new Node<T>(ele);
	//	cout<<"testmode";
	if(isEmpty())
	{	
		start = temp;
	 //  	cout<<"testing";
	}
	else if(pos==1)
         {
             temp->next=start;
             start->prev=temp;
             start=temp;
         }
    else
	{
		int i=0;
	//	cout<<"entered else";
		Node<T> *curr = start;
		while(i < pos-1 && curr->next !=0)
		{
			i++;
	//		cout<<"hmmm";	
			curr = curr->next;
		}
        if(curr->next != 0)
        {     
            temp->next = curr->next;
            curr->next->prev=temp;
        }    
            curr->next=temp;
            temp->prev=curr;
	}
}


template<class T>
void foo<T>::displayList()
{
	Node<T> *curr = start;
	cout<<"\nStart:\n";
	while(curr!=0)
	{
		curr->display();
		cout<<" ";
		curr = curr->next;
	}
}

template<class T>
void foo<T>::Delete(int pos)
{
	if(isEmpty() || pos > getLength())
		cout<<"\nWRONG POS TO DELETE\n";
	else
	{
		Node<T> *curr;
		curr = start;
		if(pos == 1)
			start = start->next;
		int i=1;
		while(curr->next!=0 && i != pos)
		{
			i++;
			curr->prev = curr;
			curr = curr->next;
		}
		if(curr == 0 || i!=pos)
			cout<<"\nError!\n";
		curr->prev->next = curr->next;
		cout<<"\nDelete done\n";
	}
}

int main()
{
        for(int j=0;j<40;j++)
                cout<<"-";
	cout<<endl;
	foo<int> l1;
	cout<<"testing for empty:"<<l1.isEmpty()<<endl;
	l1.insert(1,10);
	l1.insert(2,20);
    l1.displayList();
	l1.insert(3,15);
	l1.insert(4,40);
	l1.displayList(); 
    cout<<"\ntrying to delete pos 2:";
    l1.Delete(2);
    l1.displayList();
    cout<<endl;
        for(int j=0;j<40;j++)
                cout<<"-";

        cout<<endl;

        return 0;
}


