## Problem Name: Majority Element (> N/2 times)

**Difficulty:** Easy  
**Pattern:** Moore's Voting Algorithm

### The "Brute" vs. "Optimal" Logic

* **Brute Force:** Use two nested loops. Pick one element, count its occurrence in the rest of the array. If count > N/2, return it.
    * *Time Complexity:* $O(N^2)$.
    * *Space Complexity:* $O(1)$.

* **Better (Hashing):** Use a Map (`map<int, int>`) to store the frequency of each element.
    1.  Iterate through the array and update the count in the map.
    2.  If any element's count > `N / 2`, return that element.
    * *Time Complexity:* $O(N \log N)$ or $O(N)$ (depending on map).
    * *Space Complexity:* $O(N)$ (storing unique elements).

* **Optimal (Moore's Voting Algorithm):** Use `count` and `element` variables.
    **Logic:** The core idea is that if a number appears more than N/2 times, it will survive cancellations from all other numbers.
    1.  Initialize `count = 0` and `candidate = 0`.
    2.  Iterate through the array:
        * If `count == 0`: Set `candidate = arr[i]` and `count = 1`.
        * Else if `arr[i] == candidate`: Increment `count`.
        * Else (different element): Decrement `count`.
    3.  The `candidate` remaining at the end is the potential majority.
    * *Time Complexity:* $O(N)$.
    * *Space Complexity:* $O(1)$.

### The "Gotcha" (My Mistakes / Edge Cases)

1.  **The Verification Step:** Moore's Voting Algorithm only finds a *candidate*.
    * If the problem says "Majority element **always exists**" (like LeetCode), you can return the candidate immediately.
    * If the problem says "Majority element **might not exist**", you **MUST** run a second loop to count the occurrences of the `candidate` and verify it is truly > N/2.

2.  **Why it works:** Do not confuse this with simply "counting the most frequent". It only works specifically for > N/2 majority because the majority counts will always outnumber the minority counts combined.
