#include<iostream>
#include<string.h>
#include<stdbool.h>
using namespace std;
template <class T>
class stack
{
    private:
        T*element;
        int maxsize;
        int top;
    public:
        stack(int size)
        {
            maxsize=size;
            top=-1;
            element=new T[maxsize];
        }
        bool isempty()
        {
            return(top==-1);
        }
        bool isfull()
        {
            return(top==(maxsize-1));
        }
        T gettop()
        {
            if(!isempty())
                return element[top];
        }
        void push(T data)
        {
            if(!isfull())
            {
                top++;
                element[top]=data;
            }
            else
                cout<<"\n stack overflow";
        }
        T pop()
        {
            if(!isempty())
            {
                T data=element[top];
                top--;
                return data;
            }
            else
            {
                cout<<"\n stack underflow";
            }
        }void display()
        {
            if(!isempty())
            {
                cout<<"\n stack contents bottom->";
                for(int i=0;i<=top;i++)
                    cout<<element[i]<<"\t";
            }
            else
                cout<<"\n stack is empty";
        }
};
bool palindrome(char *str)
{
    stack<char>s(10);
    int i=0,len=strlen(str);
    while(str[i]!='\0')
    {
        if(i<len/2)
            s.push(str[i]);
        else if(i==len/2)
        {
            if(len%2==0)
                s.push(str[i]);
        }
        else
        {
            if(str[i]!=s.pop())
                return false;
        }
        i++;
    }
    return true;
}
int main()
{
    char str[20];
    cout<<"\n enter input string";
    cin>>str;
    if(palindrome(str))
        cout<<"\n entered string is palindrome";
    else
        cout<<"entered string not palindrome";
    return 0;
}

