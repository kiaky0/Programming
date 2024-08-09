package ooppAssignment;

public class Fan extends Product{
	private int speedNumber;
	private int bladesNumber;
	private double radius;
	
	// constructor
    public Fan(int itemNumber, String name, int quantity, double price, int speedNumber, int bladesNumber, double radius) {
        super(itemNumber, name, quantity, price);
        this.speedNumber = speedNumber;
        this.bladesNumber = bladesNumber;
        this.radius = radius;
    }
    
    public int getSpeedNumber() {
		return speedNumber;
	}

	public void setSpeedNumber(int speedNumber) {
		this.speedNumber = speedNumber;
	}

	public int getBladesNumber() {
		return bladesNumber;
	}

	public void setBladesNumber(int bladesNumber) {
		this.bladesNumber = bladesNumber;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	//calculate value stock of Fan
    public double calculateStockValue() {
        return getQuantity() * getPrice();
    }
    
	// toString method
	public String toString() {
		return "Item number\t: " + getItemNum()+
				"\nProduct name\t: " + getName()+
				"\nSpeed Number\t:" + getSpeedNumber()+
				"\nBlades Number\t: "+ getBladesNumber() +
				"\nRadius: "+ getRadius()+
				"\nQuantity available: "+ getQuantity()+
				"\nPrice (RM)\t: "+ getPrice()+
				"\nInventory value (RM): "+ getTotalInventoryValue()+
				"\nProduct status\t: "+ getStatus();
	}

}