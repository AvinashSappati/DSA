## Problem Name: Rotate Image (Rotate Matrix 90° Clockwise)

**Difficulty:** Medium  
**Pattern:** Matrix Manipulation / Transpose + Reverse

### The "Brute" vs. "Optimal" Logic

* **Brute Force (Using Extra Matrix):**
    Create a new dummy matrix of the same size.
    * The first row of the source becomes the last column of the destination.
    * Formula: `ans[j][n - 1 - i] = matrix[i][j]`.
    * *Time Complexity:* $O(N^2)$.
    * *Space Complexity:* $O(N^2)$ (Not allowed since the problem asks for **In-Place**).

* **Optimal (In-Place Transpose + Reverse):**
    **Core Observation:** A 90-degree clockwise rotation is mathematically equivalent to **Transposing** the matrix and then **Reversing** each row.

    1.  **Step 1: Transpose the Matrix**
        Convert rows to columns. Iterate through the matrix and swap `matrix[i][j]` with `matrix[j][i]`.
        * **Crucial:** The inner loop for `j` must start from `i` (or `i+1`), not `0`. If you start from 0, you will swap the elements back to their original positions.
    
    2.  **Step 2: Reverse Each Row**
        Iterate through every row `i` and reverse it: `reverse(matrix[i].begin(), matrix[i].end())`.

    * *Time Complexity:* $O(N^2)$ (One pass for transpose, one pass for reverse).
    * *Space Complexity:* $O(1)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The Double Swap (Transpose Bug):**
    * **Mistake:** `for(i=0..n) for(j=0..n) swap(matrix[i][j], matrix[j][i])`.
    * **Result:** Nothing changes. You swap (0,1) with (1,0), and later when `i=1, j=0`, you swap them back.
    * **Fix:** `for(i=0..n-2) for(j=i+1..n-1)`. Only traverse the upper triangle of the matrix.

2.  **Clockwise vs. Anti-Clockwise:**
    * **Clockwise:** Transpose -> Reverse Rows.
    * **Anti-Clockwise:** Transpose -> Reverse Columns (or Reverse Rows -> Transpose).
    * Memorize the difference so you don't panic if the interviewer flips the question.
