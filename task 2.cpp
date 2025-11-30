#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class employee
{
	protected:
		string name;
		string department;
		int scale;
		
    public:
	string get_name( )
     {
     	return name;
	 }
	
	string get_department( )
     {
     	return department;
	 }
	 
	  int get_scale( )
     {
     	return scale;
	 }
	 void set_name(string _name)
	 {
	 	name=_name;
	 }
	 
	  void set_depar(string _depar)
	 {
	 	department=_depar;
	 }
	 
	  void set_scale(int _scale)
	 {
	 	scale=_scale;
	 }
	 
	 virtual int take_home_income(int s)
	{   
		cout<< " this is a dummy function" ;
		 return 0;
	}						
	
	   employee (string _name,string _depar,int scale )
	{
		 this->name=_name;
		 this->department=_depar;
		 this->scale=scale;
		 
	}
	
	void display()
	{
		
	}						
										
 };
 
class officer :public employee
{
	protected:
	  int salary;
	public:
	   int get_salary( )
	    {
     	return salary;
	 }	
		
	 void set_salary(int _salary)
	 {
	 	salary=_salary;
	 }
	 
	 int take_home_income(int s)
	{   
		s=this->get_salary()-(this->get_salary()*0.1);
		cout<<"income taken home by officer"<<" "<<s;
	}
	
	officer (string _name,string _depar,int scale,int sal)
	{
		 this->name=_name;
		 this->department=_depar;
		 this->scale=scale;
		 this->salary=sal ;
		 
	}						
			
};

class daily_wager :public employee
{   
    protected:
	   int daily_wage;
	   int absentcount;
	   
	   public:
	   int get_wage( )
     {
     	return daily_wage;
	 }
	 
	   int get_absent( )
     {
     	return absentcount;
	 }
	 
	   void set_wage(int a )
     {
       daily_wage= a;
	 }
	 
	   void set_absent( int d)
     {
     	  absentcount=d;
	 }
	 
	int take_home_income(int s )
	{   
		s=this->get_wage()*(30-this->get_absent());
		cout<<"income taken home by daily wager"<<" "<<s;
	}
	
	 daily_wager (string _name,string _depar,int scale,int wage,int absentees)
	{
		 this->name=_name;
		 this->department=_depar;
		 this->scale=scale;
		 this->wage=wage;
		 this->absentcount=absentees; 
		  
	}						
};

int main()
{
	employee* ar[5];
	ar[0] = new officer("abdullah","finance",18,2000000);
	ar[1]=new officer("maryam","finance",18,200000);
	ar[2]= new daily_wager("waqas","construction",11,3000,12);
	ar[3]= new daily_wager("rahat","construction",11,3000,12);
	ar[4]= new daily_wager("ali","construction",11,3000,12);
	int sal=2000000;
	int wage=9000;
	ar[0]->take_home_income(sal);
	ar[3]->take_home_income(wage);
	 return 0;
}
