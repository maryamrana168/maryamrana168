#indef pucit_bsds_24_nc
#define pucit_bsds_24_nc
              
#include <iostream>
#include<string>

using namespace std;
template <typename T>
class stack
{
	protected:
		T *data;
		int capacity;  // total capacity of array or stack...
		int top;   // tells number of current elements present in array
	public:
	   void push(T data);
	   T pop ();
	   stack(int c); // constructor......
	   stack (const stack &ref)
	   bool isfull();    
	   bool isempty();
	   int gettop();
	   T stacktop();
	   stack operator=(const stack &ref);//asssignmnet operator........	
	   ~stack()  //destructor.....
};

#endif 
