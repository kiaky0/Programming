# Arrays and Matrices

# 算法 - 算法分析
<!-- GFM-TOC -->
* [1 Find the repeating number](#1-Find-the-repeating-number)
* [2 Find a Specific Number in a 2D Array](#2-Find-a-Specific-Number-in-a-2DArray)

<!-- GFM-TOC -->




## 1 Find the repeating number

In an array of length n, all the numbers are in the range of 0 to n-1. Some of the numbers in the array are duplicates, but it is unknown how many numbers are duplicated or how many times each number is repeated. Please find any one of the duplicate numbers in the array.


```
Input:
{2, 3, 1, 0, 2, 5}

Output:
2
```

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/643b6f18-f933-4ac5-aa7a-e304dbd7fe49.gif" width="350px"> </div><br>

Solution: 

```java
public int duplicate(int[] nums) {
    for (int i = 0; i < nums.length; i++) {
        while (nums[i] != i) {
            if (nums[i] == nums[nums[i]]) {
                return  nums[i];
            }
            swap(nums, i, nums[i]);
        }
        swap(nums, i, nums[i]);
    }
    return -1;
}

private void swap(int[] nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}
```

### Summary

- Outer for loop: Iterates through each element.
- Inner while loop: Ensures each element is placed in its correct index.
- Duplicate check: Inside the while loop to detect duplicates.
- Swapping elements: To place elements in their correct positions.
- Redundant code removal: The unnecessary extra swap at the end of the for loop is removed.

## 2 Find a Specific Number in a 2D Array



