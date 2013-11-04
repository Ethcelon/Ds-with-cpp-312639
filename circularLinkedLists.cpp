#include<iostream>
#include<stdbool.h>
using namespace std;

template<class T>
class Clinked;

template<class T>
class Node
{
    private:
        T data;
        Node<T> *next;
    public:
        Node(){}
        Node(T d)
        {
            data = d;
        }
        void display()
        {
            cout<<data;
        }
        friend class Clinked<T>;
};
template<class T>
class Clinked
{
    private:
        Node<T> *start;
    public:
        Clinked()
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
        void deleteIt(int pos);
        void displayList();
};

    template<class T>
int Clinked<T>::getLength()
{
    if(isEmpty())
        return 0;
    else
    {   
        int count = 0;
        Node<T> *curr = start;
        do
        {
            curr=curr->next;
            count++;
        }while(curr!=start);
        return count;
    }
}
    template<class T>
bool Clinked<T>::search(T key)
{
    Node<T> *curr = start;
    while(key!=curr->data && curr->next!=start)
        curr=curr->next;
    if(key == curr->data)
        return true;
    return false;
}

    template<class T>
void Clinked<T>::displayList()
{   
    if(getLength()==0)
    {
        cout<<"\nempty list!\n";
    }
    else{
        Node<T> *curr = start;
        cout<<"\nStart:\n";
        int i=1;
        while(curr->next != start)
        {
            curr->display();
            cout<<" ";
            curr=curr->next;
        }
        curr->display();

    }
}
    template<class T>
void Clinked<T>::insert(int pos, T ele)
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


        while(curr->next!=start)
            curr=curr->next;

        temp->next = start;
        start = temp;
        curr->next = start;
    }
    else
    {
        int i = 1;
        Node<T> *curr = start;
        while(i < pos-1 && curr->next != start)
        {
            i++;
            curr = curr->next;
        }
        if(curr->next != start)
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
void Clinked<T>::deleteIt(int pos)
{
    if(isEmpty() || pos > getLength())
        cout<<"\nWRONG POSITION TO DELETE!\n";
    else if(pos == 1)
    {   
        if(getLength() == 1)
        {
            start = 0;
        }
        else
        {
            Node<T> *curr = start;
            while(curr->next!=start)
                curr=curr->next;
            start = start->next;
            curr->next = start;
        }
    }
    else
    {
        Node<T> *curr,*prev;
        curr = start;
        int i = 1;
        while(curr->next != start && i != pos)
        {
            i++;
            prev = curr;
            curr=curr->next;
        }
        if(i!=pos)
            cout<<"\nERROR\n";
        else if(curr->next == start)
        {
            prev->next = start;
            delete curr;
        }
        else
        {
            prev->next == curr->next;
            delete curr;
            cout<<endl;
        }
    }

}

int main()
{
    for(int j=0; j<40;j++)
        cout<<"-";
    cout<<"\n Testing for integer.\n";
    Clinked<int> l1;
    cout<<"Checking for empty:"<<l1.isEmpty();
    l1.displayList();
    l1.insert(1,10);
    cout<<endl<<"inserted 10! Length:"<<l1.getLength();    
    l1.insert(2,20);
    cout<<endl<<"inserted 20! Length:"<<l1.getLength();
    l1.displayList();
    l1.insert(1,30);
    cout<<endl<<"inserted 30! Length:"<<l1.getLength();
    l1.displayList();
    cout<<"\nTrying to delete pos 1:";
    l1.deleteIt(1);
    l1.displayList();
    cout<<"\nTrying to delete pos 2:";
    l1.deleteIt(2);
    l1.displayList();
    cout<<endl;
    return 0;
}
