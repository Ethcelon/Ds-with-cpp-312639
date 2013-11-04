#include<iostream>
#include<stdbool.h>
#include<string.h>
using namespace std;
template<class T>
class par
{
    private:
        char exp[30];
        char estack[20];
        int top,nright,maxSize;
    public:
        par(int m)
        {
            maxSize = m;
            nright = 0;
        }
        bool isEmpty(){
            if(top==-1)
                return true;
            else
                return false;
        }
        void create(){
            top=-1;
        }
        void getexp();
        void push(char);
        void pop();
        void match();

};

template<class T>
void par<T>::getexp(){
    cout<<"\nEnter an expression:";
    cin>>exp;
    cout<<"\nEntered expression is:"<<exp;
}
template<class T>
void par<T>::push(char ch){
    if(top==maxSize-1)
        cout<<"\nStack Overflow";
    else{
        top++;
        estack[top]=ch;
    }
}
template<class T>
void par<T>::pop(){
    if(top==-1)
        nright++;
    else
        top--;
}
template<class T>
void par<T>::match(){
    int i,size;
    size = strlen(exp);
    for(i=0; i<size; i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        if(exp[i]==')')
            pop();
    }
    if(nright)
        cout<<"\n '(' parenthesis missing:"<<nright<<endl;
    else if(isEmpty())
        cout<<"\n parentheis are matched\n";
    else
        cout<<"\n ')' parentheis missing:"<<top++<<"\n";
}
int main(){
    par<int> p(20);
    p.create();
    p.getexp();
    p.match();
    
    return 0;
}

