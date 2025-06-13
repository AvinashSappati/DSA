/*
PATTERN-17:
(n=4)
      A
    A B A
  A B C B A
A B C D C B A 
*/
//[spaces,triangle,spaces]
// j-> n-i spaces per row x 2 
// j-> 2*i-1 alphabets per row 
// => condition (j<=((2*i-1)/2)) ch++
#include<bits\stdc++.h>
using namespace std;

void patt17(int n)
{
      for(int i=1;i<=n;i++)
      {
            char ch = 'A';
            //spaces
            for(int j=1;j<=(n-i);j++)
            {
                  cout << " ";
            }
            //alphabets
            int breakpoint = (2*i-1)/2;
            for(int j=1;j<=(2*i-1);j++)
            {     
                  cout << ch ;
                  if(j <= breakpoint) ch++;
                  else ch--;
            }

            for(int j=1;j<=(n-i);j++)
            {
                  cout << " ";
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt17(n);
      return 0;
}