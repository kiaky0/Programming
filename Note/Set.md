# Set

[Note](https://www.geeksforgeeks.org/set-in-java/)

## Set in Java

The set interface is present in java.util package and extends the Collection interface. 
It is an unordered collection of objects in which duplicate values cannot be stored. It is an interface that implements the mathematical set.


```java
public interface Set extends Collection
```

Creating set object

```java
// Obj is the type of the object to be stored in Set 
Set<Obj> set = new HashSet<Obj> ();
```

Example code:

```java
// Java program Illustrating Set Interface 

// Importing utility classes 
import java.util.*; 

// Main class 
public class GFG { 
	
	// Main driver method 
	public static void main(String[] args) 
	{ 
		// Demonstrating Set using HashSet 
		// Declaring object of type String 
		Set<String> hash_Set = new HashSet<String>(); 

		// Adding elements to the Set 
		// using add() method 
		hash_Set.add("Geeks"); 
		hash_Set.add("For"); 
		hash_Set.add("Geeks"); 
		hash_Set.add("Example"); 
		hash_Set.add("Set"); 

		// Printing elements of HashSet object 
		System.out.println(hash_Set); 
	} 
}
```

Output

```
[Set, Example, Geeks, For]
```

Example 2 

```java
// Java Program Demonstrating Operations on the Set 
// such as Union, Intersection and Difference operations 

// Importing all utility classes 
import java.util.*; 

// Main class 
public class SetExample { 
	
	// Main driver method 
	public static void main(String args[]) 
	{ 
		// Creating an object of Set class 
		// Declaring object of Integer type 
		Set<Integer> a = new HashSet<Integer>(); 
		
		// Adding all elements to List 
		a.addAll(Arrays.asList( 
			new Integer[] { 1, 3, 2, 4, 8, 9, 0 })); 
		
	// Again declaring object of Set class 
	// with reference to HashSet 
		Set<Integer> b = new HashSet<Integer>(); 
		
	b.addAll(Arrays.asList( 
			new Integer[] { 1, 3, 7, 5, 4, 0, 7, 5 })); 

		
		// To find union 
		Set<Integer> union = new HashSet<Integer>(a); 
		union.addAll(b); 
		System.out.print("Union of the two Set"); 
		System.out.println(union); 

		// To find intersection 
		Set<Integer> intersection = new HashSet<Integer>(a); 
		intersection.retainAll(b); 
		System.out.print("Intersection of the two Set"); 
		System.out.println(intersection); 

		// To find the symmetric difference 
		Set<Integer> difference = new HashSet<Integer>(a); 
		difference.removeAll(b); 
		System.out.print("Difference of the two Set"); 
		System.out.println(difference); 
	} 
}

```

output

```
Union of the two Set[0, 1, 2, 3, 4, 5, 7, 8, 9]
Intersection of the two Set[0, 1, 3, 4]
Difference of the two Set[2, 8, 9]
```












