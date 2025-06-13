/*
PATTERN-7:
( n = 5 )
        *
      * * *
    * * * * * 
  * * * * * * *
* * * * * * * * * 

*/
// 5 rows , [ spaces , stars , spaces ] -> 3 triangles 
/*
[ n-i-1 , 2*i + 1 , n-i-1]
[ 4 , 1 , 4]
[ 3 , 3 , 3] 
[ 2 , 5 , 2]
[ 1 , 7 , 1]
[ 0 , 9 , 0]
*/
#include<bits\stdc++.h>
using namespace std;

void patt7(int n)
{
      for(int i=0; i<n; i++)
      {
            //three loops for [ spaces , stars , spaces ]
            for(int j=0 ; j <= n-i-1 ; j++)
            {
                  cout << " ";
            }

            for(int j=0 ; j < 2*i + 1 ; j++)
            {
                  cout << "*";
            }

            for(int j=0 ; j <= n-i-1 ; j++)
            {
                  cout << " ";
            }
            cout << endl;
      }
}
int main()
{
      int n;
      cin >> n;
      patt7(n);
      return 0;
}

 