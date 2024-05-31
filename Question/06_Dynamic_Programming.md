# Dynamic Programming

## Fibonacci Sequence
--------------------------------------------------------------------------------------------------

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

## Question 4 - 64. Minimum Path Sum


Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


<div align="center"> <img src="https://github.com/kiaky0/Programming/assets/109141627/bd877441-63ab-49fa-992b-8967d5e12953" width="350px"> </div><br>

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

### Approach

[Video solution](https://www.youtube.com/watch?v=G59JEvLWEfU)

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        //initial row
        for(int j = 1; j<n; j++){
            grid[0][j] += grid[0][j-1];
        }
        //initial col
        for(int i = 1; i<m; i++){
            grid[i][0] += grid[i-1][0];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                grid[i][j] += Math.min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
}
```

Lowest runtime with Fibonacci Sequence

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int dp[][] = new int[m][n];
        return find(grid, m - 1, n - 1, dp);
    }
    public static int find(int[][] grid, int m, int n, int dp[][]) {
        if (m == 0 && n == 0)    return grid[m][n];
        else if (m < 0 || n < 0)    return Integer.MAX_VALUE;
        else if (dp[m][n] != 0)    return dp[m][n];
        return dp[m][n] = grid[m][n] + Math.min(find(grid, m - 1, n, dp), find(grid, m, n - 1, dp));
    }
}
```

## Question 5 - 62. Unique Paths

<div align="center"> <img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" width="350px"> </div><br>


```
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```



### Approach

[video solution](https://www.youtube.com/watch?v=L6dWXuh8BuE)

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[] dp = new int[m];

        for(int i=0; i<m; i++){
            dp[i] = 1;
        }
        for(int j=1; j<n; j++){
            for(int i=1; i<m; i++){
                dp[i] = dp[i]+dp[i-1];
            }
        }
        return dp[m-1];
    }
}
```

## Question 6 - 303. Range Sum Query - Immutable

```
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
```

[Video explaination](https://www.youtube.com/watch?v=2pndAmo_sMA)

### Approach

[Solution](https://leetcode.com/problems/range-sum-query-immutable/solutions/5132197/java-runtime-7ms-beats-100-00-of-users-with-java-2-approaches/)

```java
class NumArray {
    int[] nums;
    public NumArray(int[] nums) {
        for(int i=1; i<nums.length; i++){
            nums[i] += nums[i-1];
        }
        this.nums=nums;
    }
    
    public int sumRange(int left, int right) {
        if(left == 0) return nums[right];
        return nums[right] - nums[left-1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
```















