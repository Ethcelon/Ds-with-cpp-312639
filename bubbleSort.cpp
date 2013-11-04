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
        void sort();
        void display();
        void swap(int,int);
};
    template<class T>
void array<T>::readarray()
{
    for(int i=0;i<=size-1;i++)
        cin>>element[i];

}
    template<class T>
void array<T>::sort()
{
    int i,j;
    for(i=0;i<=size-1;i++)
    {
        for(j=size-1;j>=i;j--)
            if(element[j-1]>element[j])
            {
                swap(j-1,j);
            }
    }
}
    template<class T>
void array<T>::display()
{
    cout<<" elements are";
    for(int i=0;i<=size-1;i++)
        cout<<element[i]<<"\t";
}
    template<class T>
void array<T>::swap(int i,int j)
{
    T t=element[j-1];
    element[j-1]=element[j];
    element[j]=t;
}

int main()
{
    array<int>a(10);
    cout<<"enter elements";
    a.readarray();
    cout<<"the entered array is:";
    a.display();
    a.sort();
    cout<<"\n";
    cout<<"the elements after sorting:\n ";
    a.display();
    cout<<"\n";
    return 0;
}

