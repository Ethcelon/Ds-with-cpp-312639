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
        int  bsearch(T key);
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
int array<T>::bsearch(T key)
{
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(element[mid]==key)
            return mid+1;
        else if(element[mid]>key)
            high=mid-1;
        else if(element[mid]<key)
            low=mid+1;
        else return 0;
    }
}
int main()
{
    array<int>a(10);
    cout<<"\n Enter elements\n";
    a.readarray();
    cout<<"\n The elements are:\n";
    a.display();
    cout<<"\nSearching for element 7\n";
    if(a.bsearch(7)==0)
        cout<<"\nElement not found";
    else
        cout<<"\nElement found at position "<<a.bsearch(7);
    return 0;
}

