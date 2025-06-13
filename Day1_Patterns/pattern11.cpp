/*
( n = 5)
1
0 1 
1 0 1
0 1 0 1
1 0 1 0 1

*/
#include<bits\stdc++.h>
using namespace std;
void patt11(int n )
{
      int start = 0;
      for(int i=0;i<n;i++)
      {
            if(i%2 == 0) start=1;
            for(int j=0;j<=i;j++)
            {
                  cout << start;
                  start = 1 - start;
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt11(n);
      return 0;
}