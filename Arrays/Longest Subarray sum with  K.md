## Problem Name: Longest Subarray with Sum K

**Difficulty:** Medium  
**Pattern:** 1. **Positives Only:** Sliding Window (Two Pointers)  
2. **Positives & Negatives:** Hashing (Prefix Sum Map)

### The "Brute" vs. "Optimal" Logic

* **Brute Force:** Generate all subarrays using nested loops ($i$ and $j$), sum them up, and check if `sum == K`.  
    *Time Complexity:* $O(N^2)$ (TLE).

* **Optimal 1 (For Positives & Zeros Only): Two Pointers / Sliding Window** Use `left` and `right` pointers. Maintain a `currentSum`.
    1.  Add `arr[right]` to `currentSum`.
    2.  **While** `currentSum > K`, shrink window from the left (`currentSum -= arr[left]`, `left++`).
    3.  If `currentSum == K`, update `maxLen = max(maxLen, right - left + 1)`.
    *Time Complexity:* $O(2N)$.  
    *Space Complexity:* $O(1)$.

* **Optimal 2 (For Positives, Negatives & Zeros): Hashing / Prefix Sum** Use a Map (`map<long long, int>`) to store `{prefixSum, index}`.
    1.  Iterate and calculate `sum`.
    2.  If `sum == K`, `maxLen = i + 1`.
    3.  If `(sum - K)` exists in map, it means the subarray between that old index and current `i` is $K$.
        * `maxLen = max(maxLen, i - map[sum - K])`.
    4.  **Crucial:** Only add `sum` to the map if it doesn't exist already (to preserve the leftmost index).
    *Time Complexity:* $O(N \log N)$ (Ordered Map) or $O(N)$ (Unordered Map).  
    *Space Complexity:* $O(N)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The Negative Number Trap:** Do **not** use the Two Pointer/Sliding Window method if the array contains negative numbers. It fails because the sum doesn't monotonically increase, so you don't know when to shrink the window. You *must* use Hashing for negatives.

2.  **The Zero Trap (Hashing):** If the array has zeros (e.g., `[2, 0, 0, 3]`), the `prefixSum` stays the same multiple times. Always check `if (map.find(sum) == map.end())` before inserting into the map. If you overwrite the index, you lose the longest subarray potential.
