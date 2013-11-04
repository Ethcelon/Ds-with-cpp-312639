#include<iostream>
using namespace std;
template<class T>
class array
{
    private:
        int size;
        T*element;
    public:
        array(int s)
        {
            size=s;
            element=new T[size];
        }
        void readarray();
        void display();
        int lsearch(T key);
};
    template<class T>
void array<T>::readarray()
{
    cout<<"\n elements in the array:";
    for(int i=0;i<size;i++)
    {
        cin>>element[i];
    }
}
    template<class T>
void array<T>::display()
{
    cout<<"\n the elements in the array are:";
    for(int i=0;i<size;i++)
    {
        cout<<element[i]<<"\t";
    }
}
    template<class T>
int array<T>::lsearch(T key)
{
    int index=0;
    while(index<size)
    {
        if(element[index]==key)
            return (index+1);
        index++;
    }   
    
    return 0;
}
int main()
{
    array<int>a(10);
    a.readarray();
    a.display();
    cout<<"\nSearching for element 5\n";
    if(a.lsearch(8)==0)
        cout<<"\n Element not found";
    else
        cout<<"\nElement 5 found at position "<<a.lsearch(5);
    return 0;
}

