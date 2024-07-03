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






































































