/*
PATTERN-12:
(n = 4)
1             1
1 2         2 1
1 2 3     3 2 1
1 2 3 4 4 3 2 1
*/

// [triangle,space-triangle,triangle]
// num = 1 , num++ ,j<i 
// j->2*(n-i) spaces 
// num = i , num-- , j<i  
#include<bits\stdc++.h>
using namespace std;
void patt12(int n)
{
      for(int i=1;i<=n;i++)
      {
            int num = 1;
            for(int j=1;j<=i;j++)
            {
                  cout << num;
                  num++;
            }

            for(int j=1;j<=2*(n-i);j++)
            {
                  cout << " ";
            }

            num = i;
            for(int j=1;j<=i;j++)
            {
                  cout << num;
                  num--;
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt12(n);
      return 0;
}