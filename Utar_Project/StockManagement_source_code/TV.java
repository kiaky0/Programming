package ooppAssignment;


public class TV extends Product	{
	private String screenType;
	private String resolution;
	private double displaySize;
	
	// constructor
    public TV(int itemNumber, String name, int quantity, double price, String screenType, String resolution, double displaySize) {
        super(itemNumber, name, quantity, price);
        this.screenType = screenType;
        this.resolution = resolution;
        this.displaySize = displaySize;
    }
    
    
    // getter and setter
	public String getScreenType() {
		return screenType;
	}

	public void setScreenType(String screenType) {
		this.screenType = screenType;
	}

	public String getResolution() {
		return resolution;
	}

	public void setResolution(String resolution) {
		this.resolution = resolution;
	}

	public double getDisplaySize() {
		return displaySize;
	}

	public void setDisplaySize(double displaySize) {
		this.displaySize = displaySize;
	}
    
    //calculate value stock of TV
    public double calculateStockValue() {
        return getQuantity() * getPrice();
    }
    
	// toString method
	public String toString() {
		return "Item number\t: " + getItemNum()+
				"\nProduct name\t: " + getName()+
				"\nScreen type\t:" + getScreenType()+
				"\nResolution\t: "+ getResolution() +
				"\nDisplay size: "+ getDisplaySize()+
				"\nQuantity available: "+ getQuantity()+
				"\nPrice (RM)\t: "+ getPrice()+
				"\nInventory value (RM): "+ getTotalInventoryValue()+
				"\nProduct status\t: "+ getStatus();
	}

}