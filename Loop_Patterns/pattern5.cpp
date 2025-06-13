/*
PATTERN-5:
( n =5 )

* * * * *
* * * *
* * * 
* * 
*

*/
#include<bits\stdc++.h>
using namespace std;

void patt5(int n)
{
      for(int i=0; i < n;i++)
      {
            for(int j=0; j < n-i ; j++)
            {
                  cout << "* ";
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n ;
      patt5(n);
      return 0;
}