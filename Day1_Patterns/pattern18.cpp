/*
PATTERN-18:
E 
D E
C D E
B C D E
A B C D E
*/
//ch = ch-i (row to row updation) , ch++
#include<bits/stdc++.h>
using namespace std;
void patt18(int n)
{     
      for(int i=0;i<n;i++)
      {
            char ch = 'E';
            ch = ch - i;
            for(int j=0;j<=i;j++)
            {
                  cout << ch;
                  ch++;
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt18(n);
      return 0;
}