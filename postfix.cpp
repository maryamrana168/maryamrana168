#include<iostream>
#include<string>
#include <cctype>
using namespace std;

Template <typename T>
class stack
{
	protected:
		T *data;
		int capacity;    
		int top;   

  void  push(T num) 
       {
       	  if(top!=capacity)
       	  {
             data[top]=num;
			 top++;      	  	
		  }
		  else
		  {
		  	this->isfull();
		  }
	   }
	   
	   T  pop () 
	   {
	   	 if (top!=0)
	   	 {
	   	 	return data[top-1];
	   	 	top--;
		 }
		 else
		 {
		 	this->isempty();
		 }
	   }
	   
	   stack (int c)  // constructor......
	   {
	   	if(c>0)
	   	{
		   capacity=c;
		   top=0;
		   data=new T[c];
		}
		else
		{
			exit (0);
		}
	   }
	   
	   stack (stack &ref)  //copy constructor......
	   {
	   	 ref.capacity=capacity;
	   	 ref.top=top;
	   	 ref->data=new T[capacity];
	   	 for(int i=0;i<capacity;i++)
	   	 {
	   	 	ref->data[i]=this->data[i];
		 }
	   }
	   
	   bool  isfull()
	   {
	   	 if(top==capacity)
	   	 {
	   	 	return true;
		}
		else
		{
			return false;
		}
	   }
	   
	   bool  isempty()
	   {
	   	 if(top==0)
	   	 {
	   	 	return true;
		}
		else
		{
			return false;
		}
	   }
	   
	   int  gettop() //retrun top value....
	   {
	   	 return top;
	   }
	   
	   T  stacktop() // retrun top entry....
	   {
	   	  if (top!=0)
	   	 {
	   	 	return data[top-1];
		 }
		 else
		 {
		 	this->isempty();
		 }
	   }
	   
	   stack operator=(const stack &ref) //asssignmnet operator........	
	   {
	   	  if(this!=ref)
	   	  {
	   	  	this->~stack();
	   	  	capacity=ref.capacity;
	   	     top=ref.top;
	   	   for(int i=0;i<capacity;i++)
	   	   {
	   	 	this->data[i]=ref->data[i];
		   }
		  }
	   }
	   
	   ~stack()
	   {
	   	capacity=0;
	   	top=0;
	   	delete[] data;
	   	data=nullptr;
	   }
 
  class postfix ::public stack
 {  protected:
 	int size=30;
	char infix[size]='A+B*C-D';
	public:
		{
		   void conversion(char a[size=30])
		   	{
		   		stack<char> s1;
		   		s1->data=new char[30];
		   		char post[size=30];
		   		for(int h=0;h<size;h++)
		   		{
		   			if( isalnum(infix[h]))
		   			{
		   				post[h]=infix[h];
					 }
					  else(!isalnum(infix[h]))
					 {  
					    for(int i=0;!s1.isempty()&&precedence(s1.stacktop())>precedence(infix[i]);i++)
					    {
					    	post[i+1]=s1.pop();
						}
						if(infix[i]!=')')
					 	{
						 s1.push(infix[i]);
					    }
					     if(infix[i]==')')
					    {
					    	for(int j=0;!s1.isempty()&&s1.stacktop()!='(';j++)
					 	{
						   post[j+1]=s1.pop();
					    }
					        s1.pop();
					    }
					 }
				  }
				  
				  for(int k=0;!s1.isempty();k++)
				  {
				  	post[k+1]=s1.pop();
				  }
				  
				  for(int f=0;f<size;f++)
				  {
				  	cout<<post[f]<<",";
				  }
			}
    
          int precedence(char op) 
		  {
          if (op == '^')
            return 3;
         else if (op == '*' || op == '/')
            return 2;
         else if (op == '+' || op == '-')
             return 1;
         else
           return 0;   
         }
         
         void evaluation(char post[size=30])
         {
         	stack<int> s2;
         	s2->data=new int [size=30];
         	for(int i=0;i>n;i++)
         	{
         	    if(isalnum(post[i]))
				 {
				    s2.push(post[i]);	
				 }
				 else
				 {
				 	int op1=s2.stacktop();
				 	s2.pop();
				 	int op2=s2.stacktop();
				 	s2.pop();
				 	
				 	if (post[i] == '+') s2.push(operand1 + operand2);
                    else if (post[i] == '-') s2.push(operand1 - operand2);
                    else if (post[i] == '*') s2.push(operand1 * operand2);
                    else if (post[i] == '/') s2.push(operand1 / operand2);
                    else if (post[i] == '^') s2.push(pow(operand1, operand2));   // need <cmath>
 
				 }	
			 }
			 cout<<"result of epression:"<<" "<<s2.pop();
		 }

 };
