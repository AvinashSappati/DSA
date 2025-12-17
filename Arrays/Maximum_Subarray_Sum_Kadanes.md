## Problem Name: Maximum Subarray Sum (Kadane's Algorithm)

**Difficulty:** Medium  
**Pattern:** Kadane's Algorithm (Greedy / Dynamic Programming)

### The "Brute" vs. "Optimal" Logic

* **Brute Force:**
    Generate all possible subarrays using nested loops ($i$ and $j$), calculate their sums, and find the maximum.
    * *Time Complexity:* $O(N^3)$ (if sum is calculated from scratch) or $O(N^2)$ (if carrying forward the sum).
    * *Verdict:* TLE.

* **Optimal (Kadane's Algorithm):**
    **Core Idea:** "Carry the sum as long as it gives you a positive hope. If it turns negative, drop it."
    
    1.  Initialize `sum = 0` and `maxi = INT_MIN`.
    2.  Iterate through the array:
        * Add current element to `sum` (`sum += arr[i]`).
        * **Crucial Step 1:** Update `maxi` immediately: `maxi = max(maxi, sum)`.
        * **Crucial Step 2:** If `sum < 0`, reset `sum` to `0`. (Because a negative sum will only reduce the value of any future subarray).

    * *Time Complexity:* $O(N)$.
    * *Space Complexity:* $O(1)$.

### Extension: Printing the Subarray
Striver often asks to **print** the subarray, not just the sum.
* Maintain `start`, `ansStart`, and `ansEnd` variables.
* Whenever `sum == 0` (after a reset), set `start = i` (technically `i+1` for next iteration).
* When updating `maxi`, update the answer indices: `ansStart = start`, `ansEnd = i`.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The "All Negative" Array:**
    * *Mistake:* Initializing `maxi = 0`.
    * *Why it fails:* If the array is `[-2, -1, -5]`, the answer should be `-1`. If you initialize with 0, you will return 0, which is wrong (empty subarray is not allowed usually).
    * *Fix:* Always initialize `maxi = INT_MIN` (or the first element `arr[0]`).

2.  **Order of Operations:**
    * You must update `maxi` **before** resetting `sum` to 0.
    * *Example:* If array is `[-1]`.
        * `sum` becomes -1.
        * `maxi` becomes -1 (Correct).
        * `sum` resets to 0.
    * If you swap them, `maxi` might incorrectly record 0 or miss the negative max.
