#include<bits/stdc++.h>
using namespace std;
// Pushing max to last by swapping and then unsorted to sorted !
void BubbleSort(int arr[] , int n )
{
    for(int i = n-1 ; i >= 0 ; i-- )
    {
        int didSwap = 0;//for making TC to be minimum ! 
        for(int j=0;j<i;j++)
        {
            if(arr[j] > arr[j+1] )
            {    
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }    
        }
        if(didSwap == 0 ) break ; 
        //normally for checking number of runs
        // cout << "runs\n" ;
    }   
    
}    
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(auto &it : arr ) cin >> it;// 13 , 46 , 24 , 52 , 20 , 9
    BubbleSort(arr,n);
    for(auto it : arr ) cout << it ;
    return 0;
}