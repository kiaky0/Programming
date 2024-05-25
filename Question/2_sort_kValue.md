


## Question 1 - 215. Kth Largest Element in an Array

[LeetCode: Note](https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/3906260/100-3-approaches-video-heap-quickselect-sorting/)

```
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```

题目描述：找到倒数第 k 个的元素。

### Approach 1 - Sort and Select

时间复杂度 O(NlogN)，空间复杂度 O(1)

```java
public int findKthLargest(int[] nums, int k) {
    Arrays.sort(nums);
    return nums[nums.length - k];
}
```

### Approach 2 - Min-Heap




```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for(int i = 0; i<k; i++){
            minHeap.offer(nums[i]);
        }
        
        for(int i=k; i<nums.length; i++){
            if(nums[i] > minHeap.peek()){
                minHeap.poll();           // take out and remove
                minHeap.offer(nums[i]);   // push into minHeap
            }
        }
        // peek() retrreve the first element of stack
        return minHeap.peek();
    }
}
```

or

```java
public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> pq = new PriorityQueue<>(); // 小顶堆
    for (int val : nums) {
        pq.add(val);
        if (pq.size() > k)  // 维护堆的大小为 K
            pq.poll();
    }
    return pq.peek();
}
```

## Approach 3 - Quick Sort

```java
public int findKthLargest(int[] nums, int k) {
    k = nums.length - k;
    int l = 0, h = nums.length - 1;
    while (l < h) {
        int j = partition(nums, l, h);
        if (j == k) {
            break;
        } else if (j < k) {
            l = j + 1;
        } else {
            h = j - 1;
        }
    }
    return nums[k];
}

private int partition(int[] a, int l, int h) {
    int i = l, j = h + 1;
    while (true) {
        while (a[++i] < a[l] && i < h) ;
        while (a[--j] > a[l] && j > l) ;
        if (i >= j) {
            break;
        }
        swap(a, i, j);
    }
    swap(a, l, j);
    return j;
}

private void swap(int[] a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
```

## Question 2 - 347 Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 
```
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
```

[Explaination Video](https://www.youtube.com/watch?v=yXGY2srjGpQ&t=160s)

[Solution Code](https://leetcode.com/problems/top-k-frequent-elements/description/)


```java
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        // Find the frequency of each number
        Map<Integer, Integer> numFrequencyMap = new HashMap<>();
        for (int n : nums)
            numFrequencyMap.put(n, numFrequencyMap.getOrDefault(n, 0) + 1);

        PriorityQueue<Map.Entry<Integer, Integer>> topKElements = new PriorityQueue<>(
                (e1, e2) -> e1.getValue() - e2.getValue());

        // Go through all numbers of the numFrequencyMap and push them into
        // topKElements, which will have
        // the top k frequent numbers. If the heap size is more than k, we remove the
        // smallest (top) number.
        for (Map.Entry<Integer, Integer> entry : numFrequencyMap.entrySet()) {
            topKElements.add(entry);
            if (topKElements.size() > k) {
                topKElements.poll();
            }
        }

        // Create a list of top k numbers
        int[] topNumbers = new int[k];

        int i = 0;
        while (!topKElements.isEmpty()) {
            topNumbers[i] = topKElements.poll().getKey();
            i++;
        }

        return topNumbers;
    }
}
```

python

```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # find the frequency of each number
        num_frequency_map = {}
        for num in nums:
            num_frequency_map[num] = num_frequency_map.get(num, 0) + 1
        top_k_elements = []

        # go through all numbers of the num_frequency_map
        # and push them in the top_k_elements, which will have
        # top k frequent numbers. If the heap size is more than k,
        # we remove the smallest(top) number
        for num, frequency in num_frequency_map.items():
            heappush(top_k_elements, (frequency, num))
            if len(top_k_elements) > k:
                heappop(top_k_elements)

        # create a list of top k numbers
        top_numbers = []
        while top_k_elements:
            top_numbers.append(heappop(top_k_elements)[1])

        return top_numbers
```

## Question 3 - 451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 ```

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

```

### Approach

1. Iterate through the input string 's' and count the frequency of each character using an unordered map 'hm'.
2. Use a priority queue 'pq' to store pairs of characters and their frequencies, sorted in decreasing order of frequency.
3. Define a lambda function 'cmp' to compare pairs based on the second element (frequency).
4. Iterate through the hashmap entries and push each pair into the priority queue.
5. Pop elements from the priority queue and append characters to the result string according to their frequency.



```java


class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> hm = new HashMap<>();
        
        for (char c : s.toCharArray()) {
            hm.put(c, hm.getOrDefault(c, 0) + 1);
        }
        
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>(
            (a, b) -> b.getValue() - a.getValue()
        );
        
        pq.addAll(hm.entrySet());
        
        StringBuilder result = new StringBuilder();
        while (!pq.isEmpty()) {
            Map.Entry<Character, Integer> entry = pq.poll();
            result.append(String.valueOf(entry.getKey()).repeat(entry.getValue()));
        }
        
        return result.toString();
    }
}
```

## Question 4 - 75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 ```

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


```

Approch

```java
class Solution {
    public void sortColors(int[] nums) {
        int[] frequency = new int[]{0, 0, 0};
        for(int i=0; i< nums.length; i++){
            if(nums[i] == 0){
                frequency[0]++;
            }else if(nums[i] == 1){
                frequency[1]++;
            }else{
                frequency[2]++;
            }
        }
        int iter = 0;
        for(int i=0; i<nums.length;){
            if(frequency[iter]>0){
                nums[i] = iter;
                frequency[iter]--;
                i++;
            }else{
                iter++;
            }
        }
    }
}
```






