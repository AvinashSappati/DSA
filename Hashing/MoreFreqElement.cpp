#include<bits\stdc++.h>
using namespace std;

//Input : [1,2,2,3,3,3]
//My Code [1.24mb , 6ms]
/*// Although O(n + m ) [m is due to min_element search] TC , but space O(n)[but map + vector] due to vectors is more !
// Before using vector think about TC,SC ! 
int mostFrequentElement(vector<int>& nums) 
{
      unordered_map<int,int> mpp;
      for(auto it : nums) mpp[it]++;
      int max = 0 ;
      int max_key = -1;
      vector<int> vec;
      for(auto it : mpp) 
      {
            if(it.second > max )
            {
                  max_key = it.first;
                  max = it.second;
                  vec.clear();
            }
            else if(it.second == max)
            {
                  vec.push_back(it.first);
                  vec.push_back(max_key);
            }
      }
      if(vec.size() == 0) return max;
      else 
      {
            int min = *min_element(vec.begin(),vec.end());
            return min;
      }   
}
*/

// [6ms , 1.23mb]
// TC Optimized code ! O(n) TC , SC only mapp 
int mostFrequentElement(vector<int>& nums) 
{
    unordered_map<int, int> freq;

    // Count frequencies
    for (int num : nums)
        freq[num]++;

    int maxFreq = 0;
    int result = INT_MAX;

    // Find element(s) with max frequency
    for (auto& it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            result = it.first;
        } else if (it.second == maxFreq) {
            result = min(result, it.first);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 2, 3, 3};  // sample input
    int ans = mostFrequentElement(nums);
    cout << "Most frequent element: " << ans << endl;
    return 0;
}
