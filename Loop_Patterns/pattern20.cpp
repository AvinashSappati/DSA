/*
PATTERN-20:
(n=5)
*                 * 
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *
*/
#include<bits\stdc++.h>
using namespace std;

void patt20(int n)
{
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<=i;j++)
            {
                  cout << "*";
            }
            for(int j=0;j<2*(n-i-1);j++)
            {
                  cout << " ";
            }
            for(int j=0;j<=i;j++)
            {
                  cout << "*";
            }
            cout << endl;
      }
      for(int i=1;i<n;i++)
      {
            for(int j=0;j<(n-i);j++)
            {
                  cout << "*";
            }
            for(int j=0;j<2*i;j++)
            {
                  cout << " ";
            }
            for(int j=0;j<(n-i);j++)
            {
                  cout << "*";
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt20(n);
      return 0;
}