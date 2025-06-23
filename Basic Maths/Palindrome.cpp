#include<bits\stdc++.h>
using namespace std;
void Palindrome(int n) 
{
      int m = n;
      int revNum = 0;
      while(n>0)
      {
            int ld = n%10;
            revNum = revNum*10 + ld ;
            n = n/10;
      }
      if(revNum==m) cout << "True" ;
      else cout << "False";
}
int main()
{
      int n;
      cin >> n;
      Palindrome(n);
      return 0;
}