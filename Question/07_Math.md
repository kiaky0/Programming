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
