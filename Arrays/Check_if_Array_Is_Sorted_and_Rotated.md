## Problem Name: Check if Array Is Sorted and Rotated

**Difficulty:** Easy  
**Pattern:** Linear Scan / "Cliff" Detection

### The Logic

The core idea is that a sorted array that has been rotated will have **at most one** place where the sorting order "breaks" (where `nums[i] > nums[i+1]`).

* **Step 1: Find the "Cliff" (First Break):**
    Iterate through the array. The first time you find `nums[i] > nums[i+1]`, that index `i` is your pivot point.

* **Case A: No Cliff Found:**
    If the loop finishes without finding any break, the array is perfectly sorted (0 rotations). Return `true`.

* **Step 2: Verify the Rest:**
    If you found a cliff at index `i`, you must ensure two things for it to be a valid rotation:
    1.  **The Second Segment:** The rest of the array (from `i+1` to end) must be perfectly sorted. If you find *another* drop, return `false`.
    2.  **The Wrap Around:** The last element must be smaller than or equal to the first element (`nums[n-1] <= nums[0]`). If `nums[n-1] > nums[0]`, it's impossible for them to connect back in a sorted order.

* *Time Complexity:* $O(N)$ (One pass).
* *Space Complexity:* $O(1)$.

### Alternative "One-Liner" Logic (Modulo Arithmetic)

You can simplify the logic by counting the total number of "drops" in the array, including the wrap-around check.
1.  Iterate from `0` to `n-1`.
2.  Count how many times `nums[i] > nums[(i+1) % n]`.
3.  If `count <= 1`, return `true`. Otherwise `false`.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The "Wrap Around" Condition:**
    It is easy to forget the final check. Even if the array has only one drop inside (e.g., `[2, 3, 4, 1, 5]`), it is invalid because `5 > 2`. The end must connect smoothly to the start.

2.  **Duplicate Values:**
    The problem allows duplicates (e.g., `[2, 2, 2, 1, 1, 2]`). Ensure your comparison uses strict inequality `>` for finding breaks. Using `>=` would trigger false drops on equal elements.
