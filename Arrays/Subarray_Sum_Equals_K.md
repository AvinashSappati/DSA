## Problem Name: Subarray Sum Equals K

**Difficulty:** Medium  
**Pattern:** Prefix Sum + Hashing

### The "Brute" vs. "Optimal" Logic

* **Brute Force:**
    Generate all subarrays using nested loops ($i$ and $j$), calculate the sum of each, and checks if `sum == k`.
    * *Time Complexity:* $O(N^2)$ (TLE).
    * *Space Complexity:* $O(1)$.

* **Optimal (Prefix Sum Map):**
    **Core Math:** The sum of a subarray from `i` to `j` is `PrefixSum[j] - PrefixSum[i-1]`.
    Therefore, we look for a previous prefix sum such that: `CurrentSum - OldSum = K` $\Rightarrow$ `OldSum = CurrentSum - K`.

    1.  Initialize a map `mpp` to store `{PrefixSum, Count}`.
    2.  **Important Initialization:** `mpp[0] = 1`. (This handles subarrays that start from index 0).
    3.  Iterate through the array, maintaining a `currentSum`.
    4.  Calculate `remove = currentSum - k`.
    5.  **Check Map:** If `remove` exists in the map, it means there are `mpp[remove]` subarrays ending here with sum `k`.
        * `count += mpp[remove]` (Add the frequency, not just 1).
    6.  **Update Map:** `mpp[currentSum]++`.

    * *Time Complexity:* $O(N \log N)$ (Ordered map) or $O(N)$ (Unordered map).
    * *Space Complexity:* $O(N)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **Map Logic (Key vs Value):**
    * **Mistake:** Storing `{index -> sum}` or checking `map.find(k)`.
    * **Correction:** You must store `{PrefixSum -> Frequency}`. We need to know **how many times** a specific prefix sum has appeared before to count all valid subarrays.

2.  **The Initialization `mpp[0] = 1`:**
    * If `nums = [3]` and `k = 3`, `currentSum` is 3. `remove` is `3-3 = 0`.
    * If you don't initialize `mpp[0] = 1`, you will miss this subarray because the map doesn't know a sum of 0 existed "before the array started".

3.  **Frequency vs. Existence:**
    * **Mistake:** `if (mpp.find(rem) != mpp.end()) count++;`
    * **Correction:** `count += mpp[rem];`
    * *Why?* If the array has negative numbers, the same prefix sum can occur multiple times (e.g., `[1, -1, 1, -1]`). You must add **all** previous occurrences.
