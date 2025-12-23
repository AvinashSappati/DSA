## Problem Name: Best Time to Buy and Sell Stock

**Difficulty:** Easy  
**Pattern:** Greedy / Dynamic Programming (Keeping track of minimum)

### The "Brute" vs. "Optimal" Logic

* **Brute Force:**
    Use two nested loops. For every day `i` (buy), check every future day `j` (sell) where `j > i`. Calculate profit `prices[j] - prices[i]` and store the maximum.
    * *Time Complexity:* $O(N^2)$ (TLE for large inputs).
    * *Space Complexity:* $O(1)$.

* **Optimal (One Pass):**
    **Core Idea:** If you sell on day `i`, you want to have bought on the day with the **lowest price** *before* day `i`.
    
    1.  Initialize `minPrice = INT_MAX` and `maxProfit = 0`.
    2.  Iterate through the array of prices:
        * **Step 1 (Update Min):** `minPrice = min(minPrice, prices[i])`. (Assume we bought here if it's cheaper than before).
        * **Step 2 (Check Profit):** `currentProfit = prices[i] - minPrice`.
        * **Step 3 (Update Max):** `maxProfit = max(maxProfit, currentProfit)`.

    
    * *Time Complexity:* $O(N)$ (One pass).
    * *Space Complexity:* $O(1)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **Sequence is Key:**
    * **Mistake:** Simply doing `max(array) - min(array)`.
    * **Why it fails:** This ignores time. If prices are `[7, 1, 5, 3, 6, 4]`, `max` is 7 and `min` is 1. But 7 comes *before* 1, so you can't buy at 1 and sell at 7. You must iterate and track `minPrice` dynamically.

2.  **No Profit Possible:**
    * If the prices are strictly decreasing (e.g., `[7, 6, 4, 3, 1]`), you should return `0`, not a negative number. Initializing `maxProfit = 0` handles this automatically.
