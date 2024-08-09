package ooppAssignment;


public class Refrigerator extends Product {
    private String doorDesign;
    private String color;
    private int capacity;
    
    // constructor
    public Refrigerator(int itemNum, String name, int quantity, double price, String doorDesign, String color, int capacity) {
    	super(itemNum,name,quantity,price);
    	this.doorDesign=doorDesign;
    	this.color=color;
    	this.capacity=capacity;
    }
    
    // getter n setter
	public String getDoorDesign() {
		return doorDesign;
	}

	public void setDoorDesign(String doorDesign) {
		this.doorDesign = doorDesign;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public int getCapacity() {
		return capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}
	
	// calculate stock value
	public double getStockValue() {
		return getQuantity() * getPrice();
	}
    
	// toString method
	public String toString() {
		return "Item number\t: " + getItemNum()+
				"\nProduct name\t: " + getName()+
				"\nDoor design\t:" + getDoorDesign()+
				"\nColor\t: "+ getColor() +
				"\nCapacity (in Litres): "+ getCapacity()+
				"\nQuantity available: "+ getQuantity()+
				"\nPrice (RM)\t: "+ getPrice()+
				"\nInventory value (RM): "+ getTotalInventoryValue()+
				"\nProduct status\t: "+ getStatus();
	}
	
}
