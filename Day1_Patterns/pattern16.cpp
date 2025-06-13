/*
PATTERN-16:
(n=5)
A
B B
C C C
D D D D
E E E E E
*/
#include<bits\stdc++.h>
using namespace std;
void patt16(int n)
{
      char ch = 'A';
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<=i;j++)
            {
                  cout << ch;
            }
            ch++;
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt16(n);
      return 0;
}
