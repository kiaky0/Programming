# Intro to Pandas

`pandas` is a *data analysis library* that contains many high-level data structures and manipulation tools designed to make data analysis fast and easy in Python. It is built on top of `NumPy` and makes it easy to use in NumPy-centric applications.

There are two types of data structures in Pandas:

1. `Series` : a 1-dimensional array-like list object
2. `DataFrame`: a multi-dimensional array-like object


## **SERIES**

```py
s = pd.Series([4, 7, -5, 3])
print(s)
```

- result

```
0    4
1    7
2   -5
3    3
dtype: int64
```

<hr>

**Index of series**

```py
s = pd.Series([21, 'Two', 39, -4], index = ['ONE', 'TWO', 'THREE', 'FOUR'])
print(s)
```

- result

```
ONE       21
TWO      Two
THREE     39
FOUR      -4
dtype: object
```

<br>

```py
data = {'Ohio': 35000, 'Texas': 71000, 'Oregon': 16000, 'Utah': 5000}

s = pd.Series(data)
print(s)
```

- result

```
Ohio      35000
Texas     71000
Oregon    16000
Utah       5000
dtype: int64
```

calling the item by using the index name

```py
s['Ohio`]  # 35000
```
calling the item by using the position

```py
s[0]    # 35000
```

Access the index

```py
s.index
# Index(['Ohio', 'Texas', 'Oregon', 'Utah'], dtype='object')
```

Change the index of a series

```py
s.index = ['Perak', 'Penang', 'Selangor', 'Melaka']
print(s)
```

- result

```
Perak       35000
Penang      71000
Selangor    16000
Melaka       5000
dtype: int64
```

<hr>

## DATAFRAME

A *dataframe* is a *2-dimensional* data structure. It may consist of columns of potentially different types. 

Items in a dataframe are referenced by:

1. `index` (which indexes the rows) and 
2. `columns` (which indexes the columns).

<br>

Generate dataframe

```py
df = pd.DataFrame(np.random.randn(6,4))
print(df)
```

![image](https://github.com/user-attachments/assets/d8f22d84-b2aa-4e24-8aff-8f266ab0f7ef)

Specify the index row and column name

```py
df = pd.DataFrame(np.random.randn(6,4), index = ['r1', 'r2', 'r3', 'r4', 'r5', 'r6'], columns = ['c1', 'c2', 'c3', 'c4'])
```









