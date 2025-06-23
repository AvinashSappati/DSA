#include<bits/stdc++.h>
using namespace std;
void Armstrong(int n) {
    int m = n;
    int ld, sum = 0;
    int digits = (int)(log10(n)+1); // count of digits

    while (n > 0) {
        ld = n % 10;
        sum += pow(ld, digits);
        n /= 10; //division by n takes O(logn()) time complexity
    }

    if (sum == m)
        cout << "It is an Armstrong number";
    else
        cout << "It is not an Armstrong number";
}
int main()
{
      int n;
      cin >> n;
      Armstrong(n);
      return 0;
}