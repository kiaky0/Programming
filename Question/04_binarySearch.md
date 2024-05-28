# Binary Search


Note for Binary Search: [click](https://github.com/kiaky0/Programming/blob/main/Note/BinarySearch.md)

Example code

```
Input : [1,2,3,4,5]
key : 3
return the index : 2
```

```java
public int binarySearch(int[] nums, int key) {
    int l = 0, h = nums.length - 1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (nums[m] == key) {
            return m;
        } else if (nums[m] > key) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}
```

## Question 1 - 69. Sqrt(x)

```
Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```


### Approach

**Without using Binary Search**

```java
class Solution {
    public int mySqrt(int x) {
        int n = (int) Math.sqrt(x);
        return (Math.round(n));
    }
}
```

**With using Binary Search**

```java
class Solution {
    public int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        long left =1;
        long right =x;
        long result =0;

        while(left <= right){
            long mid = left + (right-left)/2;

            if(mid*mid == x){
                return (int) mid;
            }else if (mid*mid <x){
                left = mid + 1;
                result=mid;
            }else {
                right = mid -1;
            }
        }
        return (int) result;        
    }
}
```


## Question 2 - 744. Find Smallest Letter Greater Than Target

```
Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
```

### Approach

**Using Binary Search**

```java
public char nextGreatestLetter(char[] letters, char target) {
    int n = letters.length;
    int l = 0, h = n - 1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (letters[m] <= target) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return l < n ? letters[l] : letters[0];
}
```

in the leetcode solution with 0ms time execution

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        char ans = ' ';
        int n = letters.length;
        int i = 0, j = n-1;
        while( i <= j){
            int mid = (j-i)/2;
            mid+=i;
            char m = letters[mid];
            if( m > target){
                ans = m;
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return ans == ' ' ? letters[0] : ans;
    }
}
```

## Question 3 - 153. Find Minimum in Rotated Sorted Array

```
Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
```

### Approach

[Leetcode Solution](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/5149850/fastest-100-easiest-shortest-binary-search-multiple-langs/)


```java
class Solution {
    public int findMin(int[] nums) {
        int left =0, right = nums.length-1;
        while(left < right){
            int mid = left + (right-left)/2;

            if(nums[mid] < nums[right]){
                right = mid;
            }else{
                left = mid +1;
            }
        }
        return nums[left]
    }
}
```

## Question 4 - 34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

```
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
```

### Approach

[leetcode solution](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/solutions/5197418/faster-time-lessor-easy-to-understand-binary-search/)

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
      int[] ans= new int[2];
      if(nums.length ==0){
        ans[0] = -1;
        ans[1] = -1;
        return ans;
      }
      ans[0] = search(nums,target,true);
      ans[1] = search(nums,target,false);
      return ans;
    }

    int search(int[] nums , int target , boolean firstIndOrNot){
        int ans= -1;
        int start = 0;
        int end = nums.length-1;
        int mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if(target>nums[mid]){
                start = mid +1 ;
            }else if(target<nums[mid]){
                end = mid-1;
            }else {
                ans=mid;
                if(firstIndOrNot)end=mid-1;
                else start=mid+1;
            }
        }
        return ans;
    }
}

```












