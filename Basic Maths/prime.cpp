#include<bits\stdc++.h>
using namespace std;
void CheckPrime(int n)
{
      //O(sqrt(n))
      int cnt = 0;
      for(int i = 1; i*i <= n ; i++)
      {
            if(n%i==0) 
            {
                  cnt++;
                  if((n/i) != i) cnt++;
            }
      }
      if(cnt == 2 ) cout << "true";
      else cout << "false";
}
int main()
{
      int n;
      cin >> n;
      CheckPrime(n);
      return 0;
}