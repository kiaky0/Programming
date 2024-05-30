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

[Visualization](https://github.com/kiaky0/Programming/blob/main/Note/Tabulation_Explaination.md)

```java
class Solution {
    public int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        int[] dp = new int[n+1];
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
}
```


4. Space Optimization

Explanation: The space-optimized solution further reduces the space complexity by using only two variables (prev and curr) instead of an entire DP table. It initializes prev and curr to 1 since there is only one way to reach the base cases (0 and 1 steps). Then, in each iteration, it updates prev and curr by shifting their values. curr becomes the sum of the previous two values, and prev stores the previous value of curr.


```java
class Solution {
    public int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
}
```

## Question 2 - 198. House Robber



You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 
```
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

```


### Approach

[leetcode solution](https://leetcode.com/problems/house-robber/solutions/4600148/beats-100-c-java-python-js-explained-with-video-dynamic-programming-space-optimized/)

```java
class Solution {
    public int rob(int[] nums) {
        int rob = 0;
        int norob = 0;
        for (int i = 0; i < nums.length; i ++) {
            int newRob = norob + nums[i];
            int newNoRob = Math.max(norob, rob);
            rob = newRob;
            norob = newNoRob;
        }
        return Math.max(rob, norob);
    }
}
```

Note: The `rob` and `norob` is use to seperate two adjection number in the array.


## Question 3 - 213. House Robber II

跟上一题一样，不过他是个闭环第一个和最后一个数字算adjection

### Approach

[video solution](https://www.youtube.com/watch?v=hm3PPds59-0)

```java
class Solution {
    public int rob(int[] nums) {
        if(nums == null || nums.length == 0) return 0;

        if(nums.length == 1) return nums[0];
        if(nums.length == 2) return Math.max(nums[0], nums[1]);

        int res1 = helper(nums, 0, nums.length - 2);
        int res2 = helper(nums, 1, nums.length - 1);
        return Math.max(res1,res2);
    }

    private int helper(int[] nums, int start, int end){
        if(start == end) return nums[start];
        if(end-start == 1) return Math.max(nums[start], nums[end]);

        int[] dp = new int[end-start +1];

        dp[0] = nums[start];
        dp[1] = Math.max(nums[start], nums[start+1]);

        for(int i=2; i< dp.length; i++){
            dp[i] = Math.max(dp[i-2]+nums[start + i], dp[i-1]);
        }
        return dp[dp.length-1];
    }
}
```



