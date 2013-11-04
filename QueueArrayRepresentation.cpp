#include<iostream>
#include<stdbool.h>
using namespace std;
template<class T>
class queue
{
    private:
        int max_size;
        int front1;
        int rear1;
        T *element;
    public:
        queue(int msize);
        queue();
        ~queue();        
        bool is_empty()
        {
            return (front1 == rear1 + 1);
        }

        bool is_full()
        {
            return (rear1+1 == max_size);
        }

        T get_front()
        {   
            if(!is_empty())
                return(element[front1]);
            else
                return 0;
        }

        T get_rear()
        {
            if(!is_empty())
                return(element[rear1]);
            else
                return 0;
        }
        void insert(T ele);
        T pop();
        void display();
}; // Class queue


    template<class T>
queue<T>::queue(int msize)
{
    max_size = msize;
    element = new T[max_size];
    rear1 = -1;
    front1 = 0;
}

    template<class T>
queue<T>::queue()
{
    max_size = 10;
    element = new T[max_size];
    rear1 = -1;
    front1 = 0;
}


    template<class T>
queue<T>::~queue()
{
    delete[] element;
}

    template<class T>
void queue<T>::insert(T ele)
{
    if(!is_full())
    {   
        rear1 += 1;
        element[rear1] = ele;
    }
    else
        cout<<"\nERROR : The queue is full!\n";
}

    template<class T>
T queue<T>::pop()
{
    if(!is_empty())
    {   
        T temp;
        temp = element[front1];
        front1 += 1;
        return temp;
    }
    else
    {
        cout<<"\nERROR : The queue is empty!!\n";
        return -1;
    }
}

    template<class T>
void queue<T>::display()
{
    if(!is_empty())
    {
        for(int i=front1;i<=rear1;i++)
        {
            cout<<"\t"<<element[i];
        }
    }
    else
    {
        cout<<"\nempty queue\n";
    }
}

int main()
{
    queue<int> Q(10);
    cout<<"\nchecking for empty"<<Q.is_empty()<<endl;
    cout<<"\nInserting elements into queue\n";
    for(int i=0;i<10;i++)
    {
        Q.insert(i*10);

        if(i%3 == 0){
            Q.display();
            cout<<endl;}
    }

    cout<<"\nchecking for full:"<<Q.is_full();
    cout<<"\n popping elements now! \n";
    for(int i=0;i<=10;i++)
    {    cout<<"\npopped:"<<Q.pop()<<endl;
        if(i%3 == 0)
            Q.display();
    }
}
