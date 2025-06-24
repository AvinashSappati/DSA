#include<bits\stdc++.h>
using namespace std;
vector<int> fibb(int n)
{
      if(n==0) return {0};
      if(n==1) return {0,1};

      vector<int> vec = fibb(n-1);
      int size = vec.size();
      vec.emplace_back(vec[size-1]+vec[size-2]);
      return vec;
}
int main()
{
      int n;
      cin >> n;
      for(auto it : fibb(n) ) cout << it << " ";
      return 0;
}