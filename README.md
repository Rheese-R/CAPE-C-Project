# CAPE-C-Project
Bakery Inventory Program [C]

Sweet_Jamaica_Stock
Sweet_Jamaica_Stock is an inventory management system designed for a local Jamaican bakery to streamline the tracking and management of ingredients and customer orders. It is a menu-driven, password-protected program that prioritizes security, usability, and maintainability.

📋 Functional Requirements
🖥️ Welcome Screen
Displays the message: "WELCOME TO SWEET JAMAICA’S INVENTORY" upon execution.

🔐 Login
Requires a valid username and password to access the system.

Username: SweetJam2020

Password: HoMadeKng23

Users have two attempts to log in.

Successful login leads to the main menu. Failed attempts return the user to the welcome screen.

🧭 Main Menu Options
After login, the user is presented with the following options:

Manage Orders

Manage Inventory

View Inventory

📦 Manage Orders
1. Enter Order
Prompts for:

Order number

Name of the pastry

Automatically sets status to 0 (Processing)

2. Update Order Status
Prompts for order number

Displays order details

Asks the user to confirm fulfillment

If fulfilled, updates status to 1 (Completed)

3. View All Orders
Displays all orders, showing:

Order number

Pastry name

Order status

🧂 Manage Inventory
1. Add Ingredient
Prompts for:

Ingredient name

Quantity

Generates a unique ID

Displays confirmation message

2. Delete Ingredient
Prompts for ingredient ID

Displays ID, name, quantity

Confirms deletion and returns to main menu

3. Update Ingredient
Prompts user to:

Increase or decrease quantity

Requires ID number

Displays current quantity and applies change

Invalid IDs return the user to the main menu with an error message

🔍 View Inventory
1. View a Single Ingredient
Prompts for ingredient ID

Displays name, ID, and quantity if found

Displays error if not found

2. View All Ingredients
Displays a list of all ingredients in inventory

🧾 Summary Report
The program provides a summary view of current inventory and order statuses to assist with daily operations.

🛡 Non-Functional Requirements
🔒 Security
Password-protected login ensures only authorized users can access and update the system.

👨‍💻 Usability
User-friendly and menu-driven interface

Clear prompts and consistent screen layout for easy navigation

⚠️ Error Handling
Handles invalid inputs and incorrect IDs gracefully

Provides informative messages and redirects users accordingly

🔧 Maintainability
A dedicated software maintenance team will ensure the system evolves with customer needs and continues to function efficiently.

🏗 Ingredient Data Structure
Each ingredient entry includes:

ID Number (unique, auto-generated)

Ingredient Name

Quantity

📈 Future Enhancements (Optional Suggestions)
Integration with point-of-sale systems

Ingredient usage tracking per order

Real-time low-stock alerts

Backup and restore functionalities

📞 Contact
For questions or support, please contact the development team at:
📧 support@sweetjamaicastock.com
