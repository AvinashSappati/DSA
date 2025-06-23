/*
PATTERN-21:
(n=4)
* * * *
*     *
*     *
* * * *
*/
#include<bits\stdc++.h>
using namespace std;

void patt21(int n)
{
      for(int i=1;i<=n;i++)
      {
            if( i==1 || i==n )
            {
                  for(int j=0;j<n;j++) cout<< "*";
                  cout << endl;
                  continue;
            }
            cout << "*";
            for(int j=0;j<(n-2);j++) cout << " ";
            cout << "*";
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt21(n);
      return 0;
}