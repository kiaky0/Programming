# 分治 Divide and Conquer


## Question 1 - 241. Different Ways to Add Parentheses (Medium)

```
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
```

[Video explaination and solution](https://www.youtube.com/watch?v=ZNkquA2htPM)

### Approach

```java
class Solution {
    private final char MULTIPLICATION = '*';
    private final char ADDITION = '+';
    private final char SUBTRACTION = '-';
    private char[] expressionArr;
    private String expression;
    private Set<Character> operatorSet = new HashSet<>();

    public List<Integer> diffWaysToCompute(String expression) {
        this.expression = expression;
        operatorSet.add(MULTIPLICATION);
        operatorSet.add(ADDITION);
        operatorSet.add(SUBTRACTION);
        expressionArr = expression.toCharArray();
        return dfs(0, expressionArr.length - 1);
    }

    private List<Integer> dfs(int start, int end) {
        List<Integer> res = new LinkedList<>();
        for (int i = start; i < end; i++) {
            if (operatorSet.contains(expressionArr[i])) {
                List<Integer> leftList = dfs(start, i - 1);
                List<Integer> rightList = dfs(i + 1, end);
                for (Integer num1 : leftList) {
                    for (Integer num2 : rightList) {
                        Integer totalVal = calculate(num1, num2, expressionArr[i]);
                        res.add(totalVal);
                    }
                }
            }
        }
        if (res.size() == 0) {
            res.add(Integer.parseInt(expression.substring(start, end + 1)));
        }
        return res;
    }

    private Integer calculate(Integer num1, Integer num2, char operator) {
        switch (operator) {
            case MULTIPLICATION:
                return num1 * num2;
            case ADDITION:
                return num1 + num2;
            case SUBTRACTION:
                return num1 - num2;
            default:
                return -1;
        }
    }

}
```

## Question 2 - 95. Unique Binary Search Trees II (Medium)

给定一个数字 n，要求生成所有值为 1...n 的binary tree

```
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

```

### Approach

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n < 1) {
            return new LinkedList<TreeNode>();
        }
        return generateSubtrees(1, n);
    }

    private List<TreeNode> generateSubtrees(int s, int e) {
        List<TreeNode> res = new LinkedList<TreeNode>();
        if (s > e) {
            res.add(null);
            return res;
        }
        for (int i = s; i <= e; ++i) {
            List<TreeNode> leftSubtrees = generateSubtrees(s, i - 1);
            List<TreeNode> rightSubtrees = generateSubtrees(i + 1, e);
            for (TreeNode left : leftSubtrees) {
                for (TreeNode right : rightSubtrees) {
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    root.right = right;
                    res.add(root);
                }
            }
        }
        return res;
    }
}
```


