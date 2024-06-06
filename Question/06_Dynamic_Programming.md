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

this is the use of dynamic programming

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);

        int res = 1;

        for(int i = 1; i < nums.length; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }

            res = Math.max(res, dp[i]);
        }

        return res;
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

## Question 13 - 376. Wiggle Subsequence

[Explaination](https://www.jiakaobo.com/leetcode/376.%20Wiggle%20Subsequence.html)

```
Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
```

### Approach

```java
public int wiggleMaxLength(int[] nums) {
    if (nums == null || nums.length == 0) {
        return 0;
    }
    int up = 1, down = 1;
    for (int i = 1; i < nums.length; i++) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }
    return Math.max(up, down);
}
```

## Question 14 - 1143. Longest Common Subsequence

[Video Explaination](https://leetcode.com/problems/longest-common-subsequence/solutions/5162301/simple-iterative-solution-with-diagrams-in-video-javascript-c-java-python/)

### Approach

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        int[][] dpGrid = new int[n + 1][m + 1];

        for (int row = n - 1; row >= 0; row--) {
            for (int col = m - 1; col >= 0; col--) {
                if (text1.charAt(row) == text2.charAt(col)) {
                    dpGrid[row][col] = 1 + dpGrid[row + 1][col + 1];
                } else {
                    dpGrid[row][col] = Math.max(dpGrid[row + 1][col], dpGrid[row][col + 1]);
                }
            }
        }
        return dpGrid[0][0];
    }
}
```

## Question 15 - 416. Partition Equal Subset Sum

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

```
Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/416.%20Partition%20Equal%20Subset%20Sum.html)

```java
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        int n = nums.length;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;

        for (int num : nums) {
            for (int currSum = target; currSum > 0; currSum--) {
                if (currSum - num >= 0) {
                    dp[currSum] = dp[currSum] || dp[currSum - num];
                }
            }
        }

        return dp[target];
    }
}
```



## Question 16 - 322. Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

```
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/322.%20Coin%20Change.html)

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for (int coin : coins){
                if (i - coin >= 0 && dp[i - coin] != Integer.MAX_VALUE){
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }
}
```

## Question 17 - 494. Target Sum

```
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

### Approach

Using dynamic programming approach

```java
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        
        if(target < -sum || target > sum) return 0;
        
        int[] dp = new int[2 * sum + 1];
        
        dp[nums[0] + sum] = 1;
        // [0,0,0,0,0,0,0,0,1]
        dp[-nums[0] + sum] += 1;
        
        for (int i = 1; i < nums.length; i++) {
            int[] next = new int[2 * sum + 1];
            
            for (int s = 0; s <= 2 * sum; s++) {              
                if (dp[s] > 0) {
                    next[s + nums[i]] += dp[s];
                    next[s - nums[i]] += dp[s];
                }
            }
            
            dp = next;
        }
        
        return dp[target + sum];
    }
}
```

using DFS approach

```java
class Solution {
    int res = 0;

    public int findTargetSumWays(int[] nums, int target) {
        dfs(nums, 0, target, 0);
        return res;
    }

     private void dfs(int[] nums, int start, int target, int curr){
        if(start == nums.length){
            if (target == curr) res++;
            return;
        }

        dfs(nums, start + 1, target, curr + nums[start]);
        dfs(nums, start + 1, target, curr - nums[start]);
    }
}
```

## Question 17 - 474. Ones and Zeroes

```
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/474.%20Ones%20and%20Zeroes)

```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];

        for(String str : strs){
            int zeroCount = 0;
            int oneCount = 0;
            
            for(char c : str.toCharArray()){
                if(c == '0'){
                    zeroCount++;
                } else {
                    oneCount++;
                }
            }

            for(int i = m; i >= zeroCount; i--){
                for(int j = n; j >= oneCount; j--){
                    dp[i][j] = Math.max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1);
                }
            }
        }

        return dp[m][n];
    }
}
```

## Question 18 - 139. Word Break

The same word in the dictionary may be reused multiple times in the segmentation. You may assume the dictionary does not contain duplicate words. Example 1:

```
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```
```
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
```
```
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```

## Approach

[Solution](https://www.jiakaobo.com/leetcode/139.%20Word%20Break)

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordDictSet = new HashSet(wordDict);
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                // 有一次成功就可以退出这次循环了
                if (dp[j] && wordDictSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
}
```

## Question 19 - 377. Combination Sum IV

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

```
Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Therefore the output is 7.
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/377.%20Combination%20Sum%20IV)

```java
class Solution {
    public int combinationSum4(int[] nums, int target) {
        if(nums == null || nums.length == 0) return 0;

        int[] res = new int[target + 1];
        res[0] = 1;
        
        for(int i = 1; i < res.length; i++){
            for(int num : nums){
                if(i - num >= 0){
                    res[i] += res[i - num];
                }
            }
        }

        return res[target];
    }
}
```

## Question 20 - 309. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day). Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

```
Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/309.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown)

- buy[i]表示在第i天之前最后一个操作是买，此时的最大收益
- sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益
- rest[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益


```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;

        int[] sell = new int[prices.length];
        int[] buy = new int[prices.length];
        int[] rest = new int[prices.length];

        sell[0] = 0;
        buy[0] = -prices[0];
        rest[0] = 0;

        for (int i = 1; i < prices.length; ++i) {
            buy[i] = Math.max(buy[i - 1], rest[i - 1] - prices[i]);
            sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
            rest[i] = Math.max(sell[i - 1], Math.max(buy[i - 1], rest[i - 1]));
        }
        return sell[prices.length - 1];
    }
}
```

## Question 20 - 714. Best Time to Buy and Sell Stock with Transaction Fee (can understand)

```
Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

### Approach

[Solution](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/3667440/beats-100-c-java-python-beginner-friendly/)

<div align="center"> <img src="https://github.com/kiaky0/Programming/assets/109141627/f4faec67-1331-46a5-95ab-030ed8c77232
" width="350px"> </div><br>

```java
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int buy = Integer.MIN_VALUE;
        int sell = 0;

        for(int price: prices){
            buy = Math.max(buy, sell-price);
            sell = Math.max(sell, buy + price - fee);
        }
        return sell;
    }
}
```




