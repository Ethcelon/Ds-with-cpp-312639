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
                                        element= new T[size];
                                }
                void readarray();
                void display();
                void isort();
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
        void array<T>::isort()
{
        for(int i=0;i<size;i++)
        {
                        int j=i+1;
                        T elt=element[j];
                        while(j>0 && element[j-1]>elt)
                        {
                                                element[j]=element[j-1];
                                                j=j-1;
                                        }
                        element[j]=elt;
                }
}
int main()
{
        array<int> d(10);
        cout<<"\n enter elements:";
        d.readarray();
                cout<<"\n entered array is:";
        d.display();
        d.isort();
        cout<<"\n the sorted array is:";
        d.display();
        return 0;
}

