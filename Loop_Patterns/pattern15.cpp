/*
PATTERN-14:
(n=5)
A B C D E 
A B C D 
A B C 
A B
A
*/
#include<bits\stdc++.h>
using namespace std;
void patt14(int n)
{
      for(int i=0;i<n;i++)
      {     
            char ch = 'A';
            for(int j=0;j<=(n-i-1);j++)
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
      patt14(n);
      return 0;
}