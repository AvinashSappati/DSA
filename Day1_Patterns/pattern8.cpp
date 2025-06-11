/*
PATTERN-8:
( n = 5 )
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
*/
//[n-i ,2*i-1,n-i]  5->1
#include<bits\stdc++.h>
using namespace std;

void patt8(int n)
{
      for(int i= 0 ; i < n ; i++)
      {
            for (int j = 0 ; j < i ; j++)
            {
                  cout << " " ;
            }

            for ( int j = 0 ; j < 2*n-(2*i + 1) ; j++)
            {
                  cout << "*";
            }

            for (int j = 0 ; j < i ; j++)
            {
                  cout << " " ;
            }
            cout << endl ;
      }
}
int main()
{
      int n;
      cin >> n;
      patt8(n);
      return 0;
}