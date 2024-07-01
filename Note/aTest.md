An exception is an object that represents an error or a condition that prevents execution from proceeding normally. If the exception is not handled, the program will terminate abnormally.

# Try and catch

```java
	public static void main(String[] args) {
		int num = 13, denom = 0, result;
		try {
			result = num / denom;
		}
		catch(ArithmeticException ex) {
			System.out.println("Attempt to divide by zero");
		}
	}
```

# Using Exception

systex used

Declaring: method() `throws ArithmeticException`

Throwing: `throw new ArithmeticException("Divisor cannot be zero")`

```java
public class ExceptionHandle2 {
	public static void main(String[] args){
		int a=20,b=0;
		try{
			System.out.println(a + "/" + b + " = " + division(a, b));
		}
		catch(ArithmeticException e) { 				
			System.out.println(e.getMessage()); 
			System.out.println(e);
			e.printStackTrace();
		}
		System.out.println("Program continue.");
	}
	
	public static int division(int a, int b)  throws ArithmeticException{
		if(b==0)
		   throw new ArithmeticException("Divisor cannot be zero");
		
		return a/b;	
	}

}
```

# Note for the step

## 1. Declaring Exception

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/3e121045-cd99-49ca-b5ec-e8002c86041c/1a7690d4-4137-4d98-b6bf-118187756c2e/Untitled.png)

## 2. Throwing Exception

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/3e121045-cd99-49ca-b5ec-e8002c86041c/6902045c-f8de-48e6-be23-94f3009fca6c/Untitled.png)

## 3. Catching Exception

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/3e121045-cd99-49ca-b5ec-e8002c86041c/888b15c3-75ec-40ec-9e25-9f31f595501e/Untitled.png)

### Declaring, Throwing and Catching

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/3e121045-cd99-49ca-b5ec-e8002c86041c/c004a710-6490-4951-a848-e43aed2ba394/Untitled.png)

## Benefit

- seperating the detection of an error from the handling of an error

# System Errors

System errors are thrown by JVM and represented in the Error class. The Error class describes internal system errors. 

# Exception

Exception describes errors caused by your program and external circumstances. These errors can be caught and handled by your program.

# Runtime Exception

RuntimeException is cause by programming errors, such as bad casting, accessing an out-of-bounds array, and numeric errors. 

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/3e121045-cd99-49ca-b5ec-e8002c86041c/cf213503-ab9a-4cc5-93c7-a2fce29a28a9/Untitled.png)

# The `finally` Block

- Use for action that must perform at the end of try catch sequence

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/3e121045-cd99-49ca-b5ec-e8002c86041c/ccda3024-8391-4d92-8bee-e83ceafd5dcc/Untitled.png)

# Example

```java
import java.util.*;

public class ExceptionHandle3 {
	public static void main(String[] args) 
	{
	    Scanner input = new Scanner(System.in);
	    boolean continueInput = true;
	    do {
	    	try {
	    		System.out.print("Enter an integer: ");
	    		int number = input.nextInt();  
	    		System.out.println("The number entered is " + number);
	        
	    		continueInput = false;
	    		} 
	    	catch (InputMismatchException ex) {
	    		System.out.println("Try again. (" + "Incorrect input: an integer is required)");
	    		input.nextLine(); // discard input 
	    		}
	    	} while (continueInput);
	    input.close();
	}
}
```

# Check Exception

```java

public class CheckExceptionDemo {
	
	public static void main(String[] args)
	{
		int a=20,b=4;
		double c=20.0,d=0.0;
		try{
			System.out.println(a + "/" + b + " = " + division(a, b)); // optional to place inside catch block
			System.out.println(c + "/" + d + " = " + division(c, d)); // must place inside catch block
		}
		catch(ArithmeticException e) { 				
			System.out.println(e); 
		}
		catch(Exception e) { 				
			System.out.println(e); 
		}
		System.out.println("Program continue.");
	}
	
	
	public static int division(int a, int b)  throws ArithmeticException { // optional
		if(b==0)
		   throw new ArithmeticException("Divisor cannot be zero");
		
		return a/b;	
	}
	
	public static double division(double a, double b)  throws Exception { // must declare
		if(b==0)
		   throw new Exception("Divisor cannot be zero");
		
		return a/b;	
	}

}
```

# Customize exception

- Using Extend

```java
public class CustomExceptionTest {
	public static void main(String[] args)
	{
		
			try {
				new Circle(1);
			} catch (InvalidRadiusException e) {
				System.out.println(e);
			}
			System.out.println("Program ends normally");
		
	}	
}

class Circle {
	double radius;
	public Circle(double r) throws InvalidRadiusException 
	{
		if(r <= 0.0)
			throw new InvalidRadiusException(r);
		else
			radius = r;
	}
}

class InvalidRadiusException extends Exception {
	int i;
	public InvalidRadiusException(double radius) {
		super("Invalid Radius: " + radius);
	}
}
```

# File Input and Output (I/O)

- Text file: Using Scanner class and written using the PrintWritter class
- Binary: binary data I/O is handled by FileInputStream, FileOutputStream, DataOutputStream classes

## Writting text to a file

### PrintWriter Class

- The printWriter class aloows you to write data to a file using the print and println methods.

`PrintWriter outputFile = new PrintWritter("StudentData.txt");`

```java
import java.util.Scanner;   // Needed for Scanner class
import java.io.*;           // Needed for File I/O classes

/**
   This program writes data to a file.
*/

public class FileWriteDemo
{
   public static void main(String[] args)// throws IOException
   {
      String filename;      // File name
      String friendName;    // Friend's name
      int numFriends;       // Number of friends

      // Create a Scanner object for keyboard input.
      Scanner keyboard = new Scanner(System.in);
      
      // Get the number of friends.
      System.out.print("How many friends do you have? ");
      numFriends = keyboard.nextInt();

      // Get the filename.
      filename = "friends.txt";
//      filename = "../Unit10/friends.txt";  // relative file name

      // Open the file.
      PrintWriter outputFile = null;
      try {
    	   outputFile = new PrintWriter(filename);
      } 
      catch(FileNotFoundException e){
    	  System.out.println(e);   
    	  System.exit(1);
      }

      // Get data and write it to the file.
      for (int i = 1; i <= numFriends; i++)
      {
         // Get the name of a friend.
         System.out.print("Enter the name of friend " +
                          "number " + i + ": ");
         friendName = keyboard.next();

         // Write the name to the file.
         outputFile.println(friendName);
      }

      // Close the file.
      outputFile.close();
      keyboard.close();
      System.out.println("Data written to the file.");
   }
}

```

If the file already exist it will be erased and replaced with a new empty file

`throws IOException` if file no found

reading data from a file

```java
File myFile = new File("Customer.txt");
Scanner inputFile = new Scanner(myFile);
```

# File read example

```java
import java.util.Scanner; // Needed for the Scanner class
import java.io.*;         // Needed for the File class

/**
   This program reads data from a file.
*/

public class FileReadDemo
{
   public static void main(String[] args) throws IOException
   {
      // Create a Scanner object for keyboard input.
      Scanner keyboard = new Scanner(System.in);

      // Get the filename.
      System.out.print("Enter the filename: ");
      String filename = keyboard.next();

      // Open the file.
      File file = new File(filename);
      Scanner inputFile = new Scanner(file);

      // Read lines from the file until no more are left.
      while (inputFile.hasNext())
      {
         // Read the next name.
         String friendName = inputFile.nextLine();

         // Display the last name read.
         System.out.println(friendName);
      }

      // Close the file.
      inputFile.close();
      keyboard.close();
   }
}
```

# Read and perform sum

```java
import java.util.Scanner; 
import java.io.*;

/**
   This program reads a series of numbers from a file and
   accumulates their sum.
*/

public class FileSum
{
   public static void main(String[] args) throws IOException
   {
      double sum = 0.0;   // Accumulator, initialized to 0

      // Open the file for reading.
      File file = new File("Numbers.txt");
      Scanner inputFile = new Scanner(file);

      // Read all of the values from the file
      // and calculate their total.
      while (inputFile.hasNext())
      {
         // Read a value from the file.
         double number = inputFile.nextDouble();
         System.out.println(number);
         // Add the number to sum.
         sum = sum + number;
      }

      // Close the file.
      inputFile.close();

      // Display the sum of the numbers.
      System.out.println("The sum of the numbers in " +
                         "Numbers.txt is " + String.format("%.2f", sum));
   }
}

```

# Binary I/O

## Open and write binary file

```java
FileOutputStream fstream = new FileOutputStream("myfile.dat");
DataOutputStream dstream = new DataOutputStream(fstream);
```

## Open and read binary file

```java
FileInputStream fstream = new FileInputStream("myfile.dat");
DataInputStream dstream = new DataInputStream(fstream);
```

## Example of Read file

```java
import java.io.*;

//This program opens a binary file, reads and displays the contents.

public class ReadBinaryFile
{
   public static void main(String[] args) throws IOException
   {
      int number; // A number read from the file
      boolean endOfFile = false;     // EOF flag
      
      // Create the binary file input objects.
      FileInputStream fstream =  new FileInputStream("Numbers.dat");
      DataInputStream inputFile = new DataInputStream(fstream);
    
      System.out.println("Reading numbers from the file:");
   // Read the contents of the file.    
      while (!endOfFile)
      {
         try
         {
            number = inputFile.readInt();
            System.out.print(number + " ");
         }
         catch (EOFException e)
         {
            endOfFile = true;
         }
      }
      
//      while(inputFile.available() > 0) {
//    	  number = inputFile.readInt();
//          System.out.print(number + " ");
//      }

      System.out.println("\nDone.");
      
      // Close the file.
      inputFile.close();   
   }
}
```
