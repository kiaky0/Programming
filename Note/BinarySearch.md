# Binary Search Note

### Code Explanation

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

### Purpose of Binary Search

Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you’ve narrowed down the possible locations to just one.

### Detailed Step-by-Step Explanation

1. **Initialization:**
   ```java
   int l = 0, h = nums.length - 1;
   ```
   - `l` (low) is initialized to `0`, the beginning of the array.
   - `h` (high) is initialized to `nums.length - 1`, the end of the array.

2. **Binary Search Loop:**
   ```java
   while (l <= h) {
   ```
   - The loop runs as long as `l` is less than or equal to `h`. This condition ensures that there are still elements to be checked.

3. **Calculate Midpoint:**
   ```java
   int m = l + (h - l) / 2;
   ```
   - `m` (mid) is calculated as the middle index between `l` and `h`.
   - This formula `l + (h - l) / 2` is used instead of `(l + h) / 2` to prevent potential overflow when `l` and `h` are large values.

4. **Check Midpoint Value:**
   ```java
   if (nums[m] == key) {
       return m;
   }
   ```
   - If the element at index `m` is equal to `key`, the search is successful, and the method returns `m`.

5. **Adjust Search Range:**
   ```java
   else if (nums[m] > key) {
       h = m - 1;
   }
   ```
   - If `nums[m]` is greater than `key`, it means `key` must be in the left half (lower indices) of the current range. Hence, `h` is adjusted to `m - 1`.

   ```java
   else {
       l = m + 1;
   }
   ```
   - If `nums[m]` is less than `key`, it means `key` must be in the right half (higher indices) of the current range. Hence, `l` is adjusted to `m + 1`.

6. **Key Not Found:**
   ```java
   return -1;
   ```
   - If the loop exits without finding the `key`, it means the `key` is not present in the array. The method returns `-1` to indicate this.

### Visualization with an Example

Let's consider an example to visualize how this code works:
- Input array `nums = [1, 3, 5, 7, 9, 11]`
- Key to find `key = 7`

**Initial State:**
- `l = 0`
- `h = 5`

**Iteration Steps:**

1. **First Iteration:**
   - `m = 0 + (5 - 0) / 2 = 2`
   - `nums[2] = 5`
   - Since `nums[2] < 7`, adjust `l` to `m + 1 = 3`.

2. **Second Iteration:**
   - `l = 3`
   - `h = 5`
   - `m = 3 + (5 - 3) / 2 = 4`
   - `nums[4] = 9`
   - Since `nums[4] > 7`, adjust `h` to `m - 1 = 3`.

3. **Third Iteration:**
   - `l = 3`
   - `h = 3`
   - `m = 3 + (3 - 3) / 2 = 3`
   - `nums[3] = 7`
   - Since `nums[3] == 7`, return `m = 3`.

### Summary

The `binarySearch` method efficiently finds the `key` in a sorted array `nums` by repeatedly dividing the search range in half. It adjusts the search range based on the comparison of the middle element with the `key`, ensuring logarithmic time complexity \(O(\log n)\). If the `key` is found, it returns the index; otherwise, it returns `-1` to indicate the `key` is not present in the array.
