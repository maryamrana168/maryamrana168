#include <iostream>
#include<string>
#include"stackheader.h"
 
using namespace std;


       void stack::push(T num) 
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
	   
	   T stack::pop () 
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
	   
	   stack::stack(int c)  // constructor......
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
	   
	   stack::stack (stack &ref)  //copy constructor......
	   {
	   	 ref.capacity=capacity;
	   	 ref.top=top;
	   	 ref->data=new T[capacity];
	   	 for(int i=0;i<capacity;i++)
	   	 {
	   	 	ref->data[i]=this->data[i];
		 }
	   }
	   
	   bool stack:: isfull()
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
	   
	   bool stack::isempty()
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
	   
	   int stack:: gettop()
	   {
	   	 return top;
	   }
	   
	   T stack::stacktop() 
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
	   
	   stack stack::operator=(const stack &ref) //asssignmnet operator........	
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
	   
	   stack::~stack()
	   {
	   	capacity=0;
	   	top=0;
	   	delete[] data;
	   	data=nullptr;
	   }
