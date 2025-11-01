#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_CART 50
#define NAME_LEN 50
#define CNIC_LEN 20

char customerName[NAME_LEN];
char customerCNIC[CNIC_LEN];

char productNames[MAX_PRODUCTS][NAME_LEN] = {
    "Milk", "Bread", "Eggs", "Rice", "Sugar"
};
float productPrices[MAX_PRODUCTS] = {120.0, 60.0, 20.0, 250.0, 100.0};
int productStock[MAX_PRODUCTS] = {50, 40, 100, 30, 25};
int productCount = 5;

int cartIndices[MAX_CART];
int cartQuantities[MAX_CART];
int cartCount = 0;
float totalBill = 0.0;
int discountApplied = 0;

void getCustomerInfo() {
    printf("Enter customer name: ");
    fgets(customerName, NAME_LEN, stdin);
    customerName[strcspn(customerName, "\n")] = '\0';

    printf("Enter CNIC number: ");
    fgets(customerCNIC, CNIC_LEN, stdin);
    customerCNIC[strcspn(customerCNIC, "\n")] = '\0';
}

void displayInventory() {
    printf("\n--- Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d. %s - Rs %.2f - Stock: %d\n", i + 1, productNames[i], productPrices[i], productStock[i]);
    }
}

void addItemToCart() {
    int choice, quantity;
    displayInventory();
    printf("Enter product number to add to cart: ");
    scanf("%d", &choice);
    choice--;
    if (choice < 0 || choice >= productCount) {
        printf("Invalid product selection.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    getchar();

    if (productStock[choice] < quantity) {
        printf("Not enough stock available.\n");
        return;
    }

    cartIndices[cartCount] = choice;
    cartQuantities[cartCount] = quantity;
    cartCount++;

    productStock[choice] -= quantity;
    printf("Item added to cart.\n");
}

void calculateTotalBill() {
    totalBill = 0.0;
    for (int i = 0; i < cartCount; i++) {
        int index = cartIndices[i];
        totalBill += productPrices[index] * cartQuantities[i];
    }

    char code[20];
    printf("Do you have a promocode? Enter it (or press Enter to skip): ");
    fgets(code, 20, stdin);
    code[strcspn(code, "\n")] = '\0';

    if (strcmp(code, "Eid2025") == 0) {
        totalBill *= 0.75;
        discountApplied = 1;
        printf("Promocode applied. 25%% discount given.\n");
    } else {
        discountApplied = 0;
        printf("No valid promocode applied.\n");
    }
}

void showInvoice() {
    printf("\n--- Invoice ---\n");
    printf("Customer Name: %s\n", customerName);
    printf("CNIC: %s\n", customerCNIC);
    printf("Items Purchased:\n");
    for (int i = 0; i < cartCount; i++) {
        int index = cartIndices[i];
        printf("%s x %d = Rs %.2f\n", productNames[index], cartQuantities[i], productPrices[index] * cartQuantities[i]);
    }

    float originalBill = 0.0;
    for (int i = 0; i < cartCount; i++) {
        int index = cartIndices[i];
        originalBill += productPrices[index] * cartQuantities[i];
    }

    printf("Total Bill (without discount): Rs %.2f\n", originalBill);
    if (discountApplied) {
        printf("Discount Applied: 25%%\n");
        printf("Final Bill: Rs %.2f\n", totalBill);
    } else {
        printf("Final Bill: Rs %.2f\n", originalBill);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Supermarket Menu ---\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Calculate Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                getCustomerInfo();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                addItemToCart();
                break;
            case 4:
                calculateTotalBill();
                break;
            case 5:
                showInvoice();
                break;
            case 6:
                printf("Exiting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
