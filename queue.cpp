#include <iostream>
#include<string>
#include"queue.h"
 
using namespace std;


       void queue::enqueue(T num) 
       {
       	  if(!isfull())
       	  {
             data[current_s]=num;
			 current_s++;      	  	
		  }
		  else
		  {
		  	this->isfull();
		  }
	   }
	   
	   T queue::dequeue() 
	   {
	   	 int c=data[0];
	   	 for(int i=0;i<current_s;i++)
	   	 {
	   	 	data[i-1]=data[i];
	   	 	current_s--;
		}
		return c;
	   }
	   
	   queue::queue(int c)  // constructor......
	   {
	   	if(c>0)
	   	{
		   capacity=c;
		   current_s=0;
		   data=new T[c];
		}
		else
		{
			exit (0);
		}
	   }
	   
	      queue::queue(queue &ref)  //copy constructor......
	   {
	   	 ref.capacity=capacity;
	   	 ref. current_s=current_s;
	   	 ref->data=new T[capacity];
	   	 for(int i=0;i<capacity;i++)
	   	 {
	   	 	ref->data[i]=this->data[i];
		 }
	   }
	   
	   bool queue:: isfull()
	   {
	   	 if(current_s==capacity)
	   	 {
	   	 	return true;
		}
		else
		{
			return false;
		}
	   }
	   
	   bool queue::isempty()
	   {
	   	 if(current_s==0)
	   	 {
	   	 	return true;
		}
		else
		{
			return false;
		}
	   }
	   
	   int queue:: getcurrent_S()
	   {
	   	 return current_s;
	   }
	   
	   T queue::lastentry() 
	   {
	   	  if (current_s!=0)
	   	 {
	   	 	return data[current_s-1];
		 }
		 else
		 {
		 	this->isempty();
		 }
	   }
	   
	   queue::queue operator=(const queue &ref) //asssignmnet operator........	
	   {
	   	  if(this!=ref)
	   	  {
	   	  	this->~queue();
	   	  	capacity=ref.capacity;
	   	     current_s=ref.current_s;
	   	   for(int i=0;i<capacity;i++)
	   	   {
	   	 	this->data[i]=ref->data[i];
		   }
		  }
	   }
	   
	  T queue:: queuefront()
	  {
	  	 if (current_s!=0)
	   	 {
	   	 	return data[0];
		 }
		 else
		 {
		 	this->isempty();
		 }
	  }
	   
	   queue::~queue()
	   {
	   	capacity=0;
	   	current_s=0;
	   	delete[] data;
	   	data=nullptr;
	   }
