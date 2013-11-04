#include<iostream>
 using namespace std;
 template<class T>
 class cqueue
{
  private:
        int maxsize;
        T *element;
         int rear,front;
   public:
           cqueue(int size)
            {
                           maxsize=size;
                            front=0;
                            rear=0;
                          element=new T[maxsize];
                        }
   bool isempty()
            {
                           if(front==rear)
                               return true;
                            else
                                 return false;
                         }
   bool isfull()
           {
                          if((rear+1)%maxsize==front)
                            return true;
                          else
                              return false;
                       }
    T getfront()
            {
                            if(!isempty())
                              return element[(front+1)%maxsize];
                        }
   T getrear()
          {
                        if(!isempty())
                            return element[rear];
                     }
   void insertion(T data)
     {
                    if(!isfull())
                     {
                                       rear=(rear+1)%maxsize;
                                        element[rear]=data;
                                      }
                      else
                           cout<<"\n queue is full:";
          }
  T Delete()
      {
                     if(!isempty())
                      {
                                         T data;
                                        front=(front+1)%maxsize;
                                        data=element[front];
                                        return data;
                                       }
               else
                  cout<<"queue is empty:";
            }
  void display()
     {
                    cout<<" start-->";
                 int i=(front+1)%maxsize;
                 while(i!=(rear+1)%maxsize)
                   {
                                  cout<<element[i]<<"-->";
                                  i=(i+1)%maxsize;
                                  }
     
         }
   };
  int main()
      {
          cqueue<int> q(5);
          q.insertion(1);
         q.insertion(2);
         q.insertion(3);
         q.insertion(4);
         q.display();
           cout<<"\n the front element is:"<<q.getfront();
            cout<<endl;
             cout<<"\n the rear element is"<<q.getrear();
              cout<<endl;
         q.Delete();
        cout<<endl;
         q.display();
        return 0;
        }

