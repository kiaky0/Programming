# Math

[Square](#Square)

## Question 1 - 204. Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.

```
Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

### Approach

![204](https://github.com/kiaky0/Programming/assets/109141627/c365e87d-a592-4178-bb91-9a45f797df33)

- Start from 2, multiply of 2 all change to not prime number. Next 3, multiply of 3 change to not prime number. Next 4, but 4 is not prime.

```java
class Solution {
    public int countPrimes(int n) {
        boolean[] notPrime = new boolean[n];
        int result = 0;

        for(int i=2;i<n; i++){
            if(notPrime[i] == false){
                result++;
                for(int j=2; i*j < n; j++){
                    notPrime[i*j] = true;
                }
            }
        }
        return result;
    }
}
```

## Question 2 - 504. Base 7

Given an integer num, return a string of its base 7 representation.

```
Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"
```

### Approach

```java
class Solution {
    public String convertToBase7(int num) {
        if(num==0) return "0";

        StringBuilder sb = new StringBuilder();

        if(num<0){ // when -ve value, make it into +ve
            return "-" + convertToBase7(-num);
        }
        while(num !=0){
            sb.append(num%7);
        }
        return sb.reverse().toString();
    }
}
```

simple way to solve

```java
class Solution {
    public String convertToBase7(int num) {
        return Integer.toString(num, 7);
    }
}
```

## Question 3 - 405. Convert a Number to Hexadecimal

```
Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff"
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/405.%20Convert%20a%20Number%20to%20Hexadecimal)

```java
class Solution {
    public String toHex(int num) {
        char[] map = new char[]{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        if(num == 0) return "0";

        String res = "";
        while(num != 0){
            res= map[num & 15] + res;
            num = (num >>> 4);
        }

        return res;
    }
}
```

## Question 4 - 

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

```
For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
```

### Approach


[Solution](https://www.jiakaobo.com/leetcode/168.%20Excel%20Sheet%20Column%20Title)

```java
class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();

        while(columnNumber>0){
            columnNumber--;
            sb.append((char)('A' + columnNumber%26));
            columnNumber /= 26;
        }
        return sb.reverse().toString();
    }
}
```

## Question 5 - 172. Factorial Trailing Zeroes

```
Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
```

### Approach

[Solution Explaination](https://www.jiakaobo.com/leetcode/172.%20Factorial%20Trailing%20Zeroes.html)

```java
class Solution {
    public int trailingZeroes(int n) {
        int count = 0;
        for(int i=5; n/i >=1; i*=5){
            count += n/i;
        }
        return count;
    }
}
```

- Another approach

```java
class Solution {
    public int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
}
```


## Question 6 - 67. Add Binary

```
Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
```

### Approach

- Good Explaination in Leetcode:

[Leetcode Solution](https://leetcode.com/problems/add-binary/solutions/3183205/1ms-beats-100-full-explanation-append-reverse-c-java-python3/)

```java
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while(i>=0 || j>=0 || carry ==1){
            if(i >=0)
                carry += a.charAt(i--) - '0';
            if(j >=0)
                carry += b.charAt(j--) - '0';
            sb.append(carry % 2);
            carry /= 2;
        }
        return sb.reverse().toString();
    }
}
```

## Question 7 - 415. Add Strings

```
Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
```

### Approach

- similiar with question 6

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder result = new StringBuilder();
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry=0;

        while(i>=0 || j>=0 || carry != 0){
            int sum = 0;
            if(i>=0){
                sum += (num1.charAt(i) - '0');
                i--;
            }
            if(j>=0){
                sum += (num2.charAt(j) - '0');
                j--; 
            }

            sum += carry;
            carry = sum/10;
            result.append(sum%10);
        }
        return result.reverse().toString();
    }
}
```

## Question 8 - 462. Minimum Moves to Equal Array Elements II

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

```
Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
```

### Approach

[Solution](https://www.jiakaobo.com/leetcode/462.%20Minimum%20Moves%20to%20Equal%20Array%20Elements%20II.html)

```java
class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int mid = nums[nums.length / 2];

        int sum = 0;
        for(int num : nums){
            sum += Math.abs(num - mid);
        }

        return sum;
    }
}
```


## Question 9 - 169. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

``` 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

```

### Approach

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return nums[n/2];
    }
}
```

# Square

## Question 10 - 367. Valid Perfect Square

```
Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
```

### Approach

[leetcode Solution](https://leetcode.com/problems/valid-perfect-square/solutions/4982347/beats-100-time-o-log-n-space-o-1-math-easy-explained/)

**Using Binary Search**


1. Binary Search: We initialize two pointers, l and r, representing the lower and upper bounds of the search range, respectively. Initially, l is set to 1 and r is set to the given number num.
2. We perform binary search within the range [l, r]. At each step, we calculate the mid value as mid = l + (r - l) / 2.
3. If the square of mid is equal to num, we return true, indicating that num is a perfect square.
4. If the square of mid is greater than num, we update r to mid - 1 to search in the left half of the range.
5. If the square of mid is less than num, we update l to mid + 1 to search in the right half of the range.
6. We continue this process until l becomes greater than r, indicating that the search space is exhausted.
7. If we do not find any perfect square during the search, we return false.

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        long l = 1, r = num;

        while(l <= r){
            long mid = l+ (r-l)/2;
            if(mid*mid == num) return true;
            else if(mid*mid > num)
                r= mid -1;
            else
                l = mid + 1;
        }
        return false;
    }
}
```








