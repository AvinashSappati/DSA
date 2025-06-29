#include<bits/stdc++.h>
using namespace std;
/*
Best,Worst,Avg TC's are O(n²) [ sum of natural numbers ] from inside loop !
which was purely dominating the outside one O(n-1) ~ O(n) and swaps O(n)
SC : O(1) bcz , at the end temp and min_idx elemets taking  
extra space !.
*/
void Selectionsort ( int arr[] , int n)
{
    // we have to move out pointer upto last second element only !
    for(int i=0;i<=n-2;i++) 
    {
        int min_idx = i;
        //For un-sorted part of array !
        for(int j=i+1;j<=n-1;j++)//better to make j=i+1,optimized bcz j=i comparision always gives min_idx = j
        {
            if(arr[j] < arr[min_idx] ) min_idx = j;
        }
        //swapping
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }    
}    
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(auto &it : arr) cin >> it ;// 13,46,24,52,20,9
    Selectionsort(arr,n);
    for(auto it : arr ) cout << it << " " ;
    return 0;
}