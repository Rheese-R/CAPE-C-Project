//Programmers' Name: Rheese-Ashley Roman and Diontae Young 
//Date Created: December 11, 2023. Last Edited: April 26, 2024.
//Purpose: Creating a program to aid the owner of Sweet Jamaica in taking an accurate inventory in an easier and more efficient way.




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sweet_jamaica_inventory.h"


// Function prototypes
int Menu();
int Main_Menu();


int Menu() {
    int choice;
    int i;
    for (i=0; i<2; i++){            //asks the user twice
    printf("\n\nIf this is a new day of operation, please select 1. When the options reappear, select 2.");
    printf("\n\nOtherwise, please enter your choice: \n");
    printf("1... Create a new queue.\n");
    printf("2... Go to inventory. \n");
    printf("6... Exit. \n");
    scanf("%d", &choice);
    }
    return choice;
}


int Main_Menu() {
    int choice;
    printf("\n******MAIN MENU******\n");
    printf("Option 1: Manage Orders\n");
    printf("Option 2: Manage Inventory\n");
    printf("Option 3: View Inventory\n");
    printf("Option 4: Exit Program\n");
    printf("Please enter a number from the choices to select the task you would like to carry out. Enter 4 to exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}


int main() {
    
    int login = 0;
    int choice;
    
    q NewQ;
    FILE* cfPtr;
    srand(time(NULL)); // random number generator


    if ((cfPtr = fopen("Ingredients_Inventory.txt", "a+")) == NULL) {
        printf("\nError opening file.");
        return -1;
    }
    else{
    login = Login(login);
    if (login == 1){
    
    NewQ = Makeq(); // Initialize the queue


    do{
        choice = Menu();
        switch (choice) {
            case 1:
                NewQ = Makeq();
                break;
            case 2:
                choice = Main_Menu(); // Go to the main menu
                switch (choice) {
                            case 1:
                                ManageOrders(&NewQ); 
                                break;
                            case 2:
                                ManageInventory(&NewQ); 
                                break;
                            case 3:
                                View_Inventory(&NewQ); 
                                break;
                            case 4:
                                printf("Exiting program.\n");
                                break;
                            default:
                                printf("Invalid choice.\n");
                        }
                        break;
                    case 5:
                        printf("Exiting program.\n");
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
            } while (choice != 5);


            fclose(cfPtr);
            return 0;
        }
    }


    return 0;
}   //end main
	 
int Login(int login) {
	    char username[15];
	    char password[15];
	    int attempts = 0;
	 
	    printf("*****P R O G R A M   S W E E T   J A M A I C A   S T O C K*****\n");
	 
	    while (attempts < 2) {
	        printf("\nPlease enter the username here: \n");
	        scanf("%s", username);
	 
	        if (strcmp(username, "SweetJam2020") == 0) { //if the username is right 
	            printf("\nEnter password here: \n");
	            scanf("%s", password);
	 
	            if (strcmp(password, "HoMadeKng23") == 0) { 
	                login = 1;
	                printf("Login successful!\n");
	                return login;
	            } else {
	                printf("Incorrect username/password\n");
	                attempts++;
	                login = 0;
	            } //end if then else
	        } else {
	            printf("Incorrect username/password\n");
	            attempts++;
	            login = 0;
	        } //end if
	    } //end while
	 
	    printf("Maximum login attempts exceeded. Exiting program...\n");
	    exit(0);
	} //end of function definition


//Function Definitions:
           
void ManageOrders(q *orders){
    int choice;
    printf("\n******MANAGE ORDERS******\n");
    printf("Option 1: Enter New Order\n");
    printf("Option 2: Update Order Status\n");
    printf("Option 3: View Orders\n");
    printf("Option 4: Go Back\n");
    printf("Please enter a number from the choices to select the task you would like to carry out. Enter 4 to go back\n");
    printf("Enter choice: ");
    scanf("%d", &choice);


    switch (choice){
        case 1:
            EnterOrder(orders);
            break;
        case 2:
            UpdateOrderStatus(orders);
            break;
        case 3:
            ViewOrders(*orders);
            break;
        case 4:
            printf("Going back to main menu.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
}   //end of function definition


void EnterOrder(q *orders){
    struct Order newOrder;


    printf("\nEnter details for the new order:\n");
    printf("Enter order ID: ");
    scanf("%d", &newOrder.orderID);


    printf("Enter pastry name: ");
    printf("Please do not put a space to separate the words if they pastry contains more than one word.");
    scanf("%s", newOrder.pastry);


    // Assigning status to 0 to show that the order is in processing 
    newOrder.status = 0;


    // Enqueue the new order into the orders queue
    *orders = Enqueue(*orders, newOrder); // Pass the new order as an argument


    printf("Order entered successfully.\n");
} //end of function definitions


void ViewOrders(q orders) {
    Display(orders); // Call the display function with the orders queue
} // end of function definition


void UpdateOrderStatus(q *orders){
    int orderID, choice;
    printf("Enter the order ID to update status: ");
    scanf("%d", &orderID);


    int found = 0;
    int i;
    for (i = orders->front; i <= orders->rear; i++) {
        if (orders->Q[i].orderID == orderID) {
            printf("Order found:\n");
            printf("Order ID: %d\n", orders->Q[i].orderID);
            printf("Pastry: %s\n", orders->Q[i].pastry);
            printf("Status: %d\n", orders->Q[i].status);


            printf("Has the order been completed? (1 for yes, 0 for no): ");
            scanf("%d", &choice);


            if (choice == 1) {
                orders->Q[i].status = 1;
                printf("Order status updated to completed.\n");
            } else if (choice == 0) {
                // If the order is not completed, call the Dequeue function to cancel the order
                *orders = Dequeue(*orders);
                printf("Order cancelled.\n");
            } else {
                printf("Invalid choice.\n");
            }
            found = 1;
            break;
        }
    }


    if (!found) {
        printf("Order not found.\n");
    }
}   //end of function definition                    


void ManageInventory(q *inventory){
    int choice;
    
    printf("\n******MANAGE INVENTORY******\n");
    printf("Option 1: Add an Ingredient\n");
    printf("Option 2: Delete an Ingredient\n");
    printf("Option 3: Update an Ingredient\n");
    printf("Enter choice: ");
    scanf("%d", &choice);


    switch (choice){
        case 1:
            Add_Ingredient(inventory);
            break;
        case 2:
            Delete_Ingredient(inventory);
            break;
        case 3:
            Update_Ingredient(inventory);
            break;
        default:
            printf("Invalid choice.\n");
    }
} //end of function definition


int Add_Ingredient(q *inventory) {
    // Define variables
    int item_quantity;
    struct ingredient newIngredient; 


    // File pointer for writing to file
    FILE* cfPtr;
    
    // Open file in append mode
    cfPtr = fopen("Ingredients_Inventory.txt", "a");


    // Check if file opened successfully
    if (cfPtr == NULL) {
        printf("Error in opening file.");
    } else {
        // Prompt user for ingredient name
        printf("\n*****ADD AN INGREDIENT*****\n");
        printf("\nWrite the name of the ingredient:\n");
        printf("Example: Sugar\n");
        scanf("%s", newIngredient.name);


        // Prompt user for ingredient quantity
        printf("\nEnter in figures, the amount of this ingredient currently in stock.\n");
        printf("Example: 13\n");
        scanf("%d", &item_quantity);
        newIngredient.quantity = item_quantity;


        // Generate a random ID for the ingredient
        newIngredient.ID = rand(); 


        // Inform user about successful addition
        printf("\n\nIngredient successfully added!");


        // Write the ingredient to the file
        fwrite(&newIngredient, sizeof(struct ingredient), 1, cfPtr); 


        // Close the file
        fclose(cfPtr);
    } //end if
}   //end of function definition


int Delete_Ingredient(q *inventory) {
    int ID;
    struct ingredient ingredient; 
    FILE* cfPtr;


    // Open file in read-write mode
    cfPtr = fopen("Ingredients_Inventory.txt", "r+");


    // Check if file opened successfully
    if (cfPtr == NULL) {
        printf("Error in opening file.");
        return -1; // Return -1 to indicate failure
    }


    // Prompt user for the ID of the ingredient to delete
    printf("\n*****DELETE AN INGREDIENT*****\n");
    printf("\nEnter the ID of the ingredient you want to delete: ");
    scanf("%d", &ID);


    // Iterate through the file to find the ingredient with the given ID
    while (fread(&ingredient, sizeof(struct ingredient), 1, cfPtr)) { 
        if (ingredient.ID == ID) {
            // Reset the values of the ingredient
            ingredient.ID = 0;
            ingredient.quantity = 0;
            strcpy(ingredient.name, ""); 


            // Move the file pointer back to the beginning of the record
            fseek(cfPtr, -sizeof(struct ingredient), SEEK_CUR); 


            // Write the updated ingredient (with empty values) to the file
            fwrite(&ingredient, sizeof(struct ingredient), 1, cfPtr); 


            printf("Ingredient successfully deleted!\n");


            fclose(cfPtr);
            return 0; // Return 0 to indicate success
        }
    }


    // If ingredient with the given ID is not found
    printf("Ingredient with ID %d not found.\n", ID);
    fclose(cfPtr);
    return -1; // Return -1 to indicate failure
} // end of function definition


int Update_Ingredient(q *inventory) {
    int addition;
    int response;
    int subtraction;
    struct ingredient ingredient; 
    int ID;
    FILE* cfPtr;


    response = 0;


    // Open file in read-write mode
    cfPtr = fopen("Ingredients_Inventory.txt", "r+");


    // Check if file opened successfully
    if (cfPtr == NULL) {
        printf("Error in opening file.");
        return 0;
    }


    printf("\n*****UPDATE INGREDIENT*****\n");
    printf("\nChoose 1 to increase an ingredient, and 2 to decrease an ingredient. Choice: ");
    scanf("%d", &response);


    if (response == 1) {
        // Prompt user for the ID of the ingredient to increase
        printf("\nPlease enter the ID of the ingredient you wish to increase: ");
        scanf("%d", &ID);


        // Rewind file pointer to beginning
        rewind(cfPtr);


        // Loop through the file to find the ingredient with the given ID
        while (fread(&ingredient, sizeof(struct ingredient), 1, cfPtr)) { 
            if (ID == ingredient.ID) {
                printf("%d,%s ,%d\n", ingredient.ID, ingredient.name, ingredient.quantity);
                printf("\nBy how much has the quantity of this ingredient been increased? ");
                scanf("%d", &addition);
                ingredient.quantity += addition;
                printf("%d, %s, %d\n", ingredient.ID, ingredient.name, ingredient.quantity);
                fseek(cfPtr, -sizeof(struct ingredient), SEEK_CUR); 
                fwrite(&ingredient, sizeof(struct ingredient), 1, cfPtr); 
                break; // Exit the loop after finding the item
            }
        }
    } else if (response == 2) {
        // Prompt user for the ID of the ingredient to decrease
        printf("\nPlease enter the ID of the ingredient you wish to decrease: ");
        scanf("%d", &ID);


        // Rewind file pointer to beginning
        rewind(cfPtr);


        // Loop through the file to find the ingredient with the given ID
        while (fread(&ingredient, sizeof(struct ingredient), 1, cfPtr)) { 
            if (ID == ingredient.ID) {
                printf("%d,%s ,%d\n", ingredient.ID, ingredient.name, ingredient.quantity);
                printf("\nBy how much has the quantity of this ingredient been decreased? ");
                scanf("%d", &subtraction);
                ingredient.quantity -= subtraction;
                printf("%d, %s, %d\n", ingredient.ID, ingredient.name, ingredient.quantity);
                fseek(cfPtr, -sizeof(struct ingredient), SEEK_CUR); 
                fwrite(&ingredient, sizeof(struct ingredient), 1, cfPtr); 
                break; // Exit the loop after finding the item
            }
        }
    } else {
        printf("Invalid response. Please try again.\n");
        fclose(cfPtr);
        return 0;
    }


    fclose(cfPtr);
    return 1;
} // end of function definition


int View_Inventory(q *inventory) {
    int ID, option;
    FILE* cfPtr;
    struct ingredient ingredient; 


    option = 0;


    do {
        printf("\n*****VIEW INVENTORY*****\n");
        printf("\nChoose 1 to view the details of an ingredient, or 2 to view all ingredients: ");
        printf("If unsure of the ID of the single ingredient you's like to view, view all first.");
        scanf("%d", &option);


        if (option == 1) {
            printf("\nEnter the ID of the ingredient you want to view: ");
            scanf("%d", &ID);
            Search_Inventory(inventory, ID); 
        } else if (option == 2) {
            View_All_Ingredients(inventory); 
        } else {
            printf("Invalid input! Please try again\n");
        }


        printf("\nDo you want to view anything else? Enter 1 to view more. Enter any other number to exit: ");
        scanf("%d", &option);
    } while (option == 1);


    return 0;
} // end of function definition


int Search_Inventory(q *inventory, int ID) {
    FILE* cfPtr;
    struct ingredient ingredient; 


    cfPtr = fopen("Ingredients_Inventory.txt", "r");


    if (cfPtr == NULL)
        printf("Error in opening file.");
    else {
        rewind(cfPtr);
        while (!feof(cfPtr)) {
            fread(&ingredient, sizeof(struct ingredient), 1, cfPtr);


            if (ID == ingredient.ID) {
                printf("Ingredient Name: %s\n", ingredient.name);
                printf("\nQuantity: %d\n", ingredient.quantity);
                fclose(cfPtr);
                return 0;
            } //end if
        }     //end while
        printf("ID not found!\n");
        fclose(cfPtr);
    } //end else
    return -1; // Indicates ID not found
} //end of function definition


void View_All_Ingredients(q *inventory) {
    struct ingredient ingredient; 
    FILE* cfPtr;
    cfPtr = fopen("Ingredients_Inventory.txt", "r");


    if (cfPtr == NULL) {
        printf("Error in opening file.");
    } else {
        rewind(cfPtr);
        printf("ID\tNAME\tQUANTITY\n");


        // Read each item from the file and print its details
        while (fread(&ingredient, sizeof(struct ingredient), 1, cfPtr)) {
            printf("%d\t%s\t%d\n", ingredient.ID, ingredient.name, ingredient.quantity);
        }


        fclose(cfPtr);
    }
}   // end of function definition
