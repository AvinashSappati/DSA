## Problem Name: Intersection of Two Sorted Arrays

**Difficulty:** Easy  
**Pattern:** Two Pointers

### The "Brute" vs. "Optimal" Logic

* **Brute Force:**
    For every element in `arr2`, iterate through `arr1` to find a match. To handle duplicates (e.g., matching a `2` with a `2` only once), keep a "visited" array for `arr2`.
    * *Time Complexity:* $O(N_1 \times N_2)$.
    * *Space Complexity:* $O(N_2)$ (visited array).

* **Optimal (Two Pointers):**
    Since arrays are sorted, we can traverse them together.
    1.  Initialize `i = 0` (for `arr1`) and `j = 0` (for `arr2`).
    2.  **While** `i < n1` and `j < n2`:
        * If `arr1[i] < arr2[j]`: Increment `i` (Need a larger number to match).
        * If `arr1[i] > arr2[j]`: Increment `j` (Need a larger number to match).
        * If `arr1[i] == arr2[j]`: **Match Found!** Add to answer vector. Increment **both** `i` and `j`.
    * *Time Complexity:* $O(N_1 + N_2)$.
    * *Space Complexity:* $O(1)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **No "Remaining Elements" Loop:**
    Unlike Union, you do **not** need to process the rest of the array once one pointer reaches the end. Intersection requires elements to be in *both*, so if one ends, no more intersections are possible.

2.  **Multiple Duplicates:**
    If `arr1 = [2, 2, 3]` and `arr2 = [2, 2, 2, 4]`, the output should be `[2, 2]`.
    The standard Two Pointer logic (`i++, j++` on match) handles this automatically because it "consumes" one instance from both arrays simultaneously.
