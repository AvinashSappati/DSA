#include<bits\stdc++.h>
using namespace std;
int CountDigit(int n)
{
      int cnt = (int)(log10(n) + 1);
      return cnt;
}
int main()
{
      int n;
      cout << "Enter a number : " ;
      cin >> n;
      cout << "The number of digits in " << n << " are " << CountDigit(n);
}
