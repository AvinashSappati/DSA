/*
PATTERN-2:
( n = 5)
*
**
***
****
*****
*/
#include<bits\stdc++.h>
using namespace std;

void patt2( int n)
{
      for ( int i = 0 ; i < n ; i++)
      {
            for ( int j = 0 ; j <= i ; j++)
            {
                  cout << "* ";
            }
            cout << endl ;
      }
}
int main()
{
      int n;
      cin >> n;
      patt2(n);
      return 0;
}