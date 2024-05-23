# Two Sum II

## Qeustion 1 - Input Array Is Sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 
```
Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```

## 题目描述：在有序数组中找出两个数，使它们的和为 target。

使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。

- 如果两个指针指向元素的和 sum == target，那么得到要求的结果；
- 如果 sum \> target，移动较大的元素，使 sum 变小一些；
- 如果 sum \< target，移动较小的元素，使 sum 变大一些。

数组中的元素最多遍历一次，时间复杂度为 O(N)。只使用了两个额外变量，空间复杂度为  O(1)。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/437cb54c-5970-4ba9-b2ef-2541f7d6c81e.gif" width="200px"> </div><br>


Solution

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if (numbers == null) return null;
        int i = 0, j = numbers.length - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return new int[]{i + 1, j + 1};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return null;
    }
}
```

## Question 2 - Sum of Square Number

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

```
Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
```
Solution:

- Using two point i and j. j is from the quare root of the input.
- two condition the sum larger or smaller than input
- if sum larger than input move j to left
- if sum smaller than input move i to right

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        long i = 0;
        long j = (long) Math.sqrt(c);

        while(i<=j){
            long powSum = i*i + j*j;
            if(powSum == c){
                return true;
            }
            else if(powSum < c){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
}
```

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        if(c<0) return false;
        int i=0, j = (int) Math.sqrt(c);

        while(i<=j){
            int powSum = i*i + j*j;
            if(powSum == c){
                return true;
            }else if(powSum > c){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
}
```



## Question 3 - Reverse Vowels of a String

Note for Set -> [Set](https://github.com/kiaky0/Programming/blob/main/Note/Set.md)

### Question descroption

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 
```
Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
```

Solution:

```java
class Solution {
    public String reverseVowels(String s) {
        char arr[] = s.toCharArray();
        Set<Character>vowel=Set.of('a','e','i','o','u','A','E','I','O','U');
        int l=0, r=s.length()-1;
        while(l<r){
            if(vowel.contains(arr[l]) && vowel.contains(arr[r])){
                //swapping
                char t = arr[l];
                arr[l++] = arr[r];
                arr[r--] = t;
            }
            else if(!vowel.contains(arr[l])&&!vowel.contains(arr[r])){
                l++;
                r--;
            }
            else if(!vowel.contains(arr[l])&&vowel.contains(arr[r])){
                l++;
            }
            else r--;            
        }
        return String.valueOf(arr);
    }
}
```

