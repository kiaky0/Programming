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



























































