


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


