// this is the header file.....
#fndef abcd_edu_nc_pucit
#define abcd_edu_nc_pucit

#include<iostream>
#inlcude<string>

using namespace std;

class text
{
	protected:
		char* arr;
		int size;
		
	public:
		// to get size of array.....
		int getSize() const{}
		
		// to set size of array....
		void setSize(int j) const{}	
		
		// to get character.....
		char getCharacter(int i) const{}
		
		// to set character at particular index of character array....
		char setCharacter(int i,char f) const{}

		//default constructor...
	    text() const {}
			
		// copy constructor....
		text(const text &str){}
	 	
		//move construstor....
		text(text &&str){}
	
		
		//copy assignment...
		text operator=(text &other){}
		
		//move assignment....
		text operator=(text && other ){}
	
		//to find length....
		int length(const text &mar){}
	 
		
		//to output the character array...
		friend ostream& operator<<( ostream& os, const  text& mar){}

        // to insert a character at a perticular index of array...
        void insertion(int r,char q){}
        
		//destructor.....
		~text(){}
	 
};
#endif



// this is the defined class...

#include<iostream>
#inlcude<string>
#include"string.h"
using namespace std;
class text
{
	protected:
		char* arr;
		int size;
		
	public:
		// to get size of array.....
		int getSize() const
		{
			return size;
		}
		
		// to set size of array....
		void setSize(int j) const
		{
			size=j;
		}
		
		// to get character.....
		char getCharacter(int i) const
		{
			return arr[i];
		}
		
		// to set character at particular index of character array....
		char setCharacter(int i,char f) const
		{
			arr[i]=f;
		}
		
		//default constructor...
	    text() const 
		{
		   arr=new char[size];
		   setSize(0);  	
		}
			
		// copy constructor....
		text(const text &str)  
		{ 
		  cout << "copy constructor" << endl; 
		   arr=new char[str.size];
		   size=str.size;
		   for(int q=0;q<str.size;q++)
		   {
		   	 arr[q]=str[q];
		   }
		   	
		}
		
		//move construstor....
		text(text &&str)
		{
		  cout << "move constructor" << endl; 
		  arr=str.arr;
		  size=str.size;
		  str.arr =nullptr;
		  str.size=0;	
		}
		
		//copy assignment...
		text operator=(text &other)
		{
			cout<<"copy assignment "<<endl;
			if ( this != &other )
			{
			   delete []arr;
			   other.arr=new char[other.size];
			   for(int f=0;f<other.size;f++)
			   {
			   	this->arr[f]=other.arr[f];
		     	}
				this->size=other.size;	
			}
			return (*this);
		}
		
		//move assignment....
		text operator=(text && other )
		{
			cout<<"move assignment "<< endl;
		 if ( this != &other )	 
		{
	    	delete []arr;
			other.arr=this->arr;
			other.size=this->size;
			this->arr=nullptr;
	    }
			return (*this);
		}
		
		//to find length....
		int length(const text &mar)
		{ if(this->size=>mar.size) 
		   {
		    mar.setSize(12);
			mar.arr=new char[mar.size];
			int length=0;
			for(int p=0;p<mar.size;p++)
			{
			    length=length+1;	
			}
			cout<< "length"<<length;
		}
		
		//to output the character array...
		friend ostream& operator<<( ostream& os, const  text& mar)
		 {
		 	for(int r=0;r<this->size;r++)
		 	{
		 		os<<mar.arr[r]<<endl;
			 }
			 return os;
		 }

        // to insert a character at a perticular index of array...
        void insertion(int r,char q)
        {   
            this->arr=new char[this->size ];
        	for(int k=this->size-1;k>=r;k-=1)
        	{
        		this->arr[k+1]=this->arr [k];
			}
			this->arr[r]=q;
			this->size=+1;
		}
		
		//destructor.....
		~text()
		{
			cout<<"destructor"<<endl;
			delete [] this->arr;
			this->arr=nullptr;
			cout<<"this text has been destroyed ";
		}
};


// this is the main logic......

#include<iostream>
#inlcude<string>
#include"string.h"
using namespace std;


int main()
{
	try
	{
		cout<<"--------------"<<endl;
		text mtr;
		mtr.setSize(15);
		for(int g=0;g<mtr.size;g++)
		{
		  mtr.setCharacter(g,y);	
		}
		cout<<"--------------"<<endl;
		mtr.setCharacter(2,w);
		cout<<"--------------"<<endl;
		text mts;
		mtr.operator=(mts);
		cout<<"--------------"<<endl;
		mtr.operator=(mts);
		cout<<"--------------"<<endl;
		cout<<length(mtr);
		cout<<"--------------"<<endl;
		mtr.insertion(8,p);
		cout<<"--------------"<<endl;
		cout<<mtr;
		cout<<"--------------"<<endl;
		
		catch(...)
    {
        cerr << "A runtime exception occured" << endl;
    }

    return 0;
		
		
	}
}
