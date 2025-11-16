#ifdef bsds_pucit_nc
#define bsds_pucit_nc
#include <iostream>
#include<string>
 
using namespace std;
template<typename T>
class queue
{
	protected:
		T *data;
		int capacity;
		int current_s;
		
	public:
	   void  enqueue(T num)
	   T dequeue()
	    queue(int c)
	     queue(queue &ref) 
	    bool   isfull()
	     bool isempty()
	     int getcurrent_S()
	      T lastentry() 
	      queue operator=(const queue &ref) //asssignmnet operator........
	      T queuefront()
	      ~queue()
	   	
};
#end if;
