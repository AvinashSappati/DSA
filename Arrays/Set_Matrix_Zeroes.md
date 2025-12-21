## Problem Name: Set Matrix Zeroes

**Difficulty:** Medium  
**Pattern:** In-Place Matrix Manipulation / Dummy Arrays

### The "Brute" vs. "Optimal" Logic

* **Brute Force (Copy Matrix):**
    Create a deep copy of the matrix. Iterate through the *original* matrix. If `original[i][j] == 0`, set row `i` and col `j` in the *copy* to 0.
    * *Time Complexity:* $O(MN)$.
    * *Space Complexity:* $O(MN)$ (Space is expensive).

* **Better (Row/Col Arrays):**
    Create two separate arrays: `rowCheck[m]` and `colCheck[n]`.
    1.  Iterate through the matrix. If `matrix[i][j] == 0`, mark `rowCheck[i] = 1` and `colCheck[j] = 1`.
    2.  Iterate through the matrix again. If `rowCheck[i] == 1` OR `colCheck[j] == 1`, set `matrix[i][j] = 0`.
    * *Time Complexity:* $O(2 \times MN)$.
    * *Space Complexity:* $O(M + N)$.

* **Optimal (In-Place using First Row/Col):**
    Instead of using extra arrays `rowCheck` and `colCheck`, use the **first row** and **first column** of the matrix itself as the markers.

    1.  **Handle Corner Case:** Check if the first row or first column *originally* contains any zeros. Store this in boolean flags (`firstRowZero`, `firstColZero`).
    2.  **Marking Step:** Iterate through the rest of the matrix (from `i=1, j=1`). If `matrix[i][j] == 0`:
        * Set `matrix[i][0] = 0` (Mark the row).
        * Set `matrix[0][j] = 0` (Mark the column).
    3.  **Filling Step:** Iterate from `i=1, j=1` again. If `matrix[i][0] == 0` OR `matrix[0][j] == 0`, set `matrix[i][j] = 0`.
    4.  **Final Cleanup:** If `firstRowZero` was true, zero out the first row. If `firstColZero` was true, zero out the first column.

    * *Time Complexity:* $O(2 \times MN)$.
    * *Space Complexity:* $O(1)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The "Ripple Effect" (Modifying while Iterating):**
    * **Mistake:** Finding a zero and *immediately* setting the entire row/column to zero inside the same loop.
    * **Consequence:** You introduce *fake* zeros into future rows. The loop later encounters these fake zeros and destroys parts of the matrix that should have been safe. **Always separate the "Marking" phase from the "Setting" phase.**

2.  **The `[0][0]` Collision:**
    * `matrix[0][0]` is part of both the first row and the first column.
    * You cannot use `matrix[0][0]` to track both. You generally need a separate variable (like `col0 = 1`) to track the status of the first column, while `matrix[0][0]` tracks the first row.
