# Arrays and Matrices

# 算法 - 算法分析
<!-- GFM-TOC -->
* [1 Find the repeating number](#1-Find-the-repeating-number)
* [2 Find a Specific Number in a 2D Array](#2-Find-a-Specific-Number-in-a-2D-Array)
* [3 Print the matrix in a clockwise order](#3-Print-the-matrix-in-a-clockwise-order)
* 

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

Question:

Given a 2D array where each row is sorted in ascending order from left to right, and each column is also sorted in ascending order from top to bottom, determine whether a given number is in this 2D array.

```
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.
Given target = 20, return false.
```



<div align="center"> <img src="https://raw.githubusercontent.com/kiaky0/Programming/main/souce/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f33356138633731312d306463302d343631332d393566332d6265393663366336653130342e676966.gif" width="350px"> </div><br>

Solution

```java
public boolean find(int target, int[][] matrix) {
	if(matrix == null || matrix.length == 0 || matrix[0].length == 0)
		return false;
	int rows = matrix.length, cols = matrix[0].length;
	int r = 0, c = cols -1; // start from the most right corner
	while(r<=rows-1 && c >=0) {
		if (target == matrix[r][c])
            return true;
		else if (target > matrix[r][c])
			r++;
		else
			c--;
	}
	return false;
}
```

## 3 Print the matrix in a clockwise order

Print the values of the matrix in a clockwise direction from the outside to the inside. The print result of the matrix in the figure below is: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.


Solution

一层一层从外到里打印，观察可知每一层打印都有相同的处理步骤，唯一不同的是上下左右的边界不同了。因此使用四个变量 r1, r2, c1, c2 分别存储上下左右边界值，从而定义当前最外层。打印当前最外层的顺序：从左到右打印最上一行->从上到下打印最右一行->从右到左打印最下一行->从下到上打印最左一行。应当注意只有在 r1 != r2 时才打印最下一行，也就是在当前最外层的行数大于 1 时才打印最下一行，这是因为当前最外层只有一行时，继续打印最下一行，会导致重复打印。打印最左一行也要做同样处理。

![image](https://github.com/kiaky0/Programming/assets/109141627/309d7a15-98ce-4293-970e-b3c68e5d7856)



```java
public ArrayList<Integer> printMatrix(int[][] matrix) {
    ArrayList<Integer> ret = new ArrayList<>();
    int r1 = 0, r2 = matrix.length - 1, c1 = 0, c2 = matrix[0].length - 1;
    while (r1 <= r2 && c1 <= c2) {
        // 上
        for (int i = c1; i <= c2; i++)
            ret.add(matrix[r1][i]);
        // 右
        for (int i = r1 + 1; i <= r2; i++)
            ret.add(matrix[i][c2]);
        if (r1 != r2)
            // 下
            for (int i = c2 - 1; i >= c1; i--)
                ret.add(matrix[r2][i]);
        if (c1 != c2)
            // 左
            for (int i = r2 - 1; i > r1; i--)
                ret.add(matrix[i][c1]);
        r1++; r2--; c1++; c2--;
    }
    return ret;
}
```



