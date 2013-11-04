#include<iostream>
using namespace std;
template<class T>
class dQueue;
template<class T>
class node
{
    private:
        T data;
        node<T> *prev,*next;
    public:
        node(T d)
        {
            data = d;
            next = prev = 0;
        }

        void display(){
            cout<<data<<"-->";
        }
        friend class dQueue<T>;
};

template<class T>
class dQueue
{
    private:
        node<T> *front,*rear;
    public:
        dQueue(){
            front=0;
            rear=0;
        }
        bool isempty(){
            return(front == 0 && rear == 0 );
        }
        void insertRear(T data)
        {
            node<T> *temp = new node<T>(data);
            if(isempty()){
                rear=front=temp;
            }
            else{
                temp->prev = rear;
                rear->next = temp;
                rear = temp;
            }
        }
        void insertFront(T data){
            node<T> *temp = new node<T>(data);
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        void deleteFront(){
            T data;
            node<T> *curr = front;
            data = curr->data;
            front = front->next;
            front->prev = 0;
            delete(curr);

        }
        void  deleteRear(){
            T data;
            node<T> *curr = rear;
            data = curr->data;
            rear = rear->prev;
            rear->next = 0;
            delete(curr);
        }
        void display(){
            cout<<"The list is:\n";
            node<T> *curr = front;
            while(curr != 0){
                curr->display();
                curr = curr->next;
            }
        }
};

int  main()
{
    dQueue<int> d;
    d.insertRear(2);
    d.insertFront(4);
    d.display();
    d.insertFront(8);
    d.insertRear(12);
    d.display();
    cout<<"\n";
    d.deleteRear();
    d.deleteFront();
    cout<<"After deletion\n";
    d.display();
    return 0;
}           
