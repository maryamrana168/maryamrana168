#include <iostream>
using namespace std;

int  countWays(int stairsCount)
{
    if(stairsCount == 0)
    {
        return  0;
    }
    if(stairsCount == 1)
    {
        return  1;
    }
    if(stairsCount == 2)
    {
        return  2;
    }

    return countWays(stairsCount-1) + countWays(stairsCount-2);

}



int main()
{
    int n;
    cout<<"Enter no. of stairs ";
    cin>>n;

    cout<< "The no. of ways to climb "<<n<<" stairs are : " << countWays(n)<<endl;
    return 0;
}