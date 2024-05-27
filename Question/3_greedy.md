# Greedy

保证每次操作都是局部最优的，并且最后得到的结果是全局最优的。

## Question 1 - 455. Assign Cookies

you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

```
Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
```

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/e69537d2-a016-4676-b169-9ea17eeb9037.gif" width="430px"> </div><br>



### Approach

![image](https://github.com/kiaky0/Programming/assets/109141627/a75677b8-e3a9-45d9-8148-4673eba6a668)

```java
public int findContentChildren(int[] grid, int[] size) {
    if (grid == null || size == null) return 0;
    Arrays.sort(grid);
    Arrays.sort(size);
    int gi = 0, si = 0;
    while (gi < grid.length && si < size.length) {
        if (grid[gi] <= size[si]) {
            gi++;
        }
        si++;
    }
    return gi;
}
```

## Question 2 - 435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 
```
Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

### Approach: 

[Explaination video](https://www.youtube.com/watch?v=nONCGxWoUfM)

[Leetcode solution](https://leetcode.com/problems/non-overlapping-intervals/solutions/3785409/beat-s-100-c-java-python-beginner-friendly/)

The function uses a greedy approach to find the maximum number of non-overlapping meetings. It iterates through the sorted intervals starting from the second interval (index 1) because we've already counted the first interval as non-overlapping. For each interval at index i, it checks if the start time of the current interval (intervals[i][0]) is greater than or equal to the end time of the previous interval (intervals[prev][1]). If this condition is true, it means the current interval does not overlap with the previous one, and we can safely attend this meeting. In that case, we update prev to the current index i and increment count to reflect that we have attended one more meeting.

```java
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));
        int prev = 0;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= intervals[prev][1]) {
                prev = i;
                count++;
            }
        }
        return n - count;
    }
}
```


## Question 3 - 452. Minimum Number of Arrows to Burst Balloons

```
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
```

### Approach 

[video explaination](https://www.youtube.com/watch?v=lPmkKnvNPrw)

[Leetcode Solution](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/4890422/easy-91-77-beats-c-java-python-javascript-c/)

```java
class Solution {
    public int findMinArrowShots(int[][] points) {
        // Sort the balloons based on their end coordinates
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

        int arrows = 1;
        int prevEnd = points[0][1];
        
        // Count the number of non-overlapping intervals
        for (int i = 1; i < points.length; ++i) {
            if (points[i][0] > prevEnd) {
                arrows++;
                prevEnd = points[i][1];
            }
        }
        return arrows;
    }
}
```

## Question 4 - 406. Queue Reconstruction by Height

```
Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

```

[video explaination](https://www.youtube.com/watch?v=LnxOUvwZkYo&t=192s)

[leetcode solution](https://leetcode.com/problems/queue-reconstruction-by-height/description/)

[gpt visualization](https://github.com/kiaky0/Programming/blob/main/Note/array_sorting_explaination.md)

## Approach

```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        // sorting with the heigh, then the k value
        Arrays.sort(people, (a,b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        
        List<int[]> ordered = new LinkedList<>();
        // sort according to the index
        for (int[] p: people) ordered.add(p[1], p);

        return ordered.toArray(new int[people.length][2]);
    }
}
```

### Question 5 - 121. Best Time to Buy and Sell Stock

```
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

[video explaination](https://www.youtube.com/watch?v=1pkOgXD63yU)

[solution](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/4868897/most-optimized-kadane-s-algorithm-java-c-python-rust-javascript/)

### Approach

```java
class Solution {
    public int maxProfit(int[] prices) {
        int buy = prices[0];
        int profit = 0;

        for(int i =1; i<prices.length; i++){
            if(prices[i] < buy){
                buy = prices[i];
            } else if(prices[i] - buy > profit){
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
}
```


## Question 6 - 122. Best Time to Buy and Sell Stock II (Easy)

题目描述：可以进行多次交易，多次交易之间不能交叉进行，可以进行多次交易。

```
Example

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```

[video explaination](https://www.youtube.com/watch?v=3SJ3pUkPQMc)

[leetcode solution](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

### Approach

```java
class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        int start = prices[0];
        int len = prices.length;
        for(int i = 1;i<len; i++){
            if(start < prices[i]) max += prices[i] - start;
            start = prices[i];
        }
        return max;
    }
}
```

### Question 7 - 605. Can Place Flowers

题目描述：flowerbed 数组中 1 表示已经种下了花朵。花朵之间至少需要一个单位的间隔，求解是否能种下 n 朵花。

```
Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

[video explaination](https://www.youtube.com/watch?v=ZGxqqjljpUI)

[leetcode solutiion](https://leetcode.com/problems/can-place-flowers/submissions/1269159090/)

### Approach

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for (int i = 0; i < flowerbed.length; i++) {
            boolean left = (i == 0 || flowerbed[i - 1] == 0); // check is the first one or previous is = 0
            boolean right = i == flowerbed.length - 1 || flowerbed[i + 1] == 0; // check is the last one or next is = 0
            
            if (left && right && flowerbed[i] == 0) { // if both adjection is = 0 continue
                flowerbed[i] = 1;           // put the flower inside
                n--;
            }
        }
        return n <= 0;        
    }
}
```


## Question 8 - 392. Is Subsequence

```

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 
```

[leetcode solution](https://leetcode.com/problems/is-subsequence/solutions/5101957/video-two-pointer-solution/)

### Approach

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int i=0;
        int j =0;
        while(j<t.length() && i < s.length()){
            if(t.charAt(j)==s.charAt(i)){
                i++;
            }
            j++;
        }
        return i==s.length();
    }
}
```






