#include <iostream>
using namespace std;

void dec2oct(int n)
{
    if(n == 0)
    {
        return ;
    }
    dec2oct(n / 8);
    cout<< n % 8;

}



int main()
{
    int n  = 68;
    cout<< "The octal equivalent of "<< n << " is " ; dec2oct(n);
    cout<<endl;
    n  = 389;
    cout<< "The octal equivalent of "<< n << " is " ; dec2oct(n);
    cout<<endl;
    return 0;
}