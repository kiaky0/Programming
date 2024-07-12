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

Specify the index row and column name, using `index = []` and `column = []`

```py
df = pd.DataFrame(np.random.randn(6,4), index = ['r1', 'r2', 'r3', 'r4', 'r5', 'r6'], columns = ['c1', 'c2', 'c3', 'c4'])
```

<br>

Example of creating dataframe

```py
data = {'year': [2000, 2001, 2003, 2004, 2005],
        'state': ['Yokohama', 'Tokyo', 'Kyoto', 'Hokaido', 'Osaka'],
        'population': [1.5, 1.7, 3.6, 2.4, 2.9] }

df = pd.DataFrame(data, index = ['1st', '2nd', '3rd', '4th', '5th'])
df
```

![image](https://github.com/user-attachments/assets/8e5c5c4e-a2ba-46f0-a6a8-2e2e544433f4)

Using `<DataFrame>.dtypes`

```py
df.dtypes
```

- result

```
state          object
year            int64
population    float64
dtype: object
```

<br>

### Accessing items in a DataFrame

Command `.at[row_index, column_index]`

```py
df.at['5th','state']         # Indexing order: [row, column]
df.at['5th', 'state'] = 'Nagasaki'     # Change the value at the index order to Nagasaki
```

Command `.iat[row_position, column_position]`

```py
df.iat[4, 0]             # Indexing order: [column, row]
df.iat[4, 0] = 'Osaka'
```

### Accessing a single column

```py
df['yeaer']    # # access column 'year' by dict-like notation
```
- result

```
1st    2000
2nd    2001
3rd    2003
4th    2004
5th    2005
Name: year, dtype: int64
```

<br>

Modify the content in the column using numpy

```py
df['year'] = np.arange(2010, 2015)   # modifies the content of column 'year'
df
```
- result in the year become accending order from 2010 to 2015












