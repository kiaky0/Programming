package ooppAssignment;

public abstract class Product {
	private String name;
	private double price;
	private int quantity;
	private boolean status;
	private int itemNum;
	
	// default constructor
	public Product() {
		
	}
    public Product(int itemNum, String name, int quantity, double price) {
        this.itemNum = itemNum;
        this.name = name;
        this.quantity = quantity;
        this.price = price;
        this.status = true; // Default value is true
    }
    
    // getter setter
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public int getQuantity() {
		return quantity;
	}
	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	public boolean getStatus() {
		return status;
	}
	public void setStatus(boolean status) {
		this.status = status;
	}
	public int getItemNum() {
		return itemNum;
	}
	public void setItemNum(int itemNum) {
		this.itemNum = itemNum;
	}
    
	// inventory value
    public double getTotalInventoryValue() {
        return price * quantity;
    }
    
    // add quantity to stock
    public void addStock(int quantityAdded) {
    	if(status) {
    		quantity += quantityAdded;
    		System.out.println(quantityAdded + " units of " + name + " added to stock.");
    	}
    	else {
    		System.out.println("Unable to add to stock");
    	}
    }
    
    // deduct quantity from stock
    public void deductStock(int quantityDeduct) {
    	if(status) {
    		if(quantity>=quantityDeduct) {
    			quantity -= quantityDeduct;
    			System.out.println(quantityDeduct + " unit of "+ name + " deducted from stock.");
    		}else {
    			System.out.println("Insufficient stock");
    		}
    	}
    	else {
    		System.out.println("Unable to deduct from stock");
    	}
    }
    
    public String toString() {
    	return "Item number\t: " + itemNum + "\nProduct name\t: "+ name + "\nQuantity available: "+ quantity+
    			"\nPrice (RM)\t: "+ price+ "\tIventory value (RM): "+ getTotalInventoryValue() + "Product status\t: "+ status;
    }

}