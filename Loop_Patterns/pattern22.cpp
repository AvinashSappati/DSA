/*
[GOOD ONE ]
PATTERN-22:
( n = 4 )  [subtracting all from n we get ]
4 4 4 4 4 4 4       0 0 0 0 0 0 0
4 3 3 3 3 3 4       0 1 1 1 1 1 0
4 3 2 2 2 3 4       0 1 2 2 2 1 0
4 3 2 1 2 3 4   --> 0 1 2 3 2 1 0
4 3 2 2 2 3 4       0 1 2 2 2 1 0
4 3 3 3 3 3 4       0 1 1 1 1 1 0
4 4 4 4 4 4 4       0 0 0 0 0 0 0
*/
//(2n-1) x (2n-1) Matrix
//[Distance of any element ] 
/*
top = i , left = j 
right = (2n-1)-1-j
bottom = (2n-1)-1-i
*/
#include<bits\stdc++.h>
using namespace std;

void patt22(int n)
{
      for(int i=0;i<2*n-1;i++)
      {
            for(int j=0;j<2*n-1;j++)
            {
                  int top = i;
                  int left = j ;
                  int right = (2*n-2) - j;
                  int down = (2*n -2 ) - i;
                  cout << (n-min(min(top,down),min(left,right)));
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt22(n);
      return 0;
}
