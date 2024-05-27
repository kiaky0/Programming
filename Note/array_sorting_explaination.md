# Visualisation of 406. Queue Reconstruction by Height 

### Example

Given `people` array:

```java
int[][] people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
```

### Step-by-Step Visualization

#### Step 1: Sort the Array

The first step is to sort the `people` array using the custom comparator:

```java
Arrays.sort(people, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
```

This comparator sorts:
- By height in descending order (`b[0] - a[0]`).
- For equal heights, by `k` in ascending order (`a[1] - b[1]`).

Let's see the sorted array:

1. Start with the original array:

   ```java
   {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}}
   ```

2. Sort by height in descending order and by `k` in ascending order:

   ```java
   {{7, 0}, {7, 1}, {6, 1}, {5, 0}, {5, 2}, {4, 4}}
   ```

#### Step 2: Initialize the Ordered List

Next, we initialize an empty `LinkedList` to hold the ordered result:

```java
List<int[]> ordered = new LinkedList<>();
```

#### Step 3: Insert People into the Ordered List

We iterate through the sorted `people` array and insert each person into the `ordered` list at the index specified by their `k` value:

```java
for (int[] p : people) ordered.add(p[1], p);
```

Here's how it works step-by-step:

1. **Insert `[7, 0]` at index `0`**:
   ```java
   [[7, 0]]
   ```

2. **Insert `[7, 1]` at index `1`**:
   ```java
   [[7, 0], [7, 1]]
   ```

3. **Insert `[6, 1]` at index `1`**:
   ```java
   [[7, 0], [6, 1], [7, 1]]
   ```

4. **Insert `[5, 0]` at index `0`**:
   ```java
   [[5, 0], [7, 0], [6, 1], [7, 1]]
   ```

5. **Insert `[5, 2]` at index `2`**:
   ```java
   [[5, 0], [7, 0], [5, 2], [6, 1], [7, 1]]
   ```

6. **Insert `[4, 4]` at index `4`**:
   ```java
   [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
   ```

#### Step 4: Convert List Back to Array

Finally, we convert the `ordered` list back to a 2D array and return it:

```java
return ordered.toArray(new int[people.length][2]);
```

### Final Result

The final reconstructed queue is:

```java
[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
```

### Summary

The method sorts the people based on their heights in descending order and `k` values in ascending order when heights are equal. It then inserts each person into a `LinkedList` at the position specified by their `k` value, ensuring that the final queue satisfies the given constraints. The result is converted back to a 2D array for the final output.

