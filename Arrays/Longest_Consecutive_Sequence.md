## Problem Name: Longest Consecutive Sequence

**Difficulty:** Medium  
**Pattern:** Hashing (Unordered Set)

### The "Brute" vs. "Optimal" Logic

* **Brute Force (Sorting):**
    Sort the array first. Then iterate through it and count consecutive elements.
    * *Time Complexity:* $O(N \log N)$ (due to sorting).
    * *Space Complexity:* $O(1)$ (if no copy made) or $O(N)$.
    * *Why isn't this best?* The problem usually asks for $O(N)$ time complexity.

* **Optimal (Hashing / Set):**
    **Core Idea:** Put everything into a `set` for $O(1)$ lookups. Only attempt to count a sequence if you are at the **start** of the sequence.

    1.  Insert all unique elements from the array into an `unordered_set`.
    2.  Iterate through the `set` (or the array):
        * Check if `currentNum - 1` exists in the set.
        * **If it exists:** It means `currentNum` is **NOT** the starting number of a sequence (e.g., if you have 3 and 4, don't start counting at 4). **Skip it.**
        * **If it does NOT exist:** This is the **start** of a sequence. Enter a `while` loop:
            * Check if `currentNum + 1` exists.
            * Keep incrementing `currentStreak` and `currentNum` until the sequence breaks.
    3.  Update `longestStreak = max(longestStreak, currentStreak)`.

    * *Time Complexity:* $O(N)$ (Assuming average $O(1)$ for set operations).
        * *Note:* Although there is a `while` loop inside a `for` loop, each number is visited at most twice (once to check if it's a start, and once inside the streak counting). Total time is roughly $O(3N)$.
    * *Space Complexity:* $O(N)$ (to store the set).

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The "Start of Sequence" Check:**
    * **Mistake:** Forgetting to check `!set.count(num - 1)`.
    * **Consequence:** If you don't skip numbers that aren't the start, you will re-count the same sequence multiple times. For an array like `[1, 2, 3, ... 1000]`, this turns your logic into $O(N^2)$, causing **TLE (Time Limit Exceeded)**.

2.  **Empty Array:**
    * If the input array is empty `[]`, your code should return `0`. Initializing `longestStreak = 0` handles this naturally.

3.  **Duplicates:**
    * The problem might contain duplicates (e.g., `[1, 2, 0, 1]`). Using a Set automatically handles this since we only care about the *presence* of numbers, not their frequency.
