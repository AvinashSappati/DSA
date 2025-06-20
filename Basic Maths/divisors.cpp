#include<bits\stdc++.h>
using namespace std;
vector<int> divisors(int n) 
{
      //We don't know how many factors may exist so vector container is suitable here
      vector<int> div;
      for(int i=1;i<=sqrt(n);i++)
      {
            if(n%i == 0 ) 
            {
                  div.emplace_back(i);
                  if( (n / i) != i) 
                        div.emplace_back(n/i);
            }
      }
      sort(div.begin(),div.end());

      return div;
}
int main()
{
      int n;
      cin >> n;
      for(auto it : divisors(n))
      {
            cout << it << " ";
      }
      return 0;
}