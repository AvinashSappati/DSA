//NUMBER HASHING 

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    
    //Hash array.(12 is maax. number in the array)
    int hash[13] = {0};
    for(int i=0;i<n;i++) hash[arr[i]] += 1;
    
    //No. of numbers you want to enter to find its frequency.(q)
    int q;
    cin >> q;
    while(q--)
    {
        int number;
        cin >> number;
        cout << "Number of times " << number << "appears :"<< hash[number] << endl;
    }
    //int max.size in main declaration (1e6) and globally (1e7)
    //bool max. size in main declaration (1e7) and globally (1e8)
    return 0;
}