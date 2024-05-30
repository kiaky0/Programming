# Visualisation for the code

### Problem Statement
We need to find the number of distinct ways to climb a staircase with `n` steps if we can take either 1 step or 2 steps at a time.

### Code Explanation

Here's the code for reference:

```java
class Solution {
    public int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```

### Step-by-Step Visualization with `n = 4`

1. **Initialization**:
   - If `n = 0` or `n = 1`, the function immediately returns 1. This is not the case for `n = 4`, so we proceed to the next step.
   - We create an array `dp` of size `n + 1` to store the number of ways to reach each step:
     ```java
     int[] dp = new int[n + 1];  // dp = [0, 0, 0, 0, 0]
     ```
   - We initialize the base cases:
     ```java
     dp[0] = 1;  // There's one way to stay at the ground (do nothing)
     dp[1] = 1;  // There's one way to reach the first step (take one step)
     // dp = [1, 1, 0, 0, 0]
     ```

2. **Filling the DP Array**:
   - We iterate from `i = 2` to `i = 4` and fill in the `dp` array.

   **Iteration for `i = 2`**:
   ```java
   dp[2] = dp[1] + dp[0];  // dp[2] = 1 + 1 = 2
   // dp = [1, 1, 2, 0, 0]
   ```
   Explanation:
   - To reach the 2nd step, you can either:
     - Come from the 1st step (1 way to reach the 1st step)
     - Come from the 0th step (1 way to reach the ground)
   - Thus, `dp[2] = dp[1] + dp[0] = 1 + 1 = 2`

   **Iteration for `i = 3`**:
   ```java
   dp[3] = dp[2] + dp[1];  // dp[3] = 2 + 1 = 3
   // dp = [1, 1, 2, 3, 0]
   ```
   Explanation:
   - To reach the 3rd step, you can either:
     - Come from the 2nd step (2 ways to reach the 2nd step)
     - Come from the 1st step (1 way to reach the 1st step)
   - Thus, `dp[3] = dp[2] + dp[1] = 2 + 1 = 3`

   **Iteration for `i = 4`**:
   ```java
   dp[4] = dp[3] + dp[2];  // dp[4] = 3 + 2 = 5
   // dp = [1, 1, 2, 3, 5]
   ```
   Explanation:
   - To reach the 4th step, you can either:
     - Come from the 3rd step (3 ways to reach the 3rd step)
     - Come from the 2nd step (2 ways to reach the 2nd step)
   - Thus, `dp[4] = dp[3] + dp[2] = 3 + 2 = 5`

3. **Returning the Result**:
   - The final result, which is the number of ways to reach the 4th step, is stored in `dp[4]`:
     ```java
     return dp[n];  // return dp[4] = 5
     ```

### Summary

- **Initialization**:
  - `dp` array: `[1, 1, 0, 0, 0]`

- **Iteration**:
  - For `i = 2`: `dp[2] = 1 + 1 = 2`
    - `dp` array: `[1, 1, 2, 0, 0]`
  - For `i = 3`: `dp[3] = 2 + 1 = 3`
    - `dp` array: `[1, 1, 2, 3, 0]`
  - For `i = 4`: `dp[4] = 3 + 2 = 5`
    - `dp` array: `[1, 1, 2, 3, 5]`

The final result is `dp[4] = 5`, meaning there are 5 distinct ways to climb a staircase with 4 steps. The dynamic programming approach ensures that we compute the number of ways efficiently by building on the results of smaller subproblems.
