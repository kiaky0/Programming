# Two Sum II

## Qeustion 1 - Input Array Is Sorted

- Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
- Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
- Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
- The tests are generated such that there is exactly one solution. You may not use the same element twice.
- Your solution must use only constant extra space.

 
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

- Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

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

- Given a string s, reverse only all the vowels in the string and return it.

- The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 
```
Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
```

![image](https://github.com/kiaky0/Programming/assets/109141627/78d85d55-e6a3-4336-a3c2-b07142feddd7)


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

## Question 4 - Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 ```

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
```

## Approach

First we create two pointers, and start iterating until they meet, on each iteration we take chars at left and right pointers locations. if chars are not equals we use compare method that we wrote and return any true or false as result, in compare method we pass left and right pointers but in one method we shift right pointer and in another we shift left pointer, then we increment left pointer and decrement right pointer. If we reached end we return true, in compare method we do same logic but when chars are not equals we return false instead calling compare method, this is due to reason that we by calling compare method emulate removing one of the chars and we can't remove twice.

```java
class Solution {
    public boolean validPalindrome(String s) {
        //declare two pointers
        int l=0, r=s.length()-1;
        // iterate until two pointer are meet
        while(l<r){
            // take char 
            char lc = s.charAt(l);
            char rc = s.charAt(r);

            if(lc != rc){
                return compare(s, l + 1, r) || compare(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }
    // create a compare method
    public boolean compare(String s, int l, int r){
        while(l<r){
            char lc = s.charAt(l);
            char rc = s.charAt(r);

            if(lc != rc) return false;
            l++;
            r--;
        }
        return true;
    }
}
```

## Quesetion 5 - Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 ```

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

```

solution:

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index1 = m-1;  // start from right
        int index2 = n-1;
        int indexMerge = m+n-1;
        while(index2 >= 0){
            if(index1<0){
                nums1[indexMerge--] = nums2[index2--];
            }else if(index2 < 0){
                nums1[indexMerge--] = nums1[index1--];
            }else if(nums1[index1] > nums2[index2]){
                nums1[indexMerge--] = nums1[index1--];
            }else{
                nums1[indexMerge--] = nums2[index2--];
            } 
        }
    }
}
```

Same way

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
    }
}
```

Using for loop simple way

- Traverse through nums2 and append its elements to the end of nums1 starting from index m.
- Sort the entire nums1 array using sort() function.

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int j = 0, i = m; j < n; j++) {
            nums1[i] = nums2[j];
            i++;
        }
        Arrays.sort(nums1);
    }
}
```

## Question 6 - Longest Word in Dictionary through Deleting

Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 
```
Example 1:
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
```

Solution:

```java
class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        
        int maxLength = 0;
        String maxWord = "";

        for(String word : dictionary) {
            int length = checkIfWordPresentInString(s, word);

            // condition to take the word
            // the word is longest or (length same with longest and is not the same word compare with lexicographyically)
            if(length > maxLength || (length == maxLength && maxWord.compareTo(word) > 0)) {
                maxLength = length;
                maxWord = word;
            }
        }

        return maxWord;
    }

    // take the length of the word
    public int checkIfWordPresentInString(String s, String word) {
        for(int i = 0, j = 0; i <= s.length() - 1; i++) {
            
            // string contain the alpherbet of word
            if(s.charAt(i) == word.charAt(j)) {
                j++;
                if(j == word.length()) {  // total length == word of the length
                    return j;
                }
            }
        }
        return 0;
    }
}
```
