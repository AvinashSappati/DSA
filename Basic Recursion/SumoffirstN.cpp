// two ways : parameterized,functional
// Best for this question is iterative with O(1) SC,TC.
#include<bits\stdc++.h>
using namespace std;
/*
int firstN(int i,int sum)
{
      if(i<1) return sum;
      firstN(i-1,sum+i);
}
int main()
{
      int n;
      cin >> n;
      cout << firstN(n,0);
      return 0;
}
*/

//functional
int firstN(int n)
{
      if(n>0)
      {
            if(n==1) return 1;
            return n + firstN(n-1);
      }
      return -1;
}
int main()
{
      int n;
      cin >> n;
      cout << firstN(n);
      return 0;
}
