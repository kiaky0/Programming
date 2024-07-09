# Numpy

## Array Creation

```py
import numpy as np

a = np.array([2,3,4])
print(a)   # [2 3 4]
list1 = [2,4,6,8]
a = np.array(list1)
print(a)   # [2 4 6 8]
```

displaying the type of array

```py
print(type(a))            # <class 'numpy.ndarray'>
print(a.dtype)            # int32
```

### Creating a 2-D array

```py
a = np.array([[1, 2, 3, 4, 5],[6, 7, 8, 9, 10], [11, 12, 13, 14, 15]])
print(a)
```

output
```
[[ 1  2  3  4  5]
 [ 6  7  8  9 10]
 [11 12 13 14 15]]
```

display information

```py
# number of items in each dimension
# number of dimensions
# number of items in 1st dimension. Since 'a' is a matrix, this corresponds to number of rows in a
print('Shape of a =', a.shape)                   
print('Number of dimensions of a =', a.ndim)      
print('Number of rows of matrix a =', len(a))                                             
```

output

```
Shape of a = (3, 5)
Number of dimensions of a = 2
Number of rows of matrix a = 3
```

boolean

```py
a = np.array( [ [1,1], [0,1] ], dtype=bool)
print(a)
```

output

```
[[ True  True]
 [False  True]]
```

all zero and one

```py
all_zeros = np.zeros((3, 5))
all_ones = np.ones((3,2))
print(all_zeros)
print(all_ones)
```
output

```
[[0. 0. 0. 0. 0.]
 [0. 0. 0. 0. 0.]
 [0. 0. 0. 0. 0.]]
[[1. 1.]
 [1. 1.]
 [1. 1.]]
```

Generating number sequences

`np.arrange`

```py
a = np.arange( 10, 30, 5 )                  # the parameters are start, end, step. Note that end is not inclusive.
print(a)     # [10 15 20 25]
```

### Random numebr generator

`np.random.eand()`

```py
randNum = np.random.rand(3,2)          # generates a matrix of size 3x2
print(randNum)
```
output
```
[[0.50670901 0.64030911]
 [0.61370392 0.7320221 ]
 [0.36193324 0.95398891]]
```

```py
np.random.randint(0, 20+1)    # generate a random integer scalar between 0 and 20
np.random.randint(0, 21, (3,2))# generates a matrix of size (3,2)
```

### Seeding the random generator

`np.random.seed()`

it will generate the same and repeated random number every time we run

```py
np.random.seed(4)
print(np.random.rand(4))
print(np.random.rand(4))
```

# Numerical Operation

- the product operator `*` performs *elementwise multiplication, NOT matrix multiplication*

```py
A = np.array( [[1,1], [0,1]] )
B = np.array( [[2,0], [3,4]] )
print(A*B)
```
output

```
[[2, 0],
[0, 4]]
```

### Comparison and logical operations


```py
a1 = np.array([13, 22, 37, 42])
a2 = np.array([13, 22, 37, 42])
b  = np.array([2, 4, 7, 5])

print(a1 < 35)   # [ True,  True, False, False]
np.array_equal(a1, a2)  # True

# boolean comparison
bool1     = np.array([True,  True, False, False])
bool2     = np.array([False, True, False, True])
all_true  = np.array([True, True, True, True])
all_false = np.array([False, False, False, False]) 

np.all(bool1)                          # Checks if every value is True
# False
np.all(all_true) # True

print(bool1 & bool2)                         # Element-wise AND operation
# [False,  True, False, False]
```

### Comparing Array

```py
a = np.array([1, 2, 3, 4])
b = np.array([4, 2, 2, 4])

print(a == b)   # [False,  True, False,  True]
np.maximum (a, b)    # Get the element-wise maximum of all corresponding items in a and b 
np.minimum (a, b)    # Get the element-wise minimum of all corresponding items in a and b
```

### Numpy function

```py
a = np.random.randint(-10, 10, 5)
np.sin(a)
np.exp(a)
np.abs(a)
np.max(a)             # get the item with the biggest value
np.min(a)             # get the item with the smallest value
```

### nsarray functions

```py
a = np.random.randint(0, 20, 10)

print('sum:    ', a.sum())                # compute the sum
print('mean:   ', a.mean())               # compute the mean 
print('std:    ', a.std())                # compute the standard deviation
print('min:    ', a.min())                # get the smallest value in array
print('argmin: ', a.argmin())             # find the index of the item with the smallest value
print('max:    ', a.max())                # get the maximum value
print('argmax: ', a.argmax())             # find the index of the item with the biggest value

```

output

```
sum:     10
mean:    2.5
std:     1.118033988749895
min:     1
argmin:  0
max:     4
argmax:  3
```

ndarray operations on 2-D arrays

```py
a = np.random.randint (0, 20, (3, 2))
print(a)
```
output
```
[[ 0, 10],
[ 9, 16],
[ 4, 19]]
```

```py
print('sum:    ', a.sum())                # compute the sum
print('mean:   ', a.mean())               # compute the mean 
print('std:    ', a.std())                # compute the standard deviation
print('min:    ', a.min())                # get the smallest value in array
print('argmin: ', a.argmin())             # find the index of the item with the smallest value
print('max:    ', a.max())                # get the maximum value
print('argmax: ', a.argmax())             # find the index of the item with the biggest value
```

```py
a.sum(axis=0)           # axis = 0 refers to the column dimension (sum all items in each column)
a.sum(axis=1)         # axis = 1 refers to the row dimension (sum all items in each row)
```
output
```
array([13, 45])
array([10, 25, 23])
```

## Indexing, Slicing and Iterating

Simple Indexing and Slicing

```py
a = np.random.randint(0, 100, 10)
print(a)        # [28 79 74 53 91 34 58 73 43 49]

a[2]              # get item 2
a[2:5]           # start = 2, end = 5 (not inclusive). This gets item 2 up to item 4
a[:3]           # equivalent to a[0:3]
a[7:]           # gets item at position 7 to the last position
a[2] = -1         # overwritting the third item
a[::2] = -1000    # equivalent to a[0:10:2] = -1000   output---> [-1000,    79, -1000,    53, -1000,    34, -1000,    73, -1000,
          49]

```

Negative Indexing

```py
a = np.random.randint(0, 100, 10)
a[-1]   # take the last value
a[-3:]             # get the last three items
```

Multidimensional indexing

```py
a = np.random.randint(0, 100, (3, 5))
print(a)
```
output

```
[[86, 93, 62, 23, 37],
[ 7, 31, 51, 22, 69],
[23, 16, 18, 51, 30]]
```

```py
a[2, 3]               # item at row 2, column 3 (third row, fourth column)
a[:, 1]               # get the column 1 of a
a[:2, 1]              # first two items in column 1 of a
a[:, 1:3]            # get column 1 and 2 (not inclusive of 3)
a[2]              # get row 2
a[1:]             # get row 1 to the last row
```

### Indexing with Integer Arrays

```py
a = np.array([10, 11, 13,  0, 10, 10, 16, 12, 18,  9])

selected = [2, 3, 5]   #select third, fourth and sixth item from array
b = a[selected]
print(b)  # [13,  0, 10]
```

indexing a 2-D array

```py
a = np.array([[2, 5, 1, 1, 2],
              [5, 7, 2, 7, 35],
              [1, 9, 8, 49, 9]])

selected_row = (2, 1)
selected_col = (3, 4)

b = a[selected_row, selected_col]              # extracts item at location (2, 3) and (1, 4)
print(b)      # [49, 35]
```

### Indexing with Boolean Arrays

```py
a = np.array([23, -56, 2, 3, -57])

selected = [True, False, True, False, False]
print(a[selected])    # [23,  2]
```

# Matrix Computation

```py
A = np.array([[1, 0], [2, 5], [3, 1]], dtype = 'int')
print(A)

B = np.array([[4, 0.5], [2, 5], [0, 1]], dtype = 'int')
print(B)
```

output

```
[[1 0]
 [2 5]
 [3 1]]
[[4 0]
 [2 5]
 [0 1]]
```

Matrix plus and minus

`A+B`,`A-B`

Matrix multiplication

`np.dot()`

```py
m1 = np.array([[1, 2],[1, 4]])
print (m1)

m2 = np.array([[0, 1],[1, 2]])
print (m2)

np.dot(m1, m2)                     # matrix matrix multiplication
```

# Copy and Views


```py
a = np.arange(12)
print("a = ", a)     # a =  [ 0  1  2  3  4  5  6  7  8  9 10 11]

b = a
print("b = ", b)     # b =  [ 0  1  2  3  4  5  6  7  8  9 10 11]
b is a                   # for simple assignment, a and b are two names for the same ndarray objectf
# True
```

Note: Changing the content of a will affects the content of b

View copy

```py
a = np.array([[1, 2, 3],[4, 5, 6]])
a
###
array([[1, 2, 3],
       [4, 5, 6]])
###

b = a.ravel()
b               # array([1, 2, 3, 4, 5, 6])

c = a.reshape(3, 2)
c

"""
array([[1, 2],
       [3, 4],
       [5, 6]])
"""

```

Copy

```py
a = np.arange(15).reshape(3, 5) 
d = a.copy()

d is a                                # d is not the same as a
# False
```

































































