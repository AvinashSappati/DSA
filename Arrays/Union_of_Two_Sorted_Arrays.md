## Problem Name: Union of Two Sorted Arrays

**Difficulty:** Medium  
**Pattern:** Two Pointers (Merge Step of Merge Sort)

### The "Brute" vs. "Optimal" Logic

* **Brute Force (Using Set):**
    Insert all elements from `arr1` and `arr2` into a `set` (or `TreeSet` in Java). The set automatically handles duplicates and sorting. Then convert the set back to a vector.
    * *Time Complexity:* $O((N_1 + N_2) \log(N_1 + N_2))$ (due to set insertion).
    * *Space Complexity:* $O(N_1 + N_2)$ (for the set).

* **Optimal (Two Pointers):**
    Use two pointers `i` (for `arr1`) and `j` (for `arr2`).
    1.  Compare `arr1[i]` and `arr2[j]`.
    2.  If `arr1[i]` is smaller: Try to push `arr1[i]` to `Union`. Increment `i`.
    3.  If `arr2[j]` is smaller: Try to push `arr2[j]` to `Union`. Increment `j`.
    4.  If they are equal: Try to push `arr1[i]` (or `arr2[j]`) to `Union`. Increment **both** `i` and `j`.
    5.  **Clean Up:** After one array is exhausted, push the remaining elements of the other array.

    **The "Push" Logic (To avoid duplicates):**
    Before pushing any element `val` into the `Union` vector, check:
    `if (Union.size() == 0 || Union.back() != val)`
    Only push if the vector is empty OR the last element added is different from `val`.

    * *Time Complexity:* $O(N_1 + N_2)$.
    * *Space Complexity:* $O(1)$ (excluding the space for the returned answer).

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The "Remaining Elements" Loop:**
    A common mistake is stopping the code as soon as one array finishes (i.e., when `i < n1 && j < n2` becomes false).
    * **Fix:** You **must** have two extra `while` loops at the end to process the remaining elements of whichever array is longer.

2.  **Duplicate Handling:**
    Simply checking `arr1[i] == arr2[j]` isn't enough to handle duplicates *within* a single array (e.g., `[1, 1, 2]`).
    * **Fix:** The check `Union.back() != val` handles duplicates coming from *both* arrays and *within* the same array.
