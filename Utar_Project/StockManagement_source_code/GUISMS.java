package ooppAssignment;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;

public class GUISMS extends Application{
	private static int maxProduct = 10;
	private static Product[] productList;
	
	public void start(Stage primaryStage) {
		Scanner scanner = new Scanner(System.in);
		primaryStage.setTitle("Stock Management System");
		
		// login user info
		GridPane loginGrid = new GridPane();
        loginGrid.setPadding(new Insets(10, 10, 10, 10));
        loginGrid.setVgap(8);
        loginGrid.setHgap(10);
        
        Label nameLabel = new Label("Full Name:");
        GridPane.setConstraints(nameLabel, 0, 0);
        
        TextField nameInput = new TextField();
        GridPane.setConstraints(nameInput, 1, 0);

        Button registerButton = new Button("Register");
        GridPane.setConstraints(registerButton, 1, 1);
        loginGrid.getChildren().addAll(nameLabel, nameInput, registerButton);
        loginGrid.setPadding(new Insets(10,10,10,250));
        // border pane to display output
        BorderPane pane = new BorderPane();
        Text welText = new Text("Welcome to Stock Management System");
        welText.setFont(Font.font("Pacifico", FontWeight.BOLD, FontPosture.REGULAR, 40));
        welText.setFill(Color.DARKMAGENTA);
        
        StackPane welPane = new StackPane();
        welPane.setBackground(new Background(new BackgroundFill(Color.ALICEBLUE,CornerRadii.EMPTY, Insets.EMPTY)));
        welPane.getChildren().add(welText);
        pane.setTop(welPane);
        pane.setCenter(loginGrid);
        StackPane sPane = new StackPane();
        pane.setBackground(new Background(new BackgroundFill(Color.web("bdeaee", 0.8),CornerRadii.EMPTY, Insets.EMPTY)));
        pane.setBottom(sPane);
        sPane.setPadding(new Insets(10,10,400,10));
        
        VBox grpMember = new VBox();
        Text members = new Text("MEMBERS");
        Text member1 = new Text("Lim Phai Yuan");
        Text member2 = new Text("Ooi Khai Shen");
        Text member3 = new Text("Tan Kia Yee");
        Text member4 = new Text("Tan Qi Yang");
        Text blank = new Text("");
        
        members.setFont(Font.font("Playfair", FontWeight.BOLD, FontPosture.REGULAR, 20));
        members.setStroke(Color.DARKSLATEGRAY);
        members.setUnderline(true);
        //LocalDate date =LocalDate.now();
		HBox footer = new HBox(100);
		LocalDateTime now = LocalDateTime.now();
		DateTimeFormatter date = DateTimeFormatter.ofPattern("E,MMM dd yyyy HH:mm:ss");
		Text tDate = new Text(date.format(now));
	    //tDate.setFont("); //formatting the datetime
		footer.getChildren().addAll(tDate);
		footer.setAlignment(Pos.CENTER);
		BorderPane.setMargin(footer, new Insets(0,0,30,0));
        grpMember.getChildren().addAll(members,member1,member2,member3,member4,blank,footer);
        grpMember.setAlignment(Pos.CENTER);
        pane.setBottom(grpMember);
        
        // action on registerButton
        registerButton.setOnMouseClicked(new EventHandler <MouseEvent>() {
        	@Override
			public void handle(MouseEvent arg0) {

        		// create vertical box to get userName, userId, current login time
        		VBox loginInfo = new VBox(15);       		
        		String fullName = nameInput.getText();
        		UserInfo user = new UserInfo(fullName);
        		Text text1 = new Text("Name: " + user.getName());
        		Text text2 = new Text("User ID: " + user.getUserID());
        		text1.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 38));
        		text2.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 38));
        		text1.setTextAlignment(TextAlignment.CENTER);
        		text2.setTextAlignment(TextAlignment.CENTER);
        		loginInfo.setAlignment(Pos.CENTER);
        		loginInfo.getChildren().addAll(text1,text2,blank,footer);
        		sPane.getChildren().add(loginInfo);
        		pane.setBottom(sPane);
        		
        		Button continueBt = new Button("Continue");
        		GridPane.setConstraints(continueBt, 1, 2);
        		loginGrid.getChildren().remove(registerButton);
        		loginGrid.getChildren().add(continueBt);
        		        		               		
                // ask for add product
                Text askAdd = new Text("Do you want to add product?");
                askAdd.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 25));
                Button yesBt = new Button("Yes");
                yesBt.setPrefWidth(300);
                Button noBt = new Button("No");
                noBt.setPrefWidth(300);
                VBox addProductPane = new VBox(10);
                addProductPane.setAlignment(Pos.CENTER);
                addProductPane.setPadding(new Insets(10, 10, 10, 10));
                addProductPane.getChildren().addAll(askAdd,yesBt,noBt);
                addProductPane.setBackground(new Background(new BackgroundFill(Color.web("bdeaee", 0.8),CornerRadii.EMPTY, Insets.EMPTY)));
        		
        		// continue button clicked
        		continueBt.setOnAction(e->{
        			Pane maxPane = new Pane();
            		//ask for maximum number of product need to add
            		Text askMaxText = new Text("How many product do you want to add?");
            		TextField maxtf = new TextField();
            		askMaxText.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 25));
            		maxtf.setPromptText("Enter the number");
            		Button setBt = new Button("Set");
            		
            		
            		maxtf.setAlignment(Pos.CENTER);
            		
            		VBox maxVBox = new VBox(10);
            		maxVBox.getChildren().addAll(askMaxText,maxtf,setBt);
            		maxVBox.setAlignment(Pos.CENTER);
            		maxVBox.setPadding(new Insets(15,180,15,180));
            		
            		setBt.setOnMouseClicked(new EventHandler <MouseEvent>() {
            			public void handle(MouseEvent arg0) {
            		        try {
            		            int maxProductInput = Integer.parseInt(maxtf.getText());
            		            if (maxProductInput <= 0) {
            		                showAlert("Input must be greater than zero");
            		                maxtf.clear(); // Clear the text field to prompt the user to enter again
            		            }
            		            maxProduct = maxProductInput;   
            		            System.out.println("Current max product :" + maxProductInput);
            		            showAlert("Successful set the maximum product to " + maxProductInput);
            		            primaryStage.setScene(new Scene(addProductPane, 800, 300));
            		            
            		        } catch (NumberFormatException ex) {
            		            showAlert("Invalid input");
            		            maxtf.clear(); // Clear the text field to prompt the user to enter again
            		        }
            			}
            		});
            		maxVBox.setBackground(new Background(new BackgroundFill(Color.web("bdeaee", 0.8),CornerRadii.EMPTY, Insets.EMPTY)));
            		primaryStage.setScene(new Scene(maxVBox, 800, 300));
        			
        		});
        		
        		// yes Button click
        		yesBt.setOnAction(e->{
        			Stage showAddProductStage = new Stage();
        			showAddProductStage.setTitle("Add Product");
        	        VBox vbox = new VBox(10);
        	        vbox.setPadding(new Insets(10, 10, 10, 10));
        	        Label label = new Label("Select Product Type:");
        	        label.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 25));
        	        ToggleGroup toggleGroup = new ToggleGroup();
        	        
        	        RadioButton refrigeratorRadioButton = new RadioButton("Refrigerator");
        	        refrigeratorRadioButton.setToggleGroup(toggleGroup);  
        	        refrigeratorRadioButton.setSelected(true);
        	        RadioButton tvRadioButton = new RadioButton("TV");
        	        tvRadioButton.setToggleGroup(toggleGroup);
        	        RadioButton fanRadioButton = new RadioButton("Fan");
        	        fanRadioButton.setToggleGroup(toggleGroup);
        	        
        	        Button addButton = new Button("Add Product");
        	        vbox.getChildren().addAll(label, refrigeratorRadioButton, tvRadioButton, fanRadioButton, addButton);
        	        
        	        Scene productscene = new Scene(vbox, 300, 200);
        	        // handle add button event
        	        addButton.setOnMouseClicked(new EventHandler <MouseEvent>()
					{
						@Override
						public void handle(MouseEvent arg0) 
						{
	        	            if (refrigeratorRadioButton.isSelected()) {
	        	                // add product dialog
	        	            	Stage addingStage = new Stage();
	        	        		GridPane gridPane = new GridPane();
	        	                gridPane.setPadding(new Insets(10, 10, 10, 10));
	        	                gridPane.setVgap(8);
	        	                gridPane.setHgap(10);
	        	                

	        	                Label nameLabel = new Label("Name:");
	        	                GridPane.setConstraints(nameLabel, 0, 0);
	        	                TextField nametf = new TextField();
	        	                GridPane.setConstraints(nametf, 1, 0);

	        	                Label doorDesignLabel = new Label("Door Design:");
	        	                GridPane.setConstraints(doorDesignLabel, 0, 1);
	        	                TextField doorDesigntf = new TextField();
	        	                GridPane.setConstraints(doorDesigntf, 1, 1);

	        	                Label colorLabel = new Label("Color:");
	        	                GridPane.setConstraints(colorLabel, 0, 2);
	        	                TextField colortf = new TextField();
	        	                GridPane.setConstraints(colortf, 1, 2);

	        	                Label capacityLabel = new Label("Capacity:");
	        	                GridPane.setConstraints(capacityLabel, 0, 3);
	        	                TextField capacitytf = new TextField();
	        	                GridPane.setConstraints(capacitytf, 1, 3);
	        	                
	        	                Label quantityLabel = new Label("Quantity:");
	        	                GridPane.setConstraints(quantityLabel, 0, 4);
	        	                TextField quantitytf = new TextField();
	        	                GridPane.setConstraints(quantitytf, 1, 4);
	        	                
	        	                Label priceLabel = new Label("Price:");
	        	                GridPane.setConstraints(priceLabel, 0, 5);
	        	                TextField pricetf = new TextField();
	        	                GridPane.setConstraints(pricetf, 1, 5);

	        	                Label itemNumberLabel = new Label("Item Number:");
	        	                GridPane.setConstraints(itemNumberLabel, 0, 6);
	        	                TextField itemNumbertf = new TextField();
	        	                GridPane.setConstraints(itemNumbertf, 1, 6);
	        	                
	        	                Button addButton = new Button("Add");
	        	                GridPane.setConstraints(addButton, 1, 7);

	        	                gridPane.getChildren().addAll(nameLabel, nametf, doorDesignLabel, doorDesigntf,
	        	                        colorLabel, colortf, capacityLabel, capacitytf, quantityLabel, 
	        	                        quantitytf, priceLabel, pricetf,  itemNumberLabel, itemNumbertf, addButton);
	        	                
	        	                // get value
	        	                addButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
	        	                    public void handle(MouseEvent arg0) {
	        	                    	// try exception to capture wrong value
	        	                        try {
	        	                            String name = nametf.getText();
	        	                            String doorDesign = doorDesigntf.getText();
	        	                            String color = colortf.getText();
	        	                            
	        	                            // Parsing input and handling wrong data types with try-catch blocks
	        	                            int capacity = Integer.parseInt(capacitytf.getText());
	        	                            int quantity = Integer.parseInt(quantitytf.getText());
	        	                            double price = Double.parseDouble(pricetf.getText());
	        	                            int itemNumber = Integer.parseInt(itemNumbertf.getText());
	        	                            
	        	                            // add refrigerator
	        	                            Refrigerator refrigerator = new Refrigerator(itemNumber, name, quantity, price, doorDesign, color, capacity);
	        	                            addProduct(refrigerator);
	        	                            addingStage.close();
	        	                            
	        	                        } catch (NumberFormatException e) {
	        	                            // Prompt user to input again if wrong data type is entered
	        	                            Alert alert = new Alert(AlertType.ERROR);
	        	                            alert.setTitle("Input Error");
	        	                            alert.setHeaderText("Wrong Input Data Type");
	        	                            alert.setContentText("Please enter valid data types for Capacity, Quantity, Price, and Item Number.");
	        	                            alert.showAndWait();
	        	                        }
	        	                    }
	        	                });
	        	                
	        	                gridPane.setBackground(new Background(new BackgroundFill(Color.AQUAMARINE, CornerRadii.EMPTY, Insets.EMPTY)));
	        	                Scene scene = new Scene(gridPane, 500, 350);
	        	                addingStage.setTitle("Add Refrigerator");
	        	                addingStage.setScene(scene);
	        	                addingStage.show();
	        	                
	        	            } else if (tvRadioButton.isSelected()) {
	        	                // addTV dialog
	        	            	Stage addingStage = new Stage();
	        	        		GridPane gridPane = new GridPane();
	        	                gridPane.setPadding(new Insets(10, 10, 10, 10));
	        	                gridPane.setVgap(8);
	        	                gridPane.setHgap(10);

	        	                Label nameLabel = new Label("Name:");
	        	                GridPane.setConstraints(nameLabel, 0, 0);
	        	                TextField nametf = new TextField();
	        	                GridPane.setConstraints(nametf, 1, 0);

	        	                Label screenTypeLabel = new Label("Screen type:");
	        	                GridPane.setConstraints(screenTypeLabel, 0, 1);
	        	                TextField screenTypetf = new TextField();
	        	                GridPane.setConstraints(screenTypetf, 1, 1);

	        	                Label resolutionLabel = new Label("Resolution:");
	        	                GridPane.setConstraints(resolutionLabel, 0, 2);
	        	                TextField resolutiontf = new TextField();
	        	                GridPane.setConstraints(resolutiontf, 1, 2);

	        	                Label displaySizeLabel = new Label("Display size:");
	        	                GridPane.setConstraints(displaySizeLabel, 0, 3);
	        	                TextField displaySizetf = new TextField();
	        	                GridPane.setConstraints(displaySizetf, 1, 3);
	        	                
	        	                Label quantityLabel = new Label("Quantity:");
	        	                GridPane.setConstraints(quantityLabel, 0, 4);
	        	                TextField quantitytf = new TextField();
	        	                GridPane.setConstraints(quantitytf, 1, 4);
	        	                
	        	                Label priceLabel = new Label("Price:");
	        	                GridPane.setConstraints(priceLabel, 0, 5);
	        	                TextField pricetf = new TextField();
	        	                GridPane.setConstraints(pricetf, 1, 5);

	        	                Label itemNumberLabel = new Label("Item Number:");
	        	                GridPane.setConstraints(itemNumberLabel, 0, 6);
	        	                TextField itemNumbertf = new TextField();
	        	                GridPane.setConstraints(itemNumbertf, 1, 6);
	        	                
	        	                Button addButton = new Button("Add");
	        	                GridPane.setConstraints(addButton, 1, 7);

	        	                gridPane.getChildren().addAll(nameLabel, nametf, screenTypeLabel, screenTypetf,
	        	                		resolutionLabel, resolutiontf, displaySizeLabel, displaySizetf, quantityLabel, 
	        	                        quantitytf, priceLabel, pricetf,  itemNumberLabel, itemNumbertf, addButton);
	        	                
	        	                // get value
	        	                addButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
	        	                    public void handle(MouseEvent arg0) {
	        	                        try {
	        	                            String name = nametf.getText();
	        	                            String screenType = screenTypetf.getText();
	        	                            String resolution = resolutiontf.getText();
	        	                            
	        	                            // Parsing input and handling wrong data types with try-catch blocks
	        	                            int displaySize = Integer.parseInt(displaySizetf.getText());
	        	                            int quantity = Integer.parseInt(quantitytf.getText());
	        	                            double price = Double.parseDouble(pricetf.getText());
	        	                            int itemNumber = Integer.parseInt(itemNumbertf.getText());
	        	                            
	        	                            // add TV
	        	                            TV tv = new TV(itemNumber, name, quantity, price, screenType, resolution, displaySize);
	        	                            addProduct(tv);
	        	                            addingStage.close();
	        	                            
	        	                        } catch (NumberFormatException e) {
	        	                            // Prompt user to input again if wrong data type is entered
	        	                            Alert alert = new Alert(AlertType.ERROR);
	        	                            alert.setTitle("Input Error");
	        	                            alert.setHeaderText("Wrong Input Data Type");
	        	                            alert.setContentText("Please enter valid data types for Display Size, Quantity, Price, and Item Number.");
	        	                            alert.showAndWait();
	        	                        }
	        	                    }
	        	                });
	        	                
	        	                gridPane.setBackground(new Background(new BackgroundFill(Color.AQUAMARINE, CornerRadii.EMPTY, Insets.EMPTY)));
	        	                Scene scene = new Scene(gridPane, 500, 350);
	        	                addingStage.setTitle("Add TV");
	        	                addingStage.setScene(scene);
	        	                addingStage.show();
	        	                
	        	            }else if(fanRadioButton.isSelected()) {
	        	                // addTV dialog
	        	            	Stage addingStage = new Stage();
	        	        		GridPane gridPane = new GridPane();
	        	                gridPane.setPadding(new Insets(10, 10, 10, 10));
	        	                gridPane.setVgap(8);
	        	                gridPane.setHgap(10);

	        	                Label nameLabel = new Label("Name:");
	        	                GridPane.setConstraints(nameLabel, 0, 0);
	        	                TextField nametf = new TextField();
	        	                GridPane.setConstraints(nametf, 1, 0);

	        	                Label speedNumLabel = new Label("Speed Number:");
	        	                GridPane.setConstraints(speedNumLabel, 0, 1);
	        	                TextField speedNumtf = new TextField();
	        	                GridPane.setConstraints(speedNumtf, 1, 1);

	        	                Label bladesNumLabel = new Label("Blades Number:");
	        	                GridPane.setConstraints(bladesNumLabel, 0, 2);
	        	                TextField bladesNumtf = new TextField();
	        	                GridPane.setConstraints(bladesNumtf, 1, 2);

	        	                Label radiusLabel = new Label("Radius:");
	        	                GridPane.setConstraints(radiusLabel, 0, 3);
	        	                TextField radiustf = new TextField();
	        	                GridPane.setConstraints(radiustf, 1, 3);
	        	                
	        	                Label quantityLabel = new Label("Quantity:");
	        	                GridPane.setConstraints(quantityLabel, 0, 4);
	        	                TextField quantitytf = new TextField();
	        	                GridPane.setConstraints(quantitytf, 1, 4);
	        	                
	        	                Label priceLabel = new Label("Price:");
	        	                GridPane.setConstraints(priceLabel, 0, 5);
	        	                TextField pricetf = new TextField();
	        	                GridPane.setConstraints(pricetf, 1, 5);

	        	                Label itemNumberLabel = new Label("Item Number:");
	        	                GridPane.setConstraints(itemNumberLabel, 0, 6);
	        	                TextField itemNumbertf = new TextField();
	        	                GridPane.setConstraints(itemNumbertf, 1, 6);
	        	                
	        	                Button addButton = new Button("Add");
	        	                GridPane.setConstraints(addButton, 1, 7);

	        	                gridPane.getChildren().addAll(nameLabel, nametf, speedNumLabel, speedNumtf,
	        	                		bladesNumLabel, bladesNumtf, radiusLabel, radiustf, quantityLabel, 
	        	                        quantitytf, priceLabel, pricetf,  itemNumberLabel, itemNumbertf, addButton);
	        	                
	        	                // get value
	        	                addButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
	        	                    public void handle(MouseEvent arg0) {
	        	                        try {
	        	                            String name = nametf.getText();
	        	                            int speedNum = Integer.parseInt(speedNumtf.getText());
	        	                            int bladesNum = Integer.parseInt(bladesNumtf.getText());
	        	                            double radius = Double.parseDouble(radiustf.getText());
	        	                            int quantity = Integer.parseInt(quantitytf.getText());
	        	                            double price = Double.parseDouble(pricetf.getText());
	        	                            int itemNumber = Integer.parseInt(itemNumbertf.getText());
	        	                            
	        	                            // add Fan
	        	                            Fan fan = new Fan(itemNumber, name, quantity, price, speedNum, bladesNum, radius);
	        	                            addProduct(fan);
	        	                            addingStage.close();
	        	                            
	        	                        } catch (NumberFormatException e) {
	        	                            // Prompt user to input again if wrong data type is entered
	        	                            Alert alert = new Alert(AlertType.ERROR);
	        	                            alert.setTitle("Input Error");
	        	                            alert.setHeaderText("Wrong Input Data Type");
	        	                            alert.setContentText("Please enter valid data types for Speed Number, Blades Number, Radius, Quantity, Price, and Item Number.");
	        	                            alert.showAndWait();
	        	                        }
	        	                    }
	        	                });
	        	                
	        	                gridPane.setBackground(new Background(new BackgroundFill(Color.AQUAMARINE, CornerRadii.EMPTY, Insets.EMPTY)));
	        	                Scene scene = new Scene(gridPane, 500, 350);
	        	                addingStage.setTitle("Add Fan");
	        	                addingStage.setScene(scene);
	        	                addingStage.show();
	        	            }

						}
					});
					
     	        
        	        
        	        
        	        showAddProductStage.setScene(productscene);
        	        vbox.setBackground(new Background(new BackgroundFill(Color.AQUAMARINE, CornerRadii.EMPTY, Insets.EMPTY)));
        	        showAddProductStage.show();
        	        
        		});
        		
        		// no button click
        		noBt.setOnAction(e->{
        			
        			primaryStage.setTitle("Stock Management Menu");
        			
        	        // Grid for main menu
        	        VBox mainMenuBox = new VBox(10);
        	        mainMenuBox.setPadding(new Insets(2, 10, 10, 10));
        	        
        	        Text menuText = new Text("Menu");
        	        menuText.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 25));
        	        
        	        Button viewProductsButton = new Button("View Products");
        	        viewProductsButton.setPrefWidth(165);
        	        Button addStockButton = new Button("Add Stock");
        	        addStockButton.setPrefWidth(165);
        	        Button deductStockButton = new Button("Deduct Stock");
        	        deductStockButton.setPrefWidth(165);
        	        Button discontinueButton = new Button("Discontinue Product");
        	        discontinueButton.setPrefWidth(165);
        	        Button exitButton = new Button("Exit");
        	        exitButton.setPrefWidth(165);
        	        
        	        mainMenuBox.setAlignment(Pos.CENTER);
        	        mainMenuBox.getChildren().addAll(menuText, viewProductsButton, addStockButton,
        	                deductStockButton, discontinueButton, exitButton);
        	        
        	        // view product
	                viewProductsButton.setOnMouseClicked(new EventHandler <MouseEvent>() {
	                	public void handle(MouseEvent arg0) {
	        				//Setting display Stage
	        				GridPane dpProduct=new GridPane();
	        				dpProduct.setPadding(new Insets(15));
	        				dpProduct.setHgap(15);
	        				dpProduct.setVgap(5);
	        				dpProduct.setAlignment(Pos.CENTER);
	        				Stage dpProductstage=new Stage();
	        				
	        				dpProduct.add(new Text("[itemNumber]"),0,0);
	        				dpProduct.add(new Text("[name]"),1,0);
	        				dpProduct.add(new Text("[quantity]"),2,0);
	        				dpProduct.add(new Text("[price]"),3,0);
	        				
	        				for (int i=0; i<productList.length; i++) {
								dpProduct.add(new Text(Integer.toString(productList[i].getItemNum())),0,(i+1));
								dpProduct.add(new Text(productList[i].getName()),1,(i+1));
								dpProduct.add(new Text(Integer.toString(productList[i].getQuantity())),2,(i+1));
								dpProduct.add(new Text(String.format("%.2f", productList[i].getPrice())),3,(i+1));
	        				}
	        				
	        				Text head= new Text("Product Display Section");
	    					head.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 50));
	    					head.setFill(Color.GREEN);
	    					
	    					BorderPane bPane = new BorderPane(dpProduct);
	    					HBox Title  = new HBox();
	    					Title.getChildren().addAll(head);
	    					bPane.setTop(Title);
	    					bPane.setBackground(new Background(new BackgroundFill(Color.web("bdeaee", 0.8),CornerRadii.EMPTY, Insets.EMPTY)));
	    					
	    					Title.setAlignment(Pos.CENTER);
	    					Title.setMargin(head, new Insets (25,0,25,0));
	    					Title.setBackground(new Background(new BackgroundFill(Color.web("76b4bd", 1),CornerRadii.EMPTY, Insets.EMPTY)));
	    					
	    					dpProductstage.setTitle("Display Product");
	    					Scene productScene = new Scene(bPane,700,500);
	    					dpProductstage.setScene(productScene);
	    					dpProductstage.show();
	                	}
	                });
        	        
	                // add stock button
	                addStockButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
	                    public void handle(MouseEvent arg0) {
	                        Stage addStockStage = new Stage();

	                        VBox vbox = new VBox(10);
	                        vbox.setPadding(new Insets(10, 10, 10, 10));
	                        GridPane gridPane = new GridPane();
	                        gridPane.setVgap(8);
	                        gridPane.setHgap(10);

	                        Label[] productLabels = new Label[productList.length];
	                        TextField[] quantityFields = new TextField[productList.length];
	                        Button[] addButton = new Button[productList.length];

	                        for (int i = 0; i < productList.length; i++) {
	                            int index = i;
	                            productLabels[i] = new Label("Product #" + (i + 1) + " " + productList[i].getName());
	                            gridPane.setConstraints(productLabels[i], 0, i);

	                            quantityFields[i] = new TextField();
	                            quantityFields[i].setPromptText("Enter quantity");
	                            gridPane.setConstraints(quantityFields[i], 1, i);

	                            addButton[i] = new Button("Add"); // Initialize the button here
	                            gridPane.setConstraints(addButton[i], 2, i); // Set button constraints before adding action

	                            addButton[i].setOnAction(e -> {
	                                try {
	                                    int amount = Integer.parseInt(quantityFields[index].getText());
	                                    productList[index].addStock(amount);
	                                    if(!productList[index].getStatus())
	                                    	showAlert("The product is not available");
	                                    else
	                                    	showAlert("Stock added successfully.");
	                                } catch (NumberFormatException ex) {
	                                    showAlert("Please enter a valid number for quantity.");
	                                }
	                            });

	                            gridPane.getChildren().addAll(productLabels[i], quantityFields[i], addButton[i]); // Add all elements to the gridPane
	                        }

	                        vbox.getChildren().add(gridPane);
	                        vbox.setBackground(new Background(new BackgroundFill(Color.web("bdeaee", 0.8),CornerRadii.EMPTY, Insets.EMPTY)));

	                        addStockStage.setTitle("Add Stock");
	                        Scene addStockScene = new Scene(vbox, 450, 650);
	                        addStockStage.setScene(addStockScene);
	                        addStockStage.show();
	                    }
	                });
	                
	                // deduct stock button
	                deductStockButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
	                    public void handle(MouseEvent arg0) {
	                        Stage deductStockStage = new Stage();

	                        VBox vbox = new VBox(10);
	                        vbox.setPadding(new Insets(10, 10, 10, 10));
	                        GridPane gridPane = new GridPane();
	                        gridPane.setVgap(8);
	                        gridPane.setHgap(10);

	                        Label[] productLabels = new Label[productList.length];
	                        TextField[] quantityFields = new TextField[productList.length];
	                        Button[] deductButton = new Button[productList.length];

	                        for (int i = 0; i < productList.length; i++) {
	                            int index = i;
	                            productLabels[i] = new Label("Product #" + (i + 1) + " " + productList[i].getName());
	                            gridPane.setConstraints(productLabels[i], 0, i);

	                            quantityFields[i] = new TextField();
	                            quantityFields[i].setPromptText("Enter quantity");
	                            gridPane.setConstraints(quantityFields[i], 1, i);

	                            deductButton[i] = new Button("Deduct"); // Initialize the button here
	                            gridPane.setConstraints(deductButton[i], 2, i); // Set button constraints before adding action

	                            deductButton[i].setOnAction(e -> {
	                                try {
	                                    int amount = Integer.parseInt(quantityFields[index].getText());
	                                    productList[index].deductStock(amount);
	                                    if(!productList[index].getStatus())
	                                    	showAlert("The product is not available");
	                                    else
		                                    if(productList[index].getQuantity()>=amount)
		                                    	showAlert("Stock deduct successfully.");
		                                    else
		                                    	showAlert("Invalid amount");

	                                } catch (NumberFormatException ex) {
	                                    showAlert("Please enter a valid number for quantity.");
	                                }
	                            });

	                            gridPane.getChildren().addAll(productLabels[i], quantityFields[i], deductButton[i]); // Add all elements to the gridPane
	                        }

	                        vbox.getChildren().add(gridPane);
	                        vbox.setBackground(new Background(new BackgroundFill(Color.web("bdeaee", 0.8),CornerRadii.EMPTY, Insets.EMPTY)));

	                        deductStockStage.setTitle("Deduct Stock");
	                        Scene addStockScene = new Scene(vbox, 450, 650);
	                        deductStockStage.setScene(addStockScene);
	                        deductStockStage.show();
	                    }
	                });
	                
	                // discontinue the product
	                discontinueButton.setOnMouseClicked(new EventHandler <MouseEvent>() {
	                	public void handle(MouseEvent arg0) {
	                		Stage discontinueStockStage = new Stage();

	                        VBox vbox = new VBox(10);
	                        vbox.setPadding(new Insets(10, 10, 10, 10));
	                        GridPane gridPane = new GridPane();
	                        gridPane.setVgap(8);
	                        gridPane.setHgap(10);
	                        
	                        // show all the product
	                        Label[] productLabels = new Label[productList.length];
	                        Text[] statusText = new Text[productList.length];
	                        Button[] change = new Button[productList.length];
	                        
	                		for (int i = 0; i < productList.length; i++) {
	                            int index = i;
	                            productLabels[i] = new Label("Product #" + (i + 1) + " " + productList[i].getName());
	                            gridPane.setConstraints(productLabels[i], 0, i);
	                            
	                            if(productList[i].getStatus()) {
	                            	statusText[i] = new Text("True");
	                            }
	                            else {
	                            	statusText[i] = new Text("False");
	                            }
	                            gridPane.setConstraints(statusText[i], 1, i);
	                            change[i] = new Button("Change");
	                            gridPane.setConstraints(change[i], 2, i);
	                            change[i].setOnAction(e->{
	                            	
	                            	if(productList[index].getStatus()) {
	                            		productList[index].setStatus(false);
		                            	statusText[index].setText("False");		                            	
		                            }
		                            else {
	                            		productList[index].setStatus(true);

		                            	statusText[index].setText("True");
		                            	
		                            }
		                            gridPane.setConstraints(statusText[index], 1, index);
	                            });
	                            gridPane.getChildren().addAll(productLabels[i],statusText[i],change[i]); // Add all elements to the gridPane
	                		}
	                		vbox.getChildren().add(gridPane);
	                        vbox.setBackground(new Background(new BackgroundFill(Color.web("bdeaee", 0.8),CornerRadii.EMPTY, Insets.EMPTY)));

	                        discontinueStockStage.setTitle("Discontinue Stock");
	                        Scene discontinueStockScene = new Scene(vbox, 450, 650);
	                        discontinueStockStage.setScene(discontinueStockScene);
	                        discontinueStockStage.show();
	                	}
	                });
	                
	                // exit the system
	                exitButton.setOnMouseClicked(new EventHandler <MouseEvent>() {
	                	public void handle(MouseEvent arg0) {
	                		Stage tqStage = new Stage();
	                		StackPane tqPane = new StackPane();
	                		Text tqText = new Text("Thank you for using the system\n"+
	                				"UserID: " + user.getUserID() + ", Username: " + user.getName());
	                		tqText.setFont(Font.font("Dosis", FontWeight.BOLD, FontPosture.REGULAR, 30));
	                		tqText.setFill(Color.PURPLE);
	                        tqPane.getChildren().add(tqText);
	                        tqPane.setBackground(new Background(new BackgroundFill(Color.LINEN,CornerRadii.EMPTY, Insets.EMPTY)));
	                        Scene tqScene = new Scene(tqPane, 700, 300);
	                        tqStage.setScene(tqScene);
	                        tqStage.setTitle("Stock Management System");
	                        tqStage.show();
	                			                     
	                        primaryStage.close();
	                	}
	                });
	                
        	        mainMenuBox.setBackground(new Background(new BackgroundFill(Color.web("bdeaee", 0.8),CornerRadii.EMPTY, Insets.EMPTY)));
        	        Scene scene = new Scene(mainMenuBox, 800, 300);	      
        	        primaryStage.setScene(scene);
        	        primaryStage.show();
        			
        		});
        	
        	}
        });
        
        Scene scene = new Scene(pane, 800, 380);
        primaryStage.setScene(scene);
        primaryStage.show();
	}
	
	
	private static void showAlert(String message) {
	    Alert alert = new Alert(Alert.AlertType.INFORMATION);
	    alert.setTitle("Information");
	    alert.setHeaderText(null);
	    alert.setContentText(message);
	    alert.showAndWait();
	}

	// add product to array
	private static void addProduct(Product productType) {
		if(productList == null) {
			productList = new Product[1];
			productList[0] = productType;
		}
		else {
			if(productList.length >= maxProduct) {
				showAlert("Product List is full");
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
	}
	
    public static void main(String[] args) {
    	// default product
    	Refrigerator refrigerator1 = new Refrigerator(001, "Pensonic", 12, 1500.00, "one door", "Red",300);
    	addProduct(refrigerator1);
		TV tv1= new TV(002, "SamsungTV", 8, 2500, "OLED", "4K" ,42);
		addProduct(tv1);
		Fan fan1= new Fan(003,"KDKFan" , 28, 200, 5, 3,35);
		addProduct(fan1);
    	launch(args);

    }
}
