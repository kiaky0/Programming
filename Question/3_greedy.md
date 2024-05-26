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









