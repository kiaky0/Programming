package ooppAssignment;

import java.util.Scanner;

public class SMS {
	private static Product[] productList;
	private static int maxProductInput=0;
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Welcome to stock management system");
		
		System.out.print("Enter your full name to register: ");
        String fullName = scanner.nextLine();
        UserInfo user = new UserInfo(fullName);
        System.out.println("Name: " + user.getName());
        System.out.println("User ID: " + user.getUserID());
        System.out.print("How many product you want to add: ");
       
        maxProductInput = scanner.nextInt();
        while (maxProductInput <=0)
        {
        	System.out.println("Please key in integer larger than 0 ");
        	 System.out.print("How many product you want to add: ");
             maxProductInput = scanner.nextInt();
        }
        System.out.println("The maximum product is set to " + maxProductInput);
        int add;
        Refrigerator refrigerator1 = new Refrigerator(001, "Pensonic", 12, 1500.00, "one door", "Red",300);
    	addProduct(refrigerator1);
		TV tv1= new TV(002, "SamsungTV", 8, 2500, "OLED", "4K" ,42);
		addProduct(tv1);
		Fan fan1= new Fan(003,"KDKFan" , 28, 200, 5, 3,35);
		addProduct(fan1);
        do {
        	System.out.println();
        	System.out.print("Do you want to add products? yes-1, no-2: ");
        	add = scanner.nextInt();
        	
			while (add != 1 && add != 2) {
				System.out.print("Please enter a VALID option: ");
				add = scanner.nextInt();
			}
			System.out.println();
			
			if(add==1) {
				// addProduct
				System.out.println();
				do {
					addProduct(productList,scanner);
					System.out.print("Do you want to continue add product? yes-1, no-2: ");
					add = scanner.nextInt();
					while (add != 1 && add != 2) {
						System.out.print("Please enter a VALID option: ");
						add = scanner.nextInt();
					}
					System.out.println();
				}while(add==1);
			}
        }while(add == 1);
        
        int selection = 1;
        while(selection !=0) {
        	selection = displayMenu(scanner);
        	menuMethod(selection, productList,scanner);
        	
        	if(selection == 0) {
        		System.out.println("Thank you fo using the system");
        		System.out.print("UserID: "+ user.getUserID() + ", Username: "+ user.getName());
        		System.exit(0);
        	}
        	
        }

	}
	
	// get the max number of products from user
	public static int getMaxProducts(Scanner input) {
		int maxProducts;
		
		// noted can add throw exception
		do {
			System.out.print("Enter the maximum number of products to store: ");
			maxProducts = input.nextInt();
			input.nextLine(); // new line
		}while(maxProducts < 0);
		return maxProducts;
	}
	
	// display products and choice selected
	public static int displayProducts(Product[] products, Scanner scanner) {
		System.out.println("Products: ");
		for(int i=0;i<products.length;i++) {
			System.out.println(i + ". "+ products[i].getName());
		}
		int choice;
		do {
			System.out.print("Select a product to update: ");
			choice = scanner.nextInt(); 
		}while (choice <0 || choice >= products.length);
		return choice;
	}
	
	// add product
	public static void addProduct(Product[] productArray, Scanner scanner) {
		if(maxProductInput <= productArray.length) {
			System.out.println("Maximum product reached!");
			return;
		}
		System.out.println("1. Refrigerator");
		System.out.println("2. TV");
		System.out.println("3. Fan");
		System.out.print("Which product do you want to add?: ");
		int choice = scanner.nextInt();
		
		while(choice !=1 && choice !=2 && choice !=3) {
			System.out.print("Please enter a Valid number: ");
			System.out.println();
			choice = scanner.nextInt();
		}

		
		System.out.println("Enter the product detail");
		if(choice == 1) {
			addRefrigerator(scanner);
		}
		else if(choice == 2) {
			addTV(scanner);
		}
		else if(choice == 3) {
			addFan(scanner);
		}
	}
	
	// add refrigerator
	public static void addRefrigerator(Scanner scanner) {
		System.out.print("Enter name: ");
		scanner.nextLine();
		String name = scanner.nextLine();
		System.out.print("Enter door design: ");
		String doorDesign = scanner.nextLine();
		System.out.print("Enter color: ");
		String color = scanner.nextLine();
		System.out.print("Enter capacity: ");
		int capacity = scanner.nextInt();
		System.out.print("Enter quantity available in stock: ");
		int quantity = scanner.nextInt();
		System.out.print("Enter price: ");
		double price = scanner.nextDouble();
		System.out.print("Enter item number: ");
		int itemNumber = scanner.nextInt();
		scanner.nextLine();
		
		Refrigerator refrigerator = new Refrigerator(itemNumber, name, quantity, price, doorDesign, color,capacity);
		addProduct(refrigerator);
	}
	
	// add TV
	public static void addTV(Scanner scanner) {
		System.out.print("Enter name: ");
		scanner.nextLine();
		String name = scanner.nextLine();
		System.out.print("Enter screen type: ");
		String screenType = scanner.nextLine();
		System.out.print("Enter resolution: ");
		String resolution = scanner.nextLine();
		System.out.print("Enter display size: ");
		int displaySize = scanner.nextInt();
		System.out.print("Enter quantity available in stock: ");
		int quantity = scanner.nextInt();
		System.out.print("Enter price: ");
		double price = scanner.nextDouble();
		System.out.print("Enter item number: ");
		int itemNumber = scanner.nextInt();
		scanner.nextLine();
		
		TV tv = new TV(itemNumber, name, quantity, price, screenType, resolution, displaySize);
		addProduct(tv);
	}
	
	// add Fan
	public static void addFan(Scanner scanner) {
		System.out.print("Enter name: ");
		scanner.nextLine();
		String name = scanner.nextLine();
		System.out.print("Enter speed number: ");
		int speedNum = scanner.nextInt();
		System.out.print("Enter blades number: ");
		int bladesNum = scanner.nextInt();
		System.out.print("Enter radius: ");
		double radius = scanner.nextDouble();
		System.out.print("Enter quantity available in stock: ");
		int quantity = scanner.nextInt();
		System.out.print("Enter price: ");
		double price = scanner.nextDouble();
		System.out.print("Enter item number: ");
		int itemNumber = scanner.nextInt();
		scanner.nextLine();
		
		Fan fan = new Fan(itemNumber, name, quantity, price, speedNum, bladesNum, radius);
		addProduct(fan);
	}
	
	// add product to array
	private static void addProduct(Product productType) {
		if(productList == null) {
			productList = new Product[1];
			productList[0] = productType;
		}
		else {
			Product[] products = new Product[productList.length+1];
			for (int i=0; i<productList.length; i++) {
				products[i] = productList[i];
			}
			products[products.length-1] = productType;
			productList = products;
			products = null;		
		}
	}
	
	// display menu
	public static int displayMenu(Scanner scanner) {
		int choice;
		do {	
	        System.out.println("\nMenu:");
	        System.out.println("1. View products");
	        System.out.println("2. Add stock");
	        System.out.println("3. Deduct stock");
	        System.out.println("4. Discontinue product");
	        System.out.println("0. Exit");
	        System.out.print("Please enter a menu option: ");
	        choice = scanner.nextInt();
	        scanner.nextLine();
		}while(choice < 0 || choice > 4);
		return choice;
	}
	
	// Menu method
	private static void menuMethod(int choice, Product[] productArray, Scanner scanner) {
		System.out.println();
		switch(choice) {
		case 1:
			viewProducts(productArray);
			break;
		case 2:
			addStock(productArray, scanner);
			break;
		case 3:
			deductStock(productArray, scanner);
			break;
		case 4:
			discontinueProduct(productArray, scanner);
			break;
		}
	}
	
	private static void viewProducts(Product[] productArray) {
		System.out.println("Item Number \tName \t\t Quantity \t Price");
		for(int i = 0; i < productArray.length; ++i) {
			System.out.print(productArray[i].getItemNum() +"\t\t");
			System.out.print(productArray[i].getName()+"\t ");
			System.out.print(productArray[i].getQuantity()+"\t\t ");
			System.out.print(String.format("%.2f", (productArray[i].getPrice()))+"\t");
			System.out.println();
		}
	}
	
	private static void addStock(Product[] productArray, Scanner in) {
		int amount;
		
		for(int i=0;i<productArray.length;++i) {
			System.out.println("Product #"+ (i+1)+" "+ productArray[i].getName());
			System.out.print("Enter the quantity to be added to stock: ");
			amount = in.nextInt();
			productArray[i].addStock(amount);
		}
		System.out.println();
	}
	
	private static void deductStock(Product[] productArray, Scanner in) {
		int amount;
		
		for(int i=0; i< productArray.length;++i) {
			System.out.println("Product #"+ (i+1)+" "+ productArray[i].getName());
			System.out.print("Enter the quantity to be deduct from stock: ");
			amount = in.nextInt();
			productArray[i].deductStock(amount);
		}
		System.out.println();
	}
	
	private static void discontinueProduct(Product[] productArray, Scanner in) {
		for(int i=0; i<productArray.length;++i) {
			System.out.println("Product #"+ (i+1)+" "+ productArray[i].getName());
			System.out.println();
		}
		
		System.out.print("Select the product to be discontinue: ");
		int choice = in.nextInt();
		
		while(choice < 1 || choice > productArray.length) {
			System.out.print("Please enter a VALID option: ");
			choice = in.nextInt();
		}
		productArray[choice-1].setStatus(false);
		System.out.println();
	}
}
