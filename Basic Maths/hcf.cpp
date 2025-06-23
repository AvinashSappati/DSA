#include<bits\stdc++.h>
using namespace std;
int hcf(int m,int n)
{
      int gcd = 1;
      // O(min(m,n)) -> Worst case 
      //for(int i=1;i<=min(m,n);i++)
      //{
      //      if(m % i == 0 && n % i == 0) 
      //      {
      //            gcd = i;
      //      }
      //}
      
      //BETTER THAN UPPER ONE !
      //for(int i=min(m,n);i>=1;i--)
      //{
      //      if(m % i == 0 && n % i ==0 )
      //      {
      //            gcd = i;
      //            return gcd;
      //      }
      //}

      //ANOTHER APPROACH gcd(m,n) = gcd(m%n,n)[acc. to conditions]
      // O(logphi(min(a,b)))
      while(m>0 && n>0)
      {
            if(m>n) m = m%n;
            else n = n % m;
      }
      if(m==0) gcd = n;
      else gcd = m;
      return gcd;

}
int main()
{
      int m,n;
      cin >> m,n;
      cout << hcf(m,n);
      return 0;
}