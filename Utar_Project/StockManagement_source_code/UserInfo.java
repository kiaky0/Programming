package ooppAssignment;

import java.util.Scanner;


public class UserInfo {
    private String name;
    private String userID;

    public UserInfo() {
        // Default constructor
    }

    public UserInfo(String name) {
        this.name = name;
        generateUserID();
    }

    // Getter for name
    public String getName() {
        return name;
    }

    // Method to check if name contains space(s)
    private boolean containsSpaces(String name) {
        return name.contains(" ");
    }

    // Method to generate user ID
    private void generateUserID() {
        if (containsSpaces(name)) {
            String[] names = name.split(" ");
            userID = names[0].substring(0, 1) + names[names.length - 1];
        } else {
            userID = "guest";
        }
    }

    // Getter for user ID
    public String getUserID() {
        return userID;
    }

    // Setter for name
    public void setName(String name) {
        this.name = name;
        generateUserID();
    }
    
    public void registerNewUser() {
    	Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your full name: ");
        String fullName = scanner.nextLine();

        UserInfo userInfo = new UserInfo(fullName);
        System.out.println("Name: " + userInfo.getName());
        System.out.println("User ID: " + userInfo.getUserID());
    }

}
