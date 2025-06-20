#include<bits\stdc++.h>
using namespace std;
int CountDigit(int n)
{
      int ld;
      int cnt = 0;
      while(n>0)
      {
            ld = n%10;
            n = n/10;
            cnt++;
      }
      return cnt;
}
int main()
{
      int n;
      cout << "Enter a number : " ;
      cin >> n;
      cout << "The number of digits in " << n << " are " << CountDigit(n);
}