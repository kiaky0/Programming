# Math


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









