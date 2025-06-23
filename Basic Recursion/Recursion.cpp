/*
RECURSION :
When a function calls itself until a specified condition is met

->RECURSION
->Base Case
->StackOverflow | stack space
->Recurison Tree
*/
//(Q1)Print name N times if(i>n) return; sc,tc are O(n)
//(Q2)Print linearly from 1 to N TC,SC->O(n)

/* (Que)Print N to 1 with backtracking*/
#include<bits\stdc++.h>
using namespace std;
void print(int i,int n)
{
      if(i > n) return;
      print(i+1,n);
      cout << i << " ";
}
int main()
{
      int n;
      cin >> n;
      print(1,n);
      return 0;
}