# Dynamic Programming

[Fibonacci Sequence](#Fibonacci-Sequence)

[Array Interval](#Array-Interval)

# Fibonacci Sequence
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

# Array Interval

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

## Question 7 - 413. Arithmetic Slices


Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

```

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
```

### Appraoch

Three integer three integer loop through

[Video solution](https://www.youtube.com/watch?v=DEqVRwxYt6U)


```java
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        if(nums.length <= 2) return 0;

        int[] dp = new int[nums.length];
        int res = 0;

        for(int i=2; i<nums.length; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = dp[i-1] + 1;
                res += dp[i];
            }
        }
        return res;
    }
}
```



## Question 8 - 343. Integer Break

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

```
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
```

### Approach - Dynamic Programming

[Solution](https://www.jiakaobo.com/leetcode/343.%20Integer%20Break.html)

当前的最大乘积
把当前数字拆分为两部分
两部分都是之前拆分的结果，比如把10拆分成3和7
找到dp[3]，如果拆分3那么得到最大乘积是2，但是也可以选择直接用3本身，这样会让乘积更大
因此Math.max(j, dp[j])
对于7来说，选择dp[7]比7本身更大，因此最后选择3 * 12 = 36，得到结果

```java
class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;
        
        for(int i = 2; i <= n; i ++) {
            for(int j = 1; j < i; j ++) {
                dp[i] = Math.max(dp[i], Math.max(j, dp[j]) * Math.max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
}
```

Simple solution with greedy approach

```java
class Solution {
    public int integerBreak(int n) {
       if(n<=3){
            return n-1;
        }
        int ans=1;
        while(n>4){
            ans=ans*3;
            n=n-3;
        }
        ans=ans*n;
        return ans;

    }
}
```

## Question 9 - 279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, …) which sum to n.

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/279.%20Perfect%20Squares.html)

Dynamic Programming

```java
class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for (int j = 0; j <= i; j++){
                if ( (i - j * j) >= 0 && dp[i - j * j] != Integer.MAX_VALUE){
                    dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        
        return dp[n];
    }
}
```


## Question 10 - 91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

‘A’ -> 1 ‘B’ -> 2 … ‘Z’ -> 26 Given a non-empty string containing only digits, determine the total number of ways to decode it.

```
Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
### Approach
```

### Approach

[solution](https://www.jiakaobo.com/leetcode/91.%20Decode%20Ways.html)

```
class Solution {
    public int numDecodings(String s) {
        if(s==null || s.length() == 0 || s.charAt(0) == '0') return 0;
        int[] dp = new int[s.length() +1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i=1; i<s.length(); i++){
            if(s.charAt(i) != '0'){
                dp[i+1] += dp[i];
            }

            int num = Integer.valueOf(s.substring(i-1, i+1));
            if(num >= 10 && num <= 26){
                dp[i+1] += dp[i-1];
            }
        }
        return dp[s.length()];
    }
}
```

## Question 11 - 300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence

```
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/300.%20Longest%20Increasing%20Subsequence.html)

Dynamic Programming and Binary Search

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] tails = new int[nums.length + 1];
        Arrays.fill(tails, Integer.MAX_VALUE);

        for(int num : nums){
            int index = helper(tails, num);
            tails[index] = num;
        }

        int res = 0;

        for(int num : tails){
            if(num != Integer.MAX_VALUE){
                res++;
            }
        }

        return res;
    }

    private int helper(int[] nums, int target){
        int start = 0;
        int end = nums.length - 1;

        while(start + 1 < end){
            int mid = (start + end) / 2;

            if(nums[mid] == target) return mid;

            if(nums[mid] < target){
                start = mid;
            } else {
                end = mid;
            }
        }

        return end;
    }
}
```

## Question 12 - 646. Maximum Length of Pair Chain


You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

```
Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/646.%20Maximum%20Length%20of%20Pair%20Chain.html)


```java
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]);

        int end = pairs[0][1];
        int res = 1;

        for (int i = 1; i < pairs.length; i++) {
            int[] curr = pairs[i];
            if (end < curr[0]) {
                end = curr[1];
                res++;
            }
        }
        return res;
    }
}
```








