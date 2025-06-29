#include<bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[] , int n )
{
    for(int i = 0 ; i < n-1 ; i++ )
    {
        for(int j=i;j>=0;j--)
        {
            if(arr[j] > arr[j+1] )
            {    
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }    
        }
    }   
    
}    
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(auto &it : arr ) cin >> it;// 13 , 46 , 24 , 52 , 20 , 9
    InsertionSort(arr,n);
    for(auto it : arr ) cout << it << " " ;
    return 0;
}