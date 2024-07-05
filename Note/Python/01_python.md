# Print

`print(type(variable))` ---> output: `<class 'int'>` , `<class 'float'>` , `<class 'str'>`

```py
s = 'hello world'   # defining a string variable. The type of s is assigned automatically based on the value assigned to it
print(s)
print(type(s))
```
output
```
hello world
<class 'str'>
```

# Math library

[Learn more math library](https://www.w3schools.com/python/module_math.asp)

```py
import math
print ('The sin of 90 degrees is', math.sin(math.pi/2))
print ('log of 100 is ', math.log(100))
```
output
```
The sin of 90 degrees is 1.0
log of 100 is  4.605170185988092
```

# String

Like Java, Python has a built in string type. 
* You can use either a single quote (`'`)  or double quote (`"`) to define a string.
* The  `+` operator is overloaded to do string concatenation on string values.

There are many built-in function that comes with a string variable.

**Tips**: *To see the list of functions provided by a library or string, type the name and then press TAB. For example, if you type  `s.<TAB>` to see the list of built-in functions:

[String Build in function](https://www.w3schools.com/python/python_ref_string.asp)

```py
s = 'HELLO'
s.lower()  # hello
'artificial'.upper()  # ARTIFICIAL
len(s)  #5
```

# Input and Output

```py
name = input('Enter your name: ')
print(name)

# Convert the type of input variable into int
ival = int(input('Enter an integer: '))
print(ival+13)
```

# Formatting String

```py
a = 3
print('There are', a, 'people in the meeting')

# using format()
x = 5; y = 10
print('The value of x is {} and y is {}'.format(x,y))
# output: The value of x is 5 and y is 10

# Specify the order
print('I love {0} and {1}'.format('bread', 'butter'))
print('I love {1} and {0}'.format('bread', 'butter'))  # the order
```

### Formatting

Formatting integer values:

The placeholder `{:6d}` has the following meaning:
* `d` specifies that the placedholder is to be replaced by an *integer*. 
* `6` specifies that a total of 6 characters would be allocated to print out the integer.

```py
print('Integer value is {:d}.'.format(23))   # Integer value is 23.
print('Integer value is {:6d}.'.format(23))  # Integer value is     23.
```

Formatting float values:

The placedholder `{:06f}` has the following meaning:
* `f`  specifies that the placedholder is to be replaced by an *real number*. 
* `6` specifies that a total of 6 characters would be allocated to print out the number. 
* `.2` displays the real number up to two decimal places
* `0` specifies that if the number of characters is less than number of allocated characters (6 in our case), the empty spaces should be replaced with 0.

```py
print('The float value is {:f}'.format(3.141592653589793))     # The float value is 3.141593
print('The float value is {:06.2f}'.format(3.141592653589793)) # The float value is 003.14
print('The float value is {:6.2f}'.format(3.141592653589793))  # The float value is   3.14
```

### f-string

```py
x = 5.1 
y = 7.48756
print(f'The value of x is {x} and y is {y:.2f}')   # The value of x is 5.1 and y is 7.49
```

Example:

```py
num1 = int(input('Please enter first number: '))
num2 = int(input('Pleae enter second number: '))
print('{:d}/{:d} = {:d} remainder {:d}'.format(num1, num2, num1//num2, num1%num2))
```
output
```
Please enter first number: 5
Pleae enter second number: 3
5/3 = 1 remainder 2
```

Example using replace function:

```py
sentence = "The lyrics is not bad at all, not bad at all."
# your code here
sentence.replace('not bad at all', 'good', 1)
```
output
```
'The lyrics is good, not bad at all.'
```

# Function


```py
# Correct way of defining a function
def square(num):
    "Returns the square of a number"
    result = num**2
    return result

x = square(2)
print(x)  # 4
```

### Returning More than One Variable

```py
def square2and3(num):
    "Returns the square of a number"
    result1 = num**2
    result2 = num**3

    return result1, result2

sq2, sq3 = square2and3 (2)
print(sq2, sq3)     #output: 4 8
```

### Passing argument to a function

```py
def func (intval, strval):
    intval = 100
    strval = "Modified string value"
    print (">>> func: numval = {}, strval = {}".format(intval, strval))

intval  = 0
strval = "Original string value"

print ("main (before calling func): numval = {}, strval = {}".format(intval, strval))
func (intval, strval)
print ("main (after calling func): numval = {}, strval = {}".format(intval, strval))
```

### Setting Default Arguement

```py
def printinfo(name, age = 35):
    "This prints a passed info into this function"
    print ("Name: ", name)
    print ("Age: ", age)

printinfo (name = "Suzuki")	
printinfo (name = "Michiko", age = 12)
```
output
```
Name:  Suzuki
Age:  35
Name:  Michiko
Age:  12
```


# Condition Staetement and Loop

```py
price = float(input('how much is one apple? '))
print(price)
if price < 2.00:
    print (price, 'is cheap, I should buy more')
elif price < 4.0:
    print (price, 'is not cheap, I should buy less')
else:
    print (price, 'is too expensive, I cannot afford it')
```

### for in Loop

For number
```py
for num in [1, 2, 3, 4, 5]:
    print (num)
```
output
```
1
2
3
4
5
```
For String
```py
for name in ['lessie', 'joe', 'bob']:
    print (name)
```
output
```
lessie
joe
bob
```

### range

- `range(end)`

```py
for num in range(5):        
    print (num)
```
output
```
0
1
2
3
4
```

- `range(start,end)`

```py
for num in range(3,7):     
    print (num)
```
output
```
3
4
5
6
```

- `range(start,end,skip)`

```py
for num in range(10,26,5):  
    print (num)
```
output
```
10
15
20
25
```

### **The `enumerate` command**

- while using `enumerate()` function, it show the index

```py
for i, v in enumerate(['tic', 'tac', 'toe']):
    print (i, v)
```
output
```
0 tic
1 tac
2 toe
```

### **The `zip` command**

To loop over two or more sequences at the same time, the entries can be paired using the `zip()` function.

```py
questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
    print ('What is your {0}?  It is {1}.'.format(q, a))
```
output
```
What is your name?  It is lancelot.
What is your quest?  It is the holy grail.
What is your favorite color?  It is blue.
```

another example of zip command

```py
names = ['Krishnan', 'Shafie', 'Kim Loong']
grades = [99, 100, 89]

for n, g in zip(names, grades):
    print ('{0}: {1}.'.format(n, g))
```
output
```
Krishnan: 99.
Shafie: 100.
Kim Loong: 89.
```

### while loop

```py
num = 1
while num <= 5:
    print (num)
    num += 1
```
output
```
num = 1
while num <= 5:
    print (num)
    num += 1
```

# Build In Data Structure

- list
- tuple
- set
- dictionary

## List

```py
fruits = ['apple','orange','pear']   # a list of strings
print (fruits)      

numbers = [11,12,13,14]              # a list of integers
print(numbers)

isHandsome = [True, False, True]       # a list of booleans
print(isHandsome)

rojak = [11, 'hello', True, [1,2,3], ['one', 2, False]]     # a list of different types of items
print(rojak)


# get the length of list
len(numbers)    # 4
```

Slice Indexing: accessing a range of item in the list

```py
print(allFruits)    # print all items
print(allFruits[0:2])  # items 0 and 1 (not including 2)
print(allFruits[:3])   # first item to item 2 (not including 3)
print(allFruits[2:])   # items 2 to last item
```

nnegative indexing

```py
allFruits[-3:]       # Start from the third last item to the end of the list
allFruits[-3:-1]     # Start from the third last item to the second last item of the list
```

### Reference vs Copy

Using the command of `.copy()`

```py
colours1 = ["red", "green"]
colours2 = colours1   # rferencing, change in colour2 will affect the previous one
colours2 = colours1.copy()   # copy  # change in the colour2 will not affect the previous one
```

### Difference between == and is statement

* **The operator `is`** checks if two variables are referencing the same list or object. 
* **The operator `==`** checks if the lists have the same content.

Example

```py
a = [1, 2, 3]
b = a.copy()
print(b is a)  # False 
print(b == a)  # True
```


## Tuple

It is immutable once declared

```py
pair = (3,5)
print(pair)     # (3, 5)
print(pair[0])  # 3
```

## Set

Unorder list with **no duplicate items**

```py
shapes = ['circle','square','triangle','circle']
setOfShapes = set(shapes)
setOfShapes  # {'circle', 'square', 'triangle'}    <--- ordered

setOfShapes.add('polygon') 
setOfShapes.add ('circle')
setOfShapes.add('triangle')
print(setOfShapes)       # {'triangle', 'square', 'circle', 'polygon'}  <--- unordered if using print
```

Check if exist in set

```py
if 'circle' in setOfShapes:
    print ('circle exists in setOfShapes')
else:
    print ('circle does not exist in setOfShapes')
    
if 'rhombus' in setOfShapes:
    print ('rhombus exists in setOfShapes')
else:
    print ('rhombus does not exist in setOfShapes')
```

Operation on set

```py
favoriteShapes = ['circle','triangle','hexagon']
setOfFavoriteShapes = set(favoriteShapes)
print ('setOfShapes:         ', setOfShapes)
print ('setOfFavoriteShapes: ', setOfFavoriteShapes)
print ()

print('setOfShapes - setOfFavoriteShapes:', setOfShapes - setOfFavoriteShapes)
print('setOfShapes & setOfFavoriteShapes:', setOfShapes & setOfFavoriteShapes)
print('setOfShapes | setOfFavoriteShapes:', setOfShapes | setOfFavoriteShapes)
```
output
```
setOfShapes:          {'triangle', 'square', 'circle', 'polygon'}
setOfFavoriteShapes:  {'triangle', 'hexagon', 'circle'}

setOfShapes - setOfFavoriteShapes: {'square', 'polygon'}
setOfShapes & setOfFavoriteShapes: {'circle', 'triangle'}
setOfShapes | setOfFavoriteShapes: {'circle', 'hexagon', 'square', 'triangle', 'polygon'}
```


## Dictionary


The last built-in data structure is the dictionary which stores a map from one type of object (the `key`) to another (the `value`). 

* The `key` must be an immutable type (string, number, or tuple). 
* The `value` can be any Python data type.


Creating a dictionary

```py
studentIds = {'joe': 42.0, 'mary': 56.0}
studentIds     # {'joe': 42.0, 'mary': 56.0}

d1 = dict([('sape', 4139), ('guido', 4127), ('jack', 4098)])
d1     # {'sape': 4139, 'guido': 4127, 'jack': 4098}

d2 = dict(sape=4139, guido=4127, jack=4098)
d2     # {'sape': 4139, 'guido': 4127, 'jack': 4098}

# Used of different list
namelist = ['joe', 'mary']
Ids = [42.0, 56.0]
d3 = {name: age for name, age in zip(namelist, Ids)}
d3     # {'joe': 42.0, 'mary': 56.0}
```





























































