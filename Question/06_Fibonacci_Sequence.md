# Fibonacci Sequence


## Question 1 - 70. Climbing Stairs

```
Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

[video explaination](https://www.youtube.com/watch?v=Y0lT9Fck7qI)

### Approach

[leetcode solution](https://leetcode.com/problems/climbing-stairs/solutions/3708750/4-method-s-beat-s-100-c-java-python-beginner-friendly/)

1. Recursion

Explanation: The recursive solution uses the concept of Fibonacci numbers to solve the problem. It calculates the number of ways to climb the stairs by recursively calling the climbStairs function for (n-1) and (n-2) steps. However, this solution has exponential time complexity (O(2^n)) due to redundant calculations.


```java
class Solution {
    public int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
}
```

2. **Memoization**

Explanation: The memoization solution improves the recursive solution by introducing memoization, which avoids redundant calculations. We use an unordered map (memo) to store the already computed results for each step n. Before making a recursive call, we check if the result for the given n exists in the memo. If it does, we return the stored value; otherwise, we compute the result recursively and store it in the memo for future reference.


```java
class Solution {
    public int climbStairs(int n) {
        Map<Integer, Integer> memo = new HashMap<>();
        return climbStairs(n, memo);
    }
    
    private int climbStairs(int n, Map<Integer, Integer> memo) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (!memo.containsKey(n)) {
            memo.put(n, climbStairs(n-1, memo) + climbStairs(n-2, memo));
        }
        return memo.get(n);
    }
}
```

3. **Tabulation**

Explanation: The tabulation solution eliminates recursion and uses a bottom-up approach to solve the problem iteratively. It creates a DP table (dp) of size n+1 to store the number of ways to reach each step. The base cases (0 and 1 steps) are initialized to 1 since there is only one way to reach them. Then, it iterates from 2 to n, filling in the DP table by summing up the values for the previous two steps. Finally, it returns the value in the last cell of the DP table, which represents the total number of ways to reach the top.
















