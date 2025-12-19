## Problem Name: Next Permutation

**Difficulty:** Medium  
**Pattern:** Observation / "Break Point" Logic

### The "Brute" vs. "Optimal" Logic

* **Brute Force:**
    Generate all possible permutations (sorted), search for the current one, and return the next one in the list.
    * *Time Complexity:* $O(N! \times N)$ (Factorial time - impossible for large N).
    * *Space Complexity:* $O(N!)$.

* **Better (C++ STL):**
    Simply use the built-in library function: `next_permutation(nums.begin(), nums.end());`.
    * *Interview Note:* Good to know, but the interviewer will ask you to implement it manually.

* **Optimal (Observation - Single Pass):**
    **Core Idea:** The "next" permutation is just the *next smallest number* greater than the current number formed by the digits.
    
    1.  **Find the Break Point (`ind`):**
        Traverse from the **back** of the array. Find the first index `i` where `nums[i] < nums[i+1]`.
        * This marks the point where the increasing sequence (from the back) stops.
        * If no such point is found (array is like `5 4 3 2 1`), just reverse the whole array (it's the last permutation, so next is the first).
    
    2.  **Find the Swap Candidate:**
        Traverse from the **back** again. Find the first number that is **greater** than `nums[ind]`.
        * Swap `nums[ind]` with this number.
    
    3.  **Minimize the Suffix:**
        The part of the array to the right of `ind` is still in descending order (e.g., `4 3 2 1`). To make the permutation "smallest", we need this part to be ascending.
        * **Action:** **Reverse** the subarray from `ind + 1` to the end. (No need to sort!).
    
    * *Time Complexity:* $O(3N)$ $\approx O(N)$ (finding break point + finding swap + reversing).
    * *Space Complexity:* $O(1)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **Sorting vs. Reversing:**
    * **My Code:** I used `sort(nums.begin() + i, nums.end())`.
    * **Correction:** While `sort` gives the correct answer, it takes $O(N \log N)$. Since the suffix is guaranteed to be in descending order, `reverse()` achieves the same result in $O(N)$ time.

2.  **Edge Case (Last Permutation):**
    * If the array is `[3, 2, 1]`, the loop to find the break point will finish without finding anything. You must handle this case separately by reversing the entire array to `[1, 2, 3]`.

3.  **Strict Inequality:**
    * When finding the swap candidate from the back, ensure you look for `nums[j] > nums[ind]`, not `>=`. We need a strictly larger number to create the *next* permutation.
