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

![listcmd.jpg](attachment:listcmd.jpg)

The following coded show how to use several built-in functions to manipulate a string.
