#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    } 
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isGoodString(const string & s,int n = 0)
{
    if(n == s.length())
    {
        return true;
    }
    int digit = s[n] - '0';

    if(n % 2 == 0)
    {
        if(digit % 2 != 0)
        {
            return false;
        }
    }
    else
    {
        if(!isPrime(digit))
        {
            return false;
        }
        
    }
    return isGoodString(s,n+1);
}


int main()
{
    string digits_string[] = {"02468","23578" ,"224365"};
    for(string digits : digits_string)
    {
        bool isGood = isGoodString(digits , 0);
        cout<<"Digit string: "<<digits << " is: " << (isGood ? "Good" : "Not Good")<<endl;
    }
    return 0;
}
