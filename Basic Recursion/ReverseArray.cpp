// REVERSE OF AN ARRAY
/*
#include<iostream>
using namespace std;
void RevArr(int i , int arr[],int n)
{
    for(int i=0;i<=n/2;i++)
    {
        swap(arr[i],arr[n-i-1]);
    }    
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    RevArr(0,arr,n);
    for(int i=0;i<n;i++) cout << arr[i];
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
void RevArr(int i , int arr[],int n)
{
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    RevArr(i+1,arr,n);
    
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    RevArr(0,arr,n);
    for(int i=0;i<n;i++) cout << arr[i];
    return 0;
}
*/
#include<iostream>
using namespace std;
void RevArr(int l , int arr[],int r)
{
    if(l>=r) return;
    swap(arr[l],arr[r]);
    RevArr(l+1,arr,r-1);
    
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    RevArr(0,arr,n-1);
    for(int i=0;i<n;i++) cout << arr[i];
    return 0;
}