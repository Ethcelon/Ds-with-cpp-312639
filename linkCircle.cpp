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
class CLinkedList
{
    private:
        Node<T> *start; //begining of the list
    public:
        CLinkedList()
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
int CLinkedList<T>::getLength()
{
    int count = 0;
    Node<T> *curr = start;
    
    while(curr->next != start )
    {
        count++;
        curr = curr->next;
    }
    if(count == 0 && start->next == start)
        count++;
    return count;
}

    template<class T>
bool CLinkedList<T>::search(T key)
{
    Node<T> *curr = start;
    while(key != curr->data && curr->next !=start)
        curr=curr->next;
 //   if(curr->next !=start)
    if(key == curr->data)
        return true;

    return false;
}

//Display the list of nodes.

    template<class T>
void CLinkedList<T>::displayList()
{
    Node<T> *curr = start;
    cout<<"\nStart :\n";
    while(curr->next != start)
    {

        curr->display();

        cout<<" ";
        curr = curr->next;

    }
    curr->display();
}

//Insert new
    template<class T>
void CLinkedList<T>::insert(int pos, T ele)
{
    Node<T> *temp = new Node<T>(ele);
    if(isEmpty())
    {
        start = temp;
        temp->next = start;
    }
    else if(pos == 1)
    {   
        Node<T> *curr = start;
        while(curr->next != start)
            curr=curr->next;
        temp->next=start;
        start=temp;
        
    }
    else
    {
        int i = 0;
        Node<T> *curr = start;
        while(i < pos && curr->next !=start)
        {
            i++;
            curr = curr->next;
        }
        if(curr->next !=start)
        {
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            temp->next=start;
            curr->next=temp;
        }
    }
}

    template<class T>
void CLinkedList<T>::deleteIt(int pos)
{
    if(isEmpty() || pos > getLength())
        cout<<"\nWRONG POSITION TO DELETE!\n";
    if(pos == 1)
    {
     //   cout<<"pos=1";
        start=start->next;
    }
    else
    {   
        Node<T> *curr,*prev;
        curr=start;
        int i=1;
        while(curr->next != start && i != pos)
        {
            i++;
            prev = curr;
            curr=curr->next;
        }
        if(curr==0|| i!=pos)
            cout<<"\nerror\n";
        prev->next = curr->next;
        cout<<endl;

    }
}
int main()
{
    for(int j=0;j<40;j++)
        cout<<"-";

    cout<<"\nTesting for integer.\n";

    CLinkedList<int> l1;

    cout<<"Checking for empty:"<<l1.isEmpty();

    l1.insert(1,10);
    l1.insert(2,20);
    l1.insert(3,30);

    l1.displayList();
    cout<<"length:"<<l1.getLength();
    cout<<"\ntrying to delete position 1";
    l1.deleteIt(1);
    l1.displayList();

    cout<<"\nsearching for 30:"<<l1.search(30);
    cout<<endl;

    for(int j=0;j<40;j++)
        cout<<"-";

    cout<<"\nTesting for float.\n";

    CLinkedList<float> l2;

    cout<<"Checking for empty:"<<l2.isEmpty();

    l2.insert(1,10.3);
    l2.insert(2,20.3);
    l2.insert(3,30.3);

    l2.displayList();

    cout<<"\ntrying to delete position 2";
    l2.deleteIt(2);
    l2.displayList();


    cout<<"\nsearching for 30.3:"<<l2.search(30.3);
    cout<<endl;
    for(int j=0;j<40;j++)
        cout<<"-";

    cout<<endl;

    cout<<"\ntesting for single length list\n";

    CLinkedList<int> l3;
    cout<<"Checking for empty:"<<l3.isEmpty();

    l3.insert(1,10);

    l3.displayList();

    l3.deleteIt(1);
    l3.displayList();

    return 0;
}



