## Problem Name: Sort an array of 0s, 1s, and 2s (Sort Colors)

**Difficulty:** Medium  
**Pattern:** Dutch National Flag Algorithm (Three Pointers)

### The "Brute" vs. "Optimal" Logic

* **Brute Force:** Simply sort the array using a standard sorting algorithm like Merge Sort.
    * *Time Complexity:* $O(N \log N)$.
    * *Space Complexity:* $O(1)$ or $O(N)$ depending on the sort.

* **Better:** Iterate through the array to count the number of `0`s, `1`s, and `2`s. Then, overwrite the array based on these counts.
    * *Time Complexity:* $O(2N)$ (Two passes).
    * *Space Complexity:* $O(1)$.

* **Optimal (Dutch National Flag):** Use 3 pointers (`low`, `mid`, `high`).
    * `low` points to the beginning (boundary of 0s).
    * `mid` traverses the array (boundary of 1s).
    * `high` points to the end (boundary of 2s).

    **Algorithm:**
    1.  **While** `mid <= high`:
    2.  If `arr[mid] == 0`: Swap `arr[low]` and `arr[mid]`. Increment `low`, Increment `mid`.
    3.  If `arr[mid] == 1`: Just Increment `mid`.
    4.  If `arr[mid] == 2`: Swap `arr[mid]` and `arr[high]`. Decrement `high`. **(Crucial: Do NOT increment mid here)**.

    * *Time Complexity:* $O(N)$ (One pass).
    * *Space Complexity:* $O(1)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The "2" Swap Trap:** When `arr[mid] == 2`, we swap it with `arr[high]` and decrement `high`.
    * **Mistake:** I often increment `mid` here automatically.
    * **Correction:** Do **NOT** increment `mid`. The element swapped from `high` to `mid` has not been processed yet (it could be a `0` or `2`). We need to check it again in the next iteration.

2.  **Loop Condition:** The loop runs while `mid <= high`. If you use `mid < high`, you might miss the middle element if the array size is odd or specific permutations occur.
