#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
using namespace std;

class EXPRESSION
{
    private:
	    char infix[50],postfix[50];
	    char s[50];
        int top;
    public:
	    EXPRESSION(char *str);
	    void push(char ch);
	    int precedence(char ch);
	    char pop();
	    void convert();
	    void display();
};


EXPRESSION::EXPRESSION(char *str)
{
  strcpy(infix,str);
   top=0;
}
void EXPRESSION::push(char ch)
{
   s[++top]=ch;
}
char EXPRESSION::pop(void)
{
   return(s[top--]);
}

int EXPRESSION::precedence(char ch)
{
   if(ch== '(' || ch== '#') return(1);
   if(ch== '+' || ch== '-') return(2);
   if(ch== '*' || ch== '/') return(3);
      if(ch == '^') return(4);
   return 0;
}
void EXPRESSION::convert()
{
   int i,j=0;
   push('#');
   for(i=0;infix[i]!='\0';i++)
   {
      if(isalnum(infix[i]))
      postfix[j++]=infix[i];
      else
      if(infix[i]=='(')
      push(infix[i]);
      else
      if(infix[i]== ')')
      {
         while(s[top]!='(')
         postfix[j++]=pop();
         pop();
      }
      else
     {
         while(precedence(s[top])>=precedence(infix[i]))
         postfix[j++]=pop();
        push(infix[i]);
     }
   }       //end of for
   while(s[top]!='#')    //copy the remaining elements into suffix
   postfix[j++]=pop();
   postfix[j]='\0';
}
void EXPRESSION::display()
{
   cout << postfix << endl;
}

/*---------------------MAIN FUNCTION-------------------------*/

int main()
{
   char infix[50];
   cout << "Enter the valid Infix Expression   :";
   cin >> infix;
   EXPRESSION Exp(infix);    //Create a object and call the constructor with
				// argument as infix expression
   Exp.convert();
   cout << "\nThe Corresponding Suffix expression is:";
   Exp.display();
   return 0;
}


