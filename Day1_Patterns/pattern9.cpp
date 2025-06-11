/*
PATTERN-9:
( n = 5 )
        *
      * * *
    * * * * * 
  * * * * * * *
* * * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
*/
#include<bits\stdc++.h>
using namespace std;

void patt9(int n)
{
      for(int i=0; i<n; i++)
      {
            //three loops for [ spaces , stars , spaces ]
            for(int j=0 ; j <= n-i-1 ; j++)
            {
                  cout << " ";
            }

            for(int j=0 ; j < 2*i + 1 ; j++)
            {
                  cout << "*";
            }

            for(int j=0 ; j <= n-i-1 ; j++)
            {
                  cout << " ";
            }
            cout << endl;
      }
      for(int i= 0 ; i < n ; i++)
      {     ""
            cout << " ";
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
      patt9(n);
      return 0;
}