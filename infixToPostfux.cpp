#include<iostream>
#include"stackFormulaBased1.cpp"
using namespace std;
int getprecedence(char ch)
{
    switch(ch)
    {
        case'*':
        case'/':
        case'%':return 3;
        case'+':
        case'-':return 2;
        case'(':return 1;
        case'$':return 0;
    }
}
void infixtopostfix(char *infix,char *postfix)
{
    stack<char> stk(10);
    stk.push('$');
    int i=0,j=0;
    char ch, chr;
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(isalpha(ch)||isdigit(ch))
            postfix[j++]=ch;
        else
        {
            switch(ch)
            {
                case'(':stk.push(ch);
                        break;
                case')':while(chr=stk.gettop()!='(')

                            postfix[j++]=stk.pop();
                        break;
                case'+':
                case'-':
                case'*':
                case'/':
                        int prec1=getprecedence(ch);
                        int prec2=getprecedence(stk.gettop());
                        while(prec2>prec1)
                        {
                            postfix[j++]=stk.pop();
                            prec2=getprecedence(stk.gettop());
                        }
                        stk.push(ch);
                        break;
            }
        }
        i++;
    }
    while((chr=stk.pop())!='$')
        postfix[j++]=chr;
    postfix[j++]='\0';
}
int main()
{
    {
        char infix[20],postfix[20];
        cout<<"/n enter infix expression";
        cin>>infix;
        infixtopostfix(infix,postfix);
        cout<<"\n equivalent expression is:"<<postfix;
        return 0;
    }

}
