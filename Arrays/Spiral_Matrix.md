## Problem Name: Spiral Matrix

**Difficulty:** Medium  
**Pattern:** Simulation / 4 Boundaries (Top, Bottom, Left, Right)

### The Logic

There is no "Brute Force" vs "Optimal" here. The solution is a direct simulation of the spiral movement. We strip off layers of the matrix one by one.

**Algorithm:**
1.  Define 4 pointers/boundaries:
    * `top = 0`, `bottom = n-1`
    * `left = 0`, `right = m-1`
2.  Loop while `top <= bottom` and `left <= right`:
    * **Step 1 (Right):** Traverse from `left` to `right`. Increment `top` (`top++`).
    * **Step 2 (Down):** Traverse from `top` to `bottom`. Decrement `right` (`right--`).
    * **Step 3 (Left):**
        * **Check:** `if (top <= bottom)` (Crucial! See "Gotcha").
        * Traverse from `right` to `left`. Decrement `bottom` (`bottom--`).
    * **Step 4 (Up):**
        * **Check:** `if (left <= right)` (Crucial!).
        * Traverse from `bottom` to `top`. Increment `left` (`left++`).

* *Time Complexity:* $O(M \times N)$ (We visit every element exactly once).
* *Space Complexity:* $O(1)$ (excluding output vector).

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The "L-Shape" Duplicate Bug:**
    * **Scenario:** Imagine a single row matrix `[1, 2, 3]`.
    * After Step 1 (Right), `top` increments. Now `top > bottom`.
    * Step 2 (Down) doesn't run.
    * **The Bug:** If you don't check `if (top <= bottom)` before Step 3 (Left), the code will blindly try to traverse "Left" on a row that has already been processed or doesn't exist.
    * **Fix:** Always check the loop condition again before executing Step 3 (moving Left) and Step 4 (moving Up).

2.  **Loop Indices:**
    * Be careful with `for` loop ranges.
    * Moving Right: `i` goes from `left` to `right`.
    * Moving Left: `i` goes from `right` to `left`.
    * Ensure you use the correct boundary variable for the fixed index (e.g., `matrix[top][i]` vs `matrix[bottom][i]`).
