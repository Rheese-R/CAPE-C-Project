/*Name: Rheese-Ashley Roman and Diontae Young
  Purpose: To create a .h file for the Internal Assessment
  Date: December 11, 2023*/


#define SWEET_JAMAICA_INVENTORY_H
#define MAX 100
#define MAX_INGREDIENTS 100


struct Order {
    int orderID;
    char pastry[25];
    int status;
};


typedef struct Queue {
    struct Order Q[MAX]; // Change Q type to struct Order
    int front;
    int rear;
} q;


// Declaration of struct ingredient
struct ingredient {
    char name[30];
    int quantity;
    int ID;
};


// Function to create a new queue
q Makeq(void) {
    q newQueue;
    newQueue.front = -1;
    newQueue.rear = -1;
    return newQueue;
}


// Function to check if the queue is full
int isFull(q Qu) {
    return (Qu.rear == MAX - 1);
}


// Function to check if the queue is empty
int isEmpty(q Qu) {
    return (Qu.front == -1 || Qu.front > Qu.rear);
}


// Function to add an order to the queue
q Enqueue(q Qu, struct Order newOrder) {
    if (isFull(Qu)) {
        printf("Queue is full. Cannot enqueue.\n");
        return Qu;
    }


    if (Qu.front == -1) {
        Qu.front = 0;
    }


    Qu.rear++;
    Qu.Q[Qu.rear] = newOrder;
    return Qu;
}


// Function to remove an order from the queue
q Dequeue(q Qu) {
    if (isEmpty(Qu)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return Qu;
    }


    Qu.front++;
    return Qu;
}


// Function to display orders in the queue
void Display(q Qu) {
     int i;
    if (isEmpty(Qu)) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }


    printf("Order ID\tPastry\t\tStatus\n");
    printf("Please note that '0' means the order is being processed and '1' means the order was completed\n");
    for (i = Qu.front; i <= Qu.rear; i++) {
        printf("%d\t\t%s\t\t%d\n", Qu.Q[i].orderID, Qu.Q[i].pastry, Qu.Q[i].status);
    }
}


// Additional function declarations for managing inventory
int Login(int login);
int Main_Menu();
void ManageInventory(q *inventory);
void ManageOrders(q *orders);
void EnterOrder(q *orders);
void ViewOrders(q orders);
void UpdateOrderStatus(q *orders);
int Add_Ingredient(q *inventory);
int Delete_Ingredient(q *inventory);
int Update_Ingredient(q *inventory);
int View_Inventory(q *inventory);
int Search_Inventory(q *inventory, int ID);
void View_All_Ingredients(q *inventory);
