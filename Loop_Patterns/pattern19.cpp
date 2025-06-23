/*
PATTERN-19:
(n=5)
* * * * * * * * * * 
* * * *     * * * *
* * *         * * *
* *             * *
*                 *
*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
*/
#include<bits\stdc++.h>
using namespace std;
void patt19(int n)
{
      for(int i=0;i<2*n;i++)
      {
            if(i<n) 
            {
                  for(int j=0;j<(n-i);j++)
                  {
                        cout << "*" ;
                  }

                  for(int j=0;j<2*i;j++)
                  {
                        cout << " ";
                  }

                  for(int j=0;j<(n-i);j++)
                  {
                        cout << "*" ;
                  }
            }
            else
            {
                  for(int j=0;j<(i-n+1);j++)
                  {
                        cout << "*";
                  }

                  for(int j=0;j<2*(2*n-i-1);j++)
                  {
                        cout << " ";
                  }

                  for(int j=0;j<(i-n+1);j++)
                  {
                        cout << "*";
                  }
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt19(n);
      return 0;
}