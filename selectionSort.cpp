#include<iostream>
using namespace std;
template<class T>
class array
{
    private:
        int size;
        T *element;
    public:
        array(int s)
        {
            size=s;
            element=new T[size];
        }
        void readarray();
        void ssort();
        void display();
        void  swap(int,int);
};
    template<class T>
void array<T>::readarray()
{
    for(int i=0;i<size;i++)
        cin>>element[i];
}
    template<class T>
void array<T>::display()
{
    for(int i=0;i<size;i++)
        cout<<element[i]<<"\t";
}
    template<class T>
void array<T>::ssort()
{
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(element[i]>element[j])
                min=j;
        }
        swap(i,min);
    }
}
    template<class T>
void array<T>::swap(int i,int j)
{
    T  t = element[i];
    element[i]=element[j];
    element[j]=t;
}
int main()
{
    array<int>a(10);
    cout<<"\n enter elements in the array";
    a.readarray();
    cout<<"\n the array is:";
    a.display();
    a.ssort();
    cout<<"\n the sorted array is:";
    a.display();
    return 0;
}

