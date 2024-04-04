#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int returnPrime(int n)   //return prime number only
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return n;
}

int distinctPrime(int n)    //returning the number of distinct elements(prime factor).used the set container(unique elements)
{
     set<int> factor;
    for(int i=2;i<=sqrt(n);i++)   //factors will repeat after sqrt(n)
    {
        if(n%i==0)
        {
            if(returnPrime(i))
            {
                factor.insert(i);
            }
            if(n/i!=i)
            {
                  if(returnPrime(n/i))
            {
                factor.insert(n/i);
            }
            
            }
        }
    }
    return factor.size();
}
int main() {
 
     int num = 2;   //start of numbers
     while (true) {
        if (distinctPrime(num) == 4 && distinctPrime(num + 1) == 4 && distinctPrime(num + 2) == 4 &&  distinctPrime(num+3)== 4) 
            {

              cout << "Sequence of numbers found\n";
               cout << num << ", " << num + 1 << ", " << num + 2 << ", " << num + 3 <<endl;
               break; // Stop searching after finding the first sequence

            }

        // Move to the next number
        ++num;
    }

    return 0;
}